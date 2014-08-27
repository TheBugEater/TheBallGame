#pragma once
#ifndef _SQUARE_ACTOR_H_
#define _SQUARE_ACTOR_H_
#include "BaseActor.h"
#include <FeSpriteBatch.h>

namespace Actors
{
	class SquareActor : public BaseActor
	{
	public:
		SquareActor(void);
		~SquareActor(void);

		virtual void CreateActor();

		virtual void OnCollision(BaseActor *Actor);

		virtual void Update(float deltaTime);

		virtual void Draw(FeSpriteBatch spriteBatch);
	};
};
#endif