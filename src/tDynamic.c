/*
 * このファイルは tecsgen によりテンプレートとして自動生成されました
 * このファイルを編集して使用することが意図されていますが
 * tecsgen の再実行により上書きされてしまうため、通常
 *   gen/tDynamic_templ.c => src/tDynamic.c
 * のように名前, フォルダを変更してから修正します
 */
/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * #[</PREAMBLE>]# */

/* プロトタイプ宣言や変数の定義をここに書きます #_PAC_# */
#include "tDynamic_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

/* 受け口関数 #_TEPF_# */
/* #[<ENTRY_PORT>]# eDynamic
 * entry port: eDynamic
 * signature:  sDynamic
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eDynamic_initialize
 * name:         eDynamic_initialize
 * global_name:  tDynamic_eDynamic_initialize
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eDynamic_initialize(CELLIDX idx)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* エラー処理コードをここに記述します */
	} /* end if VALID_IDX(idx) */

	/* ここに処理本体を記述します #_TEFB_# */
		printf("initialize\n");
}

/* #[<ENTRY_FUNC>]# eDynamic_do_something
 * name:         eDynamic_do_something
 * global_name:  tDynamic_eDynamic_do_something
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eDynamic_do_something(CELLIDX idx)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* エラー処理コードをここに記述します */
	} /* end if VALID_IDX(idx) */

	/* ここに処理本体を記述します #_TEFB_# */
		printf("do_something\n");
}

/* #[<ENTRY_FUNC>]# eDynamic_finalize
 * name:         eDynamic_finalize
 * global_name:  tDynamic_eDynamic_finalize
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eDynamic_finalize(CELLIDX idx)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* エラー処理コードをここに記述します */
	} /* end if VALID_IDX(idx) */

	/* ここに処理本体を記述します #_TEFB_# */
		printf("finalize\n");
}

/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/
