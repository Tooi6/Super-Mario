#include "yzkgame.h"
#include <stdio.h>
#define begin_0 0
#define begin_1 1
#define dyg 2
#define mario 3
#define deg 4
#define fk_1  5
#define fk_2  6
#define fk_3  7
#define fk_4  8
#define dsg 9
#define gameover 10

int life = 3;

//第一关方块
void createfk()
{
	createSprite(fk_1, "fk_1");
	createSprite(fk_2, "fk_1");
	createSprite(fk_3, "fk_1");
	createSprite(fk_4, "fk_1");
	setSpritePosition(fk_1,247,196);
	playSpriteAnimate(fk_1,"nor");
	setSpritePosition(fk_2, 329, 196);
	playSpriteAnimate(fk_2,"nor");
	setSpritePosition(fk_3, 285, 357);
	playSpriteAnimate(fk_3,"nor");
	setSpritePosition(fk_4, 62, 196);
	playSpriteAnimate(fk_4,"nor");

}


//开始界面
void playbegin()
{
	int key;
	createImage(begin_0, "begin\\0.png");
	showImage(begin_0);
	while (1)
	{
		//playSound("begin.mp3",1);
		key=getPressedKeyCode();
		/*printf("%d",key);
		pauseGame(1000);*/
		if (key == 32)
		{
			closeSound("begin.mp3");
			playSound("bgm.mp3",0);
			createImage(begin_1,"begin\\1.png");
			showImage(begin_1);
			pauseGame(1000);
			break;
		}
	}
}

