#pragma once

#include "glInput.hpp"

namespace fundamentals {
	class GlWindow {
	public:
		GlWindow(int, int, const char*);
		~GlWindow();

		void glGLFWWindowCreation();
		void glLooper();
		bool glCloseWindow();
		void glWindowInput();
		static void glFrambufferSizeCallback(GLFWwindow*, int, int);
		void glColorClear();

	private:
		GLFWwindow* window;
		GlWindowController windowController;
		int width, height;
		const char* title;
	};
}