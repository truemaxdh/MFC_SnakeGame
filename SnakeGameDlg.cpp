// SnakeGameDlg.cpp : インプリメンテーション ファイル
//

#include "stdafx.h"
#include "SnakeGame.h"
#include "SnakeGameDlg.h"
#include "time.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// アプリケーションのバージョン情報で使われている CAboutDlg ダイアログ

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// ダイアログ データ
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard は仮想関数のオーバーライドを生成します
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV のサポート
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// メッセージ ハンドラがありません。
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSnakeGameDlg ダイアログ

CSnakeGameDlg::CSnakeGameDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSnakeGameDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSnakeGameDlg)
		// メモ: この位置に ClassWizard によってメンバの初期化が追加されます。
	//}}AFX_DATA_INIT
	// メモ: LoadIcon は Win32 の DestroyIcon のサブシーケンスを要求しません。
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSnakeGameDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSnakeGameDlg)
		// メモ: この場所には ClassWizard によって DDX と DDV の呼び出しが追加されます。
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSnakeGameDlg, CDialog)
	//{{AFX_MSG_MAP(CSnakeGameDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_KEYDOWN()
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_START, OnStart)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSnakeGameDlg メッセージ ハンドラ

BOOL CSnakeGameDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// "バージョン情報..." メニュー項目をシステム メニューへ追加します。

	// IDM_ABOUTBOX はコマンド メニューの範囲でなければなりません。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// このダイアログ用のアイコンを設定します。フレームワークはアプリケーションのメイン
	// ウィンドウがダイアログでない時は自動的に設定しません。
	SetIcon(m_hIcon, TRUE);			// 大きいアイコンを設定
	SetIcon(m_hIcon, FALSE);		// 小さいアイコンを設定
	
	// TODO: 特別な初期化を行う時はこの場所に追加してください。
	CClientDC dc(this);

	m_bmpSnake1.LoadBitmap(IDB_SNAKE1);
	m_bmpFood1.LoadBitmap(IDB_FOOD);
	m_bmpBlank.LoadBitmap(IDB_BLANK);
	m_bmpScore.LoadBitmap(IDB_NUMIMG);
	m_BoardDC.CreateCompatibleDC(&dc);
	m_bmpBoard.CreateCompatibleBitmap(&dc,GROUNDWIDTH + SCOREPANELWIDTH, GROUNDHEIGHT);
	m_BoardDC.SelectObject(&m_bmpBoard);
	
	return TRUE;  // TRUE を返すとコントロールに設定したフォーカスは失われません。
}

void CSnakeGameDlg::InitGame() 
{
	m_iSnakeSize = 5;
	
	for (int iX = 0;iX<BOARDWIDTH;iX++)
	{
		for (int iY = 0;iY<BOARDHEIGHT;iY++) m_stage[iX][iY] = 0;
	}

	for(int i = 0;i<m_iSnakeSize;i++) 
	{
		m_snakePos[i][0] = (BOARDWIDTH-m_iSnakeSize)/2 + i;
		m_snakePos[i][1] = (BOARDHEIGHT/2);	
		m_stage[m_snakePos[i][0]][m_snakePos[i][1]] = SNAKE;
	}
	
	m_iPos = 4;
	m_iDelPos = -1; 
	m_iSnakeDirection = RIGHT;

	m_iFoodCnt = 5;
	SetFood(m_iFoodCnt);
	
	m_tmrInterval = 100;
	SetTimer(TIMER1,m_tmrInterval,NULL);
}

void CSnakeGameDlg::SetFood(int iFoodCnt)
{
	srand((unsigned)time(NULL));
	int iFoodX,iFoodY;
	for(int i= 0;i<m_iFoodCnt;i++)
	{
		bool bFoodMake = true;
		while (bFoodMake)
		{
			iFoodX = rand() * BOARDWIDTH / 32768;
			iFoodY = rand() * BOARDHEIGHT / 32768;
			if (m_stage[iFoodX][iFoodY] == 0)
			{
				m_stage[iFoodX][iFoodY] = FOOD;
				bFoodMake = false;
			}
		}
	}
	m_iReservedFood = iFoodCnt;

}


void CSnakeGameDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// もしダイアログボックスに最小化ボタンを追加するならば、アイコンを描画する
// コードを以下に記述する必要があります。MFC アプリケーションは document/view
// モデルを使っているので、この処理はフレームワークにより自動的に処理されます。

void CSnakeGameDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 描画用のデバイス コンテキスト

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// クライアントの矩形領域内の中央
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// アイコンを描画します。
		dc.DrawIcon(x, y, m_hIcon);
		
	}
	else
	{
		CPaintDC dc(this); // 描画用のデバイス コンテキスト
		CRect rect;
		this->GetClientRect(&rect);
		CBrush pBrush(RGB(255,255,255));
		dc.FillRect(rect,&pBrush);
		
		CDialog::OnPaint();
	}
}

// システムは、ユーザーが最小化ウィンドウをドラッグしている間、
// カーソルを表示するためにここを呼び出します。
HCURSOR CSnakeGameDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CSnakeGameDlg::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: この位置にメッセージ ハンドラ用のコードを追加するかまたはデフォルトの処理を呼び出してください
	switch(nChar)
	{
	case VK_NUMPAD4:
	case VK_LEFT:
		m_iSnakeDirection = LEFT;
		break;
	case VK_NUMPAD6:
	case VK_RIGHT:
		m_iSnakeDirection = RIGHT;
		break;
	case VK_NUMPAD8:
	case VK_UP:
		m_iSnakeDirection = UP;
		break;
	case VK_NUMPAD2:
	case VK_DOWN:
		m_iSnakeDirection = DOWN;
		break;
	}
	
	
}


