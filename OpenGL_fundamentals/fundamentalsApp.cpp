#include "fundamentalsApp.hpp"

namespace fundamentals {
	FundamentalsApp::FundamentalsApp() {
		init.glInit();
		window.glGLFWWindowCreation();
		init.glGLADInit();
		shaderProgram.glCreateShaderProgram();
		buffor.glBuffersCreation(1, 1);
	}

	FundamentalsApp::~FundamentalsApp() {
		glfwTerminate();
	}

	void FundamentalsApp::runApp() {
		while (!window.glCloseWindow()) {
			window.glWindowInput();

			window.glColorClear();

			shaderProgram.glUsingProgram();

			buffor.glBufferBinding();

			draw.glDrawing(0, 3);

			window.glLooper();
		}
	}
}