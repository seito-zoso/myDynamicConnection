/*
 * このファイルは tecsgen によりテンプレートとして自動生成されました
 * このファイルを編集して使用することが意図されていますが
 * tecsgen の再実行により上書きされてしまうため、通常
 *   gen/tTaskMain_templ.c => src/tTaskMain.c
 * のように名前, フォルダを変更してから修正します
 */
/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * 呼び口関数 #_TCPF_#
 * call port: cDynamic signature: sDynamic context:task optional:true
 *   bool_t     is_cDynamic_joined()                     check if joined
 *   void           cDynamic_say_str( );
 *   [dynamic, optional]
 *      void           cDynamic_set_descriptor( Descriptor( sDynamic ) desc );
 *      void           cDynamic_unjoin(  );
 * call port: cRefDesc signature: sDynamic context:task optional:true
 *   bool_t     is_cRefDesc_joined(int subscript)        check if joined
 *   void           cRefDesc_say_str( subscript );
 *       subscript:  0...(NCP_cRefDesc-1)
 *   [ref_desc]
 *      Descriptor( sDynamic ) cRefDesc_refer_to_descriptor( int_t subscript );
 *      Descriptor( sDynamic ) cRefDesc_ref_desc( int_t subscript )      (same as above; abbreviated version);
 * call port: cGetDescriptor signature: sGetDescriptor context:task
 *   ER             cGetDescriptor_getDescriptor( Descriptor( sDynamic )* pDesc );
 *
 * #[</PREAMBLE>]# */

/* プロトタイプ宣言や変数の定義をここに書きます #_PAC_# */
#include "tTaskMain_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

/* 受け口関数 #_TEPF_# */
/* #[<ENTRY_PORT>]# eBody
 * entry port: eBody
 * signature:  sTaskBody
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eBody_main
 * name:         eBody_main
 * global_name:  tTaskMain_eBody_main
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eBody_main(CELLIDX idx)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* エラー処理コードをここに記述します */
	} /* end if VALID_IDX(idx) */

	/* ここに処理本体を記述します #_TEFB_# */
  Descriptor( sDynamic ) desc1, desc2;
/* 直接Descを取得する */
  printf( "参照呼び口によりDecsを取得します\n" );

  printf( "セルDynamicA に接続\n" );
  desc1 = cRefDesc_refer_to_descriptor(0);
  cDynamic_set_descriptor( desc1 );
  cDynamic_say_str();

  printf( "セルDynamicB に接続\n" );
  desc1 = cRefDesc_refer_to_descriptor(1);
  cDynamic_set_descriptor( desc1 );
  cDynamic_say_str();
  /* 結合解除 */
  cDynamic_unjoin();

  printf( "結合を解除しました\n\n" );

/* RefDescセルを介してDescを取得する */
  printf( "セルRefDescを介してDecsを取得します\n" );

  printf( "セルDynamicA に接続\n" );
  cGetDescriptor_getDescriptor( &desc2, 0 );
  cDynamic_set_descriptor( desc2 );
  cDynamic_say_str();

  printf( "セルDynamicB に接続\n" );
  cGetDescriptor_getDescriptor( &desc2, 1 );
  cDynamic_set_descriptor( desc2 );
  cDynamic_say_str();
  /* 結合解除 */
  cDynamic_unjoin();
}

/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/
