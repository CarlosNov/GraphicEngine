#include "Texture.h"

GraphicEngine::Texture::Texture(unsigned int texId, TextureType typeoftexture)
{
	_typeoftexture = typeoftexture;
	_texId = texId;
}

GraphicEngine::Texture::Texture(const char* fileName, TextureType typeoftexture)
{
	_typeoftexture = typeoftexture;
	loadTex(fileName);
}

GraphicEngine::Texture::~Texture()
{
}

unsigned int GraphicEngine::Texture::loadTex(const char* fileName)
{
	unsigned char* map;
	unsigned int w, h;
	map = loadTexture(fileName, w, h);

	if (!map)
	{
		std::cout << "Error cargando el fichero: "
			<< fileName << std::endl;
		exit(-1);
	}


	glGenTextures(1, &_texId);
	glBindTexture(GL_TEXTURE_2D, _texId);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, w, h, 0, GL_RGBA,
		GL_UNSIGNED_BYTE, (GLvoid*)map);
	delete[] map;
	glGenerateMipmap(GL_TEXTURE_2D);

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
		GL_LINEAR_MIPMAP_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);

	return _texId;
}

unsigned int GraphicEngine::Texture::useTexture()
{
	return _texId;
}

GraphicEngine::Texture::TextureType GraphicEngine::Texture::getType() 
{
	return _typeoftexture;
}

int GraphicEngine::Texture::getTypeID() 
{
	return (int) _typeoftexture;
}



unsigned char* GraphicEngine::Texture::loadTexture(const char* fileName, unsigned int& w, unsigned int& h)
{
	FreeImage_Initialise(TRUE);

	FREE_IMAGE_FORMAT format = FreeImage_GetFileType(fileName, 0);
	if (format == FIF_UNKNOWN)
		format = FreeImage_GetFIFFromFilename(fileName);
	if ((format == FIF_UNKNOWN) || !FreeImage_FIFSupportsReading(format))
		return NULL;

	FIBITMAP* img = FreeImage_Load(format, fileName);
	if (img == NULL)
		return NULL;

	FIBITMAP* tempImg = img;
	img = FreeImage_ConvertTo32Bits(img);
	FreeImage_Unload(tempImg);

	w = FreeImage_GetWidth(img);
	h = FreeImage_GetHeight(img);

	//BGRA a RGBA
	unsigned char* map = new unsigned char[4 * w * h];
	char* buff = (char*)FreeImage_GetBits(img);

	for (unsigned int j = 0; j < w * h; j++) {
		map[j * 4 + 0] = buff[j * 4 + 2];
		map[j * 4 + 1] = buff[j * 4 + 1];
		map[j * 4 + 2] = buff[j * 4 + 0];
		map[j * 4 + 3] = buff[j * 4 + 3];
	}

	FreeImage_Unload(img);
	FreeImage_DeInitialise();

	return map;
}
