#pragma once

#include "config.h"
#include "Scene/geInterface.h"
#include "Scene/geStorageInterface.h"
#include "Resources/Material.h"
#include "Resources/Texture.h"
#include "Resources/Mesh.h"

namespace GraphicEngine
{
	/**
	 *@class geNode
	 *@brief This class is a generic node.
	 *@details Stores all the node data, including mesh, textures and model.
	 *@author Carlos Novella
	 *@version 1.0
	 *@since 1.0
	 */
	class geNode : public geInterface, public geStorageInterface
	{
	public:

		/**
		 *@brief Constructor with given name and default Transform.
		 *@author Carlos Novella
		 *@version 1.0
		 *@since 1.0
		 *@param name The name of the node.
		 */
		geNode(const char* name);

		/**
		 *@brief Constructor with given name and given Transform.
		 *@author Carlos Novella
		 *@version 1.0
		 *@since 1.0
		 *@param name The name of the node.
		 *@param Transform The transform of the node.
		 */
		geNode(const char* name, Transform transform);

		/**
		 *@brief Default destructor of geInterface.
		 *@author Carlos Novella
		 *@version 1.0
		 *@since 1.0
		 */
		~geNode();


		/**
		 *@brief Renders the node.
		 *@author Carlos Novella
		 *@version 1.0
		 *@since 1.0
		 */
		void render();

		/**
		 *@brief Updates the node.
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


		/**
		 *@brief Activates the rendering program.
		 *@author Carlos Novella
		 *@version 1.0
		 *@since 1.0
		 */
		void activateProgram() const;

		/**
		 *@brief Deactivates the rendering program.
		 *@author Carlos Novella
		 *@version 1.0
		 *@since 1.0
		 */
		void deactivateProgram() const;

		/**
		 *@brief Set the ModelView Matrix
		 *@author Carlos Novella
		 *@version 1.0
		 *@since 1.0
		 */
		void setModelViewMatrix(glm::mat4 view) const;

		/**
		 *@brief Set the ModelViewProjection Matrix
		 *@author Carlos Novella
		 *@version 1.0
		 *@since 1.0
		 */
		void setModelViewProjectionMatrix(glm::mat4 view, glm::mat4 proj) const;

		/**
		 *@brief Set the Normal Matrix
		 *@author Carlos Novella
		 *@version 1.0
		 *@since 1.0
		 */
		void setNormalMatrix(glm::mat4 view) const;

		/**
		 *@brief Activates all the node textures.
		 *@author Carlos Novella
		 *@version 1.0
		 *@since 1.0
		 */
		void activateTextures() const;

		/**
		 *@brief Add a new texture to the node.
		 *@author Carlos Novella
		 *@version 1.0
		 *@since 1.0
		 */
		void addTexture(Texture* texture) const;

		glm::mat4 getModelMatrix();
		Mesh* getMesh();
		Material* getMaterial();

		void setModelMatrix(glm::mat4 modelMatrix);
		void setMesh(Mesh* mesh);
		void setMaterial(Material* material);

	protected:

		glm::mat4 _modelMatrix;
		Mesh* _mesh;
		Material* _material;
	};
}