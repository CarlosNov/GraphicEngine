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
	
	_idCount = 0;
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
	for (std::map< int, geInterface* >::iterator it = _Core->_geNodes.begin(); it != _Core->_geNodes.end(); it++)
	{
		it->second->update();

		if (it->second->isActive())
			_Core->_toRenderNodes.push_back(it->second);
	}
}

void GraphicEngine::Core::keyboardFunction(unsigned char key, bool isAutoRepeat)
{

}

void GraphicEngine::Core::mouseFunction(int button, int x, int y)
{

}

