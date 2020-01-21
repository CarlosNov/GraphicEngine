#pragma once

#include "config.h"
#include "Texture.h"

namespace GraphicEngine
{
	class Material
	{
	public:

		typedef enum {
			FORDWARD,
			POSTPROCCESS
		} ShaderType;

		/***********************************************************************************************/
		/*                              CONSTRUCTORS AND DESTRUCTORS                                   */
		/***********************************************************************************************/

		Material(ShaderType typeofshader, const char* vname, const char* fname);

		~Material();

		/***********************************************************************************************/
		/*										 METHODS											   */
		/***********************************************************************************************/

		void activateProgram(ShaderType shaderType);
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

		ShaderType _typeofshader;

		void initShaderFw(const char* vname, const char* fname);
		void initShaderPP(const char* vname, const char* fname);

		unsigned int _forwardVShader;
		unsigned int _forwardFShader;
		unsigned int _forwardProgram;
		unsigned int _postProccesVShader;
		unsigned int _postProccesFShader;
		unsigned int _postProccesProgram;

		// Uniform Variables
		int _uModelViewProjMat;
		int _uModelViewMat;
		int _uNormalMat;

		// Uniform Textures
		int _uColorTex;
		int _uEmiTex;
		unsigned int _uColorTexPP;

		// Attributes
		int _inPos;
		int _inColor;
		int _inNormal;
		int _inTexCoord;
		int _inPosPP;

	private:

		/***********************************************************************************************/
		/*								    AUXILIAR METHODS										   */
		/***********************************************************************************************/

		// Loads a file in a character string.
		char* loadStringFromFile(const char* fileName, unsigned int& fileLen);

	};
}

