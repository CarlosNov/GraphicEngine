#pragma once

#include "config.h"
#include "Texture.h"

namespace GraphicEngine
{
	class Material
	{
	public:

		/***********************************************************************************************/
		/*                              CONSTRUCTORS AND DESTRUCTORS                                   */
		/***********************************************************************************************/

		Material(const char* vname, const char* fname);

		~Material();

		/***********************************************************************************************/
		/*										 METHODS											   */
		/***********************************************************************************************/

		void activateProgram();
		void deactivateProgram();

		void activateTexture(Texture* texture);

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

	private:

		/***********************************************************************************************/
		/*								    AUXILIAR METHODS										   */
		/***********************************************************************************************/

		// Loads a file in a character string.
		char* loadStringFromFile(const char* fileName, unsigned int& fileLen);

	};
}

