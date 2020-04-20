// SnakeGame.h : SNAKEGAME アプリケーションのメイン ヘッダー ファイルです。
//

#if !defined(AFX_SNAKEGAME_H__3294A4C3_B835_4763_9905_F2950A1ED5B1__INCLUDED_)
#define AFX_SNAKEGAME_H__3294A4C3_B835_4763_9905_F2950A1ED5B1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// メイン シンボル

/////////////////////////////////////////////////////////////////////////////
// CSnakeGameApp:
// このクラスの動作の定義に関しては SnakeGame.cpp ファイルを参照してください。
//

class CSnakeGameApp : public CWinApp
{
public:
	CSnakeGameApp();

// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。
	//{{AFX_VIRTUAL(CSnakeGameApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// インプリメンテーション

	//{{AFX_MSG(CSnakeGameApp)
		// メモ - ClassWizard はこの位置にメンバ関数を追加または削除します。
		//        この位置に生成されるコードを編集しないでください。
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_SNAKEGAME_H__3294A4C3_B835_4763_9905_F2950A1ED5B1__INCLUDED_)
