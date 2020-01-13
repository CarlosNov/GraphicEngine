#pragma once
class Mesh
{
public:
	Mesh();
	~Mesh();

private:
	// Declaration of the VAO.
	unsigned int _VertexArrayObject;

	// Declaration of the Basics' VBO.
	unsigned int _posVBO;
	unsigned int _colorVBO;
	unsigned int _normalVBO;
	unsigned int _tangentVBO;
	unsigned int _texCoordVBO;
	unsigned int _triangleIndexVBO;

	// Vectors
	std::vector<unsigned int> _TriangleIndex;
	std::vector<glm::vec3> _VertexPos;
	std::vector<glm::vec3> _VertexNormal;
	std::vector<glm::vec3> _VertexColor;
	std::vector<glm::vec2> _VertexTexCoord;
	std::vector<glm::vec3> _VertexTangent;
	unsigned int _numTriangleIndex;
};

