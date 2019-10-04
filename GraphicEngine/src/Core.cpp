#include "Core.h"

/***********************************************************************************************/
/*                              CONSTRUCTORS AND DESTRUCTORS                                   */
/***********************************************************************************************/

GraphicEngine::Core::Core()
{

}

GraphicEngine::Core::~Core()
{

}

/***********************************************************************************************/
/*                            INITIALIZATION AND DESTRUCTION                                   */
/***********************************************************************************************/

/**
 *	POST: INITS THE CONTEXT OF THE WINDOW, AND LINKS ALL THE EVENT FUNCTIONS.
 *	ARGUMENTS:
 *				ARGC - NUMBER OF ARGUMENTS IN ARGV ARRAY.
 *				ARGV - ARRAY WITH ALL THE ARGUMENTS.
 */
void initContext(int argc, char** argv);

/**
 *	PRE: CONTEXT MUST BE CREATED BEFORE.
 *	POST: INITS ALL THE OPENGL PARAMETERS.
 */
void initOGL();

/**
 *	PRE: INITS ALL THE SHADERS.
 */
void initShaders();
void initObj();
void destroy();

