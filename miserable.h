//********************************************************************************//
//
// miserable.h
//
// Created by Okuty in 2015/10/15
//
//********************************************************************************//
#pragma once

#include <string>
#include <map>
#include <math.h>

//========================================//
// ���C�u�����ǂݍ���
//========================================//
#ifdef _DEBUG
#	pragma comment( lib, "miserable_d.lib" )
#else
#	pragma comment( lib, "miserable_r.lib" )
#endif

//========================================//
// �v���p�e�B
//========================================//
#define PROPERTY( _TAG_, _ARG_ ) \
class Peoperty##_TAG_ : public Property { \
public: virtual ~Peoperty##_TAG_ ( ) {} \
Peoperty##_TAG_ ( ) { set( #_TAG_, #_ARG_ ); } \
} __##Peoperty##_TAG_##__

#define GAME_BEGIN( _TITLE_ ) \
class _TITLE_ : public Game { \
public: \
	_TITLE_##( ) : Game( #_TITLE_ ) { } \
	virtual ~##_TITLE_##( ) { }

#define GAME_END \
} __game__;

//========================================//
// ��ʃT�C�Y
//========================================//
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

//========================================V//
// property
//========================================//
class Property {
public:
	Property( ) { }
	virtual ~Property( ) { }
protected:
	static void set( const char * tag, const char * arg );
};

//========================================//
// game.cpp
//========================================//
class Game {
public:
	Game( const char * tag );
	virtual ~Game( );
	virtual void main( ) = 0;
	virtual char * name( ) { return "no name"; }
	virtual char * author( ) { return "no autho"; }
	virtual char * texture( ) { return "texture.bmp"; }
};

//=======================================//
// ���w
//=======================================//
const double PI  = 3.1415926535897932384626433832795;
const double PI2 = PI * 2;

const unsigned int RATIO = 1 << 16;
const unsigned int MARGIN = 1 << 15;

inline double round(const double in_value) {
	int in = (int)(in_value * RATIO);
	return (double)in / RATIO;
}

struct Vector {
	double x;
	double y;
	double z;

	Vector()
		: x(0)
		, y(0)
		, z(0) {
	}

	Vector(const double inX, const double inY, const double inZ = 0)
		: x(round(inX))
		, y(round(inY))
		, z(round(inZ)) {
	}

	virtual ~Vector() {

	}

	// �����̂Q��i�v�Z�X�s�[�h����̂��߁j 
	inline double getLength2() const {
		return x * x + y * y + z * z;
	}

	// ����
	inline double getLength() const {
		double s[3] = {abs(x), abs(y), abs(z)};
		double n = s[0];
		for (int i = 1; i < 3; i++) {
			if (n < s[i]) n = s[i];
		}
		if (n == 0.0) {
			return 0;
		}
		double x = this->x / n;
		double y = this->y / n;
		double z = this->z / n;
		return sqrt(x * x + y * y + z * z) * n;
	}

	// �����Z
	inline Vector add(const Vector& inVector) const {
		return Vector(
			x + inVector.x,	
			y + inVector.y,
			z + inVector.z);
	}
	inline Vector operator+(const Vector& inVector) const {
		return add(inVector);
	}
	inline Vector operator+=(const Vector& inVector) {
		*this = *this + inVector;
		return *this;
	}

	// �����Z
	inline Vector sub(const Vector& inVector) const {
		return Vector(
			x - inVector.x,	
			y - inVector.y,
			z - inVector.z);
	}
	inline Vector operator-(const Vector& inVector) const {
		return sub(inVector);
	}
	inline Vector operator-=(const Vector& inVector) {
		*this = *this - inVector;
		return *this;
	}

	// �|���Z
	inline Vector multiply(const double inValue) const {
		return Vector(
			x * inValue,	
			y * inValue,
			z * inValue);
	}
	inline Vector operator*(const double inValue) const {
		return multiply(inValue);
	}
	inline Vector operator*=(const double inValue) {
		*this = *this * inValue;
		return *this;
	}

