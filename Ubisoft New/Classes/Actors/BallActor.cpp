#include "BallActor.h"
#include "Managers/TextureManager.h"
#include <FeKeyBoard.h>
#include "Globals.h"
#include <FeSize.h>
#include "Game/GamePlay.h"

namespace Actors
{
	BallActor::BallActor(void)
		: m_isJumping(true)
		, m_acceleration(0)
	{
	}


	BallActor::~BallActor(void)
	{
	}

	void BallActor::CreateActor()
	{
		m_type = Actors::ACTOR_CIRCLE;
		m_pTexture = Managers::TextureManager::GetInstance()->LoadTexture("Data/Ball.png");
		m_speed = 50;
		m_velocity = FeVector2(0,0);
		m_position = FeVector2(0,0);
		m_acceleration = 0.2f;
		m_rotation = 0;
		m_gravity = FeVector2(0,600);
		m_rotate_offset = 1;
		m_nextLifeTime = 0;
		m_isNextLife = false;
		m_font = FeFont("Times New Roman",30);
	}
	
	void BallActor::OnCollision(BaseActor *Actor)
	{
		//IF Collided with a Triangle then Reduce a life and Reset Ball Position
		if(Actor->GetActorType() == Actors::ACTOR_TRIANGLE)
		{
			Reset();
			Game::GamePlay::ReduceLife();
			m_isNextLife = true;
		}
	}
	
	void BallActor::Reset()
	{
		if(Game::GamePlay::GetLives() > 1)
		{
			m_position = FeVector2(m_position.X + 300, -100.0f);
		}
		else
		{
  			m_position = FeVector2(m_position.X,-100.0f);
		}

		m_velocity = FeVector2(0,-600);

		m_acceleration = 2.0f;

		m_isJumping = true;
	}

	void BallActor::Update(float deltaTime)
	{

		if(m_isNextLife)
		{
			if(m_nextLifeTime >= 3)
			{
				m_isNextLife = false;
				m_nextLifeTime = 0;
			}
			else
			{
				m_nextLifeTime += deltaTime;
				return;
			}
		}

		FeSize size = Globals::GetInstance()->GetFrameSize();
		FeKeyBoard keyBoard;
		
		FeVector2 tempVelocity;
		FeVector2 tempGravity;

		//If Right is not Blocked then keep moving
		if(!(m_blockedSide & Actors::RIGHT_BLOCKED))
		{
			tempVelocity.X = m_speed * m_acceleration * deltaTime;
		}
		else
		{
			m_acceleration = 2.0f;
		}

		//If Bottom is blocked don't apply Gravity
		if(!(m_blockedSide & Actors::BOTTOM_BLOCKED))
		{
			tempGravity = m_gravity;
			m_velocity += m_gravity * deltaTime * 2;
		}
		else
		{
			m_isJumping = false;
			m_velocity = FeVector2(0,-200);
		}

		
		m_position += tempVelocity + (m_velocity*deltaTime) + (tempGravity*deltaTime);
		

		if(keyBoard.IsKeyDown(VK_SPACE) && m_isJumping == false)
		{
			m_isJumping = true;
			m_velocity = FeVector2(0,-1200);
		}

		//Ground Limit
		if(m_position.Y >= size.Height - m_pTexture->Height/2)
		{
			m_position.Y = (float)size.Height - m_pTexture->Height/2;
			m_isJumping = false;
		}

		//Acceleration Limit 
		if(m_acceleration < 5)
		{
			m_acceleration += 0.002f;
		}

		//Speed Limit
		if(m_speed >= 80)
		{
			m_speed = 80;
		}
		else
		{
			m_speed += deltaTime;
		}

		m_rotation += m_speed*deltaTime*m_rotate_offset/10;
	}
	
	void BallActor::Draw(FeSpriteBatch spriteBatch)
	{
		spriteBatch.Draw(*m_pTexture,
						m_position,
						FeVector2(m_pTexture->Width/2,m_pTexture->Height/2),
						m_rotation,FeColor_White);

		if(m_isNextLife && Game::GamePlay::GetLives() > 0)
		{
			char Message[100];
			int time = 3 - (int)m_nextLifeTime;
			FeSize size = Globals::GetInstance()->GetFrameSize();
			sprintf(Message,"Next Life in %d Seconds",time);
			m_font.DrawString(Message,FeVector2(size.Width/2 - (15*strlen(Message)),size.Height/2 - 10),FeColor::FeColor_Yellow);
		}
	}
}
