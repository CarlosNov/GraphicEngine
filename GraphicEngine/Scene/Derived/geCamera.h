#pragma once

#include "config.h"
#include "Scene/geNode.h"

namespace GraphicEngine
{
	class geCamera : public geNode
	{
	public:

		typedef enum
		{
			RIGHT,
			LEFT,
			UP,
			DOWN
		} Movement;

		/**
		 *@brief Constructor with given name and default Transform.
		 *@author Carlos Novella
		 *@version 1.0
		 *@since 1.0
		 *@param name The name of the node.
		 */
		geCamera(const char* name);

		/**
		 *@brief Constructor with given name and given Transform.
		 *@author Carlos Novella
		 *@version 1.0
		 *@since 1.0
		 *@param name The name of the node.
		 *@param Transform The transform of the node.
		 */
		geCamera(const char* name, Transform transform);

		/**
		 *@brief Default destructor of geCamera.
		 *@author Carlos Novella
		 *@version 1.0
		 *@since 1.0
		 */
		~geCamera();

		/**
		 *@brief Empty.
		 *@author Carlos Novella
		 *@version 1.0
		 *@since 1.0
		 */
		void render();

		/**
		 *@brief Updates the camera.
		 *@details Including transform and visibility.
		 *@author Carlos Novella
		 *@version 1.0
		 *@since 1.0
		 */
		void update();

		/**
		 *@brief Accepts a visitor, and executes it.
		 *@author Carlos Novella
		 *@version 1.0
		 *@since 1.0
		 */
		void accept(Visitor* visitor);

		glm::mat4 getProjMatrix();
		glm::mat4 getViewMatrix();

		void setViewMatrix(glm::mat4 viewMatrix);

		unsigned int getWidth();
		unsigned int getHeight();

		void setWindowSize(int width, int height);


	private:
		glm::mat4 _projMatrix;
		glm::mat4 _viewMatrix;

		unsigned int _windowHeight;
		unsigned int _windowWidth;
	};
}