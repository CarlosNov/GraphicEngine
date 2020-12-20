#include "Shader.h"

namespace GraphicEngine
{
    Shader::Shader(const char* vertexPath, const char* fragmentPath)
    {

		m_VShader = LoadShader(vertexPath, GL_VERTEX_SHADER);
		m_FShader = LoadShader(fragmentPath, GL_FRAGMENT_SHADER);

		m_Program = glCreateProgram();
		glAttachShader(m_Program, m_VShader);
		glAttachShader(m_Program, m_FShader);

		glLinkProgram(m_Program);

		int linked;
		glGetProgramiv(m_Program, GL_LINK_STATUS, &linked);
		if (!linked)
		{
			GLint logLen;
			glGetProgramiv(m_Program, GL_INFO_LOG_LENGTH, &logLen);

			char* logString = new char[logLen];
			glGetProgramInfoLog(m_Program, logLen, NULL, logString);
			std::cout << "Error: " << logString << std::endl;
			delete logString;

			glDeleteProgram(m_Program);
			m_Program = 0;
			exit(-1);
		}

        glDeleteShader(m_VShader);
        glDeleteShader(m_FShader);
    }

	GLuint Shader::LoadShader(const char* fileName, GLenum type)
	{
		unsigned int fileLen;
		char* source = LoadStringFromFile(fileName, fileLen);

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

	char* Shader::LoadStringFromFile(const char* fileName, unsigned int& fileLen)
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

    void Shader::CheckCompileErrors(GLuint shader, std::string type)
    {
        GLint success;
        GLchar infoLog[1024];
        if (type != "PROGRAM")
        {
            glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
            if (!success)
            {
                glGetShaderInfoLog(shader, 1024, NULL, infoLog);
                std::cout << "ERROR::SHADER_COMPILATION_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
            }
        }
        else
        {
            glGetProgramiv(shader, GL_LINK_STATUS, &success);
            if (!success)
            {
                glGetProgramInfoLog(shader, 1024, NULL, infoLog);
                std::cout << "ERROR::PROGRAM_LINKING_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
            }
        }
    }
}