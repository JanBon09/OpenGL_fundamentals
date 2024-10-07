#pragma once

namespace fundamentals {
	class GlBuffor {
	public:
		GlBuffor(const char*, const char*);
		~GlBuffor();

		void glBuffersCreation(int, int, int);
		void glBufferBinding();
		void glReadVertices();
		void glReadIndices();
	private:
		unsigned int VBO, VAO, EBO;
		float vertices[32];
		int indices[6];
		const char* verticesPath;
		const char* indicesPath;
	};
}