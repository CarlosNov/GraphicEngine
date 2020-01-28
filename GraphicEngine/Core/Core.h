#pragma once

#include "config.h"
#include "Auxiliar\Macros.h"
#include "Auxiliar\ErrorHandling.h"
#include "Core\Step.h"
#include "Core\Forward.h"
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

		static Core* getCore(int argc, char** argv);

		/**
		 *	CONSTRUCTOR WITH PARAMETERS
		 */
		Core(int argc, char** argv);

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

		/***********************************************************************************************/
		/*							     ADD AND GET FUNCTIONS										   */
		/***********************************************************************************************/

		void addCamera(Camera* camera);

		void addNode(geInterface* geNode);

		void addLight(Light* light);

		geInterface* getNode(int id);

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

	private:
		std::map<int, geInterface*> _geNodes;
		std::map<int, Light*> _lights;

		Camera* _camera;
		int _idCount;

		std::vector<Step*> _steps;
		
	};
}