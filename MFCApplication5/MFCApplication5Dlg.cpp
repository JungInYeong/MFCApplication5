
// MFCApplication5Dlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "MFCApplication5.h"
#include "MFCApplication5Dlg.h"
#include "afxdialogex.h"
#include <Windows.h>
#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <algorithm>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

bool arr[5] = { 1,1,1,1,1 };
//bool dice1;
//bool dice2;
//bool dice3;
//bool dice4;
//bool dice5;

// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCApplication5Dlg 대화 상자



CMFCApplication5Dlg::CMFCApplication5Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION5_DIALOG, pParent)
	//, m_score1(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication5Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON2, m_dice1);
	DDX_Control(pDX, IDC_BUTTON3, m_dice2);
	DDX_Control(pDX, IDC_BUTTON4, m_dice3);
	DDX_Control(pDX, IDC_BUTTON5, m_dice4);
	DDX_Control(pDX, IDC_BUTTON6, m_dice5);
	//DDX_Control(pDX, IDC_BUTTON7, m_score1);
	DDX_Control(pDX, IDC_BUTTON15, m_showScore);
	DDX_Control(pDX, IDC_BUTTON7, m_score1);
	DDX_Control(pDX, IDC_BUTTON8, m_score2);
	DDX_Control(pDX, IDC_BUTTON9, m_score3);
	DDX_Control(pDX, IDC_BUTTON10, m_score4);
	DDX_Control(pDX, IDC_BUTTON11, m_score5);
}

BEGIN_MESSAGE_MAP(CMFCApplication5Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication5Dlg::OnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCApplication5Dlg::OnBnClickedButton2)
	ON_MESSAGE(WM_USER + 1, &CMFCApplication5Dlg::OnUpdateDice)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCApplication5Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFCApplication5Dlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CMFCApplication5Dlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CMFCApplication5Dlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CMFCApplication5Dlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CMFCApplication5Dlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CMFCApplication5Dlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON10, &CMFCApplication5Dlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON11, &CMFCApplication5Dlg::OnBnClickedButton11)
END_MESSAGE_MAP()


// CMFCApplication5Dlg 메시지 처리기

BOOL CMFCApplication5Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CMFCApplication5Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CMFCApplication5Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CMFCApplication5Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

// 비트맵 리소스를 로드하는 함수
HBITMAP LoadBitmapFromResource(HINSTANCE hInstance, int resourceID) {
	return LoadBitmap(hInstance, MAKEINTRESOURCE(resourceID));
}

vector<int> RemoveArr(int idx) {
	vector<int> vec = { 0,1,2,3,4 };

	vec.erase(vec.begin() + idx);

	return vec;
}

//void CMFCApplication5Dlg::OnClickedButton1() {
//	vector<int> indices = { IDB_BITMAP1, IDB_BITMAP2, IDB_BITMAP3, IDB_BITMAP4, IDB_BITMAP5, IDB_BITMAP6 };
//
//	//random_shuffle(indices.begin(), indices.end());
//
//	HINSTANCE hInstance = GetModuleHandle(nullptr);
//
//	for (int j = 0; j < 5; ++j) {
//		int i = rand() % 6;
//		HBITMAP hBitmap = LoadBitmapFromResource(hInstance, indices[i]);
//		if (hBitmap == nullptr) {
//			AfxMessageBox(_T("Failed to load bitmap!"));
//			return;
//		}
//		if (arr[j] == 1) {
//			PostMessage(WM_USER + 1, j, reinterpret_cast<LPARAM>(hBitmap));
//			CString scoreStr;
//			scoreStr.Format(_T("%d"), indices[i]);
//			m_score1.SetWindowText(scoreStr);
//		}
//	}
//	
//}
void CMFCApplication5Dlg::OnClickedButton1() {
	vector<int> indices = { IDB_BITMAP1, IDB_BITMAP2, IDB_BITMAP3, IDB_BITMAP4, IDB_BITMAP5, IDB_BITMAP6 };

	//random_shuffle(indices.begin(), indices.end());

	HINSTANCE hInstance = GetModuleHandle(nullptr);

	for (int j = 0; j < 5; ++j) {
		int i = rand() % 6;
		HBITMAP hBitmap = LoadBitmapFromResource(hInstance, indices[i]);
		if (hBitmap == nullptr) {
			AfxMessageBox(_T("Failed to load bitmap!"));
			return;
		}
		if (arr[j] == 1) {
			PostMessage(WM_USER + 1, j, reinterpret_cast<LPARAM>(hBitmap));
			CString scoreStr;
			scoreStr.Format(_T("%d"), indices[i]);
		switch(j) {
		case 0:
			m_score1.SetWindowText(scoreStr);

		case 1:
			m_score2.SetWindowText(scoreStr);

		case 2:
			m_score3.SetWindowText(scoreStr);

		case 3:
			m_score4.SetWindowText(scoreStr);

		case 4:
			m_score5.SetWindowText(scoreStr);

		}	
			
		}
		
	}

}
void AdjustButtonToBitmap(CButton& button, HBITMAP hBitmap) 
{
	BITMAP bm;
	GetObject(hBitmap, sizeof(BITMAP), &bm);
	button.SetBitmap(hBitmap);
	//button.SetWindowPos(nullptr, 0, 0, 200, 200, SWP_NOMOVE | SWP_NOZORDER);
}

