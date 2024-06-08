# Graphic Engine

## Descripción

Este es un motor gráfico desarrollado con el propósito de apoyar la educación en el ámbito universitario y mejorar la interacción del alumno durante la explicación de conceptos básicos de computación gráfica. El motor está diseñado para ser modular y extensible, permitiendo a los usuarios trabajar con diferentes APIs gráficas.

## Características

- **Modularidad**: Aunque el motor está pensado para funcionar principalmente con OpenGL, su arquitectura modular permite integrarlo fácilmente con otras APIs gráficas como Vulkan o DirectX.
- **Interfaz de Usuario**: La interfaz del motor está construida utilizando CMake y librerías auxiliares como ImGui para proporcionar una experiencia interactiva y fácil de usar.
- **Carga de Modelos 3D**: Utiliza la librería ASSIMP para cargar modelos 3D de diferentes formatos, permitiendo una gran flexibilidad en la visualización de contenido.
- **Gestión de Texturas**: FreeImage se encarga de la carga y gestión de texturas, asegurando una alta calidad y eficiencia en el procesamiento de imágenes.
- **Compatibilidad con Glew y GLFW**: El motor gráfico utiliza Glew para la extensión de OpenGL y GLFW para la gestión de ventanas y eventos, garantizando un rendimiento óptimo y facilidad de uso.

## Estructura del Proyecto

El proyecto está dividido en dos partes principales:

1. **Core**: Esta parte actúa como una librería (API) que proporciona todas las funcionalidades básicas del motor gráfico. Aquí se implementan las principales funciones de renderizado, manejo de modelos y texturas, y gestión de recursos.

2. **App**: Esta parte consume la librería Core y genera el motor gráfico, mostrando la interfaz de usuario. Es en esta sección donde se desarrollan las aplicaciones específicas que utilizan el motor gráfico para mostrar contenido y permitir la interacción del usuario.

## Dependencias

- **OpenGL**: Para el renderizado gráfico.
- **CMake**: Para la construcción del proyecto.
- **ImGui**: Para la creación de la interfaz de usuario.
- **ASSIMP**: Para la carga de modelos 3D.
- **FreeImage**: Para la gestión de texturas.
- **Glew**: Para las extensiones de OpenGL.
- **GLFW**: Para la gestión de ventanas y eventos.

## Contribuciones
Las contribuciones son bienvenidas. Siéntase libre de abrir un pull request o una issue para discutir cualquier cambio o mejora que desee implementar.

## Licencia
Este proyecto está licenciado bajo los términos de la licencia MIT.
