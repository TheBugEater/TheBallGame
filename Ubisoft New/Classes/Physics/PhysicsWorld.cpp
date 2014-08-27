#include "PhysicsWorld.h"
#include "Globals.h"
#include "Managers/ActorManager.h"
#include <FeRectangle.h>

namespace Physics
{
	PhysicsWorld* PhysicsWorld::m_pInstance = nullptr;

	PhysicsWorld::PhysicsWorld(void)
	{
	}


	PhysicsWorld::~PhysicsWorld(void)
	{
	}

	PhysicsWorld* PhysicsWorld::GetInstance()
	{
		if(m_pInstance)
		{
			return m_pInstance;
		}

		m_pInstance = new PhysicsWorld;
		return m_pInstance;
	}
	
	void PhysicsWorld::DeleteInstance()
	{
		SAFE_DELETE_POINTER(m_pInstance);
	}

	void PhysicsWorld::AddBody(BaseActor* pActor)
	{
		m_actors.push_back(pActor);
	}

	void PhysicsWorld::Update()
	{
		BaseActor *playerActor = Managers::ActorManager::GetInstance()->GetPlayerActor();

		vector<BaseActor*>::iterator it;

		it = m_actors.begin();

		while(it != m_actors.end())
		{
			BaseActor* actor = (*it);

			actor->SetBlockedSide(Actors::NONE_BLOCKED);

			if(actor->GetActorType() == Actors::ACTOR_SQUARE)
			{
				CheckSquareCircleCollision(actor,playerActor);
			}
			else if(actor->GetActorType() == Actors::ACTOR_TRIANGLE)
			{
				CheckTriangleCircleCollision(actor,playerActor);
			}

			it++;
		};
	}

	void PhysicsWorld::RemoveBody(BaseActor *pActor)
	{
		vector<BaseActor*>::iterator it;

		it = m_actors.begin();

		while(it != m_actors.end())
		{
			BaseActor* actor = (*it);

			if(actor == pActor)
			{
				m_actors.erase(it);
				return;
			}

			it++;
		};
	}

	void PhysicsWorld::CheckSquareCircleCollision(BaseActor *pSquare,BaseActor *pCircle)
	{
		float Radius = (float)pCircle->GetTexture()->Width/2;

		FeRectangle Rect1 = FeRectangle((int)pCircle->GetPosition().X - (int)Radius,(int)pCircle->GetPosition().Y - (int)Radius,pCircle->GetTexture()->Width,pCircle->GetTexture()->Height);
		FeRectangle Rect2 = FeRectangle((int)pSquare->GetPosition().X,(int)pSquare->GetPosition().Y,pSquare->GetTexture()->Width,pSquare->GetTexture()->Height);

		
		if(Rect1.Intersect(Rect2))
		{
			//Check Right Collision
			if((Rect1.X + Rect1.Width >= pSquare->GetPosition().X - 2) && (Rect1.Y + Rect1.Height > pSquare->GetPosition().Y + 5))
			{
  				pCircle->SetPosition(FeVector2(pSquare->GetPosition().X - Radius,pCircle->GetPosition().Y));
				pCircle->SetBlockedSide(Actors::RIGHT_BLOCKED);
				pCircle->OnCollision(pSquare);
			}

			//Check Bottom Collision
			else if(Rect1.Y + Rect1.Height >= pSquare->GetPosition().Y)
			{
				pCircle->SetPosition(FeVector2(pCircle->GetPosition().X,pSquare->GetPosition().Y - Radius));
				pCircle->SetBlockedSide(Actors::BOTTOM_BLOCKED);
				pCircle->OnCollision(pSquare);
			}
		}
	}

	void PhysicsWorld::CheckTriangleCircleCollision(BaseActor *pTriangle,BaseActor *pCircle)
	{
		float Radius = (float)pCircle->GetTexture()->Width/2;
		FeRectangle Rect1 = FeRectangle((int)pCircle->GetPosition().X - (int)Radius, (int)pCircle->GetPosition().Y - (int)Radius, pCircle->GetTexture()->Width,pCircle->GetTexture()->Height);
		FeRectangle Rect2 = FeRectangle((int)pTriangle->GetPosition().X, (int)pTriangle->GetPosition().Y, pTriangle->GetTexture()->Width, pTriangle->GetTexture()->Height);

		if(Rect1.Intersect(Rect2))
		{
			FeVector2 Vertex1 = FeVector2(0,pTriangle->GetTexture()->Height);
			FeVector2 Vertex2 = FeVector2(pTriangle->GetTexture()->Width,pTriangle->GetTexture()->Height);
			FeVector2 Vertex3 = FeVector2(pTriangle->GetTexture()->Width/2,0);
			Vertex1 += pTriangle->GetPosition();
			Vertex2 += pTriangle->GetPosition();
			Vertex3 += pTriangle->GetPosition();

			bool Flag = false;
			if(CircleLineCollision(Vertex1,Vertex2,pCircle->GetPosition(),Radius))
			{
  				Flag = true;
			}
			if(CircleLineCollision(Vertex2,Vertex3,pCircle->GetPosition(),Radius))
			{
  				Flag = true;
			}

			if(Flag)
			{
			pCircle->OnCollision(pTriangle);
			pTriangle->OnCollision(pCircle);
			}
		}
	}

	bool PhysicsWorld::CircleLineCollision(FeVector2 Vertex1,FeVector2 Vertex2,FeVector2 Center,float Radius)
	{
		float dx = Vertex2.X - Vertex1.X;
		float dy = Vertex2.Y - Vertex1.Y;

		float a = dx * dx + dy * dy;
		float b = 2 * (dx * (Vertex1.X - Center.X) + dy * (Vertex1.Y - Center.Y));
		float c = Center.X * Center.X + Center.Y * Center.Y;
		c += Vertex1.X * Vertex1.X + Vertex1.Y * Vertex1.Y;
		c -= 2 * (Center.X * Vertex1.X + Center.Y * Vertex1.Y);
		c -= Radius * Radius;

		float bb4ac = b * b - 4 * a * c;

		if(bb4ac < 0)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
};

