#include "fundamentalsApp.hpp"

namespace fundamentals {
	FundamentalsApp::FundamentalsApp() {
		init.glInit();
		window.glGLFWWindowCreation();
		init.glGLADInit();
		shaderProgram.glCreateShaderProgram();
		buffor.glBuffersCreation(1, 1, 1);
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

			matrix.glMatrixTranslation(0.5f, -0.5f, 0.0f);
			matrix.glMatrixRotation((float)glfwGetTime(), 0.0f, 0.0f, 1.0f);
			

			shaderProgram.glUsingProgram();

			matrix.glUniformingMatrix(shaderProgram.glShaderProgram());

			buffor.glBufferBinding();

			draw.glDrawing(6);

			window.glLooper();
		}
	}
}