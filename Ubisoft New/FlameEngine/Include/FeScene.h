#pragma once
#include"FeGameTime.h"
#include"FeSpriteBatch.h"

class FeScene
{
protected:
	FeScene *CurrentFeScene;
public:
	FeScene();
	virtual void Initialize() = 0;
	virtual void Update(FeGameTime FeGameTime) = 0;
	virtual void Draw(FeSpriteBatch FeSpriteBatch) = 0;
	virtual void Unload() = 0;

	FeScene* GetCurrentFeScene();
};

