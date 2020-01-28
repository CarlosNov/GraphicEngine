#include "Forward.h"

GraphicEngine::Forward::Forward() : GraphicEngine::Step::Step()
{
	setVariables(NULL, NULL);
}

GraphicEngine::Forward::Forward(Camera* camera, std::map<int, geInterface*>* map) : GraphicEngine::Step::Step()
{
	setVariables(camera, map);
}

GraphicEngine::Forward::~Forward()
{

}



void GraphicEngine::Forward::render()
{
	/*
	for (std::map< int, geInterface* >::iterator it = geNodes.begin();
		it != geNodes.end(); it++)
	{
		it->second->render(viewMat, projMat);
	}*/
}

void GraphicEngine::Forward::update()
{
	for (std::map< int, geInterface* >::iterator it = (*_geNodes).begin();
		it != (*_geNodes).end(); it++)
	{
		it->second->update();
	}
}

void GraphicEngine::Forward::setVariables(Camera* camera, std::map<int, geInterface*>* map)
{
	_renderCamera = camera;
	_geNodes = map;
}

void GraphicEngine::Forward::addToRender(geInterface* geNode)
{
	_toRenderNodes.push_back(geNode);
}