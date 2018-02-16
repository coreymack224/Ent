#include "PrimitiveRenderer.h"


void PrimitiveRenderer::Render() {
	shaderProgram.UseProgram();
	for (int i = 0; i < vaos.size(); i++) {
		glUniform3fv(positionUL, 1, (GLfloat*)(positions[i]));
		glUniform1f(scaleUL, *(scales[i]));
		glUniformMatrix4fv(transformMatrixUL, 1, GL_FALSE, transformMatrix);
		vaos[i]->DrawArrays(GL_QUADS, 0, 4);
	}
	vaos.clear();
	scales.clear();
	positions.clear();
}

PrimitiveRenderer::PrimitiveRenderer(GLfloat *transformMatrix) : RendererBase("primitive_vert.glsl", "primitive_frag.glsl", NULL) {
	this->transformMatrix = transformMatrix;
	positionUL = glGetUniformLocation(shaderProgram.GetProgramID(), "position");
	transformMatrixUL = glGetUniformLocation(shaderProgram.GetProgramID(), "transformMatrix");
	scaleUL = glGetUniformLocation(shaderProgram.GetProgramID(), "scale");
}

PrimitiveRenderer::~PrimitiveRenderer() {
}