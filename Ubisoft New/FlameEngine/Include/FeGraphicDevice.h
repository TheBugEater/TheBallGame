#pragma once
#include"FeGraphicDevice.h"

//Structure which holds Direct3D Device
struct FeGraphicDevice
{
	IDirect3DDevice9 *Device;

	FeGraphicDevice(IDirect3DDevice9 *Dev)
	{
		Device = Dev;
	}

	FeGraphicDevice()
	{
		Device = NULL;
	}
};