#include "Core\Core.h"

static GraphicEngine::Core* _Core = NULL;

GraphicEngine::Core::Core()
{
	std::locale::global(std::locale(R"(spanish)"));

	_Core = this;
	_geNodes.clear();
	_steps.clear();
	_lights.clear();
	_cameras.clear();
}

GraphicEngine::Core::~Core()
{

}

void GraphicEngine::Core::initGlew()
{
	glewExperimental = GL_TRUE;
	GLenum err = glewInit();
	if (GLEW_OK != err)
	{
		std::cout << "Error: " << glewGetErrorString(err) << std::endl;
		exit(-1);
	}
	const GLubyte* oglVersion = glGetString(GL_VERSION);
	std::cout << "This system supports OpenGL Version: " << oglVersion << std::endl;
}

void GraphicEngine::Core::addCamera(GraphicEngine::geCamera* camera)
{
	_mainCamera = camera;
}

void GraphicEngine::Core::addNode(geNode* geNode)
{
	_geNodes[geNode->getId()] = geNode;
}

void GraphicEngine::Core::addLight(geLight* light)
{
	_lights[light->getId()] = light;
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

void GraphicEngine::Core::renderFunction()
{
	for (std::vector<Step*>::iterator it = _Core->_steps.begin(); it != _Core->_steps.end(); it++)
	{
		(*it)->render(_Core->_geNodes, _Core->_mainCamera); 
	}
	glUseProgram(NULL);
}

void GraphicEngine::Core::resizeFunction(int width, int height)
{
	glViewport(0, 0, width, height);
	_Core->_mainCamera->setWindowSize(width, height);

	for (std::vector<Step*>::iterator it = _Core->_steps.begin(); it != _Core->_steps.end(); it++)
	{
		(*it)->resizeFBO(width, height);
	}
}

void GraphicEngine::Core::updateFunction()
{   
	for (std::map< int, geNode* >::iterator it = _Core->_geNodes.begin(); it != _Core->_geNodes.end(); it++)
	{
		it->second->update();
	}
}

void GraphicEngine::Core::keyboardFunction(unsigned char key, bool isAutoRepeat)
{

}

void GraphicEngine::Core::mouseFunction(int button, int x, int y)
{

}

unsigned int GraphicEngine::Core::getWindowWidth()
{
	return _mainCamera->getWidth();
}

unsigned int GraphicEngine::Core::getWindowHeight()
{
	return _mainCamera->getHeight();
}


