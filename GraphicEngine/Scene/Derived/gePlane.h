#pragma once

#include "Scene/Derived/geNode.h"

namespace GraphicEngine
{
	class gePlane : public geNode
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


