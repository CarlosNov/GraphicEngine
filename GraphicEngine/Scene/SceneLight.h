#pragma once

#include "config.h"

namespace GraphicEngine
{
	class SceneLight
	{
	public:
		enum class LightType { Point = 0, Directional = 1 };

	public:

		SceneLight() = default;
		virtual ~SceneLight() = default;

		void SetPoint(glm::vec4 color, float constant, float linear, float quadratic);
		void SetDirectional(glm::vec4 color, glm::vec3 direction);

		glm::vec4 GetColor() { return m_Color; }
		void SetColor(glm::vec4 color) { m_Color = color; }

		float GetPointConstant() { return m_PointConstant; }
		void SetPointConstant(float pointConstant) { m_PointConstant = pointConstant; }
		float GetPointLinear() { return m_PointLinear; }
		void SetPointLinear(float pointLinear) { m_PointLinear = pointLinear; }
		float GetPointQuadratic() { return m_PointQuadratic; }
		void SetPointQuadratic(float pointQuadratic) { m_PointQuadratic = pointQuadratic; }

		glm::vec3 GetDirection() { return m_Direction; }
		void SetDirection(glm::vec3 direction) { m_Direction = direction; }
		void SetDirectionX(float x) { m_Direction.x = x; }
		void SetDirectionY(float y) { m_Direction.y = y; }
		void SetDirectionZ(float z) { m_Direction.z = z; }

		LightType GetLightType() const { return m_LightType; }
		void SetLightType(LightType type) { m_LightType = type; }

	protected:
		LightType m_LightType = LightType::Point;

		glm::vec4 m_Color{ 255.0f, 255.0f, 255.0f, 255.0f };

		float m_PointConstant = 1.0f;
		float m_PointLinear = 0.1f;
		float m_PointQuadratic = 0.01f;

		glm::vec3 m_Direction{ 0.0f, 0.0f, 0.0f };
	};
}
