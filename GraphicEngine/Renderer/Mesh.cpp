#include "Mesh.h"

#include <assimp/postprocess.h>

namespace GraphicEngine
{
	Mesh::Mesh(std::string fileName)
	{
		m_VertexArrayObject = -1;
		m_PosVBO = -1;
		m_ColorVBO = -1;
		m_NormalVBO = -1;
		m_TangentVBO = -1;
		m_BitangentVBO = -1;
		m_TexCoordVBO = -1;
		m_TriangleIndexVBO = -1;

		Assimp::Importer* importer = new Assimp::Importer;
		const aiScene* m_aiScene = importer->ReadFile(fileName, aiProcess_CalcTangentSpace |
																aiProcess_Triangulate |
																aiProcess_JoinIdenticalVertices |
																aiProcess_SortByPType);
			
		// TODO: Log Assert Message
		if (m_aiScene->mNumMeshes > 0)
			ConvertMesh(m_aiScene->mMeshes[0]);
		else
			return;

		glGenVertexArrays(1, &m_VertexArrayObject);
		glBindVertexArray(m_VertexArrayObject);

		if (m_VertexPos.size() > 0)
		{
			glGenBuffers(1, &m_PosVBO);
			glBindBuffer(GL_ARRAY_BUFFER, m_PosVBO);
			glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * m_VertexPos.size(),
				&(m_VertexPos.front()), GL_STATIC_DRAW);
		}

