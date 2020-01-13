#pragma once

#include "geNode.h"

#include "config.h"

namespace GraphicEngine
{
	class geNodeContainer: public geNode
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
		geNodeContainer(const char* name, int id);

		/**
		 *	CONSTRUCTOR WITH 3 ARGUMENT.
		 *  ARGS:
		 *			NAME - NAME OF THE OBJECT.
		 *			ID - ID OF THE OBJECT.
		 *			TRANSFORM - STRUCT WITH THE POSITION, ROTATION AND SCALE OF THE OBJECT.
		 */
		geNodeContainer(const char* name, int id, Transform transform);

		/**
		 *	DESTRUCTOR.
		 */
		~geNodeContainer();

		/***********************************************************************************************/
		/*                        INITIALIZATION AND DESTRUCTION FUNCTIONS                             */
		/***********************************************************************************************/

		/**
		 *	POST: INITIALIZES THE OBJECT AND THE NEEDED VARIABLES.
		 */
		void initObject();

		/**
		 *	POST: DESTROYS THE OBJECT AND ITS VARIABLES.
		 */
		void destroyObject();

		/***********************************************************************************************/
		/*									RENDER FUNCTION											   */
		/***********************************************************************************************/

		/**
		 *
		 */
		void renderObject();

		/***********************************************************************************************/
		/*                              ADD  & REMOVE OPERATIONS                                       */
		/***********************************************************************************************/

		//bool addObject(Object o);

		//bool removeObject(Object o);

	private:
		std::vector<geNode> objectList;
	};
}