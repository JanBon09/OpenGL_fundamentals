#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<iostream>

#include "glInit.hpp"

namespace fundamentals {
	GlInitialization::GlInitialization(int mv, int mmv) 
		: majorVersion{mv}, minorVersion{mmv}
	{
	}

	GlInitialization::~GlInitialization() {

	}

	void GlInitialization::glInit() {
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, majorVersion);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, minorVersion);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	}


	void GlInitialization::glGLADInit() {
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
			std::cerr << "Failed to create initialize GLAD" << std::endl;
			exit(EXIT_FAILURE);
		}
	}

}