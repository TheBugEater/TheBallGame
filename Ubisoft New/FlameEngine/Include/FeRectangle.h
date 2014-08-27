#pragma once
#include"FeVector2.h"
#include<math.h>

//FeRectangle Class is Used in Rectangle Opertaions

class FeRectangle
{
private:
	int Max(int A,int B);
	int Min(int A,int B);
public:
	int X;											//X Position
	int Y;											//Y Position
	int Width;										//Width of the Rectangle
	int Height;										//Height of the Rectangle

	FeRectangle(int X,int Y,int Width,int Height);			//Constructor which takes Rectangle Properties as Parameters
	FeRectangle();
	bool Intersect(FeRectangle rect);						//Check if Two Rectangles Collides with Each Other
	bool CircleCollision(FeRectangle rect);					//Check for Circle Collision
};