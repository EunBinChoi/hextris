
// ChildView.cpp : CChildView 클래스의 구현
//

#include "stdafx.h"
#include "Tetris.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//블럭 색상표
const COLORREF CChildView::colors[] ={
	RGB(0,0,0),
	RGB(189,189,189),
	RGB(200,0,100),
	RGB(100,200,0),
	RGB(0,100,200),
	RGB(100,100,100),
	RGB(240,0,0),
	RGB(0,240,0),
	RGB(0,0,240),
	RGB(130,0,0),
	RGB(0,130,0),
	RGB(0,0,130),
	RGB(240,240,0),
	RGB(240,0,240),
	RGB(0,240,240),
	RGB(200,100,0),
	RGB(0,200,100),
	RGB(100,0,200)};

	//육각형을 그리기 위한 클래스
	class heaxgon{
	public :
		CPoint pts[6]; 
		CPoint base;
		heaxgon(){
			base = CPoint(0,0);
		}
		void calPoints(CPoint m){ //해당 점을 기준으로 6각형 위치 자동 계산
			int r = 22;
			int w = r/2;
			int h = 19;
			base = m;
			pts[0].x = base.x - w;
			pts[0].y = base.y - h;
			pts[1].x = base.x + w;
			pts[1].y = base.y - h;
			pts[2].x = base.x + r;
			pts[2].y = base.y ;
			pts[3].x = base.x + w;
			pts[3].y = base.y + h;	
			pts[4].x = base.x - w;
			pts[4].y = base.y + h;	
			pts[5].x = base.x - r;
			pts[5].y = base.y ;	
		}
		~heaxgon(){

		}
	};
	// CChildView

	CChildView::CChildView()
	{
		srand((unsigned int)time(NULL)); //랜덤 블럭 생성용 시드값 설정
		//현재 블럭, 다음 블럭 초기화
		this->nextBlock =NULL; 
		this->currentBlock = NULL;

		//점수 초기화
		score = 0;
		//게임 종료 여부 초기화
		isGameOver =false;
		//게임 중지 여부 초기화
		pauseGame = false;
		//기본 보드 높이
		board_h = 15;
		//기본 보드 너비
		board_w = 9;

		//현재 레벨 설정(기본 0)
		currentLevel = 0;

		//레벨별 블럭 생성 속도 저장
		levels[0] = 1200;
		levels[1] = 1000;
		levels[2] = 800;
		levels[3] = 600;
	}

	CChildView::~CChildView()
	{
		//블럭 메모리 해제
		if(currentBlock) delete currentBlock;
		if(nextBlock) delete nextBlock;
	}


	BEGIN_MESSAGE_MAP(CChildView, CWnd)
		ON_WM_PAINT()
		ON_WM_TIMER()
		ON_WM_CREATE()
		ON_WM_KEYDOWN()

		ON_COMMAND(ID_GAME_NEW, &CChildView::OnGameNew)
		ON_COMMAND(ID_SIZE_7X13, &CChildView::OnSize7x13)
		ON_COMMAND(ID_SIZE_7X15, &CChildView::OnSize7x15)
		ON_COMMAND(ID_SIZE_9X15, &CChildView::OnSize9x15)
		ON_COMMAND(ID_SIZE_9X17, &CChildView::OnSize9x17)
		ON_COMMAND(ID_SIZE_11X17, &CChildView::OnSize11x17)
		ON_COMMAND(ID_SIZE_11X19, &CChildView::OnSize11x19)
		ON_COMMAND(ID_LEVEL_EASY, &CChildView::OnLevelEasy)
		ON_COMMAND(ID_LEVEL_MEDIUM, &CChildView::OnLevelMedium)
		ON_COMMAND(ID_LEVEL_HARD, &CChildView::OnLevelHard)
		ON_COMMAND(ID_LEVEL_EXTREMELYHARD, &CChildView::OnLevelExtremelyhard)
		//		ON_WM_CHAR()
