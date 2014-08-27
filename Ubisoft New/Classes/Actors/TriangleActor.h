#pragma once
#ifndef _TRIANGLE_ACTOR_H_
#define _TRIANGLE_ACTOR_H_
#include "BaseActor.h"
#include <FeSpriteBatch.h>
#include <FeGameObject.h>

namespace Actors
{
	class TriangleActor : public BaseActor
	{
	public:
		TriangleActor(void);
		~TriangleActor(void);

		virtual void CreateActor();

		virtual void OnCollision(BaseActor *Actor);

		virtual void Update(float deltaTime);

		virtual void Draw(FeSpriteBatch spriteBatch);
	};
};
#endif