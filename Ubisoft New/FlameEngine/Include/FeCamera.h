#pragma once
#include"FeBase.h"
#include"FeVector2.h"

//Virtual FeCamera Projection

class FeCamera : FeBase
{
	D3DXMATRIX ViewMatrix;
	
	static float FeCameraPosX,FeCameraPosY;				//Position of the FeCamera
	int ScreenWidth,ScreenHeight;					//Screen Width and Screen Height

public:
	FeCamera(void);									//Default Constuctor
	FeCamera(int ScreenWidth,int ScreenHeight);		//Constructor which takes ScreenWidth and Height as Parameters

	float getCamMinX();								//Get Minimum X Position
	float getCamMinY();								//Get Minimum Y Position

	float getCamMaxX();								//Get Maximum X Position
	float getCamMaxY();								//Get Maximum Y Position

	void setCamPos(FeVector2 Position);				//Sets the FeCamera Position\
	
	static FeVector2 GetCamPos() { return FeVector2(-FeCameraPosX,-FeCameraPosY); }
};

