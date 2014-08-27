#include "SquareActor.h"
#include "Managers/TextureManager.h"
#include <FeSize.h>
#include "Globals.h"
#include "Managers/ActorManager.h"

namespace Actors
{
	SquareActor::SquareActor(void)
	{
	}


	SquareActor::~SquareActor(void)
	{
	}

	void SquareActor::CreateActor()
	{
		m_type = Actors::ACTOR_SQUARE;
		m_pTexture = Managers::TextureManager::GetInstance()->LoadTexture("Data/Box.png");
	}
	
	void SquareActor::OnCollision(BaseActor *Actor)
	{
	}
	
	void SquareActor::Update(float deltaTime)
	{
		FeSize size = Globals::GetInstance()->GetFrameSize();
		
		if(Managers::ActorManager::GetInstance()->GetPlayerActor()->GetPosition().X > m_position.X + size.Width)
		{
			m_isAlive = false;
		}
	}
	
	void SquareActor::Draw(FeSpriteBatch spriteBatch)
	{
		spriteBatch.Draw(*m_pTexture,m_position,FeColor_White);
	}
}