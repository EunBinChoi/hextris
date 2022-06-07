
// ChildView.cpp : CChildView Ŭ������ ����
//

#include "stdafx.h"
#include "Tetris.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//�� ����ǥ
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

	//�������� �׸��� ���� Ŭ����
	class heaxgon{
	public :
		CPoint pts[6]; 
		CPoint base;
		heaxgon(){
			base = CPoint(0,0);
		}
		void calPoints(CPoint m){ //�ش� ���� �������� 6���� ��ġ �ڵ� ���
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
		srand((unsigned int)time(NULL)); //���� �� ������ �õ尪 ����
		//���� ��, ���� �� �ʱ�ȭ
		this->nextBlock =NULL; 
		this->currentBlock = NULL;

		//���� �ʱ�ȭ
		score = 0;
		//���� ���� ���� �ʱ�ȭ
		isGameOver =false;
		//���� ���� ���� �ʱ�ȭ
		pauseGame = false;
		//�⺻ ���� ����
		board_h = 15;
		//�⺻ ���� �ʺ�
		board_w = 9;

		//���� ���� ����(�⺻ 0)
		currentLevel = 0;

		//������ �� ���� �ӵ� ����
		levels[0] = 1200;
		levels[1] = 1000;
		levels[2] = 800;
		levels[3] = 600;
	}

	CChildView::~CChildView()
	{
		//�� �޸� ����
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



	// CChildView �޽��� ó����

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
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		CPoint base = CPoint(50,50); //���Ӻ��带 �׸� ���� ��ġ
		CPoint base2 = CPoint(450,50); //���� �� �� ������ ǥ���� ���� ��ġ
		CPoint t;
		heaxgon hex; //�������� �׸��� ���� ��ü
		
		base2.x = gameBoard.width*40; //���� �� �� ������ ǥ���� ��ġ�� ���� ���� ����� ���� �������� ����
		
		CString score_str; // ���� ��¿� ���ڿ�

		dc.Rectangle(base2.x,20,base2.x+130, 200); //���� �� ǥ�ø� ���� �簢�� 
		dc.TextOutW(base2.x,20,_T("Next Block")); //���� �� ���� ǥ��	
		score_str.Format(_T("Score : %d"),this->score); //���� ǥ�ø� ���� ���ڿ� ����
		dc.TextOutW(base2.x,250,score_str); //���� ǥ��
		if(this->pauseGame){ //������ ���� ���¸� ���� ���ڿ� ǥ��
			dc.TextOutW(base2.x,350,_T("Pause!!"));	
		}
		// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.

		//������ �⺻ ����
		int r = 22;
		int w = r/2;
		int h = 19;
		int i,j;

		CPen pen1;
		pen1.CreatePen( PS_SOLID, 1, RGB(0,0,0) );    // ���� ���� ����
	
		CPen* oldPen;
		CBrush* oldBrush ;

		//���� ���带 ȭ�鿡 �׸������� �ݺ���
		for(i = 0 ; i < gameBoard.height ; i ++){
			for(j = 0 ; j < gameBoard.width ; j++) 
			{
				//���� �ִٸ�,
				if(gameBoard.field[i][j] != 0) {
					CBrush brush1;
					oldPen = dc.SelectObject( &pen1);	
					//�� ���� ���� �귯�� �� ����
					brush1.CreateSolidBrush(colors[gameBoard.field[i][j]]);   				
					oldBrush = dc.SelectObject( &brush1 );

					//�� ��ġ ���
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
					//������ ����
					dc.Polygon(hex.pts,6);
				}	
			}
		}
		//���� ���� �ִٸ�,
		if(nextBlock){
			//���� ���� �����ʿ� ǥ�� ���ֱ� ���� �ݺ���
			for(i = 0 ; i < nextBlock->getHeight() ; i ++){
				for(j = 0 ; j < nextBlock->getWidth() ; j++) 
				{
					//���� �ֵ���,
					if(nextBlock->m_block[i][j] != 0) {
						CBrush brush1;
						//�� �������� �귯�� ������
						brush1.CreateSolidBrush(colors[nextBlock->m_block[i][j]]); 		
						oldBrush = dc.SelectObject( &brush1 );//�귯�� ����
						//�� ��ġ ���
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
						//������ ����
						dc.Polygon(hex.pts,6);
					}	
				}
			}
		}
		//���� �� �� �귯���� ����
		dc.SelectObject( oldPen   );     // �ý��� �� ��ü�� ������
		dc.SelectObject( oldBrush );    // �ý��� �귯�� ��ü�� ������
		// �׸��� �޽����� ���ؼ��� CWnd::OnPaint()�� ȣ������ ���ʽÿ�.
	}
	//���� �� ���� �Լ�
	void CChildView::createNextBlock(){
		//���� ���� �ִٸ�
		if(currentBlock!=NULL){
			//�޸� ����
			delete currentBlock;
			//NULL�� �ʱ�ȭ
			currentBlock= NULL;
		}
		//���� �귰 �ִٸ�,
		if(nextBlock != NULL)
		{
			//���� ���� ���� ������ ��ü
			currentBlock = nextBlock;

			//���� �� ����
			nextBlock = new Block(rand()%16,&this->gameBoard);
		}else{ 
			//���� ���� ���� ���
			//���� ���� ���� �� ��� ����
			currentBlock = new Block(rand()%16,&this->gameBoard);
			nextBlock = new Block(rand()%16,&this->gameBoard);
		}
		//���� ���� ���� �߾� ��ġ�� ����
		this->currentBlock->setPosition(gameBoard.width/2-2 ,-2);	
		//��ġ�� �� �ִ��� �Ǻ�(��ġ �� �� ���ٸ� ���� ����)
		if(this->currentBlock->isPlaceable(gameBoard.width/2-2,-2)){
			//���� ���� ���
			nextBlock->place(false);
			//�����ϴٸ� ��ġ ��Ŵ
			this->currentBlock->place(true);
		}else{
			this->gameOver();
		}
	}
	//���� ���� ó�� �Լ�
	void CChildView::gameOver(){
		CStdioFile f;
		CString score_tmp;
		int arr[10]={0};
		CString tmp_str;
		//Ÿ�̸� ����
		this->KillTimer(1);

		//���� ���� ����
		if(f.Open(_T("score.txt"),CFile::typeText|CFile::modeReadWrite)){
			int i = 0;
			int m;
			int pos = -1 ;
			//�������Ͽ��� ������ �о�ͼ� �迭�� ���� 
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
			//���� ������ 10�� ���̶�� �ش� ��ġ�� ����(���� ���� �ڷ� �и�)
			if(pos != -1){
				for(i = 9; i>pos ; i--){
					arr[i] = arr[i-1];
				}
				arr[pos] = this->score;
			}
			//���ŵ� ���� �ٽ� ���Ͽ� ����
			f.SeekToBegin();
			for(i = 0; i<10 ; i++){
				tmp_str.Format(_T("%d\t%d\n"),i+1,arr[i]);
				f.WriteString(tmp_str);
			}
			//���� �ݱ�
			f.Close();
		}else{
			this->MessageBox(_T("���� ������ �� �� �����ϴ�."));
		}

		CString st;
		//���� ���� ���θ� ������ ����
		isGameOver = true;
		//���� ���� �ִٸ� �޸� ����
		if(currentBlock){
			delete currentBlock;
			currentBlock = NULL;
		}
		//���� ���� �ִٸ� �޸� ����
		if(nextBlock){
			delete nextBlock;
			nextBlock = NULL;
		}
		//���� ���� �ȳ� �� ���� �˾� �޼��� 
		st.Format(_T("Game Over!!!!\nScore : %d"),this->score);
		this->MessageBox(st);
	}
	//���� �߰� �Լ�
	void CChildView::addScore(int n){
		//������ ����� ���°� �ƴ϶�� ���� �߰�
		if(!isGameOver)
		this->score += n;
	}
	//��Ƽ���� ���� ���� ��� �Լ�
	int CChildView::scoreLines(int n){
		//��Ƽ���� ���ż��� ���� ����ġ ���� ��ȯ
		switch(n){
		case 1: return 100;
		case 2: return 300;
		case 3: return 1000;
		case 4: return 2000;
		}
		return 0;
	}
	//���ο� ���� ���� ó�� �Լ�
	void CChildView::newGame(){
		//���� ���� ���� 
		gameBoard.setGameBoard(board_w,board_h);		
		//�� ����
		gameBoard.drawGameBoard();
		//���� ����
		currentLevel = 0;
		//���� �ʱ�ȭ
		score = 0;

		//���� ����, ���� ���� ���� ����
		isGameOver =false;
		pauseGame = false;

		//�� ����
		if(currentBlock){
			delete currentBlock;
			currentBlock =NULL;
		}
		if(nextBlock){
			delete nextBlock;
			nextBlock =NULL;
		}
		//Ÿ�̸ӽ���
		this->SetTimer(1,levels[currentLevel],0);
		//���ο� �� ����
		createNextBlock();

	}
	//���� �Ʒ��� �����ִ� �Լ�
	bool CChildView::moveDown(){
		//���� �� �ִٸ� ���� �� ȭ�� ����
		if(this->currentBlock->moveDown()){
			this->Invalidate();
			return true;
		}else{ //���� �� ���ٸ�
			this->addScore(10); //�⺻ �� ���� �߰�
			this->addScore(scoreLines(this->gameBoard.removeFullLines())); //�������Ű� �����ϴٸ� ����� �����߰�
			createNextBlock(); //���� �� ����
			this->Invalidate(); //ȭ�� ����
			return false;
		}
	}
	void CChildView::OnTimer(UINT_PTR nIDEvent)
	{
		// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
		if(nIDEvent == 1){
			this->moveDown(); //Ÿ�̸� �ֱ⿡ ���� ���� �Ʒ��� ����
		}
		CWnd::OnTimer(nIDEvent);
	}


	int CChildView::OnCreate(LPCREATESTRUCT lpCreateStruct)
	{
		if (CWnd::OnCreate(lpCreateStruct) == -1)
			return -1;
		//���� ũ�� ����
		setBoardSize(this->board_w, this->board_h);

		// TODO:  ���⿡ Ư��ȭ�� �ۼ� �ڵ带 �߰��մϴ�.

		return 0;
	}
	//Ű���� �Է� ó�� �Լ�
	void CChildView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
	{
		
		// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
		//������ �������� ���¶��,
		if(!isGameOver && !pauseGame){
			if(nChar == 'd' ||nChar == 'D' ||nChar == VK_RIGHT){ //������ �̵�
				this->currentBlock->moveHorizontal(false);
				this->Invalidate();
			}else if(nChar == 'a' || nChar == 'A' ||nChar == VK_LEFT){ //���� �̵�
				this->currentBlock->moveHorizontal(true);
				this->Invalidate();
			}else if(nChar == 's' || nChar == 'S'||nChar == VK_DOWN){ //�Ʒ��� �̵�
				this->moveDown();	
				this->Invalidate();
			}else if(nChar == VK_SPACE){ //�Ʒ� ������ �̵�
				bool canMove  = this->moveDown();
				while(canMove && !isGameOver){
					canMove  = this->moveDown();
				}		
				this->Invalidate();
			}
			else if(nChar == 'w' || nChar == 'W' ||nChar == VK_UP){ //ȸ��(�ð����)
				this->currentBlock->rotate(false);
				this->Invalidate();
			}

		}
		//���ο� ���� ����
		if(nChar == 'n' || nChar == 'N' ){
			this->newGame();
			this->Invalidate();
		}
		//���� ����
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

	//ctrl + c ����Ű�� �޾Ƶ��̱� ���� �Լ�
	BOOL CChildView::PreTranslateMessage(MSG* pMsg)
	{
		bool bControlKey = (0x8000 == (0x8000 & GetKeyState(VK_CONTROL)));
		
		//ctrl + cŰ�� ���ȴٸ�,
		if(bControlKey && (pMsg->wParam == 'c' || pMsg->wParam == 'C')){
			//���� ���� Ȯ��
			 if(this->MessageBoxW(_T("�����Ͻðڽ��ϱ�?"),NULL,MB_YESNO) == IDYES){
				 GetParent()->SendMessage(WM_CLOSE);
			 }

		}
		
		return CWnd::PreTranslateMessage(pMsg);
	}



	//�޴� game - New �̺�Ʈ �ڵ鷯
	void CChildView::OnGameNew()
	{
		this->KillTimer(1); //Ÿ�̸� ����
		this->newGame();  //���ο� ���� ����
		this->Invalidate(); //ȭ�鰻��
		// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	}
	//���� ���� �Լ�
	void CChildView::setBoardSize(int w, int h){
		this->board_w = w+2;
		this->board_h = h;	
		CPoint base = CPoint(100,100);
		CPoint size;
		size.x = base.x + board_w*40 + 150;
		size.y = base.y + board_h*40 ;
		//���� ũ�⿡ ���� ȭ�� ũ�� ����
		this->GetParentFrame()->SetWindowPos(&CWnd::wndTop, base.x, base.y,size.x ,size.y ,SWP_DRAWFRAME);
		//���ο� ���� ����
		this->newGame();
		//ȭ�� ����
		this->Invalidate();
	}
	//�޴� ũ�� ���� �Լ���
	void CChildView::OnSize7x13()
	{
		// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
			setBoardSize(7,13);
	}
	void CChildView::OnSize7x15()
	{
		// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
		setBoardSize(7,15);
	}
	void CChildView::OnSize9x15()
	{
		// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
			setBoardSize(9,15);
	}
	void CChildView::OnSize9x17()
	{
		// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
		setBoardSize(9,17);
	}
	void CChildView::OnSize11x17()
	{
		// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
			setBoardSize(11,17);
	}
	void CChildView::OnSize11x19()
	{
		// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
		setBoardSize(15,19);
	}
	//�޴� ���� ���� �Լ���
	void CChildView::OnLevelEasy()
	{
		// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.

		this->newGame(); //���ο� ���� ����
		this->KillTimer(1); //Ÿ�̸� ���� 
		currentLevel = 0; //���� ����
		this->SetTimer(1,levels[currentLevel],0); //������ ���� �� ���� �ֱ� ����
		this->Invalidate(); //ȭ�� ����
	}
	void CChildView::OnLevelMedium()
	{
		// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
		this->newGame();
		this->KillTimer(1);
		currentLevel = 1;
		this->SetTimer(1,levels[currentLevel],0);
		this->Invalidate();
	}
	void CChildView::OnLevelHard()
	{
		// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.

		this->newGame();
		this->KillTimer(1);
		currentLevel = 2;
		this->SetTimer(1,levels[currentLevel],0);
		this->Invalidate();
	}
	void CChildView::OnLevelExtremelyhard()
	{
		// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
		this->newGame();
		this->KillTimer(1);
		currentLevel = 3;
		this->SetTimer(1,levels[currentLevel],0);
		this->Invalidate();
	}


