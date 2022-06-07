#pragma once
#include "Board.h"
class Block
{
	int blockNum; //�� ��ȣ ����

	const static int blocks[][5][5]; //�� ���� ���̺�
	int height; //����
	int width; //�ʺ�
	int posX; //�� x��ǥ
	int posY; //�� y��ǥ
	Board* pBoard; //���� ������ �ּ� ����(���Ӻ����� ���� �����ϱ� ���Ͽ�)
public:
	int m_block[5][5]; //���õ� �� ����
	Block(void){ //����Ʈ ������
		pBoard = NULL;
		height = 0;
		width = 0;
		posX  = 0;
		posY  = 0;
	}
	~Block(void){}

	Block(int n, Board* p){ //n�� �� ����, ���� �ּ� ����

		height = 5; //����
		width = 5; //�ʺ�
		//���� ����� ��ġ 
		posX  = 0; 
		posY  = 0;
		//n�� ������ �� ����
		setBlock(n);
		//���� ���� ����
		setBoard(p);
	}
	//���� ��ȯ
	int getHeight(){return this->height;}
	//�ʺ� ��ȯ
	int getWidth(){return this->width;}
	//�� ��ȣ ��ȯ
	int getBlockNum(){
		return blockNum;
	}
	//n�� ������ ����
	void setBlock(int n){
		height = 5;
		width = 5;
		this->blockNum = n +2 ; //�� ��ȣ ����
		//�� ��ȣ�� �´� ���� ������
		for(int y = 0 ; y < height ; y++){ 
			for(int x = 0 ; x < width ; x++){
				if(blocks[n][y][x])
					m_block[y][x] = this->blockNum;
				else
					m_block[y][x] = 0;
			}
		}
	}
	//���� ���� �ּ� ����
	void setBoard(Board* p){
		this->pBoard = p;
	}
	//���� ����� �� ��ġ ����
	void setPosition(int x, int y)
	{
		this->posX = x;
		this->posY = y;
	}
	//���� ���忡 ���� ��ġ��Ŵ
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
	//���� ���忡 ���� ��ġ�� �� �ִ��� �Ǻ�
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
	//���� �Ʒ��� ����
	bool moveDown(){
		this->place(false);
		//�Ʒ��� ���� �� �ִ��� �Ǻ�
		bool r = this->isPlaceable(this->posX, this->posY+1);
		if(r) this->posY += 1;
		this->place(true);
		return r;
	}
	//�¿� ������
	bool moveHorizontal(bool dir){

		int diff = dir? -1 : 1;
		this->place(false);
		//�¿�� ������ �� �ִ��� �Ǻ�
		bool r = this->isPlaceable(this->posX+diff, this->posY);
		if(r) this->posX += diff;
		this->place(true);
		return r;
	}
	//ȸ��
	bool rotate(bool direction) 
	{
		bool res = true;

		this->place(false);		
		int oldBlock[5][5];
		//���� ���� �����صΰ�
		arrCopy(oldBlock, this->m_block);
		//ȸ�� ��Ŵ
		this->getFieldRotate(2,2,direction);
		//ȸ���Ѱ��� ��ġ �� �� �ִ��� �Ǻ�
		if (this->isPlaceable(this->posX,this->posY)) ;
		else if (this->isPlaceable(this->posX+1,this->posY)) this->posX+=1;
		else if (this->isPlaceable(this->posX-1,this->posY)) this->posX-=1;
		else if (this->isPlaceable(this->posX+2,this->posY)) this->posX+=2;
		else if (this->isPlaceable(this->posX-2,this->posY)) this->posX-=2;
		else {
			//��ġ �Ҽ� ������ ȸ�� �Ƚ�Ŵ
			arrCopy( this->m_block, oldBlock);
			res = true;
		}
		this->place(true);

		return res;
	}
	//�迭 ���� �Լ�
	void arrCopy(int dst[][5],int rsc[][5]){
		for(int y = 0 ; y < 5; y ++)	
			for(int x = 0 ; x < 5; x++)
				dst[y][x] = rsc[y][x];
	}
	//�� ȸ�� �Լ�
	void getFieldRotate(int cx, int cy, bool direction)
	{
		//ȸ���� ���� ������ �迭
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
		//�迭 ����(ȸ���� ��)
		arrCopy( this->m_block, newBlock);
	}	

};

