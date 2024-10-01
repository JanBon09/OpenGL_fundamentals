#pragma once

namespace fundamentals {
	class GlBuffor {
	public:
		GlBuffor(const char*);
		~GlBuffor();

		void glBuffersCreation(int, int);
		void glBufferBinding();
		void glReadVertices();
	private:
		unsigned int VBO, VAO;
		float vertices[9];
		const char* verticesPath;
	};
}