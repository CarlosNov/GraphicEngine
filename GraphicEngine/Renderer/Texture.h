#pragma once

#include "config.h"

namespace GraphicEngine
{
	class Texture
	{
	public:

		enum class TextureType {
			DIFFUSE = 0,
			NORMAL,
			EMISIVE,
			SPECULAR,
			BUMP,
			VERTEX,
			AUXILIAR
		};

		Texture(unsigned int texId, TextureType typeoftexture);
		Texture(const char* fileName, TextureType typeoftexture);

		~Texture();

		unsigned int UseTexture();

		TextureType GetType();
		int GetTypeID();

		unsigned char* LoadTexture(const char* fileName, unsigned int& w, unsigned int& h);

		char* LoadStringFromFile(const char* fileName, unsigned int& fileLen);

	protected:
		TextureType _typeoftexture;

		unsigned int _texId;

		unsigned int LoadTex(const char* fileName);
	};
}

