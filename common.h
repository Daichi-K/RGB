#pragma once

enum AXIS {
	AXIS_X,
	AXIS_Y,
	AXIS_Z,
	AXIS_MAX
};

double getAngle( AXIS axis );
Matrix turn( AXIS axis, double angle );
void drawPlane( Vector p1, Vector p2, Vector p3, Vector p4, int Color );
