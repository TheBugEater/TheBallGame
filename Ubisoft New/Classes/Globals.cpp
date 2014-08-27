#include "Globals.h"

Globals* Globals::m_pGlobalInstance = nullptr;

Globals::Globals(void)
{
}


Globals::~Globals(void)
{
}

Globals* Globals::GetInstance()
{
	//if instance is initialized return its pointer
	if(m_pGlobalInstance)
	{
		return m_pGlobalInstance;
	}

	//else create a new one
	m_pGlobalInstance = new Globals;
	srand((unsigned int)time(NULL));
	return m_pGlobalInstance;
}

void Globals::SetFrameSize(FeSize size)
{
	m_frameSize = size;
}

float Globals::Random(float fMin,float fMax)
{
	int Min,Max;
	Min = (int)fMin * 1000;
	Max = (int)fMax * 1000;

	if(Max-Min == 0)
	{
		Max++;
	}

	float Num;
	Num = (float)(rand() % (Max-Min) + Min);

	Num = Num/1000;
	return Num;
}