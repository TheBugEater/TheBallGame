#pragma once
#include<Windows.h>
#include<d3d9.h>
#include<d3dx9.h>
#include"FeColor.h"
#include"FeGraphicDevice.h"
#include"FeGameTime.h"
#include<string>

//Abstract Class for Future Enhancement to the Framework
class FeGamePlay
{
public:
	HWND hWnd;
	IDirect3DDevice9 *Device;
	int BackBufferWidth;
	int BackBufferHeight;
	bool FullScreen;
	char ApplicationName[1024];

	void SetApplicationName(const char*);

	virtual void Initialize(FeGamePlay *FeGame) = 0;
	virtual void LoadContent(FeGraphicDevice FeGraphicDevice) = 0;
	virtual void Unload() = 0;
	virtual void Update(FeGameTime FeGameTime) = 0;
	virtual void Draw() = 0;
};
