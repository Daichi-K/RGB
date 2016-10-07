#include "ball.h"
#include "board.h"
#include "common.h"

//変数宣言
double angle = 0;

int color[ 16 ][ 2 ] = { { 0, 0 }, { 1, 0 }, { 2, 0 }, { 3, 0 },
						 { 0, 1 }, { 1, 1 }, { 2, 1 }, { 3, 1 },
						 { 0, 2 }, { 1, 2 }, { 2, 2 }, { 3, 2 }, 
						 { 0, 3 }, { 1, 3 }, { 2, 3 }, { 3, 3 } };

//0から１5まで(　0 = 見えない, 1 = 白, 2以降 = パターン　)
TYPE mapData[ 5 ][ 5 ] = {
	{ NORMAL, NORMAL, NORMAL, NORMAL, NORMAL },
	{ NORMAL, NORMAL, NORMAL, NORMAL, NORMAL },
	{ NORMAL, NORMAL, NORMAL, NORMAL, NORMAL },
	{ NORMAL, NORMAL, NORMAL, NORMAL, NORMAL },
	{ NORMAL, NORMAL, NORMAL, NORMAL, NORMAL },
};

//列挙体宣言
Vector axisList[ AXIS::AXIS_MAX ] {
	Vector( 1, 0, 0 ),
	Vector( 0, 1, 0 ),
	Vector( 0, 0, 1 ),
};

TYPE getMapData( int x, int y ) {
	return mapData[ y ][ x ];
}

void setMapData( int x, int y, TYPE type ) {
	mapData[ y ][ x ] = type;
}

Matrix turn( AXIS axis, double angle ){
	Matrix mat = Matrix::makeTransformRotation( axisList[ axis ], angle );
	return mat;
}

int getColorPos( int type, COLORPOS colorPos ) {
	return color[ type ][ colorPos ];
}

double getAngle( AXIS axis ) {
	switch( axis ) {
	case AXIS_X:
		angle = getLeftAnalogStick( ).x * ( MAX_ANGLE );
		break;
	case AXIS_Y:
		angle = getLeftAnalogStick( ).y * ( MAX_ANGLE );
		break;
	}
	return angle;
}