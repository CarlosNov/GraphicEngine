#pragma once

#include "Scene/Derived/geRenderNode.h"

namespace GraphicEngine
{
	class gePlane : public geRenderNode
	{
	public:
		/***********************************************************************************************/
		/*                              CONSTRUCTORS AND DESTRUCTORS                                   */
		/***********************************************************************************************/

		gePlane(const char* name);

		gePlane(const char* name, Transform transform);

		~gePlane();

		void setProgramShaders(const char* vShader, const char* fShader);
		unsigned int getVAO();
	};
}


