#pragma once

/**
 *	MACROS THAT CHECK OPENGL ERRORS
 */
#define ASSERT(x) if(!(x)) __debugbreak();
#define GLCall(x) GLClearError();\
	x;\
	ASSERT(GLLogCall(#x, __LINE__))

