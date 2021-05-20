#include "SceneLight.h"

namespace GraphicEngine
{
	void SceneLight::SetPoint(glm::vec4 color, float constant, float linear, float quadratic)
	{
		m_LightType = LightType::Point;
		m_PointConstant = constant;
		m_PointLinear = linear;
		m_PointQuadratic = quadratic;
	}

	void SceneLight::SetDirectional(glm::vec4 color, glm::vec3 direction)
	{
		m_LightType = LightType::Directional;
		m_Direction = direction;

	}
}