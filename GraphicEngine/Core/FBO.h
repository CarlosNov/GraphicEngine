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

		void bindFBO();

		unsigned int getColorBuffer();
		unsigned int getDepthBuffer();
		unsigned int getVertexBuffer();

		void setColorBuffer(unsigned int color);
		void setDepthBuffer(unsigned int depth);
		void setVertexBuffer(unsigned int vertex);

	private:
		unsigned int _fbo;
		unsigned int _colorBufferTex;
		unsigned int _depthBufferTex;
		unsigned int _vertexBufferTex;
	};
}


