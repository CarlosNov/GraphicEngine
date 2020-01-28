#pragma once

#include "config.h"

namespace GraphicEngine
{
	class FBO
	{
	public:

		/***********************************************************************************************/
		/*                              CONSTRUCTORS AND DESTRUCTORS                                   */
		/***********************************************************************************************/

		FBO();

		~FBO();

		/***********************************************************************************************/
		/*										 METHODS											   */
		/***********************************************************************************************/

		void initFBO();

		void resizeFBO(unsigned int w, unsigned int h);

	private:
		unsigned int _fbo;
		unsigned int _colorBufferTex;
		unsigned int _depthBufferTex;
	};
}


