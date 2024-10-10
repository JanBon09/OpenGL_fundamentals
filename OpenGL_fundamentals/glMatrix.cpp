#include <iostream>
#include <glad/glad.h>

#include "glMatrix.hpp"

namespace fundamentals {
	GlMatrix::GlMatrix() {
		identityMatrix = glm::mat4(1.0f);
	}

	void GlMatrix::glMatrixTranslation(float x, float y, float z) {
		transformationsDone[0] = true;
		if (transformationsDone[1] || transformationsDone[2]) {
			std::cerr << "Wrong order of transformations" << std::endl;
			return;
		}
		else {
			identityMatrix = glm::translate(identityMatrix, glm::vec3(x, y, z));
		}
	}

	void GlMatrix::glMatrixRotation(float deegres,float x, float y, float z) {
		transformationsDone[1] = true;
		if (transformationsDone[2]) {
			std::cerr << "Wrong order of transformations" << std::endl;
			return;
		}
		else {
			identityMatrix = glm::rotate(identityMatrix, glm::radians(deegres), glm::vec3(x, y, z));
		}
	}

	void  GlMatrix::glMatrixScaling(float x, float y, float z) {
		transformationsDone[2] = true;
		identityMatrix = glm::scale(identityMatrix, glm::vec3(x, y, z));
	}

	void GlMatrix::glUniformingMatrix(unsigned int shaderProgramId) {
		uniformedTransformationLocation = glGetUniformLocation(shaderProgramId, "transform");
		glUniformMatrix4fv(uniformedTransformationLocation, 1, GL_FALSE, glm::value_ptr(identityMatrix));
	}
}