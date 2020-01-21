#include "Core\Core.h"

/***********************************************************************************************/
/*                              CONSTRUCTORS AND DESTRUCTORS                                   */
/***********************************************************************************************/

static GraphicEngine::Core* _Core = NULL;

GraphicEngine::Core* GraphicEngine::Core::getCore(int argc, char** argv)
{
	if (_Core == NULL)
		_Core = new Core(argc, argv);

	return _Core;
}

GraphicEngine::Core::Core(int argc, char** argv)
{
	std::locale::global(std::locale(R"(spanish)"));

	_camera = NULL;
	_geNodes.clear();
	_idCount = 0;
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
}

/***********************************************************************************************/
/*							     ADD AND GET FUNCTIONS										   */
/***********************************************************************************************/

void GraphicEngine::Core::addCamera(GraphicEngine::Camera* camera)
{
	_camera = camera;
}

void GraphicEngine::Core::addNode(geInterface* geNode)
{
	_geNodes[_idCount] = geNode;
	_idCount++;
}

void GraphicEngine::Core::addLight(Light* light)
{
	_lights[_idCount] = light;
	_idCount++;
}

GraphicEngine::geInterface* GraphicEngine::Core::getNode(int id)
{
	if (_geNodes.count(id))
		return _geNodes[id];

	return NULL;
}

/***********************************************************************************************/
/*									 CORE FUNCTIONS			                                   */
/***********************************************************************************************/

void GraphicEngine::Core::mainLoop()
{
	glutMainLoop();	
}

void GraphicEngine::Core::renderFunction()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	for (std::map< int, geInterface* >::iterator it = _Core->_geNodes.begin();
		it != _Core->_geNodes.end(); it++)
	{
		it->second->render(_Core->_camera->getViewMatrix(), _Core->_camera->getProjMatrix());
	}

	glUseProgram(NULL);


	glutSwapBuffers();
}

void GraphicEngine::Core::resizeFunction(int width, int height)
{
	glViewport(0, 0, width, height);
	_Core->_camera->setWindowSize(width, height);

	glutPostRedisplay();
}

void GraphicEngine::Core::updateFunction()
{
	glutPostRedisplay();
}

void GraphicEngine::Core::keyboardFunction(unsigned char key, int x, int y)
{

}

void GraphicEngine::Core::mouseFunction(int button, int state, int x, int y)
{

}

