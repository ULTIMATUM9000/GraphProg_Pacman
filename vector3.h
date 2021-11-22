#ifndef VECTOR3_H
#define VECTOR3_H

#include <cmath>

struct Vector3
{
	float X, Y, Z;

	Vector3();
	Vector3(float X, float Y, float Z);
	Vector3 operator+ (const Vector3 W);
	void operator+= (const Vector3 W);
	Vector3 operator- (const Vector3 W);
	void operator-= (const Vector3 W);
	Vector3 operator* (const float W);
	void operator*= (const Vector3 W);
	Vector3 operator/ (const Vector3 W);
	void operator/= (const Vector3 W);
	bool operator==(const Vector3 W);
	float Magnitude();
	void Normalize();

};


#endif 