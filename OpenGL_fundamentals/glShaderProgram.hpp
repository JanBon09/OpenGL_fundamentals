#pragma once

#include "glShaderCreation.hpp"

namespace fundamentals {
	class GlShaderProgram {
	public:
		GlShaderProgram();
		~GlShaderProgram();

		void glCreateShaderProgram();
		void glUsingProgram();
	private:
		unsigned int vertexShader = 0, fragmentShader = 0, shaderProgram = 0;
		GlShaders shaders{"D:\\OpenGL_Projects\\OpenGL_fundamentals\\OpenGL_fundamentals\\vertexShader.vert", "D:\\OpenGL_Projects\\OpenGL_fundamentals\\OpenGL_fundamentals\\fragmentShader.frag" };
	};
}