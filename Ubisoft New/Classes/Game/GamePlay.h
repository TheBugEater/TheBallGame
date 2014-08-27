#pragma once
#ifndef _GAME_PLAY_H_
#define _GAME_PLAY_H_
#include <FeSpriteBatch.h>
#include "Managers/ActorManager.h"
#include "Actors/SquareActor.h"
#include "Actors/BallActor.h"
#include "Actors/TriangleActor.h"
#include "ScrollingBG.h"
#include <FeFont.h>

using namespace Actors;
using namespace Managers;

namespace Game
{
	class GamePlay
	{
	public:
		GamePlay(void);
		~GamePlay(void);

		void Load();
		void Update(float deletaTime);

		void Draw(FeSpriteBatch spriteBatch);
		 
		FeVector2 GetCamPos();
		
		static void ReduceLife();
		static int GetLives() { return m_lives; }
		static bool HasWon() { return m_winFlag; }

	private:
		BallActor *m_pActorBall;
		float m_timeCounter;
		float m_lastSpawnPos;
		float m_lastActorPos;
		ScrollingBG *bgScroller;
		FeTexture *m_pGameOverTexture;            
		FeTexture *m_pGameWinTexture;

		float m_trackTime;
		static bool m_winFlag;
		static int m_lives;
		int m_playTime;
		FeFont m_font;
	};
};
#endif