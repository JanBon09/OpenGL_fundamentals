#pragma once

#include <string>

namespace fundamentals {
	class GlShaders {
	public:
		GlShaders(const char*, const char*);
		~GlShaders();

		void inputVertexShader();
		void createVertexShader(unsigned int&);
		
		void inputFragmentShader();
		void createFragmentShader(unsigned int&);

	private:
		const char* vertexShaderPath;
		const char* fragmentShaderPath;

		std::string vertexShaderSource, fragmentShaderSource;

	};
}