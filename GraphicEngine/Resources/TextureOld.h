#pragma once

#include "config.h"

namespace GraphicEngine
{
	class TextureOld
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

		/***********************************************************************************************/
		/*                              CONSTRUCTORS AND DESTRUCTORS                                   */
		/***********************************************************************************************/

		TextureOld(unsigned int texId, TextureType typeoftexture);
		TextureOld(const char* fileName, TextureType typeoftexture);

		~TextureOld();

		unsigned int useTexture();

		TextureType getType();
		int getTypeID();

		/***********************************************************************************************/
		/*										 METHODS											   */

		/***********************************************************************************************/
		unsigned char* loadTexture(const char* fileName, unsigned int& w, unsigned int& h);

		//Carga un fichero en una cadena de caracteres
		char* loadStringFromFile(const char* fileName, unsigned int& fileLen);

	protected:
		TextureType _typeoftexture;

		unsigned int _texId;

		unsigned int loadTex(const char* fileName);
	};
}

