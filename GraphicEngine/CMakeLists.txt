#Sources
SET(SOURCES
    Application.cpp
    Auxiliar/ErrorHandling.cpp
    Core/FBO.cpp
    Core/Steps/Forward.cpp
    Core/Steps/PostProcess.cpp
    Scene/Derived/geCube.cpp
    Resources/Material.cpp
    Resources/Mesh.cpp
    Scene/Derived/Light.cpp
    Scene/Derived/Camera.cpp
    Scene/Derived/geContainer.cpp
    Scene/Derived/gePlane.cpp
    Scene/geInterface.cpp
    Core/Core.cpp
    Resources/Texture.cpp
    Core/Steps/Step.cpp

)

SET(HEADERS
    Auxiliar/ErrorHandling.h
    Auxiliar/Macros.h
    config.h
    Core/Core.h
    Core/FBO.h
    Core/Steps/Forward.h
    Core/Steps/PostProcess.h
    Scene/Derived/geCube.h
    Resources/Material.h
    Resources/Mesh.h
    Resources/PLANE.h
    Scene/Derived/gePlane.h
    Scene/Visitor/ActiveTexturesVisitor.h
    Scene/Visitor/AddTextureVisitor.h
    Scene/Visitor/DeactiveProgramVisitor.h
    Scene/Derived/Light.h
    Scene/Derived/Camera.h
    Scene/Derived/geContainer.h
    Scene/geInterface.h
    Resources/CUBE.h
    Resources/Texture.h
    Core/Steps/Step.h
    Scene/Visitor/ActiveProgramVisitor.h
    Scene/Visitor/SetNormalMatrixVisitor.h
    Scene/Visitor/SetModelViewProjectionMatrixVisitor.h
    Scene/Visitor/SetModelViewMatrixVisitor.h
    Scene/Visitor/Visitor.h
)

FILE(GLOB_RECURSE SHADERS
    ${CMAKE_CURRENT_DIR} Shaders/*.[a-z]*)

#Dependencies
find_package(FreeImage REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(GLM REQUIRED)
#find_package(Qt5Core REQUIRED 5.4)

target_include_directories(Graphic Engine PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/common/classes
    ${CMAKE_CURRENT_SOURCE_DIR}/common/auxiliar
	#${Qt5Core_INCLUDE_DIRS} 
    ${FREEIMAGE_INCLUDE_DIRS}
	${OPENGL_INCLUDE_DIR}
    ${GLEW_INCLUDE_DIRS}
    ${GLM_INCLUDE_DIR}
    ${ASSIMP_INCLUDE_DIR}
	
)

target_link_libraries(Graphic Engine
    ${FREEIMAGE_LIBRARIES}
	${OPENGL_LIBRARIES}
    ${GLEW_LIBRARIES}
    ${ASSIMP_LIBRARIES}
    ${CGAL_LIBRARIES}
	#Qt5::Core
)

add_executable(GraphicEngine ${SOURCES} ${HEADERS})