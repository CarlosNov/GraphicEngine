#pragma once

#include <GLM\glm.hpp>
#include <GLM\gtx\quaternion.hpp>

namespace GraphicEngine
{
	class Object
	{
	public:

		/**
		 *	STRUCT THAT STORES THE POSITION, ROTATION AND SCALE OF THE OBJECT.
		 */
		struct Transform
		{
			glm::vec3 position;
			glm::quat rotation;
			glm::vec3 scale;
		};

		/***********************************************************************************************/
		/*                              CONSTRUCTORS AND DESTRUCTORS                                   */
		/***********************************************************************************************/

		/**
		 *	CONSTRUCTOR WITH 2 ARGUMENTS.
		 *  ARGS:
		 *			NAME - NAME OF THE OBJECT.
		 *			ID - ID OF THE OBJECT.
		 */
		Object(const char* name, int id);

		/**
		 *	CONSTRUCTOR WITH 3 ARGUMENT.
		 *  ARGS:
		 *			NAME - NAME OF THE OBJECT.
		 *			ID - ID OF THE OBJECT.
		 *			TRANSFORM - STRUCT WITH THE POSITION, ROTATION AND SCALE OF THE OBJECT.
		 */
		Object(const char* name, int id, Transform transform);

		/**
		 *	DESTRUCTOR
		 */
		~Object();
		
		/***********************************************************************************************/
		/*                        INITIALIZATION AND DESTRUCTION FUNCTIONS                             */
		/***********************************************************************************************/

		/**
		 *	POST: INITIALIZES THE OBJECT AND THE NEEDED VARIABLES.
		 */
		virtual void initObject() = 0;

		/**
		 *	POST: DESTROYS THE OBJECT AND ITS VARIABLES.
		 */
		virtual void destroyObject() = 0;

		/***********************************************************************************************/
		/*									RENDER FUNCTION											   */
		/***********************************************************************************************/

		/**
		 *	
		 */
		virtual void renderObject() = 0;

		/***********************************************************************************************/
		/*                               GETTERS AND SETTERS										   */
		/***********************************************************************************************/

		/**
		 *	POST: RETURNS THE NAME OF THE OBJECT.
		 */
		const char* getName();

		/**
		 *	POST: RETURNS THE ID OF THE OBJECT.
		 */
		int getId();

		/**
		 *	POST: RETURN THE TRANSFORM OF THE OBJECT.
		 */
		Transform getTransform();

		/**
		 *	POST: RETURNS THE POSITION OF THE OBJECT.
		 */
		glm::vec3 getPosition();

		/**
		 *	POST: RETURN THE ROTATION OF THE OBJECT.
		 */
		glm::quat getRotation();

		/**
		 *	POST: RETURN THE SCALE OF THE OBJECT.
		 */
		glm::vec3 getScale();

		/**
		 *	POST: SETS THE CURRENT NAME OF THE OBJECT, TO THE GIVEN NAME.
		 *	ARGS:
		 *			NAME - NEW NAME OF THE OBJECT.
		 */
		void setName(const char* name);

		/**
		 *	POST: SETS THE CURRENT ID OF THE OBJECT, TO THE GIVEN ID.
		 *	ARGS:
		 *			ID - NEW ID OF THE OBJECT.
		 */
		void setId(int Id);

		/**
		 *	POST: SETS THE CURRENT TRANSFORM OF THE OBJECT, TO THE GIVEN TRANSFORM.
		 *	ARGS:
		 *			TRANSFORM - NEW TRANSFORM OF THE OBJECT.
		 */
		void setTransform(Transform transform);

		/**
		 *	POST: SETS THE CURRENT POSITION OF THE OBJECT, TO THE GIVEN POSITION.
		 *	ARGS:
		 *			POSITION - NEW POSITION OF THE OBJECT.
		 */
		void setPosition(glm::vec3 position);

		/**
		 *	POST: SETS THE CURRENT ROTATION OF THE OBJECT, TO THE GIVEN ROTATION.
		 *	ARGS:
		 *			ROTATION - NEW ROTATION OF THE OBJECT.
		 */
		void setRotation(glm::quat rotation);

		/**
		 *	POST: SETS THE CURRENT SCALE OF THE OBJECT, TO THE GIVEN SCALE.
		 *	ARGS:
		 *			SCALE - NEW SCALE OF THE OBJECT.
		 */
		void setScale(glm::vec3 scale);

	private:

		// NAME OF THE OBJECT.
		const char* name;

		// ID OF THE OBJECT.
		int id;

		// STRUCT THAT STORES ALL THE WORLD RELATED VARIABLES.
		Transform transform;
	};
}

