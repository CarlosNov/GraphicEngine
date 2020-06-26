#pragma once

#include "Scene/Derived/geRenderNode.h"

namespace GraphicEngine
{
	class geImported : public geRenderNode
	{
	public:
		/***********************************************************************************************/
		/*                              CONSTRUCTORS AND DESTRUCTORS                                   */
		/***********************************************************************************************/

		geImported(const char* name);

		geImported(const char* name, Transform transform);

		~geImported();
	};
}


