#pragma once

#include "Scene/geInterface.h"
#include "Scene/geStorageInterface.h"

namespace GraphicEngine
{
	/**
	 *@class geScene
	 *@brief Stores all the geInterface objects in the current scene.
	 *@details Also, calls the generic functions of all the stored geInterface childs.
	 *@author Carlos Novella
	 *@version 1.0
	 *@since 1.0
	 */
	class geScene : public geInterface, public geStorageInterface
	{
	public:

		/**
		 *@brief Constructor with given name and default Transform.
		 *@author Carlos Novella
		 *@version 1.0
		 *@since 1.0
		 *@param name The name of the node.
		 */
		geScene(const char* name);

		/**
		 *@brief Constructor with given name and given Transform.
		 *@author Carlos Novella
		 *@version 1.0
		 *@since 1.0
		 *@param name The name of the node.
		 *@param Transform The transform of the node.
		 */
		geScene(const char* name, Transform transform);

		/**
		 *@brief Default destructor of geScene.
		 *@author Carlos Novella
		 *@version 1.0
		 *@since 1.0
		 */
		~geScene();


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

	private:
		std::map<int, geContainer*> _geContainersMap;
		std::map<int, geNode*> _geNodesMap;
		std::map<int, geCamera*> _geCamerasMap;
		std::map<int, geLight*> _geLightsMap;
	};
}