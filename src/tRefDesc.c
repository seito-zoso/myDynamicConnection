/*
 * このファイルは tecsgen によりテンプレートとして自動生成されました
 * このファイルを編集して使用することが意図されていますが
 * tecsgen の再実行により上書きされてしまうため、通常
 *   gen/tRefDesc_templ.c => src/tRefDesc.c
 * のように名前, フォルダを変更してから修正します
 */
/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * 呼び口関数 #_TCPF_#
 * call port: cDynamic signature: sDynamic context:task
 *   void           cDynamic_initialize( );
 *   void           cDynamic_do_something( );
 *   void           cDynamic_finalize( );
 *   [ref_desc]
 *      Descriptor( sDynamic ) cDynamic_refer_to_descriptor();
 *      Descriptor( sDynamic ) cDynamic_ref_desc()      (same as above; abbreviated version);
 *
 * #[</PREAMBLE>]# */

/* プロトタイプ宣言や変数の定義をここに書きます #_PAC_# */
#include "tRefDesc_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

/* 受け口関数 #_TEPF_# */
/* #[<ENTRY_PORT>]# eGetDescriptor
 * entry port: eGetDescriptor
 * signature:  sGetDescriptor
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eGetDescriptor_getDescriptor
 * name:         eGetDescriptor_getDescriptor
 * global_name:  tRefDesc_eGetDescriptor_getDescriptor
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eGetDescriptor_getDescriptor(CELLIDX idx, Descriptor( sDynamic )* pDesc)
{
	ER		ercd = E_OK;
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		return(E_ID);
	} /* end if VALID_IDX(idx) */

	/* ここに処理本体を記述します #_TEFB_# */

	*pDesc = cDynamic_refer_to_descriptor();
	return(ercd);
}

/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/
