#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <fstream>
#include <string>
#include <iostream>

#include "glBuffor.hpp"

namespace fundamentals {
	GlBuffor::GlBuffor(const char* vp, const char* ip) : verticesPath{ vp }, indicesPath{ ip } {
		glReadVertices();
		glReadIndices();
	}

	GlBuffor::~GlBuffor() {
		glDeleteVertexArrays(1, &VAO);
		glDeleteBuffers(1, &VBO);
		glDeleteBuffers(1, &EBO);
	}

	void GlBuffor::glBuffersCreation(int numberOfVAO, int numberOfVBO, int numberOfEBO) {
		glGenVertexArrays(numberOfVAO, &VAO);
		glGenBuffers(numberOfVBO, &VBO);
		glGenBuffers(numberOfEBO, &EBO);

		glBindVertexArray(VAO);

		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);

		glEnableVertexAttribArray(0);

		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));

		glEnableVertexAttribArray(1);

		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));

		glEnableVertexAttribArray(2);

		glBindVertexArray(0);
	}

	void GlBuffor::glBufferBinding() {
		glBindVertexArray(VAO);
	}

	void GlBuffor::glReadVertices() {
		std::ifstream fin{ verticesPath };
		std::string temp;

		if (!fin) {
			std::cerr << "Failed to open vertices file" << std::endl;
			fin.close();
			exit(EXIT_FAILURE);
		}

		int i{ 0 };
		while (std::getline(fin, temp, ' ')) {
			vertices[i] = stof(temp);
			i++;
		}

		fin.close();
	}

	void GlBuffor::glReadIndices() {
		std::ifstream fin{ indicesPath };
		std::string temp;

		if (!fin) {
			std::cerr << "Failed to open vertices file" << std::endl;
			fin.close();
			exit(EXIT_FAILURE);
		}

		int i{ 0 };
		while (std::getline(fin, temp, ' ')) {
			indices[i] = std::stoi(temp);
			i++;
		}

		fin.close();
	}
}