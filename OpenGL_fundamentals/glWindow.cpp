#include<iostream>

#include "glWindow.hpp"

namespace fundamentals {
	GlWindow::GlWindow(int w, int h, const char* tit)
		: width {w}, height {h}, title {tit}
	{
	}

	GlWindow::~GlWindow() {
		glfwDestroyWindow(window);
	}

	void GlWindow::glGLFWWindowCreation() {
		window = glfwCreateWindow(width, height, title, NULL, NULL);
		if (window == NULL) {
			std::cerr << "Failed to create GLFW window" << std::endl;
			glfwTerminate();
			exit(EXIT_FAILURE);
		}

		glfwMakeContextCurrent(window);
		glfwSetFramebufferSizeCallback(window, glFrambufferSizeCallback);
	}

	void GlWindow::glLooper() {
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	bool GlWindow::glCloseWindow() {
		return glfwWindowShouldClose(window);
	}

	void GlWindow::glWindowInput() {
		windowController.glProcessInput(window);
	}

	void GlWindow::glFrambufferSizeCallback(GLFWwindow* window, int width, int height) {
		glViewport(0, 0, width, height);
	}

	void GlWindow::glColorClear() {
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
	}
}