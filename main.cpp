#include "ball.h"
#include "board.h"
#include "common.h"
#include "result.h"
#include "pattern.h"
#include "ui.h"

PROPERTY( PERFORMANCE, TRUE );
GAME_BEGIN( RBG );

//メイン関数
void main ( ) {
	camera( Vector( 0, 20, -40 ), Vector( 0, 0, 0 ) );

	ballInit( );
	resultInit( 1 );

	while ( getStage( ) < 2 && !loseCheck( ) ) {
		// カウントダウン
		while ( !countdown( ) ) {
			boardUpdate( );
			backgroundDraw( );
			boardDraw( ); // 
			ballDraw( );
			uiDraw( );
			flip();
		}

		// プレイ
		while ( !winInitCheck( ) && !loseInitCheck( ) ) {
			if( !winCheck( ) ) {
				// 更新
				boardUpdate( ); // 傾きで計算
				ballUpdate( );
			}
			resultUpdate( );
			// 描画
			backgroundDraw( );
			boardDraw( );
			ballDraw( );
			uiDraw( );
			resultDraw( );
			flip();
		}
	}
}

char * name( ) {
	return "Rolling Burst";
}

char * author( ) {
	return "鬼頭 大地 & イ ドンウン";
}

char * texture( ) {
	return "RBG.bmp";
}

GAME_END;