LRESULT CMFCApplication5Dlg::OnUpdateDice(WPARAM wParam, LPARAM lParam)
{
	int diceIndex = static_cast<int>(wParam);
	HBITMAP hBitmap = reinterpret_cast<HBITMAP>(lParam);

	switch (diceIndex)
	{
	case 0:
		AdjustButtonToBitmap(m_dice1, hBitmap);
		break;

	case 1:
		AdjustButtonToBitmap(m_dice2, hBitmap);
		break;

	case 2:
		AdjustButtonToBitmap(m_dice3, hBitmap);
		break;

	case 3:
		AdjustButtonToBitmap(m_dice4, hBitmap);
		break;

	case 4:
		AdjustButtonToBitmap(m_dice5, hBitmap);
		break;
	}

	return 0;
}


void CMFCApplication5Dlg::OnBnClickedButton2()
{
	// 버튼 2에서 이미지를 추출합니다.
	CButton* pButton2 = (CButton*)GetDlgItem(IDC_BUTTON2);
	HBITMAP hBitmap = (HBITMAP)pButton2->SendMessage(BM_GETIMAGE, IMAGE_BITMAP, 0);

	// 버튼 7에 이미지를 설정합니다.
	CButton* pButton7 = (CButton*)GetDlgItem(IDC_BUTTON7);
	pButton7->SetBitmap(hBitmap);

	// 버튼 2에 있는 이미지를 삭제합니다.
	pButton2->SetBitmap(nullptr);
	arr[0] = false;

}
	


void CMFCApplication5Dlg::OnBnClickedButton3()
{
	// 버튼 2에서 이미지를 추출합니다.
	CButton* pButton3 = (CButton*)GetDlgItem(IDC_BUTTON3);
	HBITMAP hBitmap = (HBITMAP)pButton3->SendMessage(BM_GETIMAGE, IMAGE_BITMAP, 0);

	// 버튼 7에 이미지를 설정합니다.
	CButton* pButton8 = (CButton*)GetDlgItem(IDC_BUTTON8);
	pButton8->SetBitmap(hBitmap);

	// 버튼 2에 있는 이미지를 삭제합니다.
	pButton3->SetBitmap(nullptr);
	arr[1] = false;
}


void CMFCApplication5Dlg::OnBnClickedButton4()
{
	// 버튼 2에서 이미지를 추출합니다.
	CButton* pButton4 = (CButton*)GetDlgItem(IDC_BUTTON4);
	HBITMAP hBitmap = (HBITMAP)pButton4->SendMessage(BM_GETIMAGE, IMAGE_BITMAP, 0);

	// 버튼 7에 이미지를 설정합니다.
	CButton* pButton9 = (CButton*)GetDlgItem(IDC_BUTTON9);
	pButton9->SetBitmap(hBitmap);

	// 버튼 2에 있는 이미지를 삭제합니다.
	pButton4->SetBitmap(nullptr);
	arr[2] = false;
}


void CMFCApplication5Dlg::OnBnClickedButton5()
{
	// 버튼 2에서 이미지를 추출합니다.
	CButton* pButton5 = (CButton*)GetDlgItem(IDC_BUTTON5);
	HBITMAP hBitmap = (HBITMAP)pButton5->SendMessage(BM_GETIMAGE, IMAGE_BITMAP, 0);

	// 버튼 7에 이미지를 설정합니다.
	CButton* pButton10 = (CButton*)GetDlgItem(IDC_BUTTON10);
	pButton10->SetBitmap(hBitmap);

	// 버튼 2에 있는 이미지를 삭제합니다.
	pButton5->SetBitmap(nullptr);
	arr[3] = false;
}


void CMFCApplication5Dlg::OnBnClickedButton6()
{
	// 버튼 2에서 이미지를 추출합니다.
	CButton* pButton6 = (CButton*)GetDlgItem(IDC_BUTTON6);
	HBITMAP hBitmap = (HBITMAP)pButton6->SendMessage(BM_GETIMAGE, IMAGE_BITMAP, 0);

	// 버튼 7에 이미지를 설정합니다.
	CButton* pButton11 = (CButton*)GetDlgItem(IDC_BUTTON11);
	pButton11->SetBitmap(hBitmap);

	// 버튼 2에 있는 이미지를 삭제합니다.
	pButton6->SetBitmap(nullptr);
	arr[4] = false;
}



