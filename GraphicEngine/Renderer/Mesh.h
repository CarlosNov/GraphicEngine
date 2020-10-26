#pragma once

#include "config.h"
#include <assimp/Importer.hpp>
#include <assimp/scene.h>

namespace GraphicEngine
{
	class Mesh
	{
	public:
		Mesh() = default;
		Mesh(std::string fileName);
		Mesh(const Mesh& mesh);
		~Mesh();

		void Destroy();
		void Bind();
		void Unbind();
		
		// TODO: Move gets to VBO class and VAO class
		uint32_t GetPosVBO() { return m_PosVBO; }
		uint32_t GetColorVBO() { return m_ColorVBO; }
		uint32_t GetNormalVBO() { return m_NormalVBO; }
		uint32_t GetTexCoordVBO() { return m_TexCoordVBO; }
		uint32_t GetNumTriangleIndex() { return m_NumTriangleIndex; }

		std::vector<glm::vec3> GetVertices();
		std::vector<glm::vec4> GetColors();
		std::vector<glm::vec3> GetNormals();
		std::vector<glm::vec3> GetTangents();
		std::vector<glm::vec3> GetBitangents();
		std::vector<glm::vec2> GetUVs();
		std::vector<uint32_t>  GetTriangles();

		void SetVertices (std::vector<glm::vec3> vertices);
		void SetColors	(std::vector<glm::vec4> colors);
		void SetNormals (std::vector<glm::vec3> normals);
		void SetTangents (std::vector<glm::vec3> tangents);
		void SetBitangents (std::vector<glm::vec3> bitangents);
		void SetUVs (std::vector<glm::vec2> uvs);
		void SetTriangles (std::vector<uint32_t> triangles);

	protected:
		void ConvertMesh(aiMesh* aiMesh);

	private:
		uint32_t m_VertexArrayObject;

		uint32_t m_PosVBO;
		uint32_t m_ColorVBO;
		uint32_t m_NormalVBO;
		uint32_t m_TangentVBO;
		uint32_t m_BitangentVBO;
		uint32_t m_TexCoordVBO;
		uint32_t m_TriangleIndexVBO;

		std::vector<glm::vec3> m_VertexPos;
		std::vector<glm::vec4> m_VertexColor;
		std::vector<glm::vec3> m_VertexNormal;
		std::vector<glm::vec3> m_VertexTangent;
		std::vector<glm::vec3> m_VertexBitangent;
		std::vector<glm::vec2> m_VertexTexCoord;
		std::vector<uint32_t> m_TriangleIndex;

		uint32_t m_NumTriangleIndex;
	};
}

