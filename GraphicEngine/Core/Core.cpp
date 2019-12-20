#include "Core\Core.h"

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

void GraphicEngine::Core::initContext(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitContextVersion(3, 3);
	glutInitContextProfile(GLUT_CORE_PROFILE);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutCreateWindow("Graphic Engine");


	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);

	glewExperimental = GL_TRUE;
	GLenum err = glewInit();
	if (GLEW_OK != err)
	{
		std::cout << "Error: " << glewGetErrorString(err) << std::endl;
		exit(-1);
	}
	const GLubyte *oglVersion = glGetString(GL_VERSION);
	std::cout << "This system supports OpenGL Version: " << oglVersion << std::endl;

	glutReshapeFunc(resizeFunction);
	glutDisplayFunc(renderFunction);
	glutIdleFunc(&updateFunction);
	glutKeyboardFunc(keyboardFunction);
	glutMouseFunc(mouseFunction);
}

void GraphicEngine::Core::initOGL()
{
	glEnable(GL_DEPTH_TEST);
	glClearColor(0.2f, 0.2f, 0.2f, 0.0f);

	glFrontFace(GL_CCW);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glEnable(GL_CULL_FACE);
	/*
	proj = glm::perspective(glm::radians(60.0f), 1.0f, 0.1f, 150.0f);
	view = glm::mat4(1.0f);
	view[3].z = -posicionCamaraOriginal.z;*/
}

/**
 *	PRE: INITS ALL THE SHADERS.
 */
void initShaders();
void initObj();
void destroy();


/***********************************************************************************************/
/*									 CORE FUNCTIONS			                                   */
/***********************************************************************************************/

void GraphicEngine::Core::renderFunction()
{

}

void GraphicEngine::Core::resizeFunction(int width, int height)
{

}

void GraphicEngine::Core::updateFunction()
{

}

void GraphicEngine::Core::keyboardFunction(unsigned char key, int x, int y)
{

}

void GraphicEngine::Core::mouseFunction(int button, int state, int x, int y)
{

}

