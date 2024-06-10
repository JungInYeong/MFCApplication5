
// MFCApplication5Dlg.h: 헤더 파일
//
#include<vector>
#pragma once

// CMFCApplication5Dlg 대화 상자
class CMFCApplication5Dlg : public CDialogEx
{
// 생성입니다.
public:
	bool picture = true;
	CMFCApplication5Dlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.


// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION5_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	LRESULT OnUpdateDice(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClickedButton1();
	CBitmapButton m_dice1;
	CBitmapButton m_dice2;
	CBitmapButton m_dice3;
	CBitmapButton m_dice4;
	CBitmapButton m_dice5;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();

	afx_msg void OnBnClickedButton7();
	//int m_score1;
//	CButton m_showScore;
	CButton m_showScore;
	CButton m_score1;
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton10();
	afx_msg void OnBnClickedButton11();
	CButton m_score2;
	CButton m_score3;
	CButton m_score4;
	CButton m_score5;
};
