
#include "Mesh.h"

#include "CUBE.h"

/***********************************************************************************************/
/*                              CONSTRUCTORS AND DESTRUCTORS                                   */
/***********************************************************************************************/

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

GraphicEngine::Mesh::Mesh(BasicNodes basicNode)
{
	switch (basicNode)
	{
		case CUBE:
			initCube();
			break;

		default:
			initCube();
			break;
	}
}

GraphicEngine::Mesh::Mesh(const char* fileName)
{
	
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

/***********************************************************************************************/
/*										 METHODS											   */
/***********************************************************************************************/

void GraphicEngine::Mesh::renderMesh()
{

	glBindVertexArray(_VertexArrayObject);
	glDrawElements(GL_TRIANGLES, _numTriangleIndex,
		GL_UNSIGNED_INT, (void*)0);
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