#include "FullTextureRenderer.h"

FullTextureRenderer::FullTextureRenderer(GLfloat* transformMatrix) : transformMatrix(transformMatrix), RendererBase("fulltexture_vert.glsl", "fulltexture_frag.glsl", NULL) {
	positionUL = glGetUniformLocation(shaderProgram.GetProgramID(), "position");
	transformMatrixUL = glGetUniformLocation(shaderProgram.GetProgramID(), "transformMatrix");
	scaleUL = glGetUniformLocation(shaderProgram.GetProgramID(), "scale");
	textureUL = glGetUniformLocation(shaderProgram.GetProgramID(), "texture");
}

FullTextureRenderer::~FullTextureRenderer() {
}

void FullTextureRenderer::Render() {
	shaderProgram.UseProgram();
	for (int i = 0; i < vaos.size(); i++) {
		glUniform3fv(positionUL, 1, positions[i]);
		glUniformMatrix4fv(transformMatrixUL, 1, GL_FALSE, transformMatrix);
		glUniform1f(scaleUL, *(scales[i]));
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, *(textures[i]));
		glUniform1i(textureUL, 0);
		vaos[i]->DrawArrays(GL_QUADS, 0, 4);
	}
	positions.clear();
	vaos.clear();
	scales.clear();
	textures.clear();
}