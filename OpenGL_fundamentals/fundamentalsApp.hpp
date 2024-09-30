#pragma once

#include "glInit.hpp"
#include "glWindow.hpp"
#include "glShaderProgram.hpp"

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
	};
}