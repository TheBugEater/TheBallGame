#include "TriangleActor.h"
#include "Managers/TextureManager.h"
#include <FeSize.h>
#include "Globals.h"
#include "Managers/ActorManager.h"

namespace Actors
{
	TriangleActor::TriangleActor(void)
	{
	}


	TriangleActor::~TriangleActor(void)
	{
	}

	void TriangleActor::CreateActor()
	{
		m_type = Actors::ACTOR_TRIANGLE;
		m_pTexture = Managers::TextureManager::GetInstance()->LoadTexture("Data/Triangle.png");
	}
	
	void TriangleActor::OnCollision(BaseActor *Actor)
	{
	}
	
	void TriangleActor::Update(float deltaTime)
	{
		FeSize size = Globals::GetInstance()->GetFrameSize();
		
		if(Managers::ActorManager::GetInstance()->GetPlayerActor()->GetPosition().X > m_position.X + size.Width)
		{
			m_isAlive = false;
		}
	}
	
	void TriangleActor::Draw(FeSpriteBatch spriteBatch)
	{
		spriteBatch.Draw(*m_pTexture,m_position,FeColor_White);
	}
}