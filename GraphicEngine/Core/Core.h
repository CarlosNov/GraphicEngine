#pragma once

#include "Auxiliar\Macros.h"
#include "Auxiliar\ErrorHandling.h"
#include "Scene\Object.h"
#include "Scene\CompoundObject.h"
#include "Scene\BasicObject.h"

#include <GLEW\glew.h>
#include <GLUT\freeglut.h>
#include <GLM\glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <iostream>

#define SOLVE_FGLUT_WARNING

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
		void static initContext(int argc, char** argv);

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


		/***********************************************************************************************/
		/*									 CORE FUNCTIONS			                                   */
		/***********************************************************************************************/

		/**
		 *	PRE: CONTEXT AND WINDOW MUST BE CREATED BEFORE.
		 *	POST: RENDERS THE FBO IN THE WINDOW.
		 */
		void static renderFunction();

		/**
		 *	PRE: CONTEXT AND WINDOW MUST BE CREATED BEFORE.
		 *	POST: RESIZES THE WIDTH AND HEIGHT OF THE WINDOW.
		 *	ARGUMENTS:	
		 *				WIDTH - NEW WIDTH OF THE WINDOW.
		 *				HEIGHT - NEW HEIGHT OF THE WINDOW.
		 */
		void static resizeFunction(int width, int height);

		/**
		 *	PRE: CONTEXT MUST BE CREATED BEFORE.
		 *	POST: UPDATES THE PROGRAM IN EVERY LOOP.
		 */
		void static updateFunction();

		/**
		 *	POST: BINDS A FUNCTION WITH A KEY.
		 *  ARGUMENTS:
		 *				KEY - KEYCODE PRESSED.
		 *				X - X OF THE KEY.
		 *				Y - Y OF THE KEY.
		 */
		void static keyboardFunction(unsigned char key, int x, int y);

		/**
		 *	POST: EXECUTES FUNCTIONS WHEN THE MOUSE IS PRESSED.
		 *  ARGUMENTS:
		 *				KEY - MOUSE KEYCODE PRESSED.
		 *				X - X OF THE KEY.
		 *				Y - Y OF THE KEY.
		 */
		void static mouseFunction(int button, int state, int x, int y);

		void initPlane();
		void initFBO();
		void resizeFBO(unsigned int w, unsigned int h);

		/***********************************************************************************************/
		/*                                   AUXILIAR FUNCTIONS                                        */
		/***********************************************************************************************/

		//Carga el shader indicado, devuele el ID del shader
		//!Por implementar
		GLuint loadShader(const char *fileName, GLenum type);

		//Crea una textura, la configura, la sube a OpenGL, 
		//y devuelve el identificador de la textura 
		//!!Por implementar
		unsigned int loadTex(const char *fileName);
	};
}


