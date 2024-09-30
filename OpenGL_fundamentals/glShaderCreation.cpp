#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <fstream>
#include <cstring>

#include "glShaderCreation.hpp"

namespace fundamentals {
	GlShaders::GlShaders(const char* vp, const char* fp) : vertexShaderPath {vp}, fragmentShaderPath {fp}
	{
		inputVertexShader();
		inputFragmentShader();
	}

	GlShaders::~GlShaders() {

	}

	void GlShaders::inputVertexShader() {
		std::ifstream fin{ vertexShaderPath };
		std::string temp = "";

		if (!fin) {
			std::cerr << "Failed to open file with vertex shader path" << std::endl;
			fin.close();
			exit(EXIT_FAILURE);
		}

		while (std::getline(fin, vertexShaderSource, '\n')) {
			temp.append(vertexShaderSource + '\n');
		}

		vertexShaderSource = temp;

		fin.close();
	}

	void GlShaders::createVertexShader(unsigned int& vertexShader) {
		const char* vertexSourceCC = vertexShaderSource.c_str();
		
		vertexShader = glCreateShader(GL_VERTEX_SHADER);

		glShaderSource(vertexShader, 1, &vertexSourceCC, NULL);
		glCompileShader(vertexShader);

		int success;
		char infoLog[512];

		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
		if (!success) {
			glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
			std::cerr << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
			exit(EXIT_FAILURE);
		}
	}

	void GlShaders::inputFragmentShader() {
		std::ifstream fin{ fragmentShaderPath };
		std::string temp = "";

		if (!fin) {
			std::cerr << "Failed to open file with vertex shader path" << std::endl;
			fin.close();
			exit(EXIT_FAILURE);
		}

		while (std::getline(fin, fragmentShaderSource, '\n')) {
			temp.append(fragmentShaderSource + '\n');
		}

		fragmentShaderSource = temp;

		fin.close();
	}

	void GlShaders::createFragmentShader(unsigned int& fragmentShader) {
		const char* fragmentSourceCC = fragmentShaderSource.c_str();

		fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

		glShaderSource(fragmentShader, 1, &fragmentSourceCC, NULL);
		glCompileShader(fragmentShader);

		int success;
		char infoLog[512];

		glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
		if (!success) {
			glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
			std::cerr << "ERROR::SHADER::fragment::COMPILATION_FAILED\n" << infoLog << std::endl;
			exit(EXIT_FAILURE);
		}
	}
}