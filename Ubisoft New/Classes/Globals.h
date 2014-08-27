#pragma once

#ifndef _GLOBALS_H_
#define _GLOBALS_H_

#include <FeEngine.h>
#include <FeSize.h>

#define SAFE_DELETE_POINTER(_type) { if(_type){delete _type; _type = nullptr;} }

class Globals
{
public:
	
	static Globals* GetInstance();

	void SetFrameSize(FeSize size);
	FeSize GetFrameSize() const { return m_frameSize; }

	float Random(float Min,float Max);

private:
	//Globals is a Singleton Class
	Globals(void);
	~Globals(void);

	//Static Instance of Singleton Class
	static Globals* m_pGlobalInstance;

	FeSize m_frameSize;
};

#endif