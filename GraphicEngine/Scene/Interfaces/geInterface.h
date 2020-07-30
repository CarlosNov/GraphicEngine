#pragma once

#include "config.h"
#include "Scene/Visitor/Visitor.h"

namespace GraphicEngine
{
	/**
	 *@class geInterface
	 *@brief Interface from the rest of the nodes inherits.
	 *@details Has generic methods, like render, update and accept.
	 *@author Carlos Novella
	 *@version 1.0
	 *@since 1.0
	 */
	class geInterface
	{
	public:

		/**
		 *@struct Transform
		 *@brief Contains the position, rotation and scale of the node.
		 *@author Carlos Novella
		 *@version 1.0
		 *@since 1.0
		 *@param position The position of the node.
		 *@param rotation The rotation of the node.
		 *@param scale The scale of the node.
		 */
		struct Transform
		{
			glm::vec3 position;
			glm::vec3 rotation;
			glm::vec3 scale;
		};

		/**
		 *@brief Constructor with given name and default Transform.
		 *@author Carlos Novella
		 *@version 1.0
		 *@since 1.0
		 *@param name The name of the node.
		 */
		geInterface(const char* name);

		/**
		 *@brief Constructor with given name and given Transform.
		 *@author Carlos Novella
		 *@version 1.0
		 *@since 1.0
		 *@param name The name of the node.
		 *@param Transform The transform of the node.
		 */
		geInterface(const char* name, Transform transform);

		/**
		 *@brief Default destructor of geInterface.
		 *@author Carlos Novella
		 *@version 1.0
		 *@since 1.0
		 */
		~geInterface();


		/**
		 *@brief Virtual render function.
		 *@author Carlos Novella
		 *@version 1.0
		 *@since 1.0
		 */
		virtual void render() = 0;

		/**
		 *@brief Virtual update function.
		 *@author Carlos Novella
		 *@version 1.0
		 *@since 1.0
		 */
		virtual void update() = 0;

		/**
		 *@brief Virtual accept function.
		 *@author Carlos Novella
		 *@version 1.0
		 *@since 1.0
		 *@param visitor The visitor that we want to accept.
		 */
		virtual void accept(Visitor* visitor) = 0;


		/**
		 *@brief Get the node name.
		 *@author Carlos Novella
		 *@version 1.0
		 *@since 1.0
		 *@return a character pointer.
		 */
		const char* getName();

		/**
		 *@brief Get the node id.
		 *@author Carlos Novella
		 *@version 1.0
		 *@since 1.0
		 *@return a integer.
		 */
		int getId();

		/**
		 *@brief Get the node tranform.
		 *@author Carlos Novella
		 *@version 1.0
		 *@since 1.0
		 *@return a Transform.
		 */
		Transform getTransform();

		/**
		 *@brief Get the node position of the transform.
		 *@author Carlos Novella
		 *@version 1.0
		 *@since 1.0
		 *@return a glm vec3.
		 */
		glm::vec3 getPosition();

		/**
		 *@brief Get the node rotation of the transform.
		 *@author Carlos Novella
		 *@version 1.0
		 *@since 1.0
		 *@return a glm vec3.
		 */
		glm::vec3 getRotation();

		/**
		 *@brief Get the node scale of the transform.
		 *@author Carlos Novella
		 *@version 1.0
		 *@since 1.0
		 *@return a glm vec3.
		 */
		glm::vec3 getScale();

		/**
		 *@brief Get the node active status.
		 *@author Carlos Novella
		 *@version 1.0
		 *@since 1.0
		 *@return a boolean.
		 */
		bool isActive();

		/**
		 *@brief Set a new name for the node.
		 *@author Carlos Novella
		 *@version 1.0
		 *@since 1.0
		 *@param name The new name of the node.
		 */
		void setName(const char* name);

		/**
		 *@brief Set a new id for the node.
		 *@author Carlos Novella
		 *@version 1.0
		 *@since 1.0
		 *@param id The new id of the node.
		 */
		void setId(int id);

		/**
		 *@brief Set a new transform for the node.
		 *@author Carlos Novella
		 *@version 1.0
		 *@since 1.0
		 *@param name The new transform of the node.
		 */
		void setTransform(Transform transform);

		/**
		 *@brief Set a new transform position for the node.
		 *@author Carlos Novella
		 *@version 1.0
		 *@since 1.0
		 *@param name The new transform position of the node.
		 */
		void setPosition(glm::vec3 position);

		/**
		 *@brief Set a new transform rotation for the node.
		 *@author Carlos Novella
		 *@version 1.0
		 *@since 1.0
		 *@param name The new transform rotation of the node.
		 */
		void setRotation(glm::vec3 rotation);

		/**
		 *@brief Set a new transform scale for the node.
		 *@author Carlos Novella
		 *@version 1.0
		 *@since 1.0
		 *@param scale The new transform scale of the node.
		 */
		void setScale(glm::vec3 scale);

		/**
		 *@brief Set a new active status for the node.
		 *@author Carlos Novella
		 *@version 1.0
		 *@since 1.0
		 *@param active The new active status of the node.
		 */
		void setIsActive(bool active);
	protected:
		static int _idCount;
		const char* _name;
		int _id;
		Transform _transform;
		bool _isActive;		
		geInterface* _parent;
	};
}