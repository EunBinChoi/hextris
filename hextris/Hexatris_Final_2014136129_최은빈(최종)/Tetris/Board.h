#pragma once

//���� ���� Ŭ����
class Board
{
	
public:
	int** field; //������ ���� ���� 2���� �迭 �����Ҵ��� ���� ���� ������
	int width; //�ʺ� ����
	int height; //���� ����

	Board(void){
		field = NULL;
	}
	Board(int w, int h){
		field = NULL;
		setGameBoard(w,h);	//�ʺ�, ���̿� ���� ���� ���� ����
	}
	~Board(void){}

	//�ʺ�, ���̿� ���� ���� ���� ���� �Լ�
	void setGameBoard(int w, int h){
		clearBoard(); //���� ���� ����
		this->width = w; //�ʺ� ����
		this->height = h; //���� ����
		field = new int*[h]; //���� �Ҵ�
		for(int i = 0 ; i < h ; i++) //�ʺ� �Ҵ�
			field[i] = new int[w];
	}
	//���� ���� �Լ�
	void clearBoard(){
		if(field){ //������ ���尡 �ִٸ�,
			//�޸� ����
			for(int i = 0 ; i < height ; i++)
				delete field[i];
			delete[] field;
		}
	}
	//���� ������ Ʋ�� ����� �ִ� �Լ�
	void drawGameBoard(){
		int x,y;
		for(y = 0 ; y < height-1 ; y ++){
			this->field[y][0] = 1; //���� �� ����
 			for(x = 1 ; x < width-1 ; x++) 
				this->field[y][x] = 0;	
			this->field[y][width-1] = 1; //������ �� ����
		}
		//�ϴܺ� ���� �ٴ� ����
		for(x = 0 ; x < width ; x++) this->field[height-1][x] = 1;
	}

	//y��° ������ ���� á���� Ȯ���ϴ� �Լ�
	bool lineFull(int y) 
	{
		//y��° ���� ���ʷ� ���鼭
		for (int x = 1; x < width-1; x++) {
			//0�̸� ������ ���� �ƴ�
			if (field[y][x]==0) return false;
		}
		//for ���� ��������Ǹ� ������ ����
		return true;		
	}
	//���� ���� �Լ�
	void clearLine(int y)
	{
		//y��° ������ �ݺ����� ���鼭 ���� 0���� �������(�� ����)
		for (int x = 1; x < width-1; x++) field[y][x]=0;
	}
	//srcY��° ������ destY ��° ���ο� ����
	void copyLine(int srcY,int destY) 
	{
		for (int x=1;x< width-1;x++) {
			field[destY][x]=field[srcY][x];
		} 
	}
	//���� ����
	void removeLine(int y) 
	{
		//���� �����ϱ� ���� �����ε��� ������ 
		for (int cY=y;cY>0;cY--) {
			copyLine(cY-1,cY);
		}
		//���� �� ������ 0���� �ʱ�ȭ
		for (int x=1;x<width-1;x++) field[0][x]=0;		
	}

	//�� �� ���� ����
	int removeFullLines()
	{
		int lines=0;
		//���� �Ʒ��ٺ��� �ݺ�
		for (int y = height - 2; y > 0; y--) {
			if (this->lineFull(y)) { //�ش� ���� �� á����
				this->clearLine(y);  //����
				this->removeLine(y); //�������� ���ٵ��� �����ؼ� ����		 	
				lines++;  //������ �� ī��Ʈ
				y++;
			}
		}
		return lines; //���� �� ��ȯ
	}
};

