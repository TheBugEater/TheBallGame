#include "GamePlay.h"
#include "Globals.h"
#include "Managers/TextureManager.h"
#include <FeKeyBoard.h>

namespace Game
{
	int GamePlay::m_lives = 3;
	bool GamePlay::m_winFlag = false;

	GamePlay::GamePlay(void)
	{
	}


	GamePlay::~GamePlay(void)
	{
	}

	void GamePlay::Load()
	{
		m_pActorBall = (BallActor*)ActorManager::GetInstance()->CreateActor(Actors::ACTOR_CIRCLE);
		m_timeCounter = 0;
		FeSize size = Globals::GetInstance()->GetFrameSize();
		m_lastSpawnPos = (float)m_pActorBall->GetPosition().X + size.Width + 500;
		m_lastActorPos = 0;
		bgScroller = new ScrollingBG;
		bgScroller->Load();
		m_trackTime = 0.0f;
		m_font = FeFont("Arial",20);
		m_pGameOverTexture = nullptr;
		m_pGameWinTexture = nullptr;
		m_pGameOverTexture = Managers::TextureManager::GetInstance()->LoadTexture("Data/Game Over.png");
		m_pGameWinTexture = Managers::TextureManager::GetInstance()->LoadTexture("Data/Win.png");
		//3 Minutes
		m_playTime = 180;
	}

	void GamePlay::Update(float deltaTime)
	{
		if(m_lives > 0)
		{
			FeSize size = Globals::GetInstance()->GetFrameSize();
			bgScroller->Update();

			//To Stop Genearating random obstacles when the player has stopped
			if(m_lastActorPos != m_pActorBall->GetPosition().X)
			{
				//Randomly Generate Obstacles
				if(m_timeCounter >= 1)
				{
					int val = (int)Globals::GetInstance()->Random(0,5);

					//Avoid Overlaying Blocks
					if(m_lastSpawnPos > m_pActorBall->GetPosition().X + size.Width/2)
					{
						m_lastSpawnPos =  m_lastSpawnPos + size.Width/5;
					}
					else
					{
						m_lastSpawnPos =  m_pActorBall->GetPosition().X + size.Width;
					}

					if(val != 2 && val != 4)
					{
						//Randomly Generate Square Blocks
						int val = (int)Globals::GetInstance()->Random(0,5);
						for(int i=1; i<=val; i++)
						{
							SquareActor *actor = (SquareActor*)ActorManager::GetInstance()->CreateActor(Actors::ACTOR_SQUARE);

							actor->SetPosition(FeVector2((float)m_lastSpawnPos + actor->GetTexture()->Width,(float)size.Height - actor->GetTexture()->Height));
							m_lastSpawnPos = (float)m_lastSpawnPos + actor->GetTexture()->Width;
						}
					}
					else if(val != 2)
					{
						//Randomly Generate Triangle Blocks
						int val = (int)Globals::GetInstance()->Random(0,3);
						for(int i=1; i<=val; i++)
						{
							TriangleActor *actor = (TriangleActor*)ActorManager::GetInstance()->CreateActor(Actors::ACTOR_TRIANGLE);

							actor->SetPosition(FeVector2((float)m_lastSpawnPos + actor->GetTexture()->Width,(float)size.Height - actor->GetTexture()->Height));
							m_lastSpawnPos = (float)m_lastSpawnPos + actor->GetTexture()->Width;
						}
					}
					else
					{
						int val = (int)Globals::GetInstance()->Random(0,4);
						for(int i=1; i<=val; i++)
						{
							//To generate Triangles in Middle of Square
							if(i == 2)
							{
								TriangleActor *actor = (TriangleActor*)ActorManager::GetInstance()->CreateActor(Actors::ACTOR_TRIANGLE);

								actor->SetPosition(FeVector2((float)m_lastSpawnPos + actor->GetTexture()->Width,(float)size.Height - actor->GetTexture()->Height));
								m_lastSpawnPos = (float)m_lastSpawnPos + actor->GetTexture()->Width;
							}
							else
							{
								SquareActor *actor = (SquareActor*)ActorManager::GetInstance()->CreateActor(Actors::ACTOR_SQUARE);

								actor->SetPosition(FeVector2((float)m_lastSpawnPos + actor->GetTexture()->Width,(float)size.Height - actor->GetTexture()->Height));
								m_lastSpawnPos = (float)m_lastSpawnPos + actor->GetTexture()->Width;
							}
						}
					}

					m_timeCounter = 0;
				}

				//Update Last Position
				m_lastActorPos = m_pActorBall->GetPosition().X;
			}
			m_timeCounter+=deltaTime;

			//Update Time
			m_trackTime += deltaTime;

			if(m_playTime - m_trackTime <= 0)
			{
				m_winFlag = true;
			}
		}

		if(m_lives <= 0 || m_winFlag)
		{
			FeKeyBoard keyBoard;

			if(keyBoard.IsKeyDown(VK_RETURN))
			{
				exit(0);
			}
		}
	}
	   
	void GamePlay::ReduceLife()
	{
		m_lives--;
	}

	void GamePlay::Draw(FeSpriteBatch spriteBatch)
	{                       
		bgScroller->Draw(spriteBatch);

		char timeString[100];

		int time = m_playTime - (int)m_trackTime;
		if(time <= 0)
		{
			time = 0;
		}
		sprintf(timeString,"Time Left: %d seconds",time);
		m_font.DrawString(timeString,FeVector2(0,0),FeColor_White);
		          
		FeSize size = Globals::GetInstance()->GetFrameSize();

		if(m_lives <= 0)
		{
			spriteBatch.Draw(*m_pGameOverTexture,FeVector2(m_pActorBall->GetPosition().X - size.Width/2,0.0f),FeColor_White);
		}
		else if(m_winFlag == true)
		{
			spriteBatch.Draw(*m_pGameWinTexture,FeVector2(m_pActorBall->GetPosition().X - size.Width/2,0.0f),FeColor_White);       
		}
	}

	FeVector2 GamePlay::GetCamPos()
	{
		FeSize size = Globals::GetInstance()->GetFrameSize();

		if(m_pActorBall->GetPosition().X > size.Width/2)
			return FeVector2(m_pActorBall->GetPosition().X-size.Width/2,0.0f);
		else
			return FeVector2();
	}
};