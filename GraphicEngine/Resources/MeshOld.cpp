/*#include "Mesh.h"

#include "CUBE.h"
#include "PLANE.h"

#include <assimp/postprocess.h>


GraphicEngine::Mesh* GraphicEngine::Mesh::meshCube()
{
	return new Mesh(CUBE);
}

GraphicEngine::Mesh* GraphicEngine::Mesh::meshPlane()
{
	return new Mesh(PLANE);
}

GraphicEngine::Mesh* GraphicEngine::Mesh::meshSphere()
{
	return new Mesh(SPHERE);
}

GraphicEngine::Mesh* GraphicEngine::Mesh::meshAssimp(const char* fileName)
{
	return new Mesh(fileName);
}

GraphicEngine::Mesh::Mesh(BasicNodes basicNode)
{
	switch (basicNode)
	{
		case CUBE:
			initCube();
			break;

		case PLANE:
			initPlane();
			break;

		default:
			initCube();
			break;
	}
}

GraphicEngine::Mesh::Mesh(const char* fileName)
{
	_posVBO = -1;
	_colorVBO = -1;
	_normalVBO = -1;
	_tangentVBO = -1;
	_bitangentVBO = -1;
	_texCoordVBO = -1;
	_triangleIndexVBO = -1;

	Assimp::Importer* importer = new Assimp::Importer;

	const aiScene* m_aiScene = importer->ReadFile(fileName, aiProcess_CalcTangentSpace |
		aiProcess_Triangulate |
		aiProcess_JoinIdenticalVertices |
		aiProcess_SortByPType);

	if (m_aiScene->mNumMeshes > 0)
		convertMesh(m_aiScene->mMeshes[0]);
	else
		return;

	glGenVertexArrays(1, &_VertexArrayObject);
	glBindVertexArray(_VertexArrayObject);

	if (_VertexPos.size() > 0)
	{
		glGenBuffers(1, &_posVBO);
		glBindBuffer(GL_ARRAY_BUFFER, _posVBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * _VertexPos.size(),
			&(_VertexPos.front()), GL_STATIC_DRAW);
	}

	if (_VertexColor.size() > 0)
	{
		glGenBuffers(1, &_colorVBO);
		glBindBuffer(GL_ARRAY_BUFFER, _colorVBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec4) * _VertexColor.size(),
			&(_VertexColor.front()), GL_STATIC_DRAW);
	}

	if (_VertexNormal.size() > 0)
	{
		glGenBuffers(1, &_normalVBO);
		glBindBuffer(GL_ARRAY_BUFFER, _normalVBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * _VertexNormal.size(),
			&(_VertexNormal.front()), GL_STATIC_DRAW);
	}

	if (_VertexTangent.size() > 0)
	{
		glGenBuffers(1, &_tangentVBO);
		glBindBuffer(GL_ARRAY_BUFFER, _tangentVBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * _VertexTangent.size(),
			&(_VertexTangent.front()), GL_STATIC_DRAW);
	}

	if (_VertexBitangent.size() > 0)
	{
		glGenBuffers(1, &_bitangentVBO);
		glBindBuffer(GL_ARRAY_BUFFER, _bitangentVBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * _VertexBitangent.size(),
			&(_VertexBitangent.front()), GL_STATIC_DRAW);
	}

	if (_VertexTexCoord.size() > 0)
	{
		glGenBuffers(1, &_texCoordVBO);
		glBindBuffer(GL_ARRAY_BUFFER, _texCoordVBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec2) * _VertexTexCoord.size(),
			&(_VertexTexCoord.front()), GL_STATIC_DRAW);
	}

	glGenBuffers(1, &_triangleIndexVBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _triangleIndexVBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER,
		_TriangleIndex.size() * sizeof(unsigned int), &(_TriangleIndex.front()),
		GL_STATIC_DRAW);

	_numTriangleIndex = _TriangleIndex.size();
}

GraphicEngine::Mesh::~Mesh()
{

}

void GraphicEngine::Mesh::initCube()
{
	_posVBO = -1;
	_colorVBO = -1;
	_normalVBO = -1;
	_tangentVBO = -1;
	_texCoordVBO = -1;
	_triangleIndexVBO = -1;

	glGenVertexArrays(1, &_VertexArrayObject);
	glBindVertexArray(_VertexArrayObject);


	glGenBuffers(1, &_posVBO);
	glBindBuffer(GL_ARRAY_BUFFER, _posVBO);
	glBufferData(GL_ARRAY_BUFFER, cubeNVertex * sizeof(float) * 3,
		cubeVertexPos, GL_STATIC_DRAW);

	glGenBuffers(1, &_colorVBO);
	glBindBuffer(GL_ARRAY_BUFFER, _colorVBO);
	glBufferData(GL_ARRAY_BUFFER, cubeNVertex * sizeof(float) * 3,
		cubeVertexColor, GL_STATIC_DRAW);

	glGenBuffers(1, &_normalVBO);
	glBindBuffer(GL_ARRAY_BUFFER, _normalVBO);
	glBufferData(GL_ARRAY_BUFFER, cubeNVertex * sizeof(float) * 3,
		cubeVertexNormal, GL_STATIC_DRAW);

	glGenBuffers(1, &_texCoordVBO);
	glBindBuffer(GL_ARRAY_BUFFER, _texCoordVBO);
	glBufferData(GL_ARRAY_BUFFER, cubeNVertex * sizeof(float) * 2,
		cubeVertexTexCoord, GL_STATIC_DRAW);


	glGenBuffers(1, &_triangleIndexVBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _triangleIndexVBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER,
		cubeNTriangleIndex * sizeof(unsigned int) * 3, cubeTriangleIndex,
		GL_STATIC_DRAW);

	_numTriangleIndex = cubeNTriangleIndex * 3;
}

void GraphicEngine::Mesh::initPlane()
{
	_posVBO = -1;
	_colorVBO = -1;
	_normalVBO = -1;
	_tangentVBO = -1;
	_texCoordVBO = -1;
	_triangleIndexVBO = -1;

	glGenVertexArrays(1, &_VertexArrayObject);
	glBindVertexArray(_VertexArrayObject);


	glGenBuffers(1, &_posVBO);
	glBindBuffer(GL_ARRAY_BUFFER, _posVBO);
	glBufferData(GL_ARRAY_BUFFER, planeNVertex * sizeof(float) * 3,
		planeVertexPos, GL_STATIC_DRAW);

	_numTriangleIndex = -1;
}

void GraphicEngine::Mesh::renderMesh()
{
	glBindVertexArray(_VertexArrayObject);
	glDrawElements(GL_TRIANGLES, _numTriangleIndex, GL_UNSIGNED_INT, (void*)0);
}

void GraphicEngine::Mesh::convertMesh(aiMesh* aiMesh)
{
	if (aiMesh != NULL)
	{
		unsigned int vertex_size = aiMesh->mNumVertices;
		unsigned int triangles_size = aiMesh->mNumFaces;

		_VertexPos.resize(vertex_size);
		_VertexColor.resize(vertex_size);
		_VertexNormal.resize(vertex_size);
		_VertexTangent.resize(vertex_size);
		_VertexBitangent.resize(vertex_size);
		_VertexTexCoord.resize(vertex_size);
		_TriangleIndex.resize(3 * triangles_size);

		glm::vec3 pos;
		glm::vec4 col;
		glm::vec3 nor;
		glm::vec3 tan;
		glm::vec3 bitan;
		glm::vec2 tex;

		aiVector3D aiPos, aiNor, aiTan, aiBitan, aiTex;
		aiColor4D aiCol;
		for (unsigned int i = 0; i < vertex_size; ++i)
		{
			if (aiMesh->HasPositions())
			{
				aiPos = aiMesh->mVertices[i];
				pos = glm::vec3(aiPos.x, aiPos.y, aiPos.z);
				_VertexPos[i] = pos;
			}
				
			if (aiMesh->GetNumColorChannels() >= 1)
			{
				aiCol = aiMesh->mColors[0][i];
				col = glm::vec4(aiCol.r, aiCol.g, aiCol.b, aiCol.a);
				_VertexColor[i] = col;
			}
				
			if (aiMesh->HasNormals())
			{
				aiNor = aiMesh->mNormals[i];
				nor = glm::vec3(aiNor.x, aiNor.y, aiNor.z);
				_VertexNormal[i] = nor;
			}
				
			if (aiMesh->HasTangentsAndBitangents())
			{
				aiTan = aiMesh->mTangents[i];
				tan = glm::vec3(aiTan.x, aiTan.y, aiTan.z);
				_VertexTangent[i] = tan;

				aiBitan = aiMesh->mBitangents[i];
				bitan = glm::vec3(aiBitan.x, aiBitan.y, aiBitan.z);
				_VertexBitangent[i] = bitan;
			}
				
			if (aiMesh->HasTextureCoords(0))
			{
				aiTex = aiMesh->mTextureCoords[0][i];
				tex = glm::vec2(aiTex.x, aiTex.y);
				_VertexTexCoord[i] = tex;
			}		
		}

		aiFace aiFaces;
		for (unsigned int i = 0; i < triangles_size; ++i)
		{
			aiFaces = aiMesh->mFaces[i];

			_TriangleIndex[3 * i + 0] = aiFaces.mIndices[0];
			_TriangleIndex[3 * i + 1] = aiFaces.mIndices[1];
			_TriangleIndex[3 * i + 2] = aiFaces.mIndices[2];
		}

		_numTriangleIndex = _TriangleIndex.size();
	}
}

unsigned int GraphicEngine::Mesh::getVAO()
{
	return _VertexArrayObject;
}

unsigned int GraphicEngine::Mesh::getposVBO()
{
	return _posVBO;
}

unsigned int GraphicEngine::Mesh::getcolorVBO()
{
	return _colorVBO;
}

unsigned int GraphicEngine::Mesh::getnormalVBO()
{
	return _normalVBO;
}

unsigned int GraphicEngine::Mesh::gettexCoordVBO()
{
	return _texCoordVBO;
}
*/