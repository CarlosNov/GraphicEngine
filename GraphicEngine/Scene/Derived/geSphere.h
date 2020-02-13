#pragma once

#include "Scene/Derived/geNode.h"

namespace GraphicEngine
{
	class geSphere : public geNode
	{
	public:
		/***********************************************************************************************/
		/*                              CONSTRUCTORS AND DESTRUCTORS                                   */
		/***********************************************************************************************/

		geSphere(const char* name);

		geSphere(const char* name, Transform transform);

		~geSphere();

		void setProgramShaders(const char* vShader, const char* fShader);
		unsigned int getVAO();
	};
}


