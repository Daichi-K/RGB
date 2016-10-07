#include "board.h"
#include "common.h"

// �t�@�C���X�R�[�v���ϐ�
static Matrix matX;
static Matrix matZ;
static Vector block[ 5 ][ 5 ][ 8 ];
static Vector FIRST_POINT = Vector( -BLOCK_WIDTH / 2 * 5, -BLOCK_THICKNESS, BLOCK_WIDTH / 2 * 5 );

Vector boardGetBlock( int x, int y, int z ) {
	return block[ x ][ y ][ z ];
}

bool boardGet( int x, int y ) {
	if ( getMapData( x, y ) == BALLCOLOR) {
		return false;
	} else {
		return true;
	}
}

//�X�V
void boardUpdate( ) {
	//�L�[����
	double ax = getAngle( AXIS_X );
	double az = getAngle( AXIS_Y ); 

	//�p�x�̕ϐ�
	matX = turn( AXIS_Z, ax );
	matZ = turn( AXIS_X, az );
}

//�̏����ݒ�
void boardInit( ) {
	for( int i = 0; i < 5; i++ ) {
		for( int j = 0; j < 5; j++ ) {
			setMapData( i, j, NORMAL );
		}
	}
}

void drawPlane( Vector p1, Vector p2, Vector p3, Vector p4, int Color ) {
	POLYGON::VERTEX vertex[ 4 ];

	vertex[ 0 ].pos = p1;
	vertex[ 0 ].tex = Vector( getColorPos( Color, COLORPOS::COLOR_X ) * VERTEX_LENGTH,
								getColorPos( Color, COLORPOS::COLOR_Y ) * VERTEX_LENGTH );
	vertex[ 1 ].pos = p2;
	vertex[ 1 ].tex = Vector( ( getColorPos( Color, COLORPOS::COLOR_X ) + 1 ) * VERTEX_LENGTH, 
								getColorPos( Color, COLORPOS::COLOR_Y ) * VERTEX_LENGTH );
	vertex[ 2 ].pos = p3;
	vertex[ 2 ].tex = Vector( getColorPos( Color, COLORPOS::COLOR_X ) * VERTEX_LENGTH,
								( getColorPos( Color, COLORPOS::COLOR_Y ) + 1 ) * VERTEX_LENGTH );
	vertex[ 3 ].pos = p4;
	vertex[ 3 ].tex = Vector( ( getColorPos( Color, COLORPOS::COLOR_X ) + 1 ) * VERTEX_LENGTH, 
								( getColorPos( Color, COLORPOS::COLOR_Y ) + 1 ) * VERTEX_LENGTH );

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

//�̕`��
void boardDraw( ) {
	//�̌X��
	for ( int i = 0; i < 5; i++ ) {
		for ( int j = 0; j < 5; j++ ) {
			block[ i ][ j ][ 0 ] = matZ.multiply( matX.multiply( Vector( FIRST_POINT.x + ( i * BLOCK_WIDTH ),
									FIRST_POINT.y, 
									FIRST_POINT.z + ( j * -BLOCK_WIDTH ) ) ) );
			block[ i ][ j ][ 1 ] = matZ.multiply( matX.multiply( Vector( FIRST_POINT.x + ( i * BLOCK_WIDTH ), 
									FIRST_POINT.y, 
									FIRST_POINT.z + ( ( j + 1 ) * -BLOCK_WIDTH ) ) ) );
			block[ i ][ j ][ 2 ] = matZ.multiply( matX.multiply( Vector( FIRST_POINT.x + ( i * BLOCK_WIDTH ), 
									FIRST_POINT.y + BLOCK_THICKNESS, 
									FIRST_POINT.z + ( j * -BLOCK_WIDTH ) ) ) );
			block[ i ][ j ][ 3 ] = matZ.multiply( matX.multiply( Vector( FIRST_POINT.x + ( ( i + 1 ) * BLOCK_WIDTH ), 
									FIRST_POINT.y, 
									FIRST_POINT.z + ( j * -BLOCK_WIDTH ) ) ) );
			block[ i ][ j ][ 4 ] = matZ.multiply( matX.multiply( Vector( FIRST_POINT.x + ( i * BLOCK_WIDTH ), 
									FIRST_POINT.y + BLOCK_THICKNESS, 
									FIRST_POINT.z + ( ( j + 1 ) * -BLOCK_WIDTH ) ) ) );
			block[ i ][ j ][ 5 ] = matZ.multiply( matX.multiply( Vector( FIRST_POINT.x + ( ( i + 1 ) * BLOCK_WIDTH ), 
									FIRST_POINT.y, 
									FIRST_POINT.z + ( ( j + 1 ) * -BLOCK_WIDTH ) ) ) );
			block[ i ][ j ][ 6 ] = matZ.multiply( matX.multiply( Vector( FIRST_POINT.x + ( ( i + 1 ) * BLOCK_WIDTH ), 
									FIRST_POINT.y + BLOCK_THICKNESS, 
									FIRST_POINT.z + ( j * -BLOCK_WIDTH ) ) ) );
			block[ i ][ j ][ 7 ] = matZ.multiply( matX.multiply( Vector( FIRST_POINT.x + ( ( i + 1 ) * BLOCK_WIDTH ), 
									FIRST_POINT.y + BLOCK_THICKNESS, 
									FIRST_POINT.z + ( ( j + 1 ) * -BLOCK_WIDTH ) ) ) );
		}
	}

	for ( int i = 0; i < 5; i++ ) {
		for ( int j = 0; j < 5; j++ ) {
			if ( getMapData( i , j ) > 0 ) {
				drawPlane( block[ i ][ j ][ 0 ], block[ i ][ j ][ 3 ], block[ i ][ j ][ 2 ], block[ i ][ j ][ 6 ], TYPE::BORDER );
				drawPlane( block[ i ][ j ][ 7 ], block[ i ][ j ][ 5 ], block[ i ][ j ][ 4 ], block[ i ][ j ][ 1 ], TYPE::BORDER );
				drawPlane( block[ i ][ j ][ 0 ], block[ i ][ j ][ 1 ], block[ i ][ j ][ 3 ], block[ i ][ j ][ 5 ], TYPE::BORDER );
				drawPlane( block[ i ][ j ][ 7 ], block[ i ][ j ][ 4 ], block[ i ][ j ][ 6 ], block[ i ][ j ][ 2 ], getMapData( i , j ) );
				drawPlane( block[ i ][ j ][ 0 ], block[ i ][ j ][ 2 ], block[ i ][ j ][ 1 ], block[ i ][ j ][ 4 ], TYPE::BORDER );
				drawPlane( block[ i ][ j ][ 7 ], block[ i ][ j ][ 6 ], block[ i ][ j ][ 5 ], block[ i ][ j ][ 3 ], TYPE::BORDER );
			}
		}
	}
}