#pragma once

#include "Core\Core.h"

namespace GraphicEngine
{
	class geBasic : public geInterface
	{
	public:

		/***********************************************************************************************/
		/*                              CONSTRUCTORS AND DESTRUCTORS                                   */
		/***********************************************************************************************/

		/**
		 *	CONSTRUCTOR WITHOUT ARGUMENTS.
		 */
		geBasic();

		/**
		 *	DESTRUCTOR.
		 */
		~geBasic();

		/***********************************************************************************************/
		/*                              INITIALIZATION FUNCTIONS                                       */
		/***********************************************************************************************/

		/**
		 *
		 */
		void init();

		void destroy();

		/***********************************************************************************************/
		/*									RENDER FUNCTION											   */
		/***********************************************************************************************/

		/**
		 *
		 */
		void render();

	private:

		Mesh * _mesh;
		Material * _material;
		std::map< int, Texture* > _textures;

		glm::mat4 _modelMatrix;
	};
}