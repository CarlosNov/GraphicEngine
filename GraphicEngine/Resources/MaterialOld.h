#pragma once

#include "config.h"
#include "Texture.h"

namespace GraphicEngine
{
	class MaterialOld
	{
	public:

		/***********************************************************************************************/
		/*                              CONSTRUCTORS AND DESTRUCTORS                                   */
		/***********************************************************************************************/

		MaterialOld(const char* vname, const char* fname);

		~MaterialOld();

		/***********************************************************************************************/
		/*										 METHODS											   */
		/***********************************************************************************************/

		void activateProgram();
		void deactivateProgram();

		void addTexture(Texture* texture);
		void activateTextures();
		
		void setModelViewProjMat(glm::mat4 modelView, glm::mat4 projMat);
		void setModelViewMat(glm::mat4 modelView);
		void setNormalMat(glm::mat4 normalMat);

		void setAttributes(unsigned int posVBO,
			unsigned int colorVBO = -1,
			unsigned int normalVBO = -1,
			unsigned int texCoordVBO = -1);

		GLuint loadShader(const char* fileName, GLenum type);



	protected:

		void initShader(const char* vname, const char* fname);
		void activateTexture(Texture* texture);

		unsigned int _VShader;
		unsigned int _FShader;
		unsigned int _program;

		// Uniform Variables
		int _uModelViewProjMat;
		int _uModelViewMat;
		int _uNormalMat;

		// Uniform Textures
		unsigned int _uColorTex;
		unsigned int _uEmiTex;
		unsigned int _uVertexTex;

		// Attributes
		int _inPos;
		int _inColor;
		int _inNormal;
		int _inTexCoord;

		std::map< int, Texture* > _textures;

	private:

		/***********************************************************************************************/
		/*								    AUXILIAR METHODS										   */
		/***********************************************************************************************/

		// Loads a file in a character string.
		char* loadStringFromFile(const char* fileName, unsigned int& fileLen);

	};
}

