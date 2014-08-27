#pragma once
#include<Windows.h>
#include"FeBase.h"

class FeMouse : public FeBase
{
	
public:
	static int X,Y;

	bool LeftMouseButton();
	bool RightMouseButton();
	bool MiddleMouseButton();

	void _UpdateMouse();
	FeMouse(void);
	~FeMouse(void);
};