# TECS **動的結合** の使い方
[TECS](https://www.toppers.jp/tecs.html)の動的結合の使い方です．

## コンポーネント図
<img src="https://github.com/seito-zoso/myDynamicConnection/blob/images/image.JPG" width=80%>


## 対象
TECSで開発をはじめたての方

## 動的結合とは
TECSではCDLコードにより静的にセルを結合させます．
動的結合を用いることで呼び口を受け口に **実効時** に結合します．
これにより実効時に **同一セルタイプの異なるセル** へ接続を切り替えられます．

## ディスクリプタ
TECS **シグニチャディスクリプタ** は簡単にいうと、シグニチャに貼られたラベルのようなものです．
ディスクリプタによりシグニチャの結合先のセルを判別することができます．

## 実装
実際に動的結合を実装してみます．

1. 直接参照呼び口を持つ方法
1. 他のセルを介してディスクリプタを取得する方法

があります．それぞれ見ていきます．

### 参照呼び口を持つ方法

基本実装です．
まず、CDLコードは以下のようになります．

`celltype tTaskMain { /* 動的結合するセル */
    entry sTaskBody eBody;
    [dynamic,optional] /* 動的呼び口 */
        call sDynamic cDynamic;
    [ref_desc] /* 参照呼び口 */
        call sDynamic cRefDesc;
};

celltype tDynamic { /* 動的結合されるセル */
    entry sDynamic eDynamic;
};`

tTaskMainセルがtDynamicセルに動的結合します．
[ref_desc]指定子をつけることで参照呼び口を設けることができます．

次に、tTaskMainセルタイプコードです．

`void eBody_main(CELLIDX idx)
{
  Descriptor( sDynamic ) desc;
  desc = cRefDesc_refer_to_descriptor();
  cDynamic_set_descriptor( desc );
  cDynamic_function();
}`

１行目ではsDynamic型のシグニチャディスクリプタ **desc** を宣言しています．
次の行では **desc** に値を代入しています．
参照呼び口を設置したのでrefer_to_descriptor関数が使用可能です．これによりDynamicセルへのディスクリプタを取得可能です．

set_descriptorで引数に指定したディスクリプタの通りに動的結合します．
最後の行では動的結合したので、Dynamicセルの受け口関数を使用することができています．

**ディスクリプタをgetしてsetする．** この流れが基本です．

### 他のセルを介してディスクリプタを取得する方法

他のセルに参照呼び口を持たせておくといった方法もあります．基本的な原理は同じです．
CDLコードです．

`signature sGetDescriptor {
    void getDescriptor( [out] Descriptor(sDynamic) *pDesc );
};

celltype tTaskMain { /* 動的結合するセル */
    entry sTaskBody eBody;
    [dynamic,optional]
        call sDynamic cDynamic;
    call sGetDescriptor cGetDescriptor;
};
celltype tRefDesc { /* ディスクリプタを渡すセル */
    entry sGetDescriptor eGetDescriptor;
    [ref_desc] /* 参照呼び口 */
        call sDynamic cDynamic;
};
celltype tDynamic { /* 動的結合されるセル */
    entry sDynamic eDynamic;
};`

sGetDescriptorではgetDescriptor()関数により、ポインタでディスクリプタ連れていきDynamicセルへのディスクリプタを代入します．
見てわかる通り、先の例と違うのは仲介としてtRefDescセルを設けていることだけです．

tRefDescセルタイプコードは以下のようにし

`void eGetDescriptor_getDescriptor(CELLIDX idx, Descriptor( sDynamic )* pDesc)
{
  *pDesc = cDynamic_refer_to_descriptor();
}`

参照呼び口を設置したのでDynamicへのディスクリプタを取得可能です．

tTaskMainセルタイプコードは

`void eBody_main(CELLIDX idx)
{
  Descriptor( sDynamic ) desc;
  cGetDescriptor_getDescriptor( &desc );
  cDynamic_set_descriptor( desc );
  cDynamic_function();
}`

とすれば、Dynamicセルに動的結合できます．

今回も **ディスクリプタをgetしてsetする**　流れです．

## 練習
githubより[myDynamicConnection](https://github.com/seito-zoso/myDynamicConnection)をtecsgenディレクトリにダウンロードしてください．

    % cd tecsgen
    % git clone https://github.com/seito-zoso/myDynamicConnection.git

ダウンロードできたら

    % make

tecsgenにより実行ファイルが作成されています．

    % ./dynamic.exe

動的結合の動作確認ができます．

src/ にセルタイプコードが入っています．
色々自分で変えてみてください．

## 参考
[TECSマニュアル：動的結合](https://tecs-docs.readthedocs.io/ja/latest/tecs/SPCref_dynamic_join.html)
