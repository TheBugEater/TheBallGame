#pragma once
#ifndef _ACTOR_MANAGER_H_
#define _ACTOR_MANAGER_H_
#include "Actors/BaseActor.h"
#include <vector>
#include <FeSpriteBatch.h>

using namespace std;
using namespace Actors;

namespace Managers
{
	class ActorManager
	{
	public:
		static ActorManager* GetInstance();
		static void DeleteInstance();

		BaseActor* CreateActor(Types type);

		void Update(float deltaTime);
		void Draw(FeSpriteBatch spriteBatch);
		void RemoveAll();

		BaseActor* GetPlayerActor() { return m_playerActor; }

	private:
		//Actor Manager is Singleton
		ActorManager(void);
		~ActorManager(void);

		vector<BaseActor*> m_listActors;
		static ActorManager* m_pInstance;
		BaseActor *m_playerActor;
	};
}
#endif