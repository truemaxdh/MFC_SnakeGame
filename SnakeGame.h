// SnakeGame.h : SNAKEGAME �A�v���P�[�V�����̃��C�� �w�b�_�[ �t�@�C���ł��B
//

#if !defined(AFX_SNAKEGAME_H__3294A4C3_B835_4763_9905_F2950A1ED5B1__INCLUDED_)
#define AFX_SNAKEGAME_H__3294A4C3_B835_4763_9905_F2950A1ED5B1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// ���C�� �V���{��

/////////////////////////////////////////////////////////////////////////////
// CSnakeGameApp:
// ���̃N���X�̓���̒�`�Ɋւ��Ă� SnakeGame.cpp �t�@�C�����Q�Ƃ��Ă��������B
//

class CSnakeGameApp : public CWinApp
{
public:
	CSnakeGameApp();

// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B
	//{{AFX_VIRTUAL(CSnakeGameApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����

	//{{AFX_MSG(CSnakeGameApp)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ����o�֐���ǉ��܂��͍폜���܂��B
		//        ���̈ʒu�ɐ��������R�[�h��ҏW���Ȃ��ł��������B
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_SNAKEGAME_H__3294A4C3_B835_4763_9905_F2950A1ED5B1__INCLUDED_)
