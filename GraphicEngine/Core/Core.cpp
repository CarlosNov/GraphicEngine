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

	_geNodes.clear();
	_steps.clear();
	_lights.clear();
	_cameras.clear();

	_mainCamera = NULL;
	
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
	_mainCamera = camera;
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

void GraphicEngine::Core::addStep(Step* step)
{
	_steps.push_back(step);
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
	Step* _lastStep = nullptr;

	for (std::vector<Step*>::iterator it = _Core->_steps.begin(); it != _Core->_steps.end(); it++)
	{
		if (_lastStep != nullptr)
		{
			(*it)->setColorBuffer(_lastStep->getColorBuffer());
			(*it)->setDepthBuffer(_lastStep->getDepthBuffer());
			(*it)->setVertexBuffer(_lastStep->getVertexBuffer());
		}

		(*it)->render(_Core->_toRenderNodes, _Core->_mainCamera); 
		
		_lastStep = (*it);
	}

	glUseProgram(NULL);

	glutSwapBuffers();
}

void GraphicEngine::Core::resizeFunction(int width, int height)
{
	glViewport(0, 0, width, height);
	_Core->_mainCamera->setWindowSize(width, height);

	glutPostRedisplay();
}

void GraphicEngine::Core::updateFunction()
{   
	for (std::map< int, geInterface* >::iterator it = _Core->_geNodes.begin(); it != _Core->_geNodes.end(); it++)
	{
		it->second->update();

		if (it->second->getIsActive() && it->second->getIsRenderable())
			_Core->_toRenderNodes.push_back(it->second);
	}
	glutPostRedisplay();
}

void GraphicEngine::Core::keyboardFunction(unsigned char key, int x, int y)
{

}

void GraphicEngine::Core::mouseFunction(int button, int state, int x, int y)
{

}

