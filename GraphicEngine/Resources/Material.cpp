#include "Material.h"

/***********************************************************************************************/
/*                              CONSTRUCTORS AND DESTRUCTORS                                   */
/***********************************************************************************************/

GraphicEngine::Material::Material(ShaderType shaderType , const char* vName, const char* fName)
{
	_typeofshader = shaderType;

	switch (_typeofshader)
	{
		case FORDWARD:
			initShaderFw(vName, fName);
			break;

		case POSTPROCCESS:
			initShaderPP(vName, fName);
			break;

		default:
			break;
	}
}

GraphicEngine::Material::~Material()
{
}

/***********************************************************************************************/
/*										 METHODS											   */
/***********************************************************************************************/

void GraphicEngine::Material::initShaderFw(const char* vname, const char* fname)
{
	_forwardVShader = loadShader(vname, GL_VERTEX_SHADER);
	_forwardFShader = loadShader(fname, GL_FRAGMENT_SHADER);

	_forwardProgram = glCreateProgram();
	glAttachShader(_forwardProgram, _forwardVShader);
	glAttachShader(_forwardProgram, _forwardFShader);

	glBindAttribLocation(_forwardProgram, 0, "inPos");
	glBindAttribLocation(_forwardProgram, 1, "inColor");
	glBindAttribLocation(_forwardProgram, 2, "inNormal");
	glBindAttribLocation(_forwardProgram, 3, "inTexCoord");


	glLinkProgram(_forwardProgram);

	int linked;
	glGetProgramiv(_forwardProgram, GL_LINK_STATUS, &linked);
	if (!linked)
	{
		GLint logLen;
		glGetProgramiv(_forwardProgram, GL_INFO_LOG_LENGTH, &logLen);

		char* logString = new char[logLen];
		glGetProgramInfoLog(_forwardProgram, logLen, NULL, logString);
		std::cout << "Error: " << logString << std::endl;
		delete logString;

		glDeleteProgram(_forwardProgram);
		_forwardProgram = 0;
		exit(-1);
	}

	_uNormalMat = glGetUniformLocation(_forwardProgram, "normal");
	_uModelViewMat = glGetUniformLocation(_forwardProgram, "modelView");
	_uModelViewProjMat = glGetUniformLocation(_forwardProgram, "modelViewProj");

	_uColorTex = glGetUniformLocation(_forwardProgram, "colorTex");
	_uEmiTex = glGetUniformLocation(_forwardProgram, "emiTex");

	_inPos = glGetAttribLocation(_forwardProgram, "inPos");
	_inColor = glGetAttribLocation(_forwardProgram, "inColor");
	_inNormal = glGetAttribLocation(_forwardProgram, "inNormal");
	_inTexCoord = glGetAttribLocation(_forwardProgram, "inTexCoord");
}

void GraphicEngine::Material::initShaderPP(const char* vname, const char* fname)
{
	_postProccesVShader = loadShader(vname, GL_VERTEX_SHADER);
	_postProccesFShader = loadShader(fname, GL_FRAGMENT_SHADER);

	_postProccesProgram = glCreateProgram();
	glAttachShader(_postProccesProgram, _postProccesVShader);
	glAttachShader(_postProccesProgram, _postProccesFShader);

	glBindAttribLocation(_postProccesProgram, 0, "inPos");

	glLinkProgram(_postProccesProgram);

	int linked;
	glGetProgramiv(_postProccesProgram, GL_LINK_STATUS, &linked);
	if (!linked)
	{
		GLint logLen;
		glGetProgramiv(_postProccesProgram, GL_INFO_LOG_LENGTH, &logLen);

		char* logString = new char[logLen];
		glGetProgramInfoLog(_postProccesProgram, logLen, NULL, logString);
		std::cout << "Error: " << logString << std::endl;
		delete logString;

		glDeleteProgram(_postProccesProgram);
		_postProccesProgram = 0;
		exit(-1);
	}

	_uColorTexPP = glGetUniformLocation(_postProccesProgram, "colorTex");
	_inPosPP = glGetAttribLocation(_postProccesProgram, "inPos");
}

void  GraphicEngine::Material::activateProgram(ShaderType shaderType)
{
	switch(shaderType)
	{
		case FORDWARD:
			glUseProgram(_forwardProgram);
			break;

		case POSTPROCCESS:
			glUseProgram(_postProccesProgram);
			break;

		default:
			break;
	}
	

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