//第一关
void playdyg()
{
	int key;
	int x = 4, y = 75;     //初始位置
	createImage(dyg,"begin\\dyg.png");
	//createText();
	showImage(dyg);
	createSprite(mario,"mario");
	createfk();
	playSpriteAnimate(mario,"laugh");
	setSpritePosition(mario, x, y);
	setSpriteFlipX(mario, 1);
	//while (1)
	//{
	//	key=getPressedKeyCode();
	//	switch (key)
	//	{
	//	case 100:       //D
	//	x = x + 10;
	//	playSpriteAnimate(mario, "walk");
	//	setSpritePosition(mario, x, y);
	//	setSpriteFlipX(mario, 1);
	//	pauseGame(100);
	//	break;
	//	case 97:        //A
	//		x = x -10;
	//		playSpriteAnimate(mario, "walk");
	//		setSpritePosition(mario, x, y);
	//		setSpriteFlipX(mario, 0);
	//		pauseGame(100);
	//		break;
	//	
	//	case 119:      //W
	//		y+=60;
	//		playSpriteAnimate(mario,"jump");
	//		setSpritePosition(mario, x, y);
	//		setSpriteFlipX(mario, 1);
	//		pauseGame(500);
	//		y-=60;
	//		playSpriteAnimate(mario, "jump");
	//		setSpritePosition(mario, x, y);
	//		setSpriteFlipX(mario, 1);
	//		pauseGame(500);
	//		break;
	//	case 101:         //E斜跳
	//		x += 60;
	//		y += 60;
	//		playSpriteAnimate(mario, "jump");
	//		setSpritePosition(mario, x, y);
	//		setSpriteFlipX(mario, 1);
	//		pauseGame(500);
	//		//x += 60;
	//		y -= 60;
	//		playSpriteAnimate(mario, "jump");
	//		setSpritePosition(mario, x, y);
	//		setSpriteFlipX(mario, 1);
	//		pauseGame(500);
	//		break;
	//	case 113:         //Q斜跳
	//		x -= 60;
	//		y += 60;
	//		playSpriteAnimate(mario, "jump");
	//		setSpritePosition(mario, x, y);
	//		setSpriteFlipX(mario, 0);
	//		pauseGame(500);
	//		//x += 60;
	//		y -= 60;
	//		playSpriteAnimate(mario, "jump");
	//		setSpritePosition(mario, x, y);
	//		setSpriteFlipX(mario, 0);
	//		pauseGame(500);
	//		break;
	//	}
	//}
	while (1)
	{
		Sleep(1000);
		key = getPressedKeyCode();
		switch (key)
		{
		case 0:
			//站在方块上
			if (x >= 15 && x <= 84 && y == 237)  break;
			if (x >= 176 && x <= 406 && y == 232) break;
			if (x >= 254 && x <= 325 && y == 395)break; 
			if (x >= 496 && x <= 601 && y == 152)     //站在管子上
			{
				while (1)
				{
					key = getPressedKeyCode();
					if (key == 115)
					{
						clearGameUI();
						playSound("gotodeg.mp3",0);
						return;
					}
					else break;
				}
				break;
			}
			if (y > 75)     
			{
				y--;
				playSpriteAnimate(mario, "laugh");
				setSpritePosition(mario, x, y);
				pauseGame(10);
			}
			break;
		case 119:    //W
			playSound("jump.mp3", 0);
			//顶方块
			if (x >= 180 && x <= 406 && y >= 148&&y<=198)   break;
			if (x >= 44 && x <= 70 && y >= 146&&y<=182)   break;
			if (x >= 260 && x <= 311 && y >= 305 && y <= 335)break;
			y += 5;
			playSpriteAnimate(mario,"fly");
			setSpritePosition(mario,x,y);
			pauseGame(50);
			break;
		case 101:        //E斜跳
			playSound("jump.mp3", 0);
			if (x >= 180 && x <= 406 && y >= 148 && y <= 198)   break;
			if (x >= 44 && x <= 70 && y >= 146 && y <= 182)   break;
			if (x >= 260 && x <= 311 && y >= 305 && y <= 335)break;
			y += 5;
			x += 5;
			setSpriteFlipX(mario, 1);
			playSpriteAnimate(mario, "fly");
			setSpritePosition(mario, x, y);
			pauseGame(50);
			break;
		case 113:        //Q斜跳
			playSound("jump.mp3", 0);
			if (x >= 180 && x <= 406 && y >= 148 && y <= 198)   break;
			if (x >= 44 && x <= 70 && y >= 146 && y <= 182)   break;
			if (x >= 260 && x <= 311 && y >= 305 && y <= 335)break;
			y += 5;
			x -= 5;
			setSpriteFlipX(mario, 0);
			playSpriteAnimate(mario, "fly");
			setSpritePosition(mario, x, y);
			pauseGame(50);
			break;
		case 100:       //D
			//y += 5;
			x += 5;
			setSpriteFlipX(mario, 1);
			playSpriteAnimate(mario, "walk");
			setSpritePosition(mario, x, y);
			pauseGame(50);
			break;
		case 97:         //A
			//y += 5;
			x -= 5;
			setSpriteFlipX(mario, 0);
			playSpriteAnimate(mario, "walk");
			setSpritePosition(mario, x, y);
			pauseGame(50);
			break;
		}
    
	}
}

