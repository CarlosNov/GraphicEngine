#pragma once

#include "config.h"

namespace GraphicEngine
{
	class Texture
	{
	public:

		typedef enum {
			DIFFUSE = 0,
			NORMAL,
			EMISIVE,
			SPECULAR,
			BUMP,
			VERTEX,
			AUXILIAR
		} TextureType;

		/***********************************************************************************************/
		/*                              CONSTRUCTORS AND DESTRUCTORS                                   */
		/***********************************************************************************************/

		Texture(const char* fileName, TextureType typeoftexture);

		~Texture();

		unsigned int useTexture();

		TextureType getType();

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