	// �O��
	inline Vector cross(const Vector& inVector) const {
		Vector v1 = (*this).normalize();
		Vector v2 = inVector.normalize();
		Vector vc(
			v1.y * v2.z - v2.y * v1.z,
			v1.z * v2.x - v2.z * v1.x,
			v1.x * v2.y - v2.x * v1.y);
		return vc.normalize();
	}

	// ����
	inline double dot(const Vector& inVec) const {
		double x = this->x * inVec.x;
		double y = this->y * inVec.y;
		double z = this->z * inVec.z;
		return x + y + z;
	}

	// ���K��	
	inline Vector normalize() const {
		double norm = getLength();
		if (norm == 0) {
			norm = 1; // �傫�����Ȃ��̂ŁA�P�őΉ�
		}
		return Vector(
			x / norm,
			y / norm,
			z / norm);
	}

	// �Q�x�N�g���Ԃ̊p�x�i���W�A���j�����߂�
	// �G���[��-1
	inline double angle(const Vector& in_vec) const {
		Vector v1 = normalize();
		Vector v2 = in_vec.normalize();
		double d = v1.dot(v2);

		if (d >= 1) {
			return 0;
		}
		
		if (d <= -1) {
			return PI;
		}

		return acos(d);
	}

	// ���_�m�F
	inline bool isOrijin() const {
		return
			x == 0 &&
			y == 0 &&
			z == 0;
	}

	// �C�R�[��
	inline bool operator==(const Vector& inVec) const {
		int sx = (int)(this->x * MARGIN);
		int sy = (int)(this->y * MARGIN);
		int sz = (int)(this->z * MARGIN);
		int dx = (int)(inVec.x * MARGIN);
		int dy = (int)(inVec.y * MARGIN);
		int dz = (int)(inVec.z * MARGIN);
		return
			sx == dx &&
			sy == dy &&
			sz == dz;
	}
	inline bool operator!=(const Vector& inVec) const {
		return !(*this == inVec);
	}
};

struct Matrix {
	double data[4][4];

	Matrix() {
		// Matrix�����ꂽ��A�P�ʍs����쐬����
		for (int i = 0; i < 4; i++) 
		for (int j = 0; j < 4; j++) {
			data[i][j] = 0;
		}
		for (int i = 0; i < 4; i++) {
			data[i][i] = 1;
		}
	}

	virtual ~Matrix() {
	}

	inline static Matrix makeTransformTranslation(const Vector& inTrans) {
		// ���s�ړ��̕ϊ��s������
		Matrix mat;

		mat.data[3][0] = inTrans.x;
		mat.data[3][1] = inTrans.y;
		mat.data[3][2] = inTrans.z;

		return mat;
	}

	inline static Matrix makeTransformScaling(const Vector& inScale) {
		// �g��k���̕ϊ��s������
		Matrix mat;

		mat.data[0][0] = inScale.x;
		mat.data[1][1] = inScale.y;
		mat.data[2][2] = inScale.z;

		return mat;
	}

	inline static Matrix makeTransformRotation(const Vector& inAxis, const double inRadian) {
		// �C�ӎ���]�̕ϊ��s������
		Matrix mat;	
		Vector v = inAxis.normalize();
		double c = (1 - cos(inRadian));

		mat.data[0][0] = v.x * v.x * c + cos(inRadian);
		mat.data[0][1] = v.x * v.y * c - v.z * sin(inRadian);
		mat.data[0][2] = v.z * v.x * c + v.y * sin(inRadian);

		mat.data[1][0] = v.x * v.y * c + v.z * sin(inRadian);
		mat.data[1][1] = v.y * v.y * c + cos(inRadian);
		mat.data[1][2] = v.y * v.z * c - v.x * sin(inRadian);

		mat.data[2][0] = v.z * v.x * c - v.y * sin(inRadian);
		mat.data[2][1] = v.y * v.z * c + v.x * sin(inRadian);
		mat.data[2][2] = v.z * v.z * c + cos(inRadian);

		return mat;
	}

