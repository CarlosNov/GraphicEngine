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

		GLuint getColorBuffer();
		GLuint getDepthBuffer();
		GLuint getVertexBuffer();

		void setColorBuffer(GLuint color);
		void setDepthBuffer(GLuint depth);
		void setVertexBuffer(GLuint vertex);

	private:
		unsigned int _fbo;
		GLuint _colorBufferTex;
		GLuint _depthBufferTex;
		GLuint _vertexBufferTex;
	};
}


