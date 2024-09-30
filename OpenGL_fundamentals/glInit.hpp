#pragma once

#include <string>

namespace fundamentals {
	class GlInitialization {
	public:
		GlInitialization(int, int);
		~GlInitialization();

		void glInit();

		void glGLADInit();

	private:
		int majorVersion, minorVersion;
		
	};
}