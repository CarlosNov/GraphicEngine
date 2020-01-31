#pragma once

#include "geInterface.h"

namespace GraphicEngine
{
	class geContainer: public geInterface
	{
	public:

		/***********************************************************************************************/
		/*                              CONSTRUCTORS AND DESTRUCTORS                                   */
		/***********************************************************************************************/

		/**
		 *	CONSTRUCTOR WITH 2 ARGUMENTS.
		 *  ARGS:
		 *			NAME - NAME OF THE OBJECT.
		 *			ID - ID OF THE OBJECT.
		 */
		geContainer(const char* name);

		/**
		 *	CONSTRUCTOR WITH 3 ARGUMENT.
		 *  ARGS:
		 *			NAME - NAME OF THE OBJECT.
		 *			ID - ID OF THE OBJECT.
		 *			TRANSFORM - STRUCT WITH THE POSITION, ROTATION AND SCALE OF THE OBJECT.
		 */
		geContainer(const char* name, Transform transform);

		/**
		 *	DESTRUCTOR.
		 */
		~geContainer();

		/***********************************************************************************************/
		/*									RENDER FUNCTION											   */
		/***********************************************************************************************/

		/**
		 *
		 */
		void update();

		Renderable* getRenderable() const { return NULL; }

		/***********************************************************************************************/
		/*                              ADD  & REMOVE OPERATIONS                                       */
		/***********************************************************************************************/

		bool addNode(geInterface* o);

		bool removeNode(geInterface* o);

		std::map<int, geInterface*> getNodeMap();

	private:
		std::map<int, geInterface*> _geNodes;
	};
}