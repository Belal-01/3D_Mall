#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_STATIC
 
#include "TTexture.h"
#include <stb_image.h>
#include <iostream>

void TTexture::Use()
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureID);
}

void TTexture::loadTexture(const char* filename) {

	stbi_set_flip_vertically_on_load(true);
	int width, height, channels;


	unsigned char* image = stbi_load(filename, &width, &height, &channels, 0);

	if (image) {
		std::cout << "Image loaded successfully: " << width << "x" << height << ", Channels: " << channels << std::endl;


		glGenTextures(1, &textureID);
		glBindTexture(GL_TEXTURE_2D, textureID);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0,
			channels == 4 ? GL_RGBA : GL_RGB,
			GL_UNSIGNED_BYTE, image);

		stbi_image_free(image);
	}
	else {
		std::cout << "Failed to load texture" << std::endl;
	}
}
