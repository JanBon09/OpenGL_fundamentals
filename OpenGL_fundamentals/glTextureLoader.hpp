#pragma once

namespace fundamentals {
	class GlTextureLoader {
	public:
		GlTextureLoader();
		void loadTextures();
		void bindTextures();
	private:
		int width, height, nrChannels;
		unsigned char* data;
		unsigned int texture;
	};
}