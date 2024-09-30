#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<iostream>

#include "glShaderProgram.hpp"

namespace fundamentals {
	GlShaderProgram::GlShaderProgram() 
	{
	}

	GlShaderProgram::~GlShaderProgram() {
		glDeleteProgram(shaderProgram);
	}

	void GlShaderProgram::glCreateShaderProgram() {
		shaders.createVertexShader(vertexShader);
		shaders.createFragmentShader(fragmentShader);

		shaderProgram = glCreateProgram();

		glAttachShader(shaderProgram, vertexShader);
		glAttachShader(shaderProgram, fragmentShader);
		glLinkProgram(shaderProgram);

		int success;
		char infoLog[512];

		glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
		if (!success) {
			glGetShaderInfoLog(shaderProgram, 512, NULL, infoLog);
			std::cerr << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
		}

		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);
	}

	void GlShaderProgram::glUsingProgram() {
		glUseProgram(shaderProgram);
	}
}