		if (m_VertexColor.size() > 0)
		{
			glGenBuffers(1, &m_ColorVBO);
			glBindBuffer(GL_ARRAY_BUFFER, m_ColorVBO);
			glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec4) * m_VertexColor.size(),
				&(m_VertexColor.front()), GL_STATIC_DRAW);
		}

		if (m_VertexNormal.size() > 0)
		{
			glGenBuffers(1, &m_NormalVBO);
			glBindBuffer(GL_ARRAY_BUFFER, m_NormalVBO);
			glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * m_VertexNormal.size(),
				&(m_VertexNormal.front()), GL_STATIC_DRAW);
		}

		if (m_VertexTangent.size() > 0)
		{
			glGenBuffers(1, &m_TangentVBO);
			glBindBuffer(GL_ARRAY_BUFFER, m_TangentVBO);
			glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * m_VertexTangent.size(),
				&(m_VertexTangent.front()), GL_STATIC_DRAW);
		}

		if (m_VertexBitangent.size() > 0)
		{
			glGenBuffers(1, &m_BitangentVBO);
			glBindBuffer(GL_ARRAY_BUFFER, m_BitangentVBO);
			glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * m_VertexBitangent.size(),
				&(m_VertexBitangent.front()), GL_STATIC_DRAW);
		}

		if (m_VertexTexCoord.size() > 0)
		{
			glGenBuffers(1, &m_TexCoordVBO);
			glBindBuffer(GL_ARRAY_BUFFER, m_TexCoordVBO);
			glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec2) * m_VertexTexCoord.size(),
				&(m_VertexTexCoord.front()), GL_STATIC_DRAW);
		}

		glGenBuffers(1, &m_TriangleIndexVBO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_TriangleIndexVBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER,m_TriangleIndex.size() * sizeof(unsigned int), &(m_TriangleIndex.front()), GL_STATIC_DRAW);

		m_NumTriangleIndex = m_TriangleIndex.size();
	}

	Mesh::Mesh(const Mesh& mesh)
	{
		m_VertexArrayObject = mesh.m_VertexArrayObject;

		m_PosVBO = mesh.m_PosVBO;
		m_ColorVBO = mesh.m_ColorVBO;
		m_NormalVBO = mesh.m_NormalVBO;
		m_TangentVBO = mesh.m_TangentVBO;
		m_BitangentVBO = mesh.m_BitangentVBO;
		m_TexCoordVBO = mesh.m_TexCoordVBO;
		m_TriangleIndexVBO = mesh.m_TriangleIndexVBO;

		m_VertexPos = mesh.m_VertexPos;
		m_VertexColor = mesh.m_VertexColor;
		m_VertexNormal = mesh.m_VertexNormal;
		m_VertexTangent = mesh.m_VertexTangent;
		m_VertexBitangent = mesh.m_VertexBitangent;
		m_VertexTexCoord = mesh.m_VertexTexCoord;
		m_TriangleIndex = mesh.m_TriangleIndex;

		m_NumTriangleIndex = mesh.m_NumTriangleIndex;
	}

	Mesh::~Mesh()
	{
	}

	void Mesh::Destroy()
	{
		glBindVertexArray(m_VertexArrayObject);

		if (m_VertexPos.size() > 0)
		{
			glBindBuffer(GL_ARRAY_BUFFER, m_PosVBO);
			glDeleteBuffers(1, &m_PosVBO);
		}

		if (m_VertexColor.size() > 0)
		{
			glBindBuffer(GL_ARRAY_BUFFER, m_ColorVBO);
			glDeleteBuffers(1, &m_ColorVBO);
		}

		if (m_VertexNormal.size() > 0)
		{
			glBindBuffer(GL_ARRAY_BUFFER, m_NormalVBO);
			glDeleteBuffers(1, &m_NormalVBO);
		}

		if (m_VertexTangent.size() > 0)
		{
			glBindBuffer(GL_ARRAY_BUFFER, m_TangentVBO);
			glDeleteBuffers(1, &m_TangentVBO);
		}

		if (m_VertexBitangent.size() > 0)
		{
			glBindBuffer(GL_ARRAY_BUFFER, m_BitangentVBO);
			glDeleteBuffers(1, &m_BitangentVBO);
		}

		if (m_VertexTexCoord.size() > 0)
		{
			glBindBuffer(GL_ARRAY_BUFFER, m_TexCoordVBO);
			glDeleteBuffers(1, &m_TexCoordVBO);
		}

		glDeleteBuffers(1, &m_TriangleIndexVBO);

		glBindVertexArray(m_VertexArrayObject);
		glDeleteVertexArrays(1, &m_VertexArrayObject);
	}

	void Mesh::Bind()
	{
		glBindVertexArray(m_VertexArrayObject);
	}

	void Mesh::Unbind()
	{
		glBindVertexArray(0);
	}

	std::vector<glm::vec3> Mesh::GetVertices()
	{
		return m_VertexPos;
	}

	std::vector<glm::vec4> Mesh::GetColors()
	{
		return m_VertexColor;
	}

	std::vector<glm::vec3> Mesh::GetNormals()
	{
		return m_VertexNormal;
	}

	std::vector<glm::vec3> Mesh::GetTangents()
	{
		return m_VertexTangent;
	}

	std::vector<glm::vec3> Mesh::GetBitangents()
	{
		return m_VertexBitangent;
	}

	std::vector<glm::vec2> Mesh::GetUVs()
	{
		return m_VertexTexCoord;
	}

	std::vector<uint32_t>  Mesh::GetTriangles()
	{
		return m_TriangleIndex;
	}

	void Mesh::SetVertices(std::vector<glm::vec3> vertices)
	{
		m_VertexPos = vertices;
	}

	void Mesh::SetColors(std::vector<glm::vec4> colors)
	{
		m_VertexColor = colors;
	}

	void Mesh::SetNormals(std::vector<glm::vec3> normals)
	{
		m_VertexNormal = normals;
	}

	void Mesh::SetTangents(std::vector<glm::vec3> tangents)
	{
		m_VertexTangent = tangents;
	}

	void Mesh::SetBitangents(std::vector<glm::vec3> bitangents)
	{
		m_VertexBitangent = bitangents;
	}

	void Mesh::SetUVs(std::vector<glm::vec2> uvs)
	{
		m_VertexTexCoord = uvs;
	}

	void Mesh::SetTriangles(std::vector<uint32_t> triangles)
	{
		m_TriangleIndex = triangles;
	}

	void Mesh::ConvertMesh(aiMesh* aiMesh)
	{
		if (aiMesh != NULL)
		{
			uint32_t vertexSize = aiMesh->mNumVertices;
			uint32_t trianglesSize = aiMesh->mNumFaces;

			m_VertexPos.resize(vertexSize);
			m_VertexColor.resize(vertexSize);
			m_VertexNormal.resize(vertexSize);
			m_VertexTangent.resize(vertexSize);
			m_VertexBitangent.resize(vertexSize);
			m_VertexTexCoord.resize(vertexSize);
			m_TriangleIndex.resize(3 * trianglesSize);

			aiVector3D aiPos, aiNor, aiTan, aiBitan, aiTex;
			aiColor4D aiCol;

			for (unsigned int i = 0; i < vertexSize; ++i)
			{
				if (aiMesh->HasPositions())
				{
					aiPos = aiMesh->mVertices[i];
					m_VertexPos[i] = glm::vec3(aiPos.x, aiPos.y, aiPos.z);
				}

				if (aiMesh->GetNumColorChannels() >= 1)
				{
					aiCol = aiMesh->mColors[0][i];
					m_VertexColor[i] = glm::vec4(aiCol.r, aiCol.g, aiCol.b, aiCol.a);
				}

				if (aiMesh->HasNormals())
				{
					aiNor = aiMesh->mNormals[i];
					m_VertexNormal[i] = glm::vec3(aiNor.x, aiNor.y, aiNor.z);;
				}

				if (aiMesh->HasTangentsAndBitangents())
				{
					aiTan = aiMesh->mTangents[i];
					m_VertexTangent[i] = glm::vec3(aiTan.x, aiTan.y, aiTan.z);

					aiBitan = aiMesh->mBitangents[i];
					m_VertexBitangent[i] = glm::vec3(aiBitan.x, aiBitan.y, aiBitan.z);
				}

				if (aiMesh->HasTextureCoords(0))
				{
					aiTex = aiMesh->mTextureCoords[0][i];
					m_VertexTexCoord[i] = glm::vec2(aiTex.x, aiTex.y);
				}
			}

			aiFace aiFaces;
			for (unsigned int i = 0; i < trianglesSize; ++i)
			{
				aiFaces = aiMesh->mFaces[i];

				m_TriangleIndex[3 * i + 0] = aiFaces.mIndices[0];
				m_TriangleIndex[3 * i + 1] = aiFaces.mIndices[1];
				m_TriangleIndex[3 * i + 2] = aiFaces.mIndices[2];
			}

			m_NumTriangleIndex = m_TriangleIndex.size();
		}
	}
}