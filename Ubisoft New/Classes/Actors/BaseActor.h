#pragma once

#ifndef _BASE_ACTOR_H_
#define _BASE_ACTOR_H_
#include <FeEngine.h>
#include <FeSpriteBatch.h>

namespace Actors
{
	enum Types
	{
		ACTOR_CIRCLE = 0,
		ACTOR_TRIANGLE,
		ACTOR_SQUARE,

		MAX_ACTORS
	};

	enum BlockedSide
	{
		LEFT_BLOCKED = 0x01,
		RIGHT_BLOCKED = 0x02,
		TOP_BLOCKED = 0x04,
		BOTTOM_BLOCKED = 0x08,
		NONE_BLOCKED = 0x00
	};

	class BaseActor
	{
	public:
		BaseActor(void);
		~BaseActor(void);

		//Abstract function, Should be overrided in derived classes
		//Should assign a Type for each actor : m_type
		//Should Load Texture : m_pTexture
		virtual void CreateActor() = 0;

		//Gets Called on a collision
		virtual void OnCollision(BaseActor *Actor);

		//Update
		virtual void Update(float deltaTime);

		//Draw
		virtual void Draw(FeSpriteBatch spriteBatch);

		//Get Actor Type 
		unsigned int GetActorType() const { return m_type; }

		//Accessor functions
		void SetPosition(FeVector2 position);
		FeVector2 GetPosition() const { return m_position; }

		void SetVelocity(FeVector2 velocity);
		FeVector2 GetVelocity() const { return m_velocity; }

		void SetSpeed(float speed);
		float GetSpeed() const { return m_speed; }

		FeTexture* GetTexture() const { return m_pTexture; }

		bool IsAlive() const { return m_isAlive; }

		void SetBlockedSide(BlockedSide blockedSide);
		byte GetBlockedSide() { return m_blockedSide; }

	protected:
		//Texture Holds the Texture data for Current Actor
		FeTexture *m_pTexture;

		FeVector2 m_position;
		FeVector2 m_velocity;
		float m_speed;
		Types m_type;
		bool m_isAlive;
		byte m_blockedSide;
	};
};
#endif