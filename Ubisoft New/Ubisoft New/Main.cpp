#include"FeEngine.h"
#include"FeGame.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nCmdShow)
{
	FeGamePlay *GM;

	GM = new FeGame(); //Do not Delete GM, It is automatically deleted in Framework
	FeEngine FM(hInstance,GM);
}