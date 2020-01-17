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
 * call port: cRefDesc signature: sDynamic context:task optional:true
 *   bool_t     is_cRefDesc_joined(int subscript)        check if joined
 *   void           cRefDesc_say_str( subscript );
 *       subscript:  0...(NCP_cRefDesc-1)
 *   [ref_desc]
 *      Descriptor( sDynamic ) cRefDesc_refer_to_descriptor( int_t subscript );
 *      Descriptor( sDynamic ) cRefDesc_ref_desc( int_t subscript )      (same as above; abbreviated version);
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
void
eGetDescriptor_getDescriptor(CELLIDX idx, Descriptor( sDynamic )* pDesc, int ith)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* エラー処理コードをここに記述します */
	} /* end if VALID_IDX(idx) */

	/* ここに処理本体を記述します #_TEFB_# */
	*pDesc = cRefDesc_refer_to_descriptor( ith );
}

/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/
