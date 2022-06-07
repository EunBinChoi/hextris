// HighScore.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Tetris.h"
#include "HighScore.h"
#include "afxdialogex.h"


// CHighScore 대화 상자입니다.

IMPLEMENT_DYNAMIC(CHighScore, CDialogEx)

CHighScore::CHighScore(CWnd* pParent /*=NULL*/)
	: CDialogEx(CHighScore::IDD, pParent)
{

}

CHighScore::~CHighScore()
{
}

void CHighScore::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CHighScore, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CHighScore 메시지 처리기입니다.


void CHighScore::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	// 그리기 메시지에 대해서는 CDialogEx::OnPaint()을(를) 호출하지 마십시오.
	//폰트 설정
	CFont fnt;
	LOGFONT lf;
	::ZeroMemory(&lf, sizeof(lf));
	lf.lfHeight = 18;
	lf.lfWeight = FW_BOLD;
	::lstrcpy(lf.lfFaceName, (LPCWSTR)"Tahoma");
	fnt.CreateFontIndirect(&lf);
	GetDlgItem(IDC_STATIC)->SetFont(&fnt);
	fnt.Detach();
	
	CString str;	
	CStdioFile f;
	CString tmp_str;
	//점수 저장 파일 오픈
	if(f.Open(_T("score.txt"),CFile::typeText|CFile::modeRead)){
		//파일에서 값을 읽어와서 str에 임시 저장
		while(f.ReadString(tmp_str)){
			str+= tmp_str;
			str+="\n";
		}		
		f.Close();
	}else{
		this->MessageBox(_T("점수 파일을 열 수 없습니다."));
	}
	//파일에서 읽어온 점수 값을 다이얼로그의 스태틱 문자에 출력
	SetDlgItemText(IDC_STATIC,str);
}
