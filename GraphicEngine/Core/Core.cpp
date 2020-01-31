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

	_scene = new geContainer("Scene");
	_renderer = new Renderer();
	_renderer->addStep((Step*) new Forward());
	_idCounter = 0;
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
	_renderer->addCamera(camera);
}

void GraphicEngine::Core::addNode(geInterface* geNode)
{
	geNode->setId(_idCounter);
	_idCounter++;
	_scene->addNode(geNode);
}

void GraphicEngine::Core::addLight(Light* light)
{
	_lights[_idCounter] = light;
	_idCounter++;
}

GraphicEngine::geInterface* GraphicEngine::Core::getNode(int id)
{
	if (_scene->getNodeMap().count(id))
		return _scene->getNodeMap()[id];
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
	_Core->_renderer->renderNodes();
}

void GraphicEngine::Core::resizeFunction(int width, int height)
{
	glViewport(0, 0, width, height);
	_Core->_renderer->getCamera()->setWindowSize(width, height);

	glutPostRedisplay();
}

void GraphicEngine::Core::updateFunction()
{   
	for (std::map< int, geInterface* >::iterator it = _Core->_scene->getNodeMap().begin(); it != _Core->_scene->getNodeMap().end(); it++)
	{

		if (it->second->getIsMarkedDelete())
			delete(it->second);

		it->second->update();	

		if (it->second->getIsActive() && it->second->getRenderable() != NULL)
			_Core->_renderer->addNode(it->second);
	}

	glutPostRedisplay();
}

void GraphicEngine::Core::keyboardFunction(unsigned char key, int x, int y)
{

}

void GraphicEngine::Core::mouseFunction(int button, int state, int x, int y)
{

}

