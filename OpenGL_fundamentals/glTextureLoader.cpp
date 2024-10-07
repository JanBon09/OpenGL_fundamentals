#include <iostream>
#include <glad/glad.h>

#include "glTextureLoader.hpp"
#include "stb_image.h"

namespace fundamentals {
	GlTextureLoader::GlTextureLoader() {
		data = stbi_load("wall.jpg", &width, &height, &nrChannels, 0);
	}

	void GlTextureLoader::loadTextures() {
		if (data) {
			glGenTextures(1, &texture);
			glBindTexture(GL_TEXTURE_2D, texture);

			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);

			stbi_image_free(data);
		}
		else {
			std::cerr << "Failed to load textures" << std::endl;
			exit(EXIT_FAILURE);
		}
	}

	void GlTextureLoader::bindTextures() {
		glBindTexture(GL_TEXTURE_2D, texture);
	}
}