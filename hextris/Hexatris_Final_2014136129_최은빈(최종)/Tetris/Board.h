#pragma once

//게임 보드 클랙스
class Board
{
	
public:
	int** field; //보드의 상태 저장 2차원 배열 동적할당을 위한 더블 포인터
	int width; //너비 저장
	int height; //높이 저장

	Board(void){
		field = NULL;
	}
	Board(int w, int h){
		field = NULL;
		setGameBoard(w,h);	//너비, 높이에 따른 게임 보드 생성
	}
	~Board(void){}

	//너비, 높이에 따른 게임 보드 생성 함수
	void setGameBoard(int w, int h){
		clearBoard(); //기존 보드 삭제
		this->width = w; //너비 갱신
		this->height = h; //높이 생긴
		field = new int*[h]; //높이 할당
		for(int i = 0 ; i < h ; i++) //너비 할당
			field[i] = new int[w];
	}
	//보드 삭제 함수
	void clearBoard(){
		if(field){ //기존에 보드가 있다면,
			//메모리 해제
			for(int i = 0 ; i < height ; i++)
				delete field[i];
			delete[] field;
		}
	}
	//게임 보드의 틀을 만들어 주는 함수
	void drawGameBoard(){
		int x,y;
		for(y = 0 ; y < height-1 ; y ++){
			this->field[y][0] = 1; //왼쪽 벽 생성
 			for(x = 1 ; x < width-1 ; x++) 
				this->field[y][x] = 0;	
			this->field[y][width-1] = 1; //오른쪽 벽 생성
		}
		//하단부 가로 바닥 생성
		for(x = 0 ; x < width ; x++) this->field[height-1][x] = 1;
	}

	//y번째 라인이 가득 찼는지 확인하는 함수
	bool lineFull(int y) 
	{
		//y번째 줄을 차례로 돌면서
		for (int x = 1; x < width-1; x++) {
			//0이면 가득찬 것이 아님
			if (field[y][x]==0) return false;
		}
		//for 문이 정상종료되면 가득찬 라인
		return true;		
	}
	//라인 삭제 함수
	void clearLine(int y)
	{
		//y번째 라인을 반복문을 돌면서 전부 0으로 만들어줌(벽 제외)
		for (int x = 1; x < width-1; x++) field[y][x]=0;
	}
	//srcY번째 라인을 destY 번째 라인에 복사
	void copyLine(int srcY,int destY) 
	{
		for (int x=1;x< width-1;x++) {
			field[destY][x]=field[srcY][x];
		} 
	}
	//라인 삭제
	void removeLine(int y) 
	{
		//라인 삭제하기 위해 윗라인들을 복사함 
		for (int cY=y;cY>0;cY--) {
			copyLine(cY-1,cY);
		}
		//제일 윗 라인을 0으로 초기화
		for (int x=1;x<width-1;x++) field[0][x]=0;		
	}

	//꽉 찬 줄을 삭제
	int removeFullLines()
	{
		int lines=0;
		//제일 아랫줄부터 반복
		for (int y = height - 2; y > 0; y--) {
			if (this->lineFull(y)) { //해당 줄이 꽉 찼으면
				this->clearLine(y);  //삭제
				this->removeLine(y); //삭제한줄 위줄들을 복사해서 넣음		 	
				lines++;  //삭제한 줄 카운트
				y++;
			}
		}
		return lines; //누적 줄 반환
	}
};

