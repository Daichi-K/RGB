#include "ui.h"
#include "board.h"

static int stage = 1;
static int startTimer = 0;

void uiInit( ) {
	startTimer = 0;
}

void uiDraw( ) {

	if ( startTimer < COUNTDOWN_FPS * 3 ) {
		drawString( 622, 120, "%d", 3 - startTimer / COUNTDOWN_FPS );
	}
}

int getStage( ) {
	return stage;
}

void setStage( int num ) {
	stage = num;
}

bool countdown( ) {
	startTimer++;

	if ( startTimer >= COUNTDOWN_FPS * 3 ){
		return true;
	}
	return false;
}

void backgroundDraw( ) {
	//drawTexture( 0, 0, 0, 512, 1024, 512 ); 
	POLYGON::VERTEX vertex[ 4 ];

	vertex[ 0 ].pos = Vector( -50, 20, 80 );
	vertex[ 0 ].tex = Vector( 0, VERTEX_LENGTH * 2 );
	vertex[ 1 ].pos = Vector( 50, 20, 80 );
	vertex[ 1 ].tex = Vector( VERTEX_LENGTH * 4, VERTEX_LENGTH * 2 );
	vertex[ 2 ].pos = Vector( -50, -40, 25 );
	vertex[ 2 ].tex = Vector( 0, VERTEX_LENGTH * 4 );
	vertex[ 3 ].pos = Vector( 50, -40, 25 );
	vertex[ 3 ].tex = Vector( VERTEX_LENGTH * 4, VERTEX_LENGTH * 4 );

	POLYGON polygon;

	polygon.vertex[ 0 ] = vertex[ 0 ];
	polygon.vertex[ 1 ] = vertex[ 1 ];
	polygon.vertex[ 2 ] = vertex[ 3 ];
	drawPolygon( polygon );

	polygon.vertex[ 0 ] = vertex[ 3 ];
	polygon.vertex[ 1 ] = vertex[ 2 ];
	polygon.vertex[ 2 ] = vertex[ 0 ];
	drawPolygon( polygon );
}
