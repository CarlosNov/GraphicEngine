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
		void render();
		void update() {}

		/***********************************************************************************************/
		/*                              ADD  & REMOVE OPERATIONS                                       */
		/***********************************************************************************************/

		//bool addObject(Object o);

		//bool removeObject(Object o);

		void setMatrix(glm::mat4 viewMat, glm::mat4 projMat) {}

	private:
		std::vector<geInterface*> objectList;
	};
}