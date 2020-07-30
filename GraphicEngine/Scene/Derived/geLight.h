#pragma once

#include "config.h"
#include "Scene/geNode.h"

namespace GraphicEngine {

	class geLight : public geNode
	{
	public:
		/**
		 *@brief Constructor with given name and default Transform.
		 *@author Carlos Novella
		 *@version 1.0
		 *@since 1.0
		 *@param name The name of the node.
		 */
		geLight(const char* name);

		/**
		 *@brief Constructor with given name and given Transform.
		 *@author Carlos Novella
		 *@version 1.0
		 *@since 1.0
		 *@param name The name of the node.
		 *@param Transform The transform of the node.
		 */
		geLight(const char* name, Transform transform);

		/**
		 *@brief Default destructor of geLight.
		 *@author Carlos Novella
		 *@version 1.0
		 *@since 1.0
		 */
		~geLight();

		/**
		 *@brief Empty.
		 *@author Carlos Novella
		 *@version 1.0
		 *@since 1.0
		 */
		void render();

		/**
		 *@brief Updates the light.
		 *@details Including transform and visibility.
		 *@author Carlos Novella
		 *@version 1.0
		 *@since 1.0
		 */
		void update();

		/**
		 *@brief Accepts a visitor, and executes it.
		 *@author Carlos Novella
		 *@version 1.0
		 *@since 1.0
		 */
		void accept(Visitor* visitor);

		glm::vec3 getAmbientIntensity(); 
		glm::vec3 getDiffuseIntensity();
		glm::vec3 getSpecularIntensity();

		void setAmbientIntensity(glm::vec3 aIntensity);
		void setDiffuseIntensity(glm::vec3 aIntensity);
		void setSpecularIntensity(glm::vec3 aIntensity);

	protected:
		glm::vec3 _aIntensity;
		glm::vec3 _dIntensity;
		glm::vec3 _sIntensity;
	};
}

