/*#pragma once

#include "config.h"
#include <assimp/Importer.hpp>
#include <assimp/scene.h>

namespace GraphicEngine
{
	class Mesh
	{
	public:

		typedef enum 
		{ 
			CUBE, 
			PLANE,
			SPHERE 
		} BasicNodes;

		Mesh(BasicNodes basicNodes);

		Mesh(const char *fileName);

		~Mesh();

		static Mesh* meshCube();
		static Mesh* meshPlane();
		static Mesh* meshSphere();
		static Mesh* meshAssimp(const char* fileName);

		void renderMesh();
		void convertMesh(aiMesh* aiMesh);

		unsigned int getVAO();
		unsigned int getposVBO();
		unsigned int getcolorVBO();
		unsigned int getnormalVBO();
		unsigned int gettexCoordVBO();

	private:
		// Declaration of the VAO.
		unsigned int _VertexArrayObject;

		// Declaration of the Basics' VBO.
		unsigned int _posVBO;
		unsigned int _colorVBO;
		unsigned int _normalVBO;
		unsigned int _tangentVBO;
		unsigned int _bitangentVBO;
		unsigned int _texCoordVBO;
		unsigned int _triangleIndexVBO;

		// Vectors

		std::vector<glm::vec3> _VertexPos;
		std::vector<glm::vec4> _VertexColor;
		std::vector<glm::vec3> _VertexNormal;
		std::vector<glm::vec3> _VertexTangent;
		std::vector<glm::vec3> _VertexBitangent;
		std::vector<glm::vec2> _VertexTexCoord;
		std::vector<unsigned int> _TriangleIndex;

		unsigned int _numTriangleIndex;

		void initCube();
		void initPlane();
	};
}
*/
