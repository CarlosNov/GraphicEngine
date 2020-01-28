#include "Material.h"

/***********************************************************************************************/
/*                              CONSTRUCTORS AND DESTRUCTORS                                   */
/***********************************************************************************************/

GraphicEngine::Material::Material(const char* vName, const char* fName)
{
	initShader(vName, fName);
}

GraphicEngine::Material::~Material()
{
}

/***********************************************************************************************/
/*										 METHODS											   */
/***********************************************************************************************/

void GraphicEngine::Material::initShader(const char* vname, const char* fname)
{
	_VShader = loadShader(vname, GL_VERTEX_SHADER);
	_FShader = loadShader(fname, GL_FRAGMENT_SHADER);

	_program = glCreateProgram();
	glAttachShader(_program, _VShader);
	glAttachShader(_program, _FShader);

	glBindAttribLocation(_program, 0, "inPos");
	glBindAttribLocation(_program, 1, "inColor");
	glBindAttribLocation(_program, 2, "inNormal");
	glBindAttribLocation(_program, 3, "inTexCoord");


	glLinkProgram(_program);

	int linked;
	glGetProgramiv(_program, GL_LINK_STATUS, &linked);
	if (!linked)
	{
		GLint logLen;
		glGetProgramiv(_program, GL_INFO_LOG_LENGTH, &logLen);

		char* logString = new char[logLen];
		glGetProgramInfoLog(_program, logLen, NULL, logString);
		std::cout << "Error: " << logString << std::endl;
		delete logString;

		glDeleteProgram(_program);
		_program = 0;
		exit(-1);
	}

	_uNormalMat = glGetUniformLocation(_program, "normal");
	_uModelViewMat = glGetUniformLocation(_program, "modelView");
	_uModelViewProjMat = glGetUniformLocation(_program, "modelViewProj");

	_uColorTex = glGetUniformLocation(_program, "colorTex");
	_uEmiTex = glGetUniformLocation(_program, "emiTex");

	_inPos = glGetAttribLocation(_program, "inPos");
	_inColor = glGetAttribLocation(_program, "inColor");
	_inNormal = glGetAttribLocation(_program, "inNormal");
	_inTexCoord = glGetAttribLocation(_program, "inTexCoord");
}

void  GraphicEngine::Material::activateProgram()
{
	glUseProgram(_program);
}
void  GraphicEngine::Material::deactivateProgram()
{
	glUseProgram(NULL);

}


void GraphicEngine::Material::activateTexture(Texture* texture)
{
	switch (texture->getType())
	{
	case Texture::DIFFUSE:

		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, texture->useTexture());
		glUniform1i(_uColorTex, 0);
		break;

	case Texture::EMISIVE:
		glActiveTexture(GL_TEXTURE0 + 1);
		glBindTexture(GL_TEXTURE_2D, texture->useTexture());
		glUniform1i(_uEmiTex, 1);
		break;
	}

}

void GraphicEngine::Material::setModelViewProjMat(glm::mat4 modelView, glm::mat4 projMat)
{
	glm::mat4 modelViewProj = projMat * modelView;

	if (_uModelViewProjMat != -1)
		glUniformMatrix4fv(_uModelViewProjMat, 1, GL_FALSE, &(modelViewProj[0][0]));
}

void GraphicEngine::Material::setModelViewMat(glm::mat4 modelView)
{
	if (_uModelViewMat != -1)
		glUniformMatrix4fv(_uModelViewMat, 1, GL_FALSE, &(modelView[0][0]));
}

void GraphicEngine::Material::setNormalMat(glm::mat4 normalMat) 
{
	if (_uNormalMat != -1)
		glUniformMatrix4fv(_uNormalMat, 1, GL_FALSE, &(normalMat[0][0]));
}

void GraphicEngine::Material::setAttributes(unsigned int posVBO, unsigned int colorVBO,
											unsigned int normalVBO, unsigned int texCoordVBO)
{

	if (_inPos != -1)
	{


		glBindBuffer(GL_ARRAY_BUFFER, posVBO);
		glVertexAttribPointer(_inPos, 3, GL_FLOAT, GL_FALSE, 0, 0);
		glEnableVertexAttribArray(_inPos);
	}

	if (_inColor != -1)
	{


		glBindBuffer(GL_ARRAY_BUFFER, colorVBO);
		glVertexAttribPointer(_inColor, 3, GL_FLOAT, GL_FALSE, 0, 0);
		glEnableVertexAttribArray(_inColor);
	}

	if (_inNormal != -1)
	{


		glBindBuffer(GL_ARRAY_BUFFER, normalVBO);
		glVertexAttribPointer(_inNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
		glEnableVertexAttribArray(_inNormal);
	}


	if (_inTexCoord != -1)
	{


		glBindBuffer(GL_ARRAY_BUFFER, texCoordVBO);
		glVertexAttribPointer(_inTexCoord, 2, GL_FLOAT, GL_FALSE, 0, 0);
		glEnableVertexAttribArray(_inTexCoord);
	}

}

/***********************************************************************************************/
/*								    AUXILIAR METHODS										   */
/***********************************************************************************************/

GLuint GraphicEngine::Material::loadShader(const char* fileName, GLenum type)
{
	unsigned int fileLen;
	char* source = loadStringFromFile(fileName, fileLen);

	GLuint shader;
	shader = glCreateShader(type);
	glShaderSource(shader, 1,
		(const GLchar**)&source, (const GLint*)&fileLen);
	glCompileShader(shader);
	delete source;

	// Check if compilation succedeed
	GLint compiled;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);
	if (!compiled)
	{
		// Calculate error lenght
		GLint logLen;
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &logLen);

		char* logString = new char[logLen];
		glGetShaderInfoLog(shader, logLen, NULL, logString);
		std::cout << "Error: " << logString << std::endl;
		delete logString;

		glDeleteShader(shader);
		exit(-1);
	}

	return shader;
}

char* GraphicEngine::Material::loadStringFromFile(const char* fileName, unsigned int& fileLen)
{
	// Load file
	std::ifstream file;
	file.open(fileName, std::ios::in);
	if (!file) return 0;

	// Calculate file lenght
	file.seekg(0, std::ios::end);
	fileLen = unsigned int(file.tellg());
	file.seekg(std::ios::beg);

	// Read of file
	char* source = new char[fileLen + 1];

	int i = 0;
	while (file.good())
	{
		source[i] = char(file.get());
		if (!file.eof()) i++;
		else fileLen = i;
	}
	source[fileLen] = '\0';
	file.close();

	return source;
}