#pragma once
#include<d3d9.h>
#include<string>
#include<d3dx9.h>
#include<list>

using namespace std;

//FeBase Class which Handles Loading of FeTextures and Unloading them Properly
class FeBase
{
protected:
	static list<IDirect3DTexture9*> LoadedFeTextures;					//List Containes the Loaded FeTextures
	static IDirect3DDevice9 *Device;
	static HWND hWnd;

public:
	FeBase();
	FeBase(IDirect3DDevice9 *GetDevice,HWND hwnd);					//Get Created DirectX Device for use in FeTexture Loading etc.
	void UnloadFeBase();												//Unloads all the loaded FeTextures before exiting
};

