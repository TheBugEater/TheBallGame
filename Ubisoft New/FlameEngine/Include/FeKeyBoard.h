#pragma once
#include<Windows.h>

class FeKeyBoard
{
public:
	bool IsKeyDown(int VirtualKey);
	FeKeyBoard(void);
	~FeKeyBoard(void);
};

