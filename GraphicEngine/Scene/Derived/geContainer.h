#pragma once

#include "Scene/geInterface.h"

namespace GraphicEngine
{
	/**
	 *@class geContainer
	 *@brief Stores other geInterface childs.
	 *@details Also, calls the generic functions of all the stored geInterface childs.
	 *@author Carlos Novella
	 *@version 1.0
	 *@since 1.0
	 */
	class geContainer : public geInterface
	{
	public:

		/**
		 *@brief Constructor with given name and default Transform.
		 *@author Carlos Novella
		 *@version 1.0
		 *@since 1.0
		 *@param name The name of the node.
		 */
		geContainer(const char* name);

		/**
		 *@brief Constructor with given name and given Transform.
		 *@author Carlos Novella
		 *@version 1.0
		 *@since 1.0
		 *@param name The name of the node.
		 *@param Transform The transform of the node.
		 */
		geContainer(const char* name, Transform transform);

		/**
		 *@brief Default destructor of geContainer.
		 *@author Carlos Novella
		 *@version 1.0
		 *@since 1.0
		 */
		~geContainer();


		/**
		 *@brief Renders all the internal nodes.
		 *@author Carlos Novella
		 *@version 1.0
		 *@since 1.0
		 */
		void render();

		/**
		 *@brief Updates all the internal nodes.
		 *@author Carlos Novella
		 *@version 1.0
		 *@since 1.0
		 */
		void update();

		/**
		 *@brief Virtual accept function.
		 *@author Carlos Novella
		 *@version 1.0
		 *@since 1.0
		 *@param visitor The visitor that we want to accept.
		 */
		void accept(Visitor* visitor) {}

		std::vector<geInterface*> getChildren();

		bool add(geInterface* node);

		bool remove(geInterface* node);

	private:
		std::map<int, geInterface*> _children;
	};
}