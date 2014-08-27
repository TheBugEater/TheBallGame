#pragma once
#include"FeTexture.h"
#include"FeVector2.h"
#include"FeRectangle.h"

class FeGameObject
{
	FeRectangle BoundingFeRectangle;
	bool Animated;
	int FrameWidth,FrameHeight,Rows,Columns;
	int CurrentRow,CurrentColumn;

public:
	FeVector2 Position;
	FeTexture ObjectFeTexture;

	FeGameObject(void);
	FeGameObject(FeTexture FeTextureFile,FeVector2 Position);
	FeGameObject(FeTexture FeTextureFile,FeVector2 Position,int FrameWidth,int FrameHeight,int Rows,int Columns);

	bool SetFrame(int Row,int Column);
	void NextFrame();
	void PrevFrame();
	void SetRow(int Row);
	void SetColumn(int Column);
	FeRectangle GetBoundingFeRectangle();
	FeRectangle GetCurrentRectangle();

	~FeGameObject(void);
};