	inline Matrix multiply(const Matrix& inMat) const {
		Matrix mat;
		for (int n = 0; n < 4; n++) {
			for (int m = 0; m < 4; m++) {
				mat.data[n][m] = 0;
				for (int i = 0; i < 4; i++) {
					mat.data[n][m] += data[n][i] * inMat.data[i][m];
				}
			}
		}
		return mat;
	}

	inline Matrix operator*(const Matrix& inMat) const {
		return this->multiply(inMat);
	}

	inline Vector multiply(const Vector& inVector) const {
		return Vector(
			data[0][0] * inVector.x + data[1][0] * inVector.y + data[2][0] * inVector.z + data[3][0] * 1,
			data[0][1] * inVector.x + data[1][1] * inVector.y + data[2][1] * inVector.z + data[3][1] * 1,
			data[0][2] * inVector.x + data[1][2] * inVector.y + data[2][2] * inVector.z + data[3][2] * 1);
	}

	inline Vector operator*(const Vector& inVector) const {
		return this->multiply(inVector);
	}

	inline Matrix unit( ) const {
		Matrix mat;
		for ( int i = 0; i < 4; i++ ) {
			for ( int j = 0; j < 4; j++ ) {
				mat.data[ i ][ j ] = ( i == j ) ? 1.0: 0.0;
			}
		}

		return mat;
	}

	inline Matrix inverse( ) const {
		Matrix a = *this;
		double buf; //�ꎞ�I�ȃf�[�^��~����
 
		//�P�ʍs��
		Matrix inv = Matrix::unit( );

		//�|���o���@
		for ( int i = 0; i < 4; i++ ) {
			buf = 1 / a.data[ i ][ i ];
			for ( int j = 0; j < 4; j++ ) {
				a.data[ i ][ j ] *= buf;
				inv.data[ i ][ j ] *= buf;
			}
			for( int j = 0; j < 4; j++ ) {
				if ( i != j ) {
					buf = a.data[ j ][ i ];
					for ( int k = 0; k < 4; k++ ) {
						a.data[ j ][ k ] -= a.data[ i ][ k ] * buf;
						inv.data[ j ][ k ] -= inv.data[ i ][ k ]*buf;
					}
				}
			}
		}

		return inv;
	}
};

struct POLYGON {
	struct VERTEX {
		Vector pos;
		Vector tex;
		Vector norm;
	};
	VERTEX vertex[ 3 ];
};

//========================================//
// ���\�b�h
//========================================//
int  random( );
void flip();
void drawPolygon( const Vector& p1, const Vector& p2, const Vector& p3 );
void drawPolygon( const POLYGON& polygon );
void camera( const Vector& pos, const Vector& target );
void updateViewer( double length = 10.0 );
Vector getLeftAnalogStick( );
Vector getRightAnalogStick( );
int getLeftPushButton( );
int getRightPushButton( );
int getLeftHoldButton( );
int getRightHoldButton( );
void drawString( int x, int y, const char * fmt, ... );
void drawTexture( int sx, int sy, int tx, int ty, int tw, int th );
void success( );

//========================================//
// Model�N���X
//========================================//
#include <vector>

class Model {
public:
	Model( );
	~Model( );
	void addTriangle( Vector pos0, Vector pos1, Vector pos2,
					  Vector tex0, Vector tex1, Vector tex2,
					  Vector norm0 = Vector( ),
					  Vector norm1 = Vector( ),
					  Vector norm2 = Vector( ) );

	void addSquare( Vector pos0,
					Vector pos1,
					Vector pos2,
					Vector pos3,
					Vector tex0,
					Vector tex1,
					Vector tex2,
					Vector tex3,
					Vector norm0 = Vector( ),
					Vector norm1 = Vector( ),
					Vector norm2 = Vector( ),
					Vector norm3 = Vector( ) );

	void addCube( Vector pos, 
				  Vector size, 
					Vector tex0,
					Vector tex1,
					Vector tex2,
					Vector tex3 );

	void addSphere( const double radius, const int accuracy, Vector tex_xy, Vector tex_wh  );
	void draw( const Vector& pos, double rot_y = 0 ) const;
private:
	std::vector< POLYGON > _polygon;
};
