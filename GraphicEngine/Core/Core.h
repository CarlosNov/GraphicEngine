#pragma once

#include "config.h"
#include "Auxiliar\Macros.h"
#include "Auxiliar\ErrorHandling.h"
#include "Resources\Mesh.h"
#include "Resources\Material.h"
#include "Resources\Texture.h"
#include "Scene\geInterface.h"
#include "Scene\geContainer.h"
#include "Scene\geBasic.h"
#include "Scene\Camera.h"
#include "Scene\Light.h"

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
		/*							     ADD AND GET FUNCTIONS										   */
		/***********************************************************************************************/

		void addCamera(Camera* camera);

		void addNode(std::string name, geInterface* geNode);

		void addLight(Light* light);

		geInterface* getNode(std::string name);

		/***********************************************************************************************/
		/*									 CORE FUNCTIONS			                                   */
		/***********************************************************************************************/

		void mainLoop();

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

	private:
		std::map<std::string, geInterface*> _geNodes;
		std::map<std::string, Light*> _geLights;
		GraphicEngine::Camera* _camera;
	};
}