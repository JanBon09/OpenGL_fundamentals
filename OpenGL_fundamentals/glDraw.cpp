#include<glad/glad.h>
#include<GLFW/glfw3.h>

#include "glDraw.hpp"

namespace fundamentals {
	GlDraw::GlDraw(){}
	GlDraw::~GlDraw(){}

	void GlDraw::glDrawing(int first) {
		glDrawElements(GL_TRIANGLES, first, GL_UNSIGNED_INT, 0);
	}
}