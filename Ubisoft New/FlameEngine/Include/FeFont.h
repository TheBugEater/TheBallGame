#pragma once
#include"FeBase.h"
#include"FeVector2.h"
#include"FeRectangle.h"
#include"FeColor.h"

class FeFont : public FeBase
{
	ID3DXFont *Font;

public:
	FeFont(void);
	FeFont(std::string FontName,int Size);

	void DrawString(std::string Message,FeVector2 Position,FeColor FeColor);
	void Unload();
	~FeFont(void);
};

