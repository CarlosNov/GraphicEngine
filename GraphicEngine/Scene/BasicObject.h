#pragma once

#include "Object.h"

namespace GraphicEngine
{
	class BasicObject : public Object
	{
	public:

		/***********************************************************************************************/
		/*                              CONSTRUCTORS AND DESTRUCTORS                                   */
		/***********************************************************************************************/

		/**
		 *	CONSTRUCTOR WITHOUT ARGUMENTS.
		 */
		BasicObject();

		/**
		 *	DESTRUCTOR.
		 */
		~BasicObject();

		/***********************************************************************************************/
		/*                              INITIALIZATION FUNCTIONS                                       */
		/***********************************************************************************************/

		/**
		 *
		 */
		virtual void initObject();

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
	};
}