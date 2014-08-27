#pragma once
#include"FeEngine.h"
#include"FeColor.h"

#define VERTEX_FORMAT D3DFVF_XYZ| D3DFVF_DIFFUSE | D3DFVF_TEX1
#define VERTEX_FORMATRHW D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1

struct Vertex
{
	float X,Y,Z;
	D3DCOLOR Color;
	float U,V;
};

struct VertexRHW
{
	float X,Y,Z,RHW;
	D3DCOLOR Color;
	float U,V;
};

class FeSpriteBatch
{
	IDirect3DDevice9 *spriteDevice;
	IDirect3DVertexBuffer9* vertexBuffer;
	IDirect3DVertexBuffer9* vertexBufferRHW;
	Vertex *vertices;
	VertexRHW *VerticesRHW;
	FeCamera Cam;

	bool BeginDraw;
	bool RHW;

	FeVector2 Rotate(FeVector2 Position,float Angle);

public:
	
	FeSpriteBatch();
	~FeSpriteBatch();
	FeSpriteBatch(FeGraphicDevice FeGraphicDevice);

	void Unload();

	void InitFeSpriteBatch();

	void Begin();
	void Begin(FeVector2 FeCameraPosition);
	void End();

	bool IsRHW();

	//All Types of Draw Calls for FeVector2
	void Draw(FeTexture FeTextureFile,FeVector2 Position,FeColor FeColor);
	void Draw(FeTexture FeTextureFile,FeRectangle Rect,FeColor FeColor);
	void Draw(FeTexture FeTextureFile,FeRectangle Rect,FeRectangle SourceRect,FeColor FeColor);
	void Draw(FeTexture FeTextureFile,FeVector2 Position,FeRectangle SourceRect,FeColor FeColor);
	void Draw(FeTexture FeTextureFile,FeVector2 Position,FeVector2 Origin,float Rotation,FeColor FeColor);
	void Draw(FeTexture FeTextureFile,FeRectangle Rect,FeVector2 Origin,float Rotation,FeColor FeColor);
	void Draw(FeTexture FeTextureFile,FeRectangle Rect,FeRectangle SourceRect,FeVector2 Origin,float Rotation,FeColor FeColor);
	void Draw(FeTexture FeTextureFile,FeVector2 Position,FeRectangle SourceRect,FeVector2 Origin,float Rotation,FeColor FeColor);

	//All Types of Draw Calls for Vector3
	//void Draw(FeTexture FeTextureFile,Vector3 Position,FeColor FeColor);
	//void Draw(FeTexture FeTextureFile,FeRectangle Rect,FeColor FeColor);
	//void Draw(FeTexture FeTextureFile,FeRectangle Rect,FeRectangle SourceRect,FeColor FeColor);
	//void Draw(FeTexture FeTextureFile,Vector3 Position,FeRectangle SourceRect,FeColor FeColor);
	//void Draw(FeTexture FeTextureFile,Vector3 Position,FeVector2 Origin,float Rotation,FeColor FeColor);
	//void Draw(FeTexture FeTextureFile,FeRectangle Rect,FeVector2 Origin,float Rotation,FeColor FeColor);
	//void Draw(FeTexture FeTextureFile,FeRectangle Rect,FeRectangle SourceRect,FeVector2 Origin,float Rotation,FeColor FeColor);
	//void Draw(FeTexture FeTextureFile,Vector3 Position,FeRectangle SourceRect,FeVector2 Origin,float Rotation,FeColor FeColor);
};