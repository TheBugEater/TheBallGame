#pragma once
#include"FeGamePlay.h"

//FeGame Class which Inherits Abstract Class FeGame Play

class FeGame : public FeGamePlay
{
public:
	virtual void Initialize(FeGamePlay *FeGame);										//This Function Gets Called before Initialization of DirectX Window
	virtual void LoadContent(FeGraphicDevice FeGraphicDevice);							//Load Content is Called when the Framework is Ready to Load Images
	virtual void Unload();															
	virtual void Update(FeGameTime FeGameTime);															//Update gets Called Automatically For Every Frame
	virtual void Draw();															//Draw gets Called when Device is Ready to Draw for Each Frame

	FeGame()
	{
		BackBufferWidth = 800;
		BackBufferHeight = 600;
		FullScreen = false;
		strncpy_s(ApplicationName,"FeEngine - DirectX Abstract Graphics Library",1024);
	}
};