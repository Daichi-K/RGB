#pragma once
#include "miserable.h"

//定数宣言
const int SPHERE_RESOLUTION = 30;
const double SPHERE_RADIUS = 1;
const double REBOUND = 0.3;		//弾性係数
const double MAX_JUMP = 1.5;	//JUMP
const Vector GRAVITY = Vector( 0, -0.3, 0 );  //重力


//構造体
struct BALL {
	Vector pos = Vector( 0, 10, 0 );
	Vector accel = GRAVITY;
	Vector spd;
};

//プロトタイプ宣言
void ballDraw( );
void ballInit( );
void ballUpdate( );
void setFalling( int i );
void setBall( Vector pos, Vector spd, Vector accel );
BALL getBall( );
