#include "result.h"
#include "ui.h"
#include "ball.h"
#include "pattern.h"

static int clearTimer = 0;
static int loseTimer = 0;

void resultInit( int i ) {
	ballInit( );
	boardInit( );
	uiInit( );
	patternInit( );
	setStage( i );
	setFalling( 0 );
	clearTimer = 0;
	loseTimer = 0;
}

void resultUpdate( ) {
	if ( !loseCheck( ) && patternUpdate( ) ) {
		clearTimer++;
	}
}

bool winInitCheck( ) {
	if ( clearTimer >= RESULT_TIME + RESULT_DRAW_TIME && getBall( ).pos.y >= LOSE_JUDGE_HEIGHT ) {
		resultInit( 2 );
		success( );
		return true;
	}
	return false;
}

bool winCheck( ) {
	if( clearTimer >= RESULT_TIME ) {
		return true;
	} else {
		return false;
	}
}

void resultDraw( ) {
	if( clearTimer >= RESULT_TIME && getBall( ).pos.y >= LOSE_JUDGE_HEIGHT ) {
		drawString( 550, 120, "CLEAR!" );
	} else if ( getBall( ).pos.y < LOSE_JUDGE_HEIGHT ) {
		drawString( 580, 120, "FAIL" );
	}
}

bool loseInitCheck( ) {
	if ( loseCheck( ) ) {
		resultInit( 2 );
		return true;
	}
	return false;
}

bool loseCheck( ) {
	if ( getBall( ).pos.y < LOSE_JUDGE_HEIGHT ) {
		loseTimer++;
		if ( loseTimer >= RESULT_TIME)
			return true;
	} 
	return false;
}