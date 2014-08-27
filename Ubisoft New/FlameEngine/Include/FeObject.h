#pragma once
#include<Box2D\Box2D.h>
#include"FeTexture.h"
#include"FeVector2.h"
#include"FeWorld.h"
#include"FeSpriteBatch.h"

namespace BODYTYPE
{
	enum _BodyType
	{
		STATIC,
		DYNAMIC,
		KINEMATIC
	};
}

namespace SHAPE
{
	enum _Shape
	{
		FEOBJECT_BOX,
		FEOBJECT_TRIANGLE,
		FEOBJECT_CIRCLE
	};
}

class FeObject
{
	b2World *World;
	b2FixtureDef boxFixtureDef;
	b2PolygonShape pShape;
	b2CircleShape cShape;

	SHAPE::_Shape Shape;

	FeTexture Texture;
	FeVector2 Position;
	float Rotation;

	b2BodyType GetBodyType(BODYTYPE::_BodyType type);
	b2Shape* GetBodyShape(SHAPE::_Shape shape,FeTexture Image);

public:
	FeObject(void);
	b2Body *Body;

	FeObject(FeTexture texture,FeVector2 Position,BODYTYPE::_BodyType Type,SHAPE::_Shape Shape,FeWorld *feWorld);

	void Update();
	void Draw(FeSpriteBatch spriteBatch);

	void Release();

	~FeObject(void);
};

