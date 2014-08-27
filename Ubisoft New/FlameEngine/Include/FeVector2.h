#pragma once
#include<math.h>

class FeVector2
{
public:
	float X,Y;
	static FeVector2 Zero;

	FeVector2();
	FeVector2(int X,int Y);
	FeVector2(float X,float Y);

	FeVector2& operator+= (FeVector2 Vector);
	FeVector2& operator-= (FeVector2 Vector);
	FeVector2& operator+= (float Value);
	FeVector2& operator-= (float Value);
	FeVector2& operator*= (float Value);
	FeVector2& operator/= (float Value);

	FeVector2 operator+ (FeVector2 Vector);
	FeVector2 operator- (FeVector2 Vector);
	FeVector2 operator* (float Value);
	FeVector2 operator/ (float Value);

	bool operator == (FeVector2 Vector);

	float Distance(FeVector2 Vector);
	float Length();
	float Angle(FeVector2 Vector);
	float Dot(FeVector2 Vector);
	void Normalize();

	static FeVector2 NormalizeEx(FeVector2 Vect1,FeVector2 Vect2);
};