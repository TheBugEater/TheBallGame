#pragma once
#include"FeTexture.h"
#include"FeVector2.h"
#include"FeSpriteBatch.h"
#include<list>
#include<time.h>

#define MAX_BATCH_BUFFER 1000

//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
//Particle Draw - Where All Particles are drawn in one lock to VertexBuffer
//////////////////////////////////////////////////////////////////////////////////////

class _ParticleDraw : FeBase
{
	IDirect3DDevice9 *particleDevice;
	IDirect3DVertexBuffer9 *VertexBuffer;
	IDirect3DVertexBuffer9 *VertexBufferRHW;
	IDirect3DIndexBuffer9 *IndexBuffer;
	VertexRHW *VerticesRHW;
	Vertex *Vertices;

	FeTexture BatchFeTexture;
	int VerticesCounter;

	void SetupVertices();
	FeVector2 Rotate(FeVector2 Position,float Angle);

	bool bParticleDestroyed;
public:
	_ParticleDraw();
	_ParticleDraw(bool val);
	~_ParticleDraw();
	void Init();
	void Unload();

	void Begin(FeTexture BatchFeTexture,FeSpriteBatch FeSpriteBatch);
	void End(FeSpriteBatch FeSpriteBatch);
	void Draw(FeVector2 Position,FeSpriteBatch FeSpriteBatch,float Rotation);
};

//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
//Particle - Class Declaration : Single Particle Definition
//////////////////////////////////////////////////////////////////////////////////////

class _Particle
{
	FeTexture ParticleFeTexture;
	int LifeTime;
	FeVector2 Velocity;
	FeVector2 Position;
	float Rotation;
	float Gravity;
	float RotationSpeed;

public:
	bool Alive;
	void Update();
	void Update(FeVector2 Pos);
	void Draw(_ParticleDraw* particleDraw,FeSpriteBatch FeSpriteBatch);
	_Particle(FeTexture FeTexture,int LifeTime,FeVector2 Position,FeVector2 Velocity,float RotationSpeed,float Gravity);
};


//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
//Particle System - Class Declaration : FeBase Class for Particle Generator
//////////////////////////////////////////////////////////////////////////////////////

class FeParticleSystem
{
	//List which holds all the Generated Particles in the System
	std::list<_Particle> Particles;
	std::list<_Particle>::iterator ParticleIterator;

	_ParticleDraw DrawParticles;	//Particle Draw Class to Draw Each Position with same FeTexture
	FeTexture Texture;				//Particle FeTexture
	FeVector2 Position;				//Particle Spawn Position
	FeVector2 MinVelocity;			//Minimum Velocity of Particles
	FeVector2 MaxVelocity;			//Maximum Velocity of Particles
	float RotationSpeed;			//Rotation Speed
	float Gravity;					//Gravity
	int LifeTime;					//LifeTime of Each Particle
	int NumberOfParticles;			//Number of Particles per Update
	float Random(float fMin,float fMax);
	void Create(FeVector2 Pos);
public:
	FeParticleSystem(void);
	FeParticleSystem(FeTexture particleFeTexture,FeVector2 Position,int NumberOfParticles,int LifeTime,FeVector2 MinVelocity,FeVector2 MaxVelocity,float RotationSpeed,float Gravity);

	void Update();
	void Update(FeVector2 Pos);
	void Draw(FeSpriteBatch feSpriteBatch);

	void Unload();

	~FeParticleSystem(void);
};

