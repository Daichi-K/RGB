#pragma once
#include "miserable.h"

const int COUNTDOWN_FPS = 60;

void uiDraw( );
void uiInit( );
int getStage( );
void setStage( int num );
bool countdown( );
void backgroundDraw( );
char * name( );
char * author( );
char * texture( );