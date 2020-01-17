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

今回は以下のセルに動的結合するとします．

```:dynamic.cdl
signature sDynamic {
    void say_str( void );
};
celltype tDynamic {
    entry sDynamic eDynamic;
    attr {
        char *str;
    };
};
cell tDynamic DynamicA {
    str = "Hello A";
};
cell tDynamic DynamicB {
    str = "Hello B";
};
```
同一セルタイプを持つ異なるセルを用意しました．区別できるように属性にstrを持たせ、受け口関数で喋らせます．

動的結合には

1. 直接参照呼び口を持つ方法
1. 他のセルを介してディスクリプタを取得する方法

があります．それぞれ見ていきます．

### １．参照呼び口を持つ方法

基本となる実装です．
まず、CDLコードは以下のようになります．

```:dynamic.cdl
celltype tTaskMain { /* 動的結合するセル */
    entry sTaskBody eBody;
    [dynamic, optional] /* 動的呼び口 */
        call sDynamic cDynamic;
    [ref_desc, optional] /* 参照呼び口 */
        call sDynamic cRefDesc[];
};

cell tTaskMain TaskMain {
    cGetDescriptor = RefDesc.eGetDescriptor;
    cRefDesc[] = DynamicA.eDynamic;
    cRefDesc[] = DynamicB.eDynamic;
};
```

tTaskMainセルがtDynamicセルに動的結合します．
[ref_desc]指定子をつけることで参照呼び口を設けることができます．
今回は２つのセルに対して呼び口配列で実装します．

次に、tTaskMainセルタイプコードです．

```c:tTaskMain.c
void eBody_main(CELLIDX idx)
{
  Descriptor( sDynamic ) desc;

  desc = cRefDesc_refer_to_descriptor(0);
  cDynamic_set_descriptor( desc );
  cDynamic_say_str();

  desc = cRefDesc_refer_to_descriptor(1);
  cDynamic_set_descriptor( desc );
  cDynamic_say_str();
}
```

１行目ではsDynamic型のシグニチャディスクリプタ **desc** を宣言しています．
次の行では **desc** に値を代入しています．
参照呼び口を設置したのでrefer_to_descriptor関数が使用可能です．これによりDynamicセルへのディスクリプタを取得可能です．
呼び口配列で定義したので、引数０はDynamicAセル、引数１はDynamicBセルへのディスクリプタを取得します．

最後にset_descriptorで引数に指定したディスクリプタの通りに動的結合します．
これでDynamicセルの受け口関数を使用することができます．

**ディスクリプタをgetしてsetする．** この流れが基本です．

### ２．他のセルを介してディスクリプタを取得する方法

他のセルに参照呼び口を持たせておくといった方法もあります．基本的な原理は同じです．
CDLコードです．

```:dynamic.cdl
signature sGetDescriptor {
    void getDescriptor( [out] Descriptor(sDynamic) *pDesc, [in] int ith );
};

celltype tTaskMain { /* 動的結合するセル */
    entry sTaskBody eBody;
    [dynamic, optional]
        call sDynamic cDynamic;
    call sGetDescriptor cGetDescriptor;
};
celltype tRefDesc { /* ディスクリプタを渡すセル */
    entry sGetDescriptor eGetDescriptor;
    [ref_desc] /* 参照呼び口 */
        call sDynamic cDynamic[];
};

cell tTaskMain TaskMain {
    cGetDescriptor = RefDesc.eGetDescriptor;
};
cell tRefDesc RefDesc {
    cRefDesc[] = DynamicA.eDynamic;
    cRefDesc[] = DynamicB.eDynamic;
};
```

sGetDescriptorではgetDescriptor()関数により、ポインタでディスクリプタ連れていきDynamicセルへのディスクリプタを代入します．第二引数ithで呼び口配列の添数を指定します．
見てわかる通り、先の例と違うのは仲介としてtRefDescセルを設けていることだけです．

tRefDescセルタイプコードは以下の通り

```c:tRefDesc.c
void eGetDescriptor_getDescriptor(CELLIDX idx, Descriptor( sDynamic )* pDesc, int ith)
{
  *pDesc = cDynamic_refer_to_descriptor(ith);
}
```


参照呼び口を設置したのでDynamicへのディスクリプタを取得可能です．

tTaskMainセルタイプコードは

```c:tTaskMain.c
void eBody_main(CELLIDX idx)
{
  Descriptor( sDynamic ) desc;

  cGetDescriptor_getDescriptor( &desc, 0 );
  cDynamic_set_descriptor( desc );
  cDynamic_say_str();

  cGetDescriptor_getDescriptor( &desc, 1 );
  cDynamic_set_descriptor( desc );
  cDynamic_say_str();
}
```

とすれば、Dynamicセルに動的結合できます．

今回も **ディスクリプタをgetしてsetする** 流れです．

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
