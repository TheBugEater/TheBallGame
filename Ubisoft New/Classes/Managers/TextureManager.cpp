#include "TextureManager.h"
#include "Globals.h"

namespace Managers
{
	TextureManager* TextureManager::m_pInstance = nullptr;

	TextureManager::TextureManager(void)
	{
	}


	TextureManager::~TextureManager(void)
	{
	}

	TextureManager* TextureManager::GetInstance()
	{
		if(m_pInstance)
		{
			return m_pInstance;
		}

		m_pInstance = new TextureManager;
		return m_pInstance;
	}

	FeTexture* TextureManager::LoadTexture(string fileName)
	{
		TextureData *data;
		data = GetTextureData(fileName);

		if(data)
		{
			data->ReferenceCount++;
			return data->m_pTexture;
		}

		data = new TextureData;
		data->m_pTexture = new FeTexture(fileName);
		data->Name = fileName;
		data->ReferenceCount++;

		m_textureList.push_back(data);

		return data->m_pTexture;
	}

	TextureData* TextureManager::GetTextureData(string fileName)
	{
		vector<TextureData*>::iterator it;
		
		for(it = m_textureList.begin(); it != m_textureList.end(); it++)
		{
			TextureData* textureInfo;
			textureInfo = (*it);

			if(textureInfo->Name.compare(fileName) == 0)
			{
				return textureInfo;
			}
		}

		return NULL;
	}

	bool TextureManager::RemoveTexure(string fileName)
	{
		vector<TextureData*>::iterator it;
		
		for(it = m_textureList.begin(); it != m_textureList.end(); it++)
		{
			TextureData* textureInfo;
			textureInfo = (*it);

			if(textureInfo->Name.compare(fileName) == 0)
			{
				textureInfo->ReferenceCount--;
				if(textureInfo->ReferenceCount <= 0)
				{
					textureInfo->m_pTexture->Unload();
					m_textureList.erase(it);
					SAFE_DELETE_POINTER(textureInfo);
					return true;
				}
			}
		}

		return false;
	}

	void TextureManager::DeleteInstance()
	{
		m_pInstance->RemoveAll();
		SAFE_DELETE_POINTER(m_pInstance);
	}

	void TextureManager::RemoveAll()
	{
		vector<TextureData*>::iterator it;
		it = m_textureList.begin();

		while(it != m_textureList.end())
		{
			TextureData* textureInfo = (*it);
			textureInfo->m_pTexture->Unload();
			SAFE_DELETE_POINTER(textureInfo);
			it++;
		}

		m_textureList.clear();
	}
};