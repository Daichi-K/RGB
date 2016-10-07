#pragma once
#include "miserable.h"
#include "common.h"

//定数宣言
const double BLOCK_WIDTH = 4;
const double BLOCK_THICKNESS = 1;
const double MAX_ANGLE = PI / 10;	//入力される最大の板の角度
const int VERTEX_LENGTH = 256;

enum COLORPOS{
	COLOR_X,
	COLOR_Y,
};

enum TYPE {
	BALLCOLOR, NORMAL, PURPLE, GREEN,
	BLUE, WHITE, BORDER, NORMAL2,
};

//変数宣言

//プロトタイプ宣言
void boardInit( );
void boardUpdate( );
void boardDraw( );
bool boardGet( int x, int y );
TYPE getMapData( int x, int y );
void setMapData( int x, int y, TYPE type );
int getColorPos( int type, COLORPOS colorPos );
Vector boardGetBlock( int x, int y, int z );