#pragma once
#ifndef _BALL_ACTOR_H_
#define _BALL_ACTOR_H_
#include "BaseActor.h"
#include <FeSpriteBatch.h>
#include <FeFont.h>

namespace Actors
{
	class BallActor : public BaseActor
	{
	public:
		BallActor(void);
		~BallActor(void);

		virtual void CreateActor();

		virtual void OnCollision(BaseActor *Actor);

		virtual void Update(float deltaTime);

		virtual void Draw(FeSpriteBatch spriteBatch);

	private:
		void Reset();

		bool m_isJumping;
		float m_acceleration;
		float m_rotation;
		FeVector2 m_gravity;
		FeVector2 m_jumpVector;
		UINT m_rotate_offset;
		float m_nextLifeTime;
		bool m_isNextLife;
		FeFont m_font;
	};
};
#endif