void CMFCApplication5Dlg::OnBnClickedButton7()
{
	// 버튼 7에서 이미지를 추출합니다.
	CButton* pButton7 = (CButton*)GetDlgItem(IDC_BUTTON7);
	HBITMAP hBitmap = (HBITMAP)pButton7->SendMessage(BM_GETIMAGE, IMAGE_BITMAP, 0);

	// 버튼 2에 이미지를 설정합니다.
	CButton* pButton2 = (CButton*)GetDlgItem(IDC_BUTTON2);
	pButton2->SetBitmap(hBitmap);

	// 버튼 7에 있는 이미지를 삭제합니다.
	pButton7->SetBitmap(nullptr);
	arr[0] = true;
	
	CString str;
	pButton7->GetWindowText(str);
	m_showScore.SetWindowText(str);
	//CString str;
	//GetDlgItemText(IDC_BUTTON7, str);
	//m_showScore.SetWindowText(str);

}


void CMFCApplication5Dlg::OnBnClickedButton8()
{
	// 버튼 7에서 이미지를 추출합니다.
	CButton* pButton8 = (CButton*)GetDlgItem(IDC_BUTTON8);
	HBITMAP hBitmap = (HBITMAP)pButton8->SendMessage(BM_GETIMAGE, IMAGE_BITMAP, 0);

	// 버튼 2에 이미지를 설정합니다.
	CButton* pButton3 = (CButton*)GetDlgItem(IDC_BUTTON3);
	pButton3->SetBitmap(hBitmap);

	// 버튼 7에 있는 이미지를 삭제합니다.
	pButton8->SetBitmap(nullptr);
	arr[1] = true;

	CString str;
	pButton8->GetWindowText(str);
	m_showScore.SetWindowText(str);
	//CString str;
	//GetDlgItemText(IDC_BUTTON7, str);
	//m_showScore.SetWindowText(str);
}


void CMFCApplication5Dlg::OnBnClickedButton9()
{
	// 버튼 7에서 이미지를 추출합니다.
	CButton* pButton9 = (CButton*)GetDlgItem(IDC_BUTTON9);
	HBITMAP hBitmap = (HBITMAP)pButton9->SendMessage(BM_GETIMAGE, IMAGE_BITMAP, 0);

	// 버튼 2에 이미지를 설정합니다.
	CButton* pButton4 = (CButton*)GetDlgItem(IDC_BUTTON4);
	pButton4->SetBitmap(hBitmap);

	// 버튼 7에 있는 이미지를 삭제합니다.
	pButton9->SetBitmap(nullptr);
	arr[2] = true;

	CString str;
	pButton9->GetWindowText(str);
	m_showScore.SetWindowText(str);
	//CString str;
	//GetDlgItemText(IDC_BUTTON7, str);
	//m_showScore.SetWindowText(str);
}


void CMFCApplication5Dlg::OnBnClickedButton10()
{
	// 버튼 7에서 이미지를 추출합니다.
	CButton* pButton10 = (CButton*)GetDlgItem(IDC_BUTTON10);
	HBITMAP hBitmap = (HBITMAP)pButton10->SendMessage(BM_GETIMAGE, IMAGE_BITMAP, 0);

	// 버튼 2에 이미지를 설정합니다.
	CButton* pButton5 = (CButton*)GetDlgItem(IDC_BUTTON5);
	pButton5->SetBitmap(hBitmap);

	// 버튼 7에 있는 이미지를 삭제합니다.
	pButton10->SetBitmap(nullptr);
	arr[3] = true;

	CString str;
	pButton10->GetWindowText(str);
	m_showScore.SetWindowText(str);
	//CString str;
	//GetDlgItemText(IDC_BUTTON7, str);
	//m_showScore.SetWindowText(str);}
}

void CMFCApplication5Dlg::OnBnClickedButton11()
{
	// 버튼 7에서 이미지를 추출합니다.
	CButton* pButton11 = (CButton*)GetDlgItem(IDC_BUTTON11);
	HBITMAP hBitmap = (HBITMAP)pButton11->SendMessage(BM_GETIMAGE, IMAGE_BITMAP, 0);

	// 버튼 2에 이미지를 설정합니다.
	CButton* pButton6 = (CButton*)GetDlgItem(IDC_BUTTON6);
	pButton6->SetBitmap(hBitmap);

	// 버튼 7에 있는 이미지를 삭제합니다.
	pButton11->SetBitmap(nullptr);
	arr[4] = true;

	CString str;
	pButton11->GetWindowText(str);
	m_showScore.SetWindowText(str);
	//CString str;
	//GetDlgItemText(IDC_BUTTON7, str);
	//m_showScore.SetWindowText(str);}
}