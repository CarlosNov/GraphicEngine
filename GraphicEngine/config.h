#pragma once

#define _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS
#define _CRT_SECURE_NO_WARNINGS

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#define GLM_FORCE_RADIANS
#include <GLM/glm.hpp>
#include <GLM/gtc/matrix_transform.hpp>
#include "GLM/gtx/string_cast.hpp"
#include <GLM/gtx/rotate_vector.hpp>

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <fstream>

#include <FREEIMAGE/FreeImage.h>
#define _CRT_SECURE_DEPRECATE_MEMORY
#include <memory.h>

#define DEVELOPMENT true
#define PRODUCTION !DEVELOPMENT


