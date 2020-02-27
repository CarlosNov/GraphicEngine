#pragma once

#include "config.h"
#include "Scene/geInterface.h"
#include "Scene/geStorageInterface.h"

namespace GraphicEngine {

	class geLight : public geInterface, public geStorageInterface
	{
	public:
		geLight();
		~geLight();

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

