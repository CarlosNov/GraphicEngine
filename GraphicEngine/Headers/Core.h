#pragma once

#include "Macros.h"
#include "ErrorHandling.h"
#include "Object.h"
#include "Basics.h"

#include <GLEW\glew.h>
#include <GLUT\freeglut.h>
#include <GLM\glm.hpp>

#include <iostream>

namespace GraphicEngine
{
	class Core
	{
	public:

		/***********************************************************************************************/
		/*                              CONSTRUCTORS AND DESTRUCTORS                                   */
		/***********************************************************************************************/

		/**
		 *	CONSTRUCTOR WITHOUT PARAMETERS
		 */
		Core();

		/**
		 *	DESTRUCTOR
		 */
		~Core();


		/***********************************************************************************************/
		/*                            INITIALIZATION AND DESTRUCTION                                   */
		/***********************************************************************************************/

		/**
		 *	POST: INITS THE CONTEXT OF THE WINDOW, AND LINKS ALL THE EVENT FUNCTIONS.
		 *	ARGUMENTS: 
		 *				ARGC - NUMBER OF ARGUMENTS IN ARGV ARRAY.
		 *				ARGV - ARRAY WITH ALL THE ARGUMENTS.
		 */
		void initContext(int argc, char** argv);

		/**
		 *	PRE: CONTEXT MUST BE CREATED BEFORE.
		 *	POST: INITS ALL THE OPENGL PARAMETERS.
		 */
		void initOGL();

		/**
		 *	POST: INITS ALL THE SHADERS.
		 */
		void initShaders();
		
		/**
		 * POST: INITS ALL THE BASIC OBJECTS (CUBE, PLANE AND SPHERE)
		 */
		void initBasicObjects();

		/**
		 *	POST: DESTROYS ALL THE DECLARED VARIABLES AND FREES THE MEMORY.
		 */
		void destroy();



		void renderFunc();
		void resizeFunc(int width, int height);
		void idleFunc();
		void keyboardFunc(unsigned char key, int x, int y);
		void mouseFunc(int button, int state, int x, int y);

		void initPlane();
		void initFBO();
		void resizeFBO(unsigned int w, unsigned int h);

		//Carga el shader indicado, devuele el ID del shader
		//!Por implementar
		GLuint loadShader(const char *fileName, GLenum type);

		//Crea una textura, la configura, la sube a OpenGL, 
		//y devuelve el identificador de la textura 
		//!!Por implementar
		unsigned int loadTex(const char *fileName);
	};
}


