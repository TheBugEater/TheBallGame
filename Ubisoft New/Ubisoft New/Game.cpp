#include <FeGame.h>
#include <FeSpriteBatch.h>
#include "Game\GamePlay.h"
#include "Managers\ActorManager.h"
#include "Managers\TextureManager.h"
#include <FeSize.h>
#include "Globals.h"
#include "Physics\PhysicsWorld.h"

FeSpriteBatch spriteBatch;
Game::GamePlay *gamePlay;

void FeGame::Initialize(FeGamePlay *Game)
{
	Game->BackBufferWidth = 1280;
	Game->BackBufferHeight = 720;
	Game->SetApplicationName("Ball Game Test - Ubisoft");
	//Game->FullScreen = true;
}

void FeGame::LoadContent(FeGraphicDevice graphicDevice)
{
	spriteBatch = FeSpriteBatch(graphicDevice);
	gamePlay = new Game::GamePlay;

	Globals::GetInstance()->SetFrameSize(FeSize(this->BackBufferWidth,this->BackBufferHeight));

	gamePlay->Load();
}

void FeGame::Update(FeGameTime gameTime)
{
	float deltaTime = 0;
	deltaTime = (float)gameTime.ElapsedGameTime()/1000;

	if(Game::GamePlay::GetLives() > 0 && !Game::GamePlay::HasWon())
	{
		Managers::ActorManager::GetInstance()->Update(deltaTime);
	}

	gamePlay->Update(deltaTime);
	Physics::PhysicsWorld::GetInstance()->Update();
}

void FeGame::Unload()
{
	SAFE_DELETE_POINTER(gamePlay);
	Managers::TextureManager::GetInstance()->DeleteInstance();
	Managers::ActorManager::GetInstance()->DeleteInstance();
	spriteBatch.Unload();
}

void FeGame::Draw()
{
	//////////////////////////////////////////////////////////////////////////////////////////
	//Will be Drawn in WorldSpace RHW is off
	spriteBatch.Begin(gamePlay->GetCamPos());

	gamePlay->Draw(spriteBatch);
	Managers::ActorManager::GetInstance()->Draw(spriteBatch);

	spriteBatch.End();
	//////////////////////////////////////////////////////////////////////////////////////////
	
	Actors::BaseActor *m_pActorBall = Managers::ActorManager::GetInstance()->GetPlayerActor();

	//////////////////////////////////////////////////////////////////////////////////////////
	//Will be Drawn in Screen Space RHW is on
	spriteBatch.Begin();

	//Display Left Lives 
	FeSize size = Globals::GetInstance()->GetFrameSize();
	FeRectangle Rect = FeRectangle(size.Width - 100,0,50,50);

	for(int i=1;i<=Game::GamePlay::GetLives();i++)
	{
		spriteBatch.Draw(*m_pActorBall->GetTexture(),FeRectangle(size.Width - i * Rect.Width,Rect.Y,Rect.Width,Rect.Height),FeColor_White);
	}

	spriteBatch.End();
}