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
		 *@brief Default destructor of geInterface.
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
		 *@brief Returns true if the container has some renderable object.
		 *@author Carlos Novella
		 *@version 1.0
		 *@since 1.0
		 *@return a boolean.
		 */
		bool isRenderable();


		//bool addObject(geInterface* node);

		//bool removeObject(Object o);

	private:
		std::map<int, geInterface*> _geNodeList;
		std::vector<geInterface*> _toRenderList;
	};
}