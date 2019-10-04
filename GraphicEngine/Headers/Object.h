#pragma once

#include <GLM\glm.hpp>
#include <GLM\gtx\quaternion.hpp>

namespace GraphicEngine
{
	struct Transform
	{
		glm::vec3 position;
		glm::quat rotation;
		glm::vec3 scale;
	};

	class Object
	{
	public:
		/***********************************************************************************************/
		/*                              CONSTRUCTORS AND DESTRUCTORS                                   */
		/***********************************************************************************************/

		/**
		 *	CONSTRUCTOR WITHOUT PARAMETERS
		 */
		Object();

		/**
		 *	DESTRUCTOR
		 */
		~Object();
		
		/***********************************************************************************************/
		/*                               GETTERS AND SETTERS										   */
		/***********************************************************************************************/

		const char* getName();

		Transform getTransform();

		glm::vec3 getPosition();

		void setName();

		void setTransform();

		void setPosition();

	private:
		static const char* name;
		Transform transform;
	};
}

