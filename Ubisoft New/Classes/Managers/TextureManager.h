#pragma once
#ifndef _TEXTURE_MANAGER_H_
#define _TEXTURE_MANAGER_H_
#include <FeEngine.h>
#include <vector>

using namespace std;

//When Ever a Texture is needed ask texture manger for it. So it won't load duplicated textures to memory
namespace Managers
{
	struct TextureData
	{
		FeTexture* m_pTexture;
		int ReferenceCount;
		string Name;

		TextureData()
		{
			m_pTexture = nullptr;
			ReferenceCount = 0;
		}
	};

	class TextureManager
	{
	public:
		static TextureManager* GetInstance();
		static void DeleteInstance();

		FeTexture* LoadTexture(string fileName);
		bool RemoveTexure(string fileName);
		void RemoveAll();

	private:
		//Texture Manager is Singleton
		TextureManager(void);
		~TextureManager(void);

		TextureData* GetTextureData(string fileName);
		static TextureManager* m_pInstance;

		vector<TextureData*> m_textureList;
	};
};
#endif