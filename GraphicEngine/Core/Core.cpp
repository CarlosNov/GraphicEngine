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

void GraphicEngine::Core::addSteps(std::vector<Step*> steps)
{
	_steps = steps;
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

	_Core->calculateDelta();
}

void GraphicEngine::Core::keyboardFunction(QKeyEvent* event)
{
	glm::vec3 cameraPos = _mainCamera->getPosition();
	glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
	glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

	const float cameraSpeed = 4 * deltaTime;

	switch (event->key())
	{
	case Qt::Key_W:
		cameraPos += cameraSpeed * cameraFront;
		
		break;
	case Qt::Key_S:
		cameraPos -= cameraSpeed * cameraFront;
		break;
	case Qt::Key_D:
		cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
		break;
	case Qt::Key_A:
		cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
		break;
	default:
		break;
	}

	_mainCamera->setPosition(cameraPos);
	_mainCamera->setViewMatrix(glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp));
}

void GraphicEngine::Core::mouseFunction(int button, int x, int y)
{

}

void GraphicEngine::Core::calculateDelta()
{
	float time = glutGet(GLUT_ELAPSED_TIME);
	deltaTime = (time - lastFrame) / 1000.0;
	lastFrame = time;
}

unsigned int GraphicEngine::Core::getWindowWidth()
{
	return _mainCamera->getWidth();
}

unsigned int GraphicEngine::Core::getWindowHeight()
{
	return _mainCamera->getHeight();
}


