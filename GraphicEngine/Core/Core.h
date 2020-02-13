#pragma once

#include "config.h"
#include "Core/Steps/Step.h"
#include "Core/Steps/Forward.h"
#include "Core/Steps/PostProcess.h"
#include "Scene/geInterface.h"
#include "Scene/Derived/geContainer.h"
#include "Scene/Derived/geNode.h"
#include "Scene/Derived/geCube.h"
#include "Scene/Derived/geSphere.h"
#include "Scene/Derived/Camera.h"
#include "Scene/Derived/Light.h"

namespace GraphicEngine
{
	/** 
	 *@class Core
	 *@brief Represents the core of all the Graphic Engine.
	 *@details Manages all the objects, updating and rendering.
	 *@author Carlos Novella
	 *@version 1.0
	 *@since 1.0
	 */
	class Core
	{
	public:

		/**
		 *@brief Default constructor of Core.
		 *@author Carlos Novella
		 *@version 1.0
		 *@since 1.0
		 */
		Core();

		/**
		 *@brief Default destructor of Core.
		 *@author Carlos Novella
		 *@version 1.0
		 *@since 1.0
		 */
		~Core();

		/**
		 *@brief Inits GLEW and checks if the system supports OpenGL.
		 *@author Carlos Novella
		 *@version 1.0
		 *@since 1.0
		 */
		void initGlew();

		/**
		 *@brief Adds a camera to the Core class.
		 *@author Carlos Novella
		 *@version 1.0
		 *@since 1.0
		 *@param camera The camera to add.
		 */
		void addCamera(Camera* camera);

		/**
		 *@brief Adds a geNode to the Core class.
		 *@author Carlos Novella
		 *@version 1.0
		 *@since 1.0
		 *@param geNode The geNode to add.
		 */
		void addNode(geInterface* geNode);

		/**
		 *@brief Adds a light to the Core class.
		 *@author Carlos Novella
		 *@version 1.0
		 *@since 1.0
		 *@param light The light to add.
		 */
		void addLight(Light* light);

		/**
		 *@brief Adds a rendering Step to the Core class.
		 *@author Carlos Novella
		 *@version 1.0
		 *@since 1.0
		 *@param step The step to add.
		 */
		void addStep(Step* step);

		geInterface* getNode(int id);

		/**
		 *@brief Renders all the Steps.
		 *@details Context and windows must be created before. Loops all the Steps and calls their render function.
		 *@author Carlos Novella
		 *@version 1.0
		 *@since 1.0
		 */
		void static renderFunction();

		/**
		 *@brief Resizes the width and height of the window.
		 *@details Context and windows must be created before. Resizes the main window, the camera viewport and all FBO.
		 *@author Carlos Novella
		 *@version 1.0
		 *@since 1.0
		 *@param width New width of the window.
		 *@param height New height of the window.
		 */
		void static resizeFunction(int width, int height);

		/**
		 *@brief Updates the program in every loop.
		 *@details Context and windows must be created before. Calls the update function of every geInterface. 
		 *         Add them to the renderList if they are visible and active.
		 *@author Carlos Novella
		 *@version 1.0
		 *@since 1.0
		 *@param width New width of the window.
		 *@param height New height of the window.
		 */
		void static updateFunction();

		/**
		 *@brief Binds a function with a key.
		 *@author Carlos Novella
		 *@version 1.0
		 *@since 1.0
		 *@param key The code of the key that was pressed or released.
		 *@param isAutoRepeat True if this event comes from an auto-repeating key;
		 *					  returns false if it comes from an initial key press.
		 */
		void static keyboardFunction(unsigned char key, bool isAutoRepeat);

		/**
		 *@brief Binds a function with a key.
		 *@author Carlos Novella
		 *@version 1.0
		 *@since 1.0
		 *@param button The button that caused the event.
		 *@param x The x position of the mouse cursor.
		 *@param y The y position of the mouse cursor.
		 */
		void static mouseFunction(int button, int x, int y);

	private:

		//geContainer _scene;

		std::map<int, geInterface*> _geNodes;

		std::vector<geInterface*> _toRenderNodes;

		std::map<int, Light*> _lights;

		std::map<int, Camera*> _cameras;

		Camera* _mainCamera;

		std::vector<Step*> _steps;

		int _idCount;	
	};
}