#pragma once
#include "miserable.h"
#include "board.h"

//�萔�錾
const int PAINT_PATTERN_TIME = 60;
const int CLEAN_PATTERN_TIME = 110;
const int DESTROY_PATTERN_TIME = 130;
const int DIF_MAX = 9;

//�v���g�^�C�v�錾
void patternInit( );
bool patternUpdate( );
void patternDraw( );