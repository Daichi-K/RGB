#pragma once
#include "miserable.h"
#include "board.h"
#include "ball.h"

const int RESULT_TIME = 480;
const int RESULT_DRAW_TIME = 60;
const int LOSE_JUDGE_HEIGHT = -100;

//プロトタイプ宣言
void resultInit( int i );
void resultUpdate( );
void resultDraw( );
bool winInitCheck( );
bool loseInitCheck( );
bool loseCheck( );
bool winCheck( );