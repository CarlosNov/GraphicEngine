#include "CompoundObject.h"

GraphicEngine::CompoundObject::CompoundObject(const char* name, int id) : GraphicEngine::Object::Object(name, id)
{
	setName(name);
	setId(id);
}

GraphicEngine::CompoundObject::CompoundObject(const char* name, int id, Transform transform): GraphicEngine::Object::Object(name, id, transform)
{
	setName(name);
	setId(id);
	setTransform(transform);
}

GraphicEngine::CompoundObject::~CompoundObject()
{
}

void GraphicEngine::CompoundObject::initObject()
{

}

void GraphicEngine::CompoundObject::renderObject()
{

}

void GraphicEngine::CompoundObject::destroyObject()
{

}

