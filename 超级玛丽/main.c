#include "yzkgame.h"
#include <windows.h>
#include "engine.h"

#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" )
#pragma comment(lib, "YZKGame.lib")



void gameMain(void)
{ 
	
	setGameTitle("��������");
	setGameSize(626, 586);
	playSound("begin.mp3",0);
	playbegin();
	playdyg();       //��һ��
	playdeg();       //�ڶ���
	playdsg();       //������
	playgameover();  //��Ϸ����
	pauseGame(10000);

}

int main(void)
{
	rpInit(gameMain);

	return 0;
}
