#pragma once
#include<Box2D\Box2D.h>
#include<FeVector2.h>

#define METRE_TO_PIXEL 50
#define PIXEL_TO_METRE 0.02
 
class FeWorld
{
	float32 TimeStep;
	int32 velocityIterations;
	int32 positionIterations;

protected:

public:
	static b2World *World;

	FeWorld(void);

	FeWorld(FeVector2 gravity,float timeStep);
	
	void Update();
	void Unload();

	~FeWorld(void);
};

