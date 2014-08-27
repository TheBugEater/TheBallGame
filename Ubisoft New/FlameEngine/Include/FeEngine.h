#pragma once
#include<Windows.h>
#include<d3d9.h>
#include<d3dx9.h>
#include<string>
#include"FeGamePlay.h"
#include"FeVector2.h"
#include"FeRectangle.h"
#include"FeTexture.h"
#include"FeMouse.h"
#include"FeCamera.h"
#include"FeGameTime.h"
#include<math.h>


/******************************************
Flame Engine - 2D FeGame Engine
Author - Dilhan Geeth Amarasinghe
********COPYRIGHTS © Dilhan Geeth**********
*******************************************/

/*
Framework Initialization
FeEngine is the FeBase Framework Engine Class which acts as the Mediator between DirectX and FeEngine Framework
*/


//Window Procedure Prototype
LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);

 
class FeEngine
{
private:

	bool FullScreen;									//To Check if User Prefers Full Screen Mode
	int ScreenHeight;									//Height of the Screen
	int ScreenWidth;									//Width of the Screen
	char AppName[1024];									//Name of the Application to Display on the Title Bar

	HINSTANCE hInstance;								//Instance to the Application
	FeMouse *M;											//FeMouse Object - To update the Position of FeMouse Every Frame

	void MessageLoop();									//Windows Message Loop
	void Render();										//Render Function which does all the rendering 
	bool CreateFrameworkWindow();						//Frame Work Window Creation

public:

	HWND hWnd;											//Handle to the Created Window
	FeGamePlay *Game;									//The FeGame Play Class Object - This is the class which user interacts with
	IDirect3DDevice9 *Device;							//Pointer to the Direct3D Device
	IDirect3D9 *d3d;
	D3DPRESENT_PARAMETERS d3dpp;						//Present Parameters
	FeGraphicDevice feGraphicDevice;						//Graphic Device to Point the DirectX Device to other classes
	FeBase feTextureDevice;									//FeBase Class which deals with all the FeTexture Unloading
	FeCamera Cam;											//Virtual FeCamera used in Orthogonal Projection
	FeGameTime feGameTime;									//FeGameTime to Calculate the Elapsed and Total FeGame Time;

	static IDirect3DDevice9 *staticFeGraphicDevice;
	static HWND hWindowHandle;

	FeEngine(HINSTANCE hInstance,FeGamePlay *Game);			//Constructor which Takes Application Instance and Pointer to the FeGamePlay class as Parameters

	void InitPointers();								//Where Initialization of Pointers takes place
	void DeletePointers();								//Where Deletion of Pointers takes place

	void InitFramework(FeGamePlay *Game);				//Initializing FeGamePlay as Current Framework Environment
	void CallingFunction();								//Used to Call Other Functions
	void updateFeCamera();								//FeCamera Updating 
	bool InitDirectx();									//Initializing DirectX
};