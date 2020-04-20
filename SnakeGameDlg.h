// SnakeGameDlg.h : �w�b�_�[ �t�@�C��
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
// CSnakeGameDlg �_�C�A���O

class CSnakeGameDlg : public CDialog
{
// �\�z
public:
	CSnakeGameDlg(CWnd* pParent = NULL);	// �W���̃R���X�g���N�^
	void SetFood(int iFoodCnt);
	void GameOverMsg();
	void InitGame();
	void SetScoreBoard(CDC* pDC);
// �_�C�A���O �f�[�^
	//{{AFX_DATA(CSnakeGameDlg)
	enum { IDD = IDD_SNAKEGAME_DIALOG };
		// ����: ���̈ʒu�� ClassWizard �ɂ���ăf�[�^ �����o���ǉ�����܂��B
	//}}AFX_DATA

	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B
	//{{AFX_VIRTUAL(CSnakeGameDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �̃T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
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
	// �������ꂽ���b�Z�[�W �}�b�v�֐�
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
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_SNAKEGAMEDLG_H__76961C1C_A883_4F22_BEFC_8340121A406C__INCLUDED_)
