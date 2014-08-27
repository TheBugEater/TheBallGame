#pragma once
#ifndef _PHYSICS_WORLD_H_
#define _PHYSICS_WORLD_H_
#include "Actors/BaseActor.h"
#include <vector>

using namespace std;
using namespace Actors;

//This is where Real Collision happes if something is collided then that object's OnCollision Function will be Called
namespace Physics
{
	//There is only one instance of PhysicsWorld so make it singleton
	class PhysicsWorld
	{
	public:
		static PhysicsWorld* GetInstance();
		static void DeleteInstance();

		void AddBody(BaseActor* pActor);
		void Update();
		void RemoveBody(BaseActor* pActor);

	private:
		PhysicsWorld(void);
		~PhysicsWorld(void);
		void CheckSquareCircleCollision(BaseActor *pSquare,BaseActor *pCircle);
		void CheckTriangleCircleCollision(BaseActor *pTriangle,BaseActor *pCircle);

		bool CircleLineCollision(FeVector2 Vertex1,FeVector2 Vertex2,FeVector2 Center,float Radius);

		static PhysicsWorld* m_pInstance;
		vector<BaseActor*> m_actors;
	};
};
#endif