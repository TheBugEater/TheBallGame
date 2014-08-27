#include "ActorManager.h"
#include "Actors/SquareActor.h"
#include "Actors/BallActor.h"
#include "Actors/TriangleActor.h"
#include "Globals.h"
#include "Physics/PhysicsWorld.h"

using namespace Physics;
namespace Managers
{
	ActorManager* ActorManager::m_pInstance = nullptr;

	ActorManager::ActorManager(void)
		: m_playerActor(nullptr)
	{
	}


	ActorManager::~ActorManager(void)
	{
	}

	ActorManager* ActorManager::GetInstance()
	{
		if(m_pInstance)
		{
			return m_pInstance;
		}

		m_pInstance = new ActorManager;
		return m_pInstance;
	}

	BaseActor* ActorManager::CreateActor(Types type)
	{
		PhysicsWorld *physicsWorld  = Physics::PhysicsWorld::GetInstance();
		switch(type)
		{
		case Actors::ACTOR_CIRCLE:
			{
				//Player Actor is Created only once
				if(!m_playerActor)
				{
				m_playerActor = new BallActor;
				m_listActors.push_back(m_playerActor);
				m_playerActor->CreateActor();
				physicsWorld->AddBody(m_playerActor);
				}
				return m_playerActor;
			}
			break;
		case Actors::ACTOR_SQUARE:
			{
				SquareActor *actor = new SquareActor;
				m_listActors.push_back(actor);
				actor->CreateActor();
				physicsWorld->AddBody(actor);
				return actor;
			}
		case Actors::ACTOR_TRIANGLE:
			{
				TriangleActor *actor = new TriangleActor;
				m_listActors.push_back(actor);
				actor->CreateActor();
				physicsWorld->AddBody(actor);
				return actor;
			}
			break;
		}

		return NULL;
	}

	void ActorManager::Update(float deltaTime)
	{
		PhysicsWorld *physicsWorld  = Physics::PhysicsWorld::GetInstance();

		vector<BaseActor*>::iterator it;
		it = m_listActors.begin();
		while(it != m_listActors.end())
		{
			BaseActor *actor = (*it);

			if(actor->IsAlive())
			{
				actor->Update(deltaTime);
				it++;
			}
			else
			{
				it = m_listActors.erase(it);
				physicsWorld->RemoveBody(actor);
			}
		}

		//physicsWorld->Update();
	}

	void ActorManager::Draw(FeSpriteBatch spriteBatch)
	{
		vector<BaseActor*>::iterator it;
		
		for(it = m_listActors.begin(); it !=  m_listActors.end(); it++)
		{
			BaseActor *actor = (*it);
			actor->Draw(spriteBatch);
		}
	}

	void ActorManager::DeleteInstance()
	{
		m_pInstance->RemoveAll();
		SAFE_DELETE_POINTER(m_pInstance);
		Physics::PhysicsWorld::DeleteInstance();
	}

	void ActorManager::RemoveAll()
	{
		PhysicsWorld *physicsWorld  = Physics::PhysicsWorld::GetInstance();
		vector<BaseActor*>::iterator it;
		it = m_listActors.begin();
		while(it != m_listActors.end())
		{
			BaseActor* baseActor = (*it);
			SAFE_DELETE_POINTER(baseActor);
			it = m_listActors.erase(it);
			physicsWorld->RemoveBody(baseActor);
		}
	}
}