//		ON_UPDATE_COMMAND_UI(ID_GAME_HIGHSCORE, &CChildView::OnUpdateGameHighscore)
	END_MESSAGE_MAP()



	// CChildView 메시지 처리기

	BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
	{
		if (!CWnd::PreCreateWindow(cs))
			return FALSE;

		cs.dwExStyle |= WS_EX_CLIENTEDGE;
		cs.style &= ~WS_BORDER;
		cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
			::LoadCursor(NULL, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), NULL);



		return TRUE;
	}

	void CChildView::OnPaint() 
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		CPoint base = CPoint(50,50); //게임보드를 그릴 기준 위치
		CPoint base2 = CPoint(450,50); //다음 블럭 및 점수를 표현할 기준 위치
		CPoint t;
		heaxgon hex; //육각형을 그리기 위한 객체
		
		base2.x = gameBoard.width*40; //다음 블럭 및 점수를 표현할 위치의 값을 보드 사이즈에 따라 동적으로 설정
		
		CString score_str; // 점수 출력용 문자열

		dc.Rectangle(base2.x,20,base2.x+130, 200); //다음 블럭 표시를 위한 사각형 
		dc.TextOutW(base2.x,20,_T("Next Block")); //다음 블럭 글자 표시	
		score_str.Format(_T("Score : %d"),this->score); //점수 표시를 위한 문자열 생성
		dc.TextOutW(base2.x,250,score_str); //점수 표시
		if(this->pauseGame){ //게임이 중지 상태면 중지 문자열 표시
			dc.TextOutW(base2.x,350,_T("Pause!!"));	
		}
		// TODO: 여기에 메시지 처리기 코드를 추가합니다.

		//육각형 기본 정보
		int r = 22;
		int w = r/2;
		int h = 19;
		int i,j;

		CPen pen1;
		pen1.CreatePen( PS_SOLID, 1, RGB(0,0,0) );    // 검정 펜을 생성
	
		CPen* oldPen;
		CBrush* oldBrush ;

		//게임 보드를 화면에 그리기위한 반복문
		for(i = 0 ; i < gameBoard.height ; i ++){
			for(j = 0 ; j < gameBoard.width ; j++) 
			{
				//블럭이 있다면,
				if(gameBoard.field[i][j] != 0) {
					CBrush brush1;
					oldPen = dc.SelectObject( &pen1);	
					//블럭 색에 따라 브러쉬 색 생성
					brush1.CreateSolidBrush(colors[gameBoard.field[i][j]]);   				
					oldBrush = dc.SelectObject( &brush1 );

					//블럭 위치 계산
					t = base;
					t.x+= (j * r)+ (j * w) ;
					t.y+= i * h *2;
					if(j%2 == 0){
						t.y-=h;
						hex.calPoints(t);					
					}
					else{					
						hex.calPoints(t);
					}
					//육각형 생성
					dc.Polygon(hex.pts,6);
				}	
			}
		}
		//다음 블럭이 있다면,
		if(nextBlock){
			//다음 블럭을 오른쪽에 표시 해주기 위한 반복문
			for(i = 0 ; i < nextBlock->getHeight() ; i ++){
				for(j = 0 ; j < nextBlock->getWidth() ; j++) 
				{
					//블럭이 있따면,
					if(nextBlock->m_block[i][j] != 0) {
						CBrush brush1;
						//블럭 색에따라 브러쉬 색설정
						brush1.CreateSolidBrush(colors[nextBlock->m_block[i][j]]); 		
						oldBrush = dc.SelectObject( &brush1 );//브러쉬 적용
						//블럭 위치 계산
						t = base2;
						t.x+= (j * r)+ (j * w) ;
						t.y+= i * h *2;
						if(j%2 == 0){
							t.y-=h;
							hex.calPoints(t);					
						}
						else{					
							hex.calPoints(t);
						}
						//육각형 생성
						dc.Polygon(hex.pts,6);
					}	
				}
			}
		}
		//원래 펜 및 브러쉬로 복구
		dc.SelectObject( oldPen   );     // 시스템 펜 객체를 돌려줌
		dc.SelectObject( oldBrush );    // 시스템 브러시 객체를 돌려줌
		// 그리기 메시지에 대해서는 CWnd::OnPaint()를 호출하지 마십시오.
	}
	//다음 블럭 생성 함수
	void CChildView::createNextBlock(){
		//현재 블럭이 있다면
		if(currentBlock!=NULL){
			//메모리 해제
			delete currentBlock;
			//NULL로 초기화
			currentBlock= NULL;
		}
		//다음 브럭 있다면,
		if(nextBlock != NULL)
		{
			//현재 블럭을 다음 블럭으로 대체
			currentBlock = nextBlock;

			//다음 블럭 생성
			nextBlock = new Block(rand()%16,&this->gameBoard);
		}else{ 
			//다음 블럭이 없는 경우
			//현재 블럭과 다음 블럭 모두 생성
			currentBlock = new Block(rand()%16,&this->gameBoard);
			nextBlock = new Block(rand()%16,&this->gameBoard);
		}
		//현재 블럭을 보드 중앙 위치로 생성
		this->currentBlock->setPosition(gameBoard.width/2-2 ,-2);	
		//위치할 수 있는지 판별(위치 할 수 없다면 게임 종료)
		if(this->currentBlock->isPlaceable(gameBoard.width/2-2,-2)){
			//다음 블럭은 대기
			nextBlock->place(false);
			//가능하다면 위치 시킴
			this->currentBlock->place(true);
		}else{
			this->gameOver();
		}
	}
	//게임 종료 처리 함수
	void CChildView::gameOver(){
		CStdioFile f;
		CString score_tmp;
		int arr[10]={0};
		CString tmp_str;
		//타이머 종료
		this->KillTimer(1);

		//점수 파일 오픈
		if(f.Open(_T("score.txt"),CFile::typeText|CFile::modeReadWrite)){
			int i = 0;
			int m;
			int pos = -1 ;
			//점수파일에서 점수를 읽어와서 배열에 저장 
			while(f.ReadString(score_tmp) && i<10){
				CString resToken;
				int cur = 0;
				resToken = score_tmp.Tokenize(_T("\t"),cur);
				while (resToken != "")
				{ 						
					resToken= score_tmp.Tokenize(_T("\t"),cur); 
					m = _ttoi(resToken);					
					break;
				}
				arr[i] = m;
				if(pos==-1 && arr[i] <= this->score) {					
					pos = i;
				}
				i++;
			}		
			//현재 점수가 10위 안이라면 해당 위치로 복사(기존 값은 뒤로 밀림)
			if(pos != -1){
				for(i = 9; i>pos ; i--){
					arr[i] = arr[i-1];
				}
				arr[pos] = this->score;
			}
			//갱신된 값을 다시 파일에 저장
			f.SeekToBegin();
			for(i = 0; i<10 ; i++){
				tmp_str.Format(_T("%d\t%d\n"),i+1,arr[i]);
				f.WriteString(tmp_str);
			}
			//파일 닫기
			f.Close();
		}else{
			this->MessageBox(_T("점수 파일을 열 수 없습니다."));
		}

		CString st;
		//게임 종료 여부를 참으로 설정
		isGameOver = true;
		//현재 블럭이 있다면 메모리 해제
		if(currentBlock){
			delete currentBlock;
			currentBlock = NULL;
		}
		//다음 블럭이 있다면 메모리 해제
		if(nextBlock){
			delete nextBlock;
			nextBlock = NULL;
		}
		//게임 종료 안내 및 점수 팝업 메세지 
		st.Format(_T("Game Over!!!!\nScore : %d"),this->score);
		this->MessageBox(st);
	}
	//점수 추가 함수
	void CChildView::addScore(int n){
		//게임이 종료된 상태가 아니라면 점수 추가
		if(!isGameOver)
		this->score += n;
	}
	//멀티라인 제거 점수 계산 함수
	int CChildView::scoreLines(int n){
		//멀티라인 제거수에 따라 가중치 점수 반환
		switch(n){
		case 1: return 100;
		case 2: return 300;
		case 3: return 1000;
		case 4: return 2000;
		}
		return 0;
	}
	//새로운 게임 시작 처리 함수
	void CChildView::newGame(){
		//게임 보드 생성 
		gameBoard.setGameBoard(board_w,board_h);		
		//벽 생성
		gameBoard.drawGameBoard();
		//레벨 설정
		currentLevel = 0;
		//점수 초기화
		score = 0;

		//게임 종료, 중지 변수 거짓 설정
		isGameOver =false;
		pauseGame = false;

		//블럭 제거
		if(currentBlock){
			delete currentBlock;
			currentBlock =NULL;
		}
		if(nextBlock){
			delete nextBlock;
			nextBlock =NULL;
		}
		//타이머시작
		this->SetTimer(1,levels[currentLevel],0);
		//새로운 블럭 생성
		createNextBlock();

	}
	//블럭을 아래로 내려주는 함수
	bool CChildView::moveDown(){
		//내릴 수 있다면 내린 후 화면 갱신
		if(this->currentBlock->moveDown()){
			this->Invalidate();
			return true;
		}else{ //내릴 수 없다면
			this->addScore(10); //기본 블럭 점수 추가
			this->addScore(scoreLines(this->gameBoard.removeFullLines())); //라인제거가 가능하다면 계산후 점수추가
			createNextBlock(); //다음 블럭 생성
			this->Invalidate(); //화면 갱신
			return false;
		}
	}
	void CChildView::OnTimer(UINT_PTR nIDEvent)
	{
		// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
		if(nIDEvent == 1){
			this->moveDown(); //타이머 주기에 따라 블럭을 아래로 내림
		}
		CWnd::OnTimer(nIDEvent);
	}


	int CChildView::OnCreate(LPCREATESTRUCT lpCreateStruct)
	{
		if (CWnd::OnCreate(lpCreateStruct) == -1)
			return -1;
		//보드 크기 설정
		setBoardSize(this->board_w, this->board_h);

		// TODO:  여기에 특수화된 작성 코드를 추가합니다.

		return 0;
	}
	//키보드 입력 처리 함수
	void CChildView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
	{
		
		// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
		//게임이 정상진행 상태라면,
		if(!isGameOver && !pauseGame){
			if(nChar == 'd' ||nChar == 'D' ||nChar == VK_RIGHT){ //오른쪽 이동
				this->currentBlock->moveHorizontal(false);
				this->Invalidate();
			}else if(nChar == 'a' || nChar == 'A' ||nChar == VK_LEFT){ //왼쪽 이동
				this->currentBlock->moveHorizontal(true);
				this->Invalidate();
			}else if(nChar == 's' || nChar == 'S'||nChar == VK_DOWN){ //아래로 이동
				this->moveDown();	
				this->Invalidate();
			}else if(nChar == VK_SPACE){ //아래 끝까지 이동
				bool canMove  = this->moveDown();
				while(canMove && !isGameOver){
					canMove  = this->moveDown();
				}		
				this->Invalidate();
			}
			else if(nChar == 'w' || nChar == 'W' ||nChar == VK_UP){ //회전(시계방향)
				this->currentBlock->rotate(false);
				this->Invalidate();
			}

		}
		//새로운 게임 시작
		if(nChar == 'n' || nChar == 'N' ){
			this->newGame();
			this->Invalidate();
		}
		//게임 중지
		if(nChar == 'p' || nChar == 'P' ){
			if(pauseGame){ pauseGame = false;
			this->SetTimer(1,levels[currentLevel],0);
			}
			else{
				this->KillTimer(1);
				pauseGame = true;				
			}
			this->Invalidate();
		}
		CWnd::OnKeyDown(nChar, nRepCnt, nFlags);
	}

	//ctrl + c 단축키를 받아들이기 위한 함수
	BOOL CChildView::PreTranslateMessage(MSG* pMsg)
	{
		bool bControlKey = (0x8000 == (0x8000 & GetKeyState(VK_CONTROL)));
		
		//ctrl + c키가 눌렸다면,
		if(bControlKey && (pMsg->wParam == 'c' || pMsg->wParam == 'C')){
			//종료 여부 확인
			 if(this->MessageBoxW(_T("종료하시겠습니까?"),NULL,MB_YESNO) == IDYES){
				 GetParent()->SendMessage(WM_CLOSE);
			 }

		}
		
		return CWnd::PreTranslateMessage(pMsg);
	}



	//메뉴 game - New 이벤트 핸들러
	void CChildView::OnGameNew()
	{
		this->KillTimer(1); //타이머 제거
		this->newGame();  //새로운 게임 시작
		this->Invalidate(); //화면갱신
		// TODO: 여기에 명령 처리기 코드를 추가합니다.
	}
	//보드 생성 함수
	void CChildView::setBoardSize(int w, int h){
		this->board_w = w+2;
		this->board_h = h;	
		CPoint base = CPoint(100,100);
		CPoint size;
		size.x = base.x + board_w*40 + 150;
		size.y = base.y + board_h*40 ;
		//보드 크기에 따라 화면 크기 설정
		this->GetParentFrame()->SetWindowPos(&CWnd::wndTop, base.x, base.y,size.x ,size.y ,SWP_DRAWFRAME);
		//새로운 게임 시작
		this->newGame();
		//화면 갱신
		this->Invalidate();
	}
	//메뉴 크기 변경 함수들
	void CChildView::OnSize7x13()
	{
		// TODO: 여기에 명령 처리기 코드를 추가합니다.
			setBoardSize(7,13);
	}
	void CChildView::OnSize7x15()
	{
		// TODO: 여기에 명령 처리기 코드를 추가합니다.
		setBoardSize(7,15);
	}
	void CChildView::OnSize9x15()
	{
		// TODO: 여기에 명령 처리기 코드를 추가합니다.
			setBoardSize(9,15);
	}
	void CChildView::OnSize9x17()
	{
		// TODO: 여기에 명령 처리기 코드를 추가합니다.
		setBoardSize(9,17);
	}
	void CChildView::OnSize11x17()
	{
		// TODO: 여기에 명령 처리기 코드를 추가합니다.
			setBoardSize(11,17);
	}
	void CChildView::OnSize11x19()
	{
		// TODO: 여기에 명령 처리기 코드를 추가합니다.
		setBoardSize(15,19);
	}
	//메뉴 레벨 변경 함수들
	void CChildView::OnLevelEasy()
	{
		// TODO: 여기에 명령 처리기 코드를 추가합니다.

		this->newGame(); //새로운 게임 설정
		this->KillTimer(1); //타이머 제거 
		currentLevel = 0; //레벨 설정
		this->SetTimer(1,levels[currentLevel],0); //레벨에 따른 블럭 생성 주기 설정
		this->Invalidate(); //화면 갱신
	}
	void CChildView::OnLevelMedium()
	{
		// TODO: 여기에 명령 처리기 코드를 추가합니다.
		this->newGame();
		this->KillTimer(1);
		currentLevel = 1;
		this->SetTimer(1,levels[currentLevel],0);
		this->Invalidate();
	}
	void CChildView::OnLevelHard()
	{
		// TODO: 여기에 명령 처리기 코드를 추가합니다.

		this->newGame();
		this->KillTimer(1);
		currentLevel = 2;
		this->SetTimer(1,levels[currentLevel],0);
		this->Invalidate();
	}
	void CChildView::OnLevelExtremelyhard()
	{
		// TODO: 여기에 명령 처리기 코드를 추가합니다.
		this->newGame();
		this->KillTimer(1);
		currentLevel = 3;
		this->SetTimer(1,levels[currentLevel],0);
		this->Invalidate();
	}


