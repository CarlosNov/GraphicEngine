#pragma once

#include "Scene/Derived/geNode.h"

namespace GraphicEngine
{
	class geCube : public geNode
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


