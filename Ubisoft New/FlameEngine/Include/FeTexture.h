#pragma once
#include"FeBase.h"

class FeTexture : public FeBase
{
public:
	int Width,Height;
	IDirect3DTexture9 *FeTextureFile;

	FeTexture(void);
	FeTexture(std::string FileName);

	bool Unload();
	~FeTexture(void);
};

