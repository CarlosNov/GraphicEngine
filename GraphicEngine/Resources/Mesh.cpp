#include "Mesh.h"


/***********************************************************************************************/
/*                              CONSTRUCTORS AND DESTRUCTORS                                   */
/***********************************************************************************************/

GraphicEngine::Mesh::Mesh()
{
	
}

GraphicEngine::Mesh::~Mesh()
{
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