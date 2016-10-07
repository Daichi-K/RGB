#include "pattern.h"
#include "ui.h"
#include <time.h>

static int timer = 0;
static int dif = random( ) % 9;

TYPE patternMap[ DIF_MAX ][ 3 ][ 5 ][ 5 ] = {
	{
		{
			{ PURPLE, PURPLE, PURPLE, PURPLE, PURPLE },
			{ NORMAL, NORMAL, NORMAL, NORMAL, NORMAL },
			{ PURPLE, PURPLE, PURPLE, PURPLE, PURPLE },
			{ NORMAL, NORMAL, NORMAL, NORMAL, NORMAL },
			{ PURPLE, PURPLE, PURPLE, PURPLE, PURPLE }
		},
		
		{
			{ BLUE, NORMAL, BLUE, NORMAL, BLUE },
			{ BLUE, NORMAL, BLUE, NORMAL, BLUE },
			{ BLUE, NORMAL, BLUE, NORMAL, BLUE },
			{ BLUE, NORMAL, BLUE, NORMAL, BLUE },
			{ BLUE, NORMAL, BLUE, NORMAL, BLUE }
		},
		
		{
			{ NORMAL, NORMAL, NORMAL, NORMAL, NORMAL },
			{ NORMAL, GREEN, NORMAL, NORMAL, NORMAL },
			{ NORMAL, NORMAL, NORMAL, NORMAL, NORMAL },
			{ NORMAL, NORMAL, NORMAL, GREEN, NORMAL },
			{ NORMAL, NORMAL, NORMAL, NORMAL, NORMAL }
		},
		//--------------------------------------------------------------
	},
	
	{
		//-------------------------------------------------------------2
		{
			{ NORMAL, PURPLE, NORMAL, NORMAL, NORMAL },
			{ PURPLE, NORMAL, NORMAL, NORMAL, NORMAL },
			{ NORMAL, NORMAL, PURPLE, NORMAL, NORMAL },
			{ NORMAL, NORMAL, NORMAL, NORMAL, PURPLE },
			{ NORMAL, NORMAL, NORMAL, PURPLE, NORMAL }
		},
		
		{
			{ NORMAL, NORMAL, NORMAL, BLUE, NORMAL },
			{ NORMAL, NORMAL, NORMAL, NORMAL, BLUE },
			{ NORMAL, NORMAL, NORMAL, NORMAL, NORMAL },
			{ BLUE, NORMAL, NORMAL, NORMAL, NORMAL },
			{ NORMAL, BLUE, NORMAL, NORMAL, NORMAL }
		},
		
		{
			{ NORMAL, NORMAL, NORMAL, NORMAL, NORMAL },
			{ NORMAL, GREEN, GREEN, GREEN, NORMAL },
			{ NORMAL, GREEN, NORMAL, GREEN, NORMAL },
			{ NORMAL, GREEN, GREEN, GREEN, NORMAL },
			{ NORMAL, NORMAL, NORMAL, NORMAL, NORMAL }
		},
		//-------------------------------------------
	},
	
	{
		//-------------------------------------------------------------3
		{
			{ NORMAL, NORMAL, NORMAL, NORMAL, NORMAL },
			{ NORMAL, NORMAL, NORMAL, NORMAL, NORMAL },
			{ NORMAL, NORMAL, PURPLE, NORMAL, NORMAL },
			{ NORMAL, NORMAL, NORMAL, NORMAL, NORMAL },
			{ NORMAL, NORMAL, NORMAL, NORMAL, NORMAL }
		},
		
		{
			{ NORMAL, NORMAL, NORMAL, NORMAL, NORMAL },
			{ NORMAL, NORMAL, NORMAL, NORMAL, NORMAL },
			{ NORMAL, NORMAL, NORMAL, NORMAL, NORMAL },
			{ NORMAL, NORMAL, NORMAL, NORMAL, NORMAL },
			{ NORMAL, NORMAL, NORMAL, NORMAL, NORMAL }
		},
		
		{
			{ GREEN, GREEN, GREEN, GREEN, GREEN },
			{ GREEN, GREEN, GREEN, GREEN, GREEN },
			{ GREEN, GREEN, GREEN, GREEN, GREEN },
			{ GREEN, GREEN, GREEN, GREEN, GREEN },
			{ GREEN, GREEN, GREEN, GREEN, NORMAL }
		},
		//-------------------------------------------
	},
	
	{
		//-------------------------------------------------------------4
		{
			{ PURPLE,NORMAL, NORMAL, NORMAL, PURPLE },
			{ NORMAL,PURPLE, NORMAL, PURPLE, NORMAL },
			{ NORMAL,NORMAL, PURPLE, NORMAL, NORMAL },
			{ NORMAL,PURPLE, NORMAL, PURPLE, NORMAL },
			{ PURPLE,NORMAL, NORMAL, NORMAL, PURPLE }
		},
		
		{
			{ NORMAL,NORMAL, BLUE, NORMAL, NORMAL },
			{ NORMAL,NORMAL, BLUE, NORMAL, NORMAL },
			{ BLUE,BLUE, NORMAL, BLUE, BLUE },
			{ NORMAL,NORMAL, BLUE, NORMAL, NORMAL },
			{ NORMAL,NORMAL, BLUE, NORMAL, NORMAL }
		},
		
		{
			{ NORMAL,NORMAL, NORMAL, GREEN, NORMAL },
			{ GREEN,NORMAL, NORMAL, NORMAL, NORMAL },
			{ NORMAL,NORMAL, NORMAL, NORMAL, NORMAL },
			{ NORMAL,NORMAL, NORMAL, NORMAL, GREEN },
			{ NORMAL,GREEN, NORMAL, NORMAL, NORMAL }
		},
		//-------------------------------------------
	},
	
	{
		//-------------------------------------------------------------5
		{
			{ NORMAL,NORMAL, NORMAL, NORMAL, NORMAL },
			{ NORMAL,NORMAL, NORMAL, NORMAL, NORMAL },
			{ NORMAL,PURPLE, PURPLE, PURPLE, NORMAL },
			{ NORMAL,PURPLE, PURPLE, PURPLE, NORMAL },
			{ NORMAL,PURPLE, PURPLE, PURPLE, NORMAL }
		},
		
		{
			{ BLUE,NORMAL, BLUE, NORMAL, BLUE },
			{ BLUE,NORMAL, BLUE, NORMAL, BLUE },
			{ NORMAL,NORMAL, NORMAL, NORMAL, NORMAL },
			{ NORMAL,NORMAL, NORMAL, NORMAL, NORMAL },
			{ NORMAL,NORMAL, NORMAL, NORMAL, NORMAL }
		},
		
		{
			{ NORMAL,GREEN, NORMAL, NORMAL, NORMAL },
			{ NORMAL,GREEN, NORMAL, NORMAL, NORMAL },
			{ NORMAL,NORMAL, NORMAL, NORMAL, GREEN },
			{ NORMAL,NORMAL, NORMAL, NORMAL, GREEN },
			{ NORMAL,NORMAL, NORMAL, NORMAL, GREEN }
		},
		//-------------------------------------------
	},
	
	{
		//-------------------------------------------------------------6
		{
			{ PURPLE,PURPLE, NORMAL, PURPLE, PURPLE },
			{ PURPLE,PURPLE, NORMAL, PURPLE, PURPLE },
			{ NORMAL,NORMAL, NORMAL, NORMAL, NORMAL },
			{ PURPLE,PURPLE, NORMAL, PURPLE, PURPLE },
			{ PURPLE,PURPLE, NORMAL, PURPLE, PURPLE }
		},
		
		{
			{ NORMAL,NORMAL, NORMAL, NORMAL, NORMAL },
			{ NORMAL,NORMAL, BLUE, NORMAL, NORMAL },
			{ NORMAL,BLUE, NORMAL, BLUE, NORMAL },
			{ NORMAL,NORMAL, BLUE, NORMAL, NORMAL },
			{ NORMAL,NORMAL, NORMAL, NORMAL, NORMAL }
		},
		
		{
			{ NORMAL,NORMAL, NORMAL, NORMAL, NORMAL },
			{ NORMAL,NORMAL, NORMAL, NORMAL, NORMAL },
			{ GREEN,NORMAL, GREEN, NORMAL, NORMAL },
			{ NORMAL,NORMAL, NORMAL, NORMAL, NORMAL },
			{ NORMAL,NORMAL, GREEN, NORMAL, NORMAL }
		},
		//------------------------------------------
	},
	
	{
		//-------------------------------------------------------------7
		{
			{ NORMAL,NORMAL, PURPLE, NORMAL, NORMAL },
			{ NORMAL,NORMAL, PURPLE, NORMAL, NORMAL },
			{ NORMAL,NORMAL, PURPLE, NORMAL, NORMAL },
			{ NORMAL,NORMAL, PURPLE, NORMAL, NORMAL },
			{ NORMAL,NORMAL, PURPLE, NORMAL, NORMAL }
		},
		
		{
			{ NORMAL,NORMAL, NORMAL, NORMAL, NORMAL },
			{ NORMAL,NORMAL, NORMAL, NORMAL, NORMAL },
			{ BLUE,BLUE, NORMAL, BLUE, BLUE },
			{ NORMAL,NORMAL, NORMAL, NORMAL, NORMAL },
			{ NORMAL,NORMAL, NORMAL, NORMAL, NORMAL }
		},
		
		{
			{ NORMAL,NORMAL, NORMAL, GREEN, GREEN },
			{ NORMAL,NORMAL, NORMAL, GREEN, GREEN },
			{ NORMAL,NORMAL, NORMAL, NORMAL, NORMAL },
			{ GREEN,GREEN, NORMAL, NORMAL, NORMAL },
			{ GREEN,GREEN, NORMAL, NORMAL, NORMAL }
		},
		//-------------------------------------------
	},
	
	{
		//-------------------------------------------------------------8
		{
			{ PURPLE,NORMAL, PURPLE, NORMAL, PURPLE },
			{ NORMAL,NORMAL, NORMAL, NORMAL, NORMAL },
			{ PURPLE,NORMAL, PURPLE, NORMAL, PURPLE },
			{ NORMAL,NORMAL, NORMAL, NORMAL, NORMAL },
			{ PURPLE,NORMAL, PURPLE, NORMAL, PURPLE }
		},
		
		{
			{ NORMAL,NORMAL, NORMAL, NORMAL, NORMAL },
			{ NORMAL,BLUE, NORMAL, BLUE, NORMAL },
			{ NORMAL,NORMAL, NORMAL, NORMAL, NORMAL },
			{ NORMAL,BLUE, NORMAL, BLUE, NORMAL },
			{ NORMAL,NORMAL, NORMAL, NORMAL, NORMAL }
		},
		
		{
			{ NORMAL,GREEN, NORMAL, GREEN, NORMAL },
			{ NORMAL,NORMAL, NORMAL, NORMAL, NORMAL },
			{ NORMAL,GREEN, NORMAL, GREEN, NORMAL },
			{ NORMAL,NORMAL, NORMAL, NORMAL, NORMAL },
			{ NORMAL,GREEN, NORMAL, GREEN, NORMAL }
		},
		//-------------------------------------------
	},
	
	{
		//-------------------------------------------------------------9
		{
			{ NORMAL,NORMAL, NORMAL, NORMAL, NORMAL },
			{ NORMAL,NORMAL, NORMAL, NORMAL, NORMAL },
			{ NORMAL,NORMAL, PURPLE, NORMAL, NORMAL },
			{ NORMAL,NORMAL, NORMAL, NORMAL, NORMAL },
			{ NORMAL,NORMAL, NORMAL, NORMAL, NORMAL }
		},
		
		{
			{ NORMAL,NORMAL, NORMAL, NORMAL, NORMAL },
			{ NORMAL,BLUE, BLUE, BLUE, NORMAL },
			{ NORMAL,BLUE, NORMAL, BLUE, NORMAL },
			{ NORMAL,BLUE, BLUE, BLUE, NORMAL },
			{ NORMAL,NORMAL, NORMAL, NORMAL, NORMAL }
		},
		
		{
			{ GREEN,GREEN, GREEN, GREEN, GREEN },
			{ GREEN,NORMAL, NORMAL, NORMAL, GREEN },
			{ GREEN,NORMAL, NORMAL, NORMAL, GREEN },
			{ GREEN,NORMAL, NORMAL, NORMAL, GREEN },
			{ GREEN,GREEN, NORMAL, GREEN, GREEN }
		},
		//-------------------------------------------
	}
};

void patternInit( ) {
	timer = 0;
	dif = random( ) % 9;
}

//î¬ÇÃÉpÉ^Å[Éì
bool patternUpdate( ) {

	timer++;

	for ( int z = 0; z < 3; z++ ) {
		for ( int i = 0; i < 5; i++ ) {
			for ( int j = 0; j < 5; j++ ) {
				if ( timer == PAINT_PATTERN_TIME + DESTROY_PATTERN_TIME * z ) {
					if ( getMapData( i , j ) != BALLCOLOR ) {
						setMapData( i , j, patternMap[ dif ][ z ][ j ][ i ] );

					}
				}

				if ( timer == CLEAN_PATTERN_TIME + DESTROY_PATTERN_TIME * z ) {
					if ( getMapData( i , j ) != NORMAL && getMapData( i , j ) != BALLCOLOR ) {
						setMapData( i , j, NORMAL2 );
					}
				}

				if ( timer == DESTROY_PATTERN_TIME + DESTROY_PATTERN_TIME * z ) {
					if ( getMapData( i , j ) == NORMAL2 ) {
						setMapData( i , j, BALLCOLOR );
					}
				}
			}
		}
	}
	return true;
}

