#pragma once
#include "Board.h"
class Block
{
	int blockNum; //블럭 번호 저장

	const static int blocks[][5][5]; //블럭 종류 테이블
	int height; //높이
	int width; //너비
	int posX; //블럭 x좌표
	int posY; //블럭 y좌표
	Board* pBoard; //게임 보드의 주소 저장(게임보드의 값을 변경하기 위하여)
public:
	int m_block[5][5]; //선택된 블럭 저장
	Block(void){ //디폴트 생성자
		pBoard = NULL;
		height = 0;
		width = 0;
		posX  = 0;
		posY  = 0;
	}
	~Block(void){}

	Block(int n, Board* p){ //n번 블럭 생성, 보드 주소 저장

		height = 5; //높이
		width = 5; //너비
		//게임 보드상 위치 
		posX  = 0; 
		posY  = 0;
		//n번 블럭으로 블럭 셋팅
		setBlock(n);
		//게임 보드 저장
		setBoard(p);
	}
	//높이 반환
	int getHeight(){return this->height;}
	//너비 반환
	int getWidth(){return this->width;}
	//블럭 번호 반환
	int getBlockNum(){
		return blockNum;
	}
	//n번 블럭으로 셋팅
	void setBlock(int n){
		height = 5;
		width = 5;
		this->blockNum = n +2 ; //블럭 번호 저장
		//블럭 번호에 맞는 블럭을 저장함
		for(int y = 0 ; y < height ; y++){ 
			for(int x = 0 ; x < width ; x++){
				if(blocks[n][y][x])
					m_block[y][x] = this->blockNum;
				else
					m_block[y][x] = 0;
			}
		}
	}
	//게임 보드 주소 저장
	void setBoard(Board* p){
		this->pBoard = p;
	}
	//게임 보드상 블럭 위치 변경
	void setPosition(int x, int y)
	{
		this->posX = x;
		this->posY = y;
	}
	//게임 보드에 블럭을 위치시킴
	void place(bool p){
		int bx;
		int by;
		if(pBoard == NULL) return;
		for(int y = 0 ; y < height ; y++){
			for(int x = 0 ; x < width ; x++){
				if(m_block[y][x]){ 
					bx = posX + x;
					by = posY + y + abs((posX%2)*(x%2));
					if( by >= 0 )
						pBoard->field[by][bx] = p? blockNum : 0;
				}
			}
		}
	}
	//게임 보드에 블럭이 위치할 수 있는지 판별
	bool isPlaceable(int nx,int ny){
		int bx;
		int by;
		if(pBoard == NULL) return false;
		for(int y = 0 ; y < height ; y++){
			for(int x = 0 ; x < width ; x++){
				if(m_block[y][x]){
					bx = nx + x;
					by = ny + y + abs((nx%2)*(x%2));
					if( by >= 0 && pBoard->field[by][bx] != 0) return false;
				}
			}
		}
		return true;
	} 
	//블럭을 아래로 내림
	bool moveDown(){
		this->place(false);
		//아래로 내릴 수 있는지 판별
		bool r = this->isPlaceable(this->posX, this->posY+1);
		if(r) this->posY += 1;
		this->place(true);
		return r;
	}
	//좌우 움직임
	bool moveHorizontal(bool dir){

		int diff = dir? -1 : 1;
		this->place(false);
		//좌우로 움직일 수 있는지 판별
		bool r = this->isPlaceable(this->posX+diff, this->posY);
		if(r) this->posX += diff;
		this->place(true);
		return r;
	}
	//회전
	bool rotate(bool direction) 
	{
		bool res = true;

		this->place(false);		
		int oldBlock[5][5];
		//기존 블럭을 복사해두고
		arrCopy(oldBlock, this->m_block);
		//회전 시킴
		this->getFieldRotate(2,2,direction);
		//회전한것이 위치 할 수 있는지 판별
		if (this->isPlaceable(this->posX,this->posY)) ;
		else if (this->isPlaceable(this->posX+1,this->posY)) this->posX+=1;
		else if (this->isPlaceable(this->posX-1,this->posY)) this->posX-=1;
		else if (this->isPlaceable(this->posX+2,this->posY)) this->posX+=2;
		else if (this->isPlaceable(this->posX-2,this->posY)) this->posX-=2;
		else {
			//위치 할수 없으면 회전 안시킴
			arrCopy( this->m_block, oldBlock);
			res = true;
		}
		this->place(true);

		return res;
	}
	//배열 복사 함수
	void arrCopy(int dst[][5],int rsc[][5]){
		for(int y = 0 ; y < 5; y ++)	
			for(int x = 0 ; x < 5; x++)
				dst[y][x] = rsc[y][x];
	}
	//블럭 회전 함수
	void getFieldRotate(int cx, int cy, bool direction)
	{
		//회전한 블럭을 저장할 배열
		int newBlock[5][5] = {0};

		for (int y = 0; y < this->height ;y++) {
			for (int x = 0; x < this->width ; x++) {
				if (this->m_block[y][x]!=0) {
					//compute path
					int path[] = {0,0,0};
					int dx = x - cx;
					int dy = y - cy;
					path[0]+= dy;
					path[1]+= dx/2;
					path[2]+= dx/2;
					if (dx%2>0) path[1]+=1;
					if (dx%2<0) path[2]-=1;

					//rotate path	
					int newPath[3] = {0};
					if (direction){
						newPath[0] =-path[2];
						newPath[1] = path[0];
						newPath[2] = path[1];
					}else{
						newPath[0] =path[1];
						newPath[1] =path[2];
						newPath[2] =-path[0];				
					}


					int newx = cx;
					int newy = cy;
					//path[0]
					newy+=newPath[0];
					//path[1]
					if (newx%2==1 && newPath[1]%2==1) newy+=1;
					if (newx%2==0 && newPath[1]%2==-1) newy-=1;
					newx+=newPath[1];
					newy+=newPath[1]/2;
					//path[2]
					if (newx%2==0 && newPath[2]%2==1) newy-=1;
					if (newx%2==1 && newPath[2]%2==-1) newy+=1;
					newx+=newPath[2];
					newy-=newPath[2]/2;


					if ((newx< this->width) && (newx>=0) && (newy< this->height) && (newy>=0)) newBlock[newy][newx]=m_block[y][x];
				}
			}
		}
		//배열 복사(회전된 블럭)
		arrCopy( this->m_block, newBlock);
	}	

};

