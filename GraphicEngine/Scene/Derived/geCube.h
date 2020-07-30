#pragma once

#include "Scene/Derived/geRenderNode.h"

namespace GraphicEngine
{
	class geCube : public geRenderNode
	{
	public:
		/***********************************************************************************************/
		/*                              CONSTRUCTORS AND DESTRUCTORS                                   */
		/***********************************************************************************************/

		geCube(const char* name);

		geCube(const char* name, Transform transform);

		~geCube();
	};
}


