#pragma once

#include "Core\Core.h"

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
		geContainer(const char* name, int id);

		/**
		 *	CONSTRUCTOR WITH 3 ARGUMENT.
		 *  ARGS:
		 *			NAME - NAME OF THE OBJECT.
		 *			ID - ID OF THE OBJECT.
		 *			TRANSFORM - STRUCT WITH THE POSITION, ROTATION AND SCALE OF THE OBJECT.
		 */
		geContainer(const char* name, int id, Transform transform);

		/**
		 *	DESTRUCTOR.
		 */
		~geContainer();

		/***********************************************************************************************/
		/*                        INITIALIZATION AND DESTRUCTION FUNCTIONS                             */
		/***********************************************************************************************/

		/**
		 *	POST: INITIALIZES THE OBJECT AND THE NEEDED VARIABLES.
		 */
		void init();

		/**
		 *	POST: DESTROYS THE OBJECT AND ITS VARIABLES.
		 */
		void destroy();

		/***********************************************************************************************/
		/*									RENDER FUNCTION											   */
		/***********************************************************************************************/

		/**
		 *
		 */
		void render();

		/***********************************************************************************************/
		/*                              ADD  & REMOVE OPERATIONS                                       */
		/***********************************************************************************************/

		//bool addObject(Object o);

		//bool removeObject(Object o);

	private:
		std::vector<geInterface> objectList;
	};
}