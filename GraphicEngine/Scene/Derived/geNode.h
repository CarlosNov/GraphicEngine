#pragma once

#include "config.h"
#include "Scene/geInterface.h"
#include "Resources/Material.h"
#include "Resources/Texture.h"
#include "Resources/Mesh.h"

namespace GraphicEngine
{
	class geNode : public geInterface
	{
	public:

		/***********************************************************************************************/
		/*                              CONSTRUCTORS AND DESTRUCTORS                                   */
		/***********************************************************************************************/

		geNode(const char* name);
		geNode(const char* name, Transform transform);
		~geNode();

		void render();
		void update();
		void accept(Visitor* visitor);

		void activateProgram() const;
		void deactivateProgram() const;

		void setModelViewMatrix(glm::mat4 view) const;
		void setModelViewProjectionMatrix(glm::mat4 view, glm::mat4 proj) const;
		void setNormalMatrix(glm::mat4 view) const;

		void activateTextures() const;

		void addTexture(Texture* texture);

		bool getIsRenderable();

	protected:

		glm::mat4 _modelMatrix;
		Mesh* _mesh;
		Material* _material;
	};
}