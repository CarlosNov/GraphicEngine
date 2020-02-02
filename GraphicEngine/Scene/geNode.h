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

		typedef enum
		{
			CUBE,
			PLANE,
			SPHERE
		} BasicNodes;

		/***********************************************************************************************/
		/*                              CONSTRUCTORS AND DESTRUCTORS                                   */
		/***********************************************************************************************/

		/**
		 *	CONSTRUCTOR WITHOUT ARGUMENTS.
		 */
		geNode(const char* name);

		/**
		 *	CONSTRUCTOR WITH 1 ARGUMENT
		 *	ARGS:
		 *			TYPE - THE TYPE OF GEBASIC
		 */
		geNode(const char* name, BasicNodes basicNodes);

		/**
		 *	DESTRUCTOR.
		 */
		~geNode();

		static geNode* geBasicCube(const char* name);
		static geNode* geBasicPlane(const char* name);
		static geNode* geBasicSphere(const char* name);

		/***********************************************************************************************/
		/*									RENDER FUNCTION											   */
		/***********************************************************************************************/

		void render();
		void update();

		void setMatrix(glm::mat4 viewMat, glm::mat4 projMat);
	protected:

		// Node model attributes

		glm::mat4 _modelMatrix;
		glm::mat4 _viewMatrix;
		glm::mat4 _projMatrix;
		Mesh* _mesh;
		Material* _material;
		std::map< int, Texture* > _textures;
	};
}