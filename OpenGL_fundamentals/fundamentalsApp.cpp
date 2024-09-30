#include "fundamentalsApp.hpp"

namespace fundamentals {
	FundamentalsApp::FundamentalsApp() {
		init.glInit();
		window.glGLFWWindowCreation();
		init.glGLADInit();
		shaderProgram.glCreateShaderProgram();
	}

	FundamentalsApp::~FundamentalsApp() {
		glfwTerminate();
	}

	void FundamentalsApp::runApp() {
		while (!window.glCloseWindow()) {
			window.glWindowInput();

			window.glColorClear();

			shaderProgram.glUsingProgram();

			window.glLooper();
		}
	}
}