//第二关
void playdeg()
{
	int key;
	int x = 57, y = 500;
	int mario_x,mario_y;
	createSprite(mario,"mario");
	playSpriteAnimate(mario, "idle");
	setSpritePosition(mario, 55, 487);
	createImage(deg,"begin\\deg.png");
	showImage(deg);
	setSpritePosition(mario,x,y);
	while (1)
	{
		mario_x = getSpriteX;
		mario_y = getSpriteY;
		key = getPressedKeyCode();
		switch (key)
		{
		case 0:
			if (x >= 516 && x <= 609 && y == 75)     //进入第三关
			{
				while (1)
				{
					key = getPressedKeyCode();
					if (key == 100)
					{
						clearGameUI();
						playSound("gotodeg.mp3", 0);
						return;
					}
					else break;
				}
				break;
			}
			if (x >= 124 && x <= 435 && y == 196) break;
			if (x >= 485 && y == 154) break;
			if (x >= 123 && x <= 436 && y == 517) break;
			if (y > 75)
			{
				y--;
				playSpriteAnimate(mario, "laugh");
				setSpritePosition(mario, x, y);
				pauseGame(10);
			}
			break;
		case 119:    //W
			playSound("jump.mp3", 0);
			y += 5;
			playSpriteAnimate(mario, "fly");
			setSpritePosition(mario, x, y);
			pauseGame(50);
			break;
		case 101:        //E斜跳
			playSound("jump.mp3", 0);
			if (x > 569) break;
			if (x >= 124 && x <= 436 && y <= 195) break;
			y += 5;
			x += 5;
			setSpriteFlipX(mario, 1);
			playSpriteAnimate(mario, "fly");
			setSpritePosition(mario, x, y);
			pauseGame(50);
			break;
		case 113:        //Q斜跳
			playSound("jump.mp3", 0);
			if (x >= 128 && x <= 437 && y <= 195)  break;
			if (x <= 36 && y <= 516) break;
			y += 5;
			x -= 5;
			setSpriteFlipX(mario, 0);
			playSpriteAnimate(mario, "fly");
			setSpritePosition(mario, x, y);
			pauseGame(50);
			break;
		case 100:       //D
			//y += 5;
			if (x > 569) break;
			if (x >= 124 && x <= 436 && y<=195)  break;
		//	if (x <= 36 && y <= 516) break;
			x += 5;
			setSpriteFlipX(mario, 1);
			playSpriteAnimate(mario, "walk");
			setSpritePosition(mario, x, y);
			pauseGame(50);
			break;
		case 97:         //A
		  //y += 5;
			if (x >= 128&&x <= 437 && y <= 195)  break;
			if (x <= 36 && y <= 516) break;
			x -= 5;
			setSpriteFlipX(mario, 0);
			playSpriteAnimate(mario, "walk");
			setSpritePosition(mario, x, y);
			pauseGame(50);
			break;
		}
	}
}

//第三关
void playdsg()
{
	int key;
	int x, y;
	x = 77, y = 437;
	createSprite(mario,"mario");
	createImage(dsg,"begin\\dsg.png");
	playSpriteAnimate(mario,"happyrun");
	setSpriteFlipX(mario, 1);
	setSpritePosition(mario, x, y);
	while (1)
	{
		key = getPressedKeyCode();
		switch (key)
		{
		case 0:
			if (x >= 332 && x <= 370&&y <= 158) return;
			if (y > 75)
			{
				y--;
				setSpritePosition(mario, x, y);
				pauseGame(10);
			}
			break;
		case 119:    //W
			playSound("jump.mp3", 0);
			y += 5;
			playSpriteAnimate(mario, "fly");
			setSpritePosition(mario, x, y);
			pauseGame(50);
			break;
		case 101:        //E斜跳
			playSound("jump.mp3", 0);
			y += 5;
			x += 5;
			setSpriteFlipX(mario, 1);
			playSpriteAnimate(mario, "fly");
			setSpritePosition(mario, x, y);
			pauseGame(50);
			break;
		case 113:        //Q斜跳
			playSound("jump.mp3", 0);
			y += 5;
			x -= 5;
			setSpriteFlipX(mario, 0);
			playSpriteAnimate(mario, "fly");
			setSpritePosition(mario, x, y);
			pauseGame(50);
			break;
		case 100:       //D
						//y += 5;
			x += 5;
			setSpriteFlipX(mario, 1);
			playSpriteAnimate(mario, "walk");
			setSpritePosition(mario, x, y);
			pauseGame(50);
			break;
		case 97:         //A
						 //y += 5;
			x -= 5;
			setSpriteFlipX(mario, 0);
			playSpriteAnimate(mario, "walk");
			setSpritePosition(mario, x, y);
			pauseGame(50);
			break;
		}

	}

}

//游戏结束
void playgameover()
{
	clearGameUI();
	createImage(gameover,"begin\\gameover.png");
}