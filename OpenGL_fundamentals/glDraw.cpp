#include<glad/glad.h>
#include<GLFW/glfw3.h>

#include "glDraw.hpp"

namespace fundamentals {
	GlDraw::GlDraw(){}
	GlDraw::~GlDraw(){}

	void GlDraw::glDrawing(int first, int second) {
		glDrawArrays(GL_TRIANGLES, first, second);
	}
}