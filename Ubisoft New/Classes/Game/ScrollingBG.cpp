#include "ScrollingBG.h"
#include "Managers\TextureManager.h"
#include "Managers\ActorManager.h"
#include "Globals.h"

namespace Game
{
	ScrollingBG::ScrollingBG(void)
	{
	}


	ScrollingBG::~ScrollingBG(void)
	{
	}

	void ScrollingBG::Load()
	{
		m_pBg = Managers::TextureManager::GetInstance()->LoadTexture("Data/BG.png");
		m_firstVector = FeVector2(0,0);
		m_secondVector - FeVector2(Globals::GetInstance()->GetFrameSize().Width,0);
	}

	void ScrollingBG::Update()
	{
		Actors::BaseActor *actor = Managers::ActorManager::GetInstance()->GetPlayerActor();
		FeSize size = Globals::GetInstance()->GetFrameSize();

		int number = (int)( actor->GetPosition().X - size.Width/2)/size.Width;
			
		m_firstVector = FeVector2(number * size.Width,0);
		m_secondVector = FeVector2((number+1) * size.Width,0);
	}

	void ScrollingBG::Draw(FeSpriteBatch spriteBatch)
	{
		spriteBatch.Draw(*m_pBg,m_firstVector,FeColor_White);
		spriteBatch.Draw(*m_pBg,m_secondVector,FeColor_White);
	}
};