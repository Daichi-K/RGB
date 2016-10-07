#pragma once
#include "miserable.h"
#include "common.h"

//�萔�錾
const double BLOCK_WIDTH = 4;
const double BLOCK_THICKNESS = 1;
const double MAX_ANGLE = PI / 10;	//���͂����ő�̔̊p�x
const int VERTEX_LENGTH = 256;

enum COLORPOS{
	COLOR_X,
	COLOR_Y,
};

enum TYPE {
	BALLCOLOR, NORMAL, PURPLE, GREEN,
	BLUE, WHITE, BORDER, NORMAL2,
};

//�ϐ��錾

//�v���g�^�C�v�錾
void boardInit( );
void boardUpdate( );
void boardDraw( );
bool boardGet( int x, int y );
TYPE getMapData( int x, int y );
void setMapData( int x, int y, TYPE type );
int getColorPos( int type, COLORPOS colorPos );
Vector boardGetBlock( int x, int y, int z );