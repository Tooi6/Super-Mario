#include "yzkgame.h"
#include <windows.h>
#include "engine.h"

#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" )
#pragma comment(lib, "YZKGame.lib")



void gameMain(void)
{ 
	
	setGameTitle("超级玛丽");
	setGameSize(626, 586);
	playSound("begin.mp3",0);
	playbegin();
	playdyg();       //第一关
	playdeg();       //第二关
	playdsg();       //第三关
	playgameover();  //游戏结束
	pauseGame(10000);

}

int main(void)
{
	rpInit(gameMain);

	return 0;
}
