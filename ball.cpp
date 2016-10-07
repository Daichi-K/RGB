#include "ball.h"
#include "common.h"
#include "board.h"

// ファイルスコープ内変数
static Vector SPHERE[ SPHERE_RESOLUTION ][ SPHERE_RESOLUTION ];
static BALL ball;
static Vector normalForce;
static int falling = 0;

TYPE a;

BALL getBall( ) {
	return ball;
}

void setBall( Vector pos, Vector spd, Vector accel ) {
	ball.pos = pos;
	ball.spd = spd;
	ball.accel = accel;
}

//球の初期設定
void ballInit( ) {
	for ( int i = 0; i < SPHERE_RESOLUTION; i++ ) {
		for ( int j = 0; j < SPHERE_RESOLUTION; j++ ) { 
			SPHERE[ i ][ j ] = Vector( SPHERE_RADIUS * sin( PI / ( SPHERE_RESOLUTION - 1 ) * i ) * cos( 2 * PI / ( SPHERE_RESOLUTION - 1 ) * j ),
										SPHERE_RADIUS * cos( PI / ( SPHERE_RESOLUTION - 1 ) * i ),
										SPHERE_RADIUS * sin( PI / ( SPHERE_RESOLUTION - 1 ) * i ) * sin( 2 * PI / ( SPHERE_RESOLUTION - 1 ) * j ) );
		}
	}

	ball.pos = Vector( 0, 10, 0 );
	ball.spd = Vector( 0, 0, 0 );
	ball.accel = Vector( 0, 0, 0 );	
}


//球の描画
void ballDraw( ) {
	for ( int i = 0; i < SPHERE_RESOLUTION - 1; i++ ) {
		for ( int j = 0; j < SPHERE_RESOLUTION - 1; j++ ) {
			drawPlane(
				SPHERE[ i ][ j ] + ball.pos,
				SPHERE[ i + 1 ][ j ] + ball.pos,
				SPHERE[ i ][ j + 1 ] + ball.pos,
				SPHERE[ i + 1 ][ j + 1 ] + ball.pos, BALLCOLOR );
		}
	}
}

//球の衝突判定と重力
void ballUpdate( ) {

	ball.spd += ball.accel;
	ball.pos += ball.spd;
		
	Vector v1 = boardGetBlock( 4, 4, 7 ) - boardGetBlock( 4, 4, 4 );
	Vector v2 = boardGetBlock( 4, 4, 7 ) - boardGetBlock( 4, 4, 6 );
	Vector boardDirection = v1.cross( v2 ).normalize( );

	normalForce = boardDirection * GRAVITY.dot( boardDirection );
	ball.accel = GRAVITY;

	int ground = 0;
	double rx = 10 * cos( getAngle( AXIS_X ) );
	double rz = 10 * cos( getAngle( AXIS_Y ) );
	if ( falling == 0 && ball.pos.dot( boardDirection ) - SPHERE_RADIUS <= 0 && 
		abs( ball.pos.x ) < abs( rx ) && 
		abs( ball.pos.z ) < abs( rz ) ) {

		// 床の上
		ball.spd *= 0.8;
		ball.accel += boardDirection * ball.accel.dot( boardDirection * -1 );
		ground = 1;
		while( ball.pos.dot( boardDirection ) - SPHERE_RADIUS < 0 ) {
			ball.pos += Vector( 0.01 * sin( getAngle( AXIS_X ) ), 
								0.01 * ( cos( getAngle( AXIS_X ) ) + cos( getAngle( AXIS_Y ) ) ), 
								0.01 * sin( -getAngle( AXIS_Y ) ) );
		}

		int mx = ( int )( ( ball.pos.x + rx ) / ( 4 * rx / 10 ) );
		int mz = ( int )( ( ball.pos.z - rz ) / ( 4 * -rz / 10 ) );
		TYPE type = getMapData( mx, mz );
		if ( type == BALLCOLOR ) {
			// 穴の上
			falling = 1;
		}
	}

	//球のジャンプ
	if ( getRightPushButton( ) == 1 && ground == 1 ) {
		ball.spd = boardDirection * MAX_JUMP;
	}
}

void setFalling( int i ) {
	falling = i;
}