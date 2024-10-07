#include "fundamentalsApp.hpp"

namespace fundamentals {
	FundamentalsApp::FundamentalsApp() {
		init.glInit();
		window.glGLFWWindowCreation();
		init.glGLADInit();
		shaderProgram.glCreateShaderProgram();
		buffor.glBuffersCreation(1, 1);
		textures.loadTextures();
	}

	FundamentalsApp::~FundamentalsApp() {
		glfwTerminate();
	}

	void FundamentalsApp::runApp() {
		while (!window.glCloseWindow()) {
			window.glWindowInput();

			window.glColorClear();

			textures.bindTextures();

			shaderProgram.glUsingProgram();

			buffor.glBufferBinding();

			draw.glDrawing(0, 6);

			window.glLooper();
		}
	}
}