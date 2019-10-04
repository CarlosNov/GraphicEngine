#pragma once

#include "Object.h"

namespace GraphicEngine
{
	class Basics : public Object
	{
	public:
		Basics();
		Basics(float position[], float color[], float normal[],
			float texCoord[], unsigned int triangleIndex[]);
		~Basics();
	private:
		
		// Declaration of the VAO.
		unsigned int VertexArrayObject;

		// Declaration of the Basics' VBO.
		unsigned int posVBO;
		unsigned int colorVBO;
		unsigned int normalVBO;
		unsigned int tangentVBO;
		unsigned int texCoordVBO;
		unsigned int triangleIndexVBO;

		// Declaration of the textures.
		unsigned int colorTexId;
		unsigned int emiTexId;
	};
}

