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
 *   void           cDynamic_initialize( );
 *   void           cDynamic_do_something( );
 *   void           cDynamic_finalize( );
 *   [dynamic, optional]
 *      void           cDynamic_set_descriptor( Descriptor( sDynamic ) desc );
 *      void           cDynamic_unjoin(  );
 * call port: cRefDesc signature: sDynamic context:task
 *   void           cRefDesc_initialize( );
 *   void           cRefDesc_do_something( );
 *   void           cRefDesc_finalize( );
 *   [ref_desc]
 *      Descriptor( sDynamic ) cRefDesc_refer_to_descriptor();
 *      Descriptor( sDynamic ) cRefDesc_ref_desc()      (same as above; abbreviated version);
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
    Descriptor( sDynamic ) desc;
    // cGetDescriptor_getDescriptor( &desc ); // RefDescセルを介してDescを取得する
    desc = cRefDesc_refer_to_descriptor(); // 直接Descを取得する
    cDynamic_set_descriptor( desc );
    cDynamic_initialize();
}

/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/
