// SnakeGameDlg.h : ヘッダー ファイル
//

#if !defined(AFX_SNAKEGAMEDLG_H__76961C1C_A883_4F22_BEFC_8340121A406C__INCLUDED_)
#define AFX_SNAKEGAMEDLG_H__76961C1C_A883_4F22_BEFC_8340121A406C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define BOARDWIDTH			50
#define BOARDHEIGHT			50
#define GROUNDWIDTH			500
#define GROUNDHEIGHT		500
#define SCOREPANELWIDTH		100
#define SCOREPANELHEIGHT	100
#define SNAKE	1
#define FOOD	2
#define LEFT	1
#define RIGHT   2
#define UP		3
#define DOWN	4
#define TIMER1	1
/////////////////////////////////////////////////////////////////////////////
// CSnakeGameDlg ダイアログ

class CSnakeGameDlg : public CDialog
{
// 構築
public:
	CSnakeGameDlg(CWnd* pParent = NULL);	// 標準のコンストラクタ
	void SetFood(int iFoodCnt);
	void GameOverMsg();
	void InitGame();
	void SetScoreBoard(CDC* pDC);
// ダイアログ データ
	//{{AFX_DATA(CSnakeGameDlg)
	enum { IDD = IDD_SNAKEGAME_DIALOG };
		// メモ: この位置に ClassWizard によってデータ メンバが追加されます。
	//}}AFX_DATA

	// ClassWizard は仮想関数のオーバーライドを生成します。
	//{{AFX_VIRTUAL(CSnakeGameDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV のサポート
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:
	HICON m_hIcon;
	int m_stage[BOARDWIDTH][BOARDHEIGHT];
	int m_snakePos[200][2],m_iPos, m_iDelPos, m_iSnakeSize, m_iSnakeDirection;
	int m_iFoodCnt,m_iReservedFood;
	int m_iScore;
	UINT m_tmrInterval;
	CDC m_BoardDC;
	CBitmap m_bmpBoard;
	CBitmap m_bmpSnake1, m_bmpFood1, m_bmpBlank, m_bmpScore;
	// 生成されたメッセージ マップ関数
	//{{AFX_MSG(CSnakeGameDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnStart();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_SNAKEGAMEDLG_H__76961C1C_A883_4F22_BEFC_8340121A406C__INCLUDED_)