BOOL CSnakeGameDlg::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: この位置に固有の処理を追加するか、または基本クラスを呼び出してください
	if(pMsg->message == WM_KEYDOWN && 
		(pMsg->wParam == VK_RIGHT || pMsg->wParam == VK_LEFT || pMsg->wParam == VK_UP || pMsg->wParam == VK_DOWN))
	{
		SendMessage(pMsg->message, pMsg->wParam, pMsg->lParam);
	}		
	return CDialog::PreTranslateMessage(pMsg);
}


void CSnakeGameDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: この位置にメッセージ ハンドラ用のコードを追加するかまたはデフォルトの処理を呼び出してください
	bool GameOverFlag = false;
	int iOldPos = m_iPos++;
	if (m_iPos==200 ) m_iPos = 0;
	if (m_iDelPos++ ==200 ) m_iDelPos = 0;

	m_snakePos[m_iPos][0] = m_snakePos[iOldPos][0];
	m_snakePos[m_iPos][1] = m_snakePos[iOldPos][1];
	switch(m_iSnakeDirection)
	{
	case LEFT:
		m_snakePos[m_iPos][0]--;
		if (m_snakePos[m_iPos][0] < 0) GameOverFlag = true;
		break;
	case RIGHT:
		m_snakePos[m_iPos][0]++;
		if (m_snakePos[m_iPos][0] >= BOARDWIDTH) GameOverFlag = true;
		break;
	case UP:
		m_snakePos[m_iPos][1]--;
		if (m_snakePos[m_iPos][1] < 0) GameOverFlag = true;
		break;
	case DOWN:
		m_snakePos[m_iPos][1]++;
		if (m_snakePos[m_iPos][1] >= BOARDHEIGHT) GameOverFlag = true;
		break;
	}
	if (GameOverFlag) {
		GameOverMsg();
		return;
	}
	if (m_stage[m_snakePos[m_iPos][0]][m_snakePos[m_iPos][1]] == FOOD) 
	{
		m_iSnakeSize++;
		m_iScore++;
		m_iDelPos--;
		if (m_iDelPos < 0) m_iDelPos+= 200;
		m_tmrInterval-=2;
		if (m_tmrInterval < 1) m_tmrInterval = 1;
		m_iReservedFood--;
		if (m_iReservedFood == 0) SetFood(++m_iFoodCnt);
		SetTimer(TIMER1,m_tmrInterval,NULL);
	}
	
	CClientDC dc(this);
	CDC CellDC;
	CellDC.CreateCompatibleDC(&dc);
	m_stage[m_snakePos[m_iPos][0]][m_snakePos[m_iPos][1]] = SNAKE;
	m_stage[m_snakePos[m_iDelPos][0]][m_snakePos[m_iDelPos][1]] = 0;
	for (int iX = 0;iX<BOARDWIDTH;iX++)
	{
		for (int iY = 0;iY<BOARDHEIGHT;iY++)
		{
			switch(m_stage[iX][iY])
			{
			case SNAKE:
				CellDC.SelectObject(&m_bmpSnake1);
				break;
			case FOOD:
				CellDC.SelectObject(&m_bmpFood1);
				break;
			default:
				CellDC.SelectObject(&m_bmpBlank);
			}
			m_BoardDC.StretchBlt(iX*GROUNDWIDTH/BOARDWIDTH,iY*GROUNDHEIGHT/BOARDHEIGHT,GROUNDWIDTH/BOARDWIDTH,GROUNDHEIGHT/BOARDHEIGHT,&CellDC,0,0,14,14,SRCCOPY);
		}
	}
	SetScoreBoard(&CellDC);

	dc.BitBlt(0,0,GROUNDWIDTH + SCOREPANELWIDTH,GROUNDHEIGHT,&m_BoardDC,0,0,SRCCOPY);
	CDialog::OnTimer(nIDEvent);
}


void CSnakeGameDlg::SetScoreBoard(CDC* pDC) 
{
	//CellDC.SelectObject(&m_bmpScore);
	pDC->SelectObject(&m_bmpScore);
	int iScoreWk,iNumBase = 10000;
	for (int iNumPos = 0;iNumPos < 5;iNumPos++)
	{
		iScoreWk = m_iScore / iNumBase;
		//m_BoardDC.StretchBlt(GROUNDWIDTH,SCOREPANELHEIGHT,SCOREPANELWIDTH,SCOREPANELHEIGHT,&CellDC,0,0,SCOREPANELWIDTH,SCOREPANELHEIGHT,SRCCOPY);
		m_BoardDC.StretchBlt(GROUNDWIDTH + 16 * iNumPos,SCOREPANELHEIGHT, 16, SCOREPANELHEIGHT, pDC,iScoreWk * 16,0,16,SCOREPANELHEIGHT,SRCCOPY);
	}
}


void CSnakeGameDlg::GameOverMsg() 
{
	KillTimer(TIMER1);
	AfxMessageBox("GameOver");
	GetDlgItem(IDC_START)->EnableWindow(true);
}

void CSnakeGameDlg::OnStart() 
{
	// TODO: この位置にコントロール通知ハンドラ用のコードを追加してください
	GetDlgItem(IDC_START)->EnableWindow(false);
	SetFocus();
	InitGame();
}
