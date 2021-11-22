#include "vector3.h"


Vector3::Vector3()
{
	this->X = 0.0;
	this->Y = 0.0;
	this->Z = 0.0;
}

Vector3::Vector3(float X, float Y, float Z)
{
	this->X = X;
	this->Y = Y;
	this->Z = Z;
}

Vector3 Vector3::operator+ (const Vector3 W)
{
	Vector3 Result;
	Result.X = this->X + W.X;
	Result.Y = this->Y + W.Y;
	Result.Z = this->Z + W.Z;
	return Result;
}

void Vector3::operator+= (const Vector3 W)
{
	this->X += W.X;
	this->Y += W.Y;
	this->Z += W.Z;
}

Vector3 Vector3::operator- (const Vector3 W)
{
	Vector3 Result;
	Result.X = this->X - W.X;
	Result.Y = this->Y - W.Y;
	Result.Z = this->Z - W.Z;
	return Result;
}

void Vector3::operator-= (const Vector3 W)
{
	this->X -= W.X;
	this->Y -= W.Y;
	this->Z -= W.Z;
}

Vector3 Vector3::operator* (const float W)
{
	Vector3 Result;
	Result.X = this->X * W;
	Result.Y = this->Y * W;
	Result.Z = this->Z * W;
	return Result;
}

void Vector3::operator*= (const Vector3 W)
{
	this->X *= W.X;
	this->Y *= W.Y;
	this->Z *= W.Z;
}

Vector3 Vector3::operator/ (const Vector3 W)
{
	Vector3 Result;
	Result.X = this->X / W.X;
	Result.Y = this->Y / W.Y;
	Result.Z = this->Z / W.Z;
	return Result;
}

void Vector3::operator/= (const Vector3 W)
{
	this->X /= W.X;
	this->Y /= W.Y;
	this->Z /= W.Z;
}

bool Vector3::operator==(const Vector3 W)
{
	return ((int)(this->X * 1000.0f) == (int)(W.X * 1000.0) && (int)(this->Y * 1000.0) == (int)(W.Y * 1000.0) && (int)(this->Z * 1000.0) == (int)(W.Z * 1000.0));
}

float Vector3::Magnitude() //from internet
{
	double mag = sqrt(pow(this->X, 2) + pow(this->Y, 2) + pow(this->Z, 2));
	return mag;
}

void Vector3::Normalize() //from internet
{
	double mag = sqrt(pow(this->X, 2) + pow(this->Y, 2) + pow(this->Z, 2));
	this->X = this->X / mag;
	this->X = this->X / mag;
	this->X = this->X / mag;
}
