#pragma once
#include "miserable.h"

//�萔�錾
const int SPHERE_RESOLUTION = 30;
const double SPHERE_RADIUS = 1;
const double REBOUND = 0.3;		//�e���W��
const double MAX_JUMP = 1.5;	//JUMP
const Vector GRAVITY = Vector( 0, -0.3, 0 );  //�d��


//�\����
struct BALL {
	Vector pos = Vector( 0, 10, 0 );
	Vector accel = GRAVITY;
	Vector spd;
};

//�v���g�^�C�v�錾
void ballDraw( );
void ballInit( );
void ballUpdate( );
void setFalling( int i );
void setBall( Vector pos, Vector spd, Vector accel );
BALL getBall( );
