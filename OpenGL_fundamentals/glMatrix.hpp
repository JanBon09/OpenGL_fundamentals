#pragma once

#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>

namespace fundamentals {
	class GlMatrix {
	public:
		GlMatrix();
		void glMatrixScaling(float, float, float);
		void glMatrixRotation(float, float, float, float);
		void glMatrixTranslation(float, float, float);
		void glUniformingMatrix(unsigned int);

	private:
		glm::mat4 identityMatrix;
		bool transformationsDone[3] = {false, false, false};	//Scaling -> Rotation -> Translation
		unsigned int uniformedTransformationLocation{ 0 };
	};
}