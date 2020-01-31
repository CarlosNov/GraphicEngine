#pragma once

#include "config.h"
#include "Scene/geInterface.h"
#include "Resources/Material.h"
#include "Resources/Texture.h"
#include "Resources/Mesh.h"

namespace GraphicEngine
{
	class geBasic : public geInterface
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
		geBasic(const char* name);

		/**
		 *	CONSTRUCTOR WITH 1 ARGUMENT
		 *	ARGS:
		 *			TYPE - THE TYPE OF GEBASIC
		 */
		geBasic(const char* name, BasicNodes basicNodes);

		/**
		 *	DESTRUCTOR.
		 */
		~geBasic();

		static geBasic* geBasicCube(const char* name);
		static geBasic* geBasicPlane(const char* name);
		static geBasic* geBasicSphere(const char* name);

		/***********************************************************************************************/
		/*									RENDER FUNCTION											   */
		/***********************************************************************************************/

		void update();

		Renderable* getRenderable();

	protected:

		// Node model attributes
		Renderable* _renderable;

		glm::mat4 _modelMatrix;
		Mesh* _mesh;
		Material* _material;
		std::map< int, Texture* > _textures;
	};
}