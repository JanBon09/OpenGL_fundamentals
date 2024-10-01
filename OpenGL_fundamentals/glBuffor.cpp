#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <fstream>
#include <string>

#include "glBuffor.hpp"

namespace fundamentals {
	GlBuffor::GlBuffor(const char* vp) : verticesPath{vp} {
		glReadVertices();
	}

	GlBuffor::~GlBuffor() {
		glDeleteVertexArrays(1, &VAO);
		glDeleteBuffers(1, &VBO);
	}

	void GlBuffor::glBuffersCreation(int numberOfVAO, int numberOfVBO) {
		glGenVertexArrays(numberOfVAO, &VAO);
		glGenBuffers(numberOfVBO, &VBO);

		glBindVertexArray(VAO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

		glEnableVertexAttribArray(0);

		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);
	}

	void GlBuffor::glBufferBinding() {
		glBindVertexArray(VAO);
	}

	void GlBuffor::glReadVertices() {
		std::ifstream fin{ verticesPath };
		std::string temp;

		int i{ 0 };
		while (std::getline(fin, temp, ' ')) {
			vertices[i] = stof(temp);
			i++;
		}

		fin.close();
	}
}