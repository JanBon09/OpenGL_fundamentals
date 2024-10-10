#pragma once

#include "glInit.hpp"
#include "glWindow.hpp"
#include "glShaderProgram.hpp"
#include "glBuffor.hpp"
#include "glDraw.hpp"
#include "glTextureLoader.hpp"
#include "glMatrix.hpp"

namespace fundamentals {
	class FundamentalsApp {
	public:
		FundamentalsApp();
		~FundamentalsApp();

		void runApp();
	private:
		GlInitialization init{ 3, 3};
		GlWindow window{ 800, 600, "Sielol" };
		GlShaderProgram shaderProgram;
		GlBuffor buffor{"D:\\OpenGL_Projects\\OpenGL_fundamentals\\OpenGL_fundamentals\\vertices.txt","D:\\OpenGL_Projects\\OpenGL_fundamentals\\OpenGL_fundamentals\\indices.txt" };
		GlDraw draw;
		GlTextureLoader textures;
		GlMatrix matrix;
	};
}