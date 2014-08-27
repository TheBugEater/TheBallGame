#pragma once
#ifndef _SCROLLING_BG_H_
#define _SCROLLING_BG_H_
#include <FeSpriteBatch.h>

//Scrolling BG loops 2 bg's to do infinite scrolling
namespace Game
{
	class ScrollingBG
	{
	public:
		ScrollingBG(void);
		~ScrollingBG(void);

		void Load();
		void Update();
		void Draw(FeSpriteBatch spriteBatch);

	private:
		FeTexture *m_pBg;
		FeVector2 m_firstVector;
		FeVector2 m_secondVector;
	};
};
#endif