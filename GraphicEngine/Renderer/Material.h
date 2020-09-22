#pragma once

#include "config.h"
#include "Texture.h"

namespace GraphicEngine
{
	class Material
	{
	public:
		Material() = default;
		Material(const char* vname, const char* fname);
		~Material() = default;

		void ActivateProgram();
		void DeactivateProgram();

		void AddTexture(Texture* texture);
		void ActivateTextures();
		
		void SetModelViewProjMat(glm::mat4 modelViewProj);
		void SetModelViewMat(glm::mat4 modelView);
		void SetNormalMat(glm::mat4 normalMat);

		void SetAttributes(unsigned int posVBO,
			unsigned int colorVBO = -1,
			unsigned int normalVBO = -1,
			unsigned int texCoordVBO = -1);

		GLuint LoadShader(const char* fileName, GLenum type);



	protected:

		void InitShader(const char* vname, const char* fname);
		void ActivateTexture(Texture* texture);

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

		char* LoadStringFromFile(const char* fileName, unsigned int& fileLen);

	};
}

