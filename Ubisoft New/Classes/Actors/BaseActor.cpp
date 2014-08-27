#include "BaseActor.h"
#include "Globals.h"

namespace Actors
{
	BaseActor::BaseActor(void)
		: m_pTexture(nullptr)
		, m_position(0,0)
		, m_velocity(0,0)
		, m_speed(0)
		, m_isAlive(true)
		, m_blockedSide(Actors::NONE_BLOCKED)
	{
	}

	void BaseActor::SetPosition(FeVector2 position)
	{
		m_position = position;
	}

	void BaseActor::SetVelocity(FeVector2 velocity)
	{
		m_velocity = velocity;
	}

	void BaseActor::SetSpeed(float speed)
	{
		m_speed = speed;
	}

	void BaseActor::SetBlockedSide(BlockedSide blockedSide)
	{
		if(blockedSide == BlockedSide::NONE_BLOCKED)
		{
			m_blockedSide = blockedSide;
		}
		else
		{
			m_blockedSide |= blockedSide;
		}
	}

	BaseActor::~BaseActor(void)
	{
	}

	void BaseActor::OnCollision(BaseActor *Actor)
	{
	}

	void BaseActor::Update(float deltaTime)
	{
	}

	void BaseActor::Draw(FeSpriteBatch spriteBatch)
	{
	}
};