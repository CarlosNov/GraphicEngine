#pragma once

#include "config.h"
#include "Scene/Interfaces/geInterface.h"
#include "Scene/Interfaces/geStorageInterface.h"
#include "Renderer/Material.h"
#include "Renderer/Texture.h"
#include "Renderer/Mesh.h"

namespace GraphicEngine
{
	/**
	 *@class geNode
	 *@brief This class is a generic node.
	 *@author Carlos Novella
	 *@version 1.0
	 *@since 1.0
	 */
	class geNode : public geInterface, public geStorageInterface
	{
	public:

		/**
		 *@brief Constructor with given name and default Transform.
		 *@author Carlos Novella
		 *@version 1.0
		 *@since 1.0
		 *@param name The name of the node.
		 */
		geNode(const char* name);

		/**
		 *@brief Constructor with given name and given Transform.
		 *@author Carlos Novella
		 *@version 1.0
		 *@since 1.0
		 *@param name The name of the node.
		 *@param Transform The transform of the node.
		 */
		geNode(const char* name, Transform transform);

		/**
		 *@brief Default destructor of geInterface.
		 *@author Carlos Novella
		 *@version 1.0
		 *@since 1.0
		 */
		~geNode();


		/**
		 *@brief Renders the node.
		 *@author Carlos Novella
		 *@version 1.0
		 *@since 1.0
		 */
		void render();

		/**
		 *@brief Updates the node.
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
	};
}