#pragma once

#include "config.h"
#include "QtGui/qevent.h"
#include "Core/Steps/Step.h"
#include "Core/Steps/Forward.h"
#include "Core/Steps/PostProcess.h"
#include "Scene/Interfaces/geInterface.h"
#include "Scene/geNode.h"
#include "Scene/Derived/geCube.h"
#include "Scene/Derived/gePlane.h"
#include "Scene/Derived/geSphere.h"
#include "Scene/Derived/geLight.h"
#include "Scene/Derived/geImported.h"

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
		 *@brief Adds a geNode to the Core class.
		 *@author Carlos Novella
		 *@version 1.0
		 *@since 1.0
		 *@param geNode The geNode to add.
		 */
		void addNode(geNode* geNode);

		/**
		 *@brief Adds a light to the Core class.
		 *@author Carlos Novella
		 *@version 1.0
		 *@since 1.0
		 *@param light The light to add.
		 */
		void addLight(geLight* light);

		/**
		 *@brief Adds a rendering Step to the Core class.
		 *@author Carlos Novella
		 *@version 1.0
		 *@since 1.0
		 *@param step The step to add.
		 */
		void addStep(Step* step);

		void addSteps(std::vector<Step*> steps);

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
		void keyboardFunction(QKeyEvent* event);

		/**
		 *@brief Binds a function with a key.
		 *@author Carlos Novella
		 *@version 1.0
		 *@since 1.0
		 *@param button The button that caused the event.
		 *@param x The x position of the mouse cursor.
		 *@param y The y position of the mouse cursor.
		 */
		void mouseFunction(int button, int x, int y);

		void calculateDelta();

		unsigned int getWindowWidth();
		unsigned int getWindowHeight();

	private:

		std::map<int, geNode*> _geNodes;
		std::map<int, geLight*> _lights;


		std::vector<Step*> _steps;

		float deltaTime = 0.0f;
		float lastFrame = 0.0f;
	};
}