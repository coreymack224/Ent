#include "BlitTextureRenderer.h"

BlitTextureRenderer::BlitTextureRenderer(GLfloat* transformMatrix) : transformMatrix(transformMatrix), RendererBase("blittexture_vert.glsl", "blittexture_frag.glsl", NULL) {
	transformMatrixUL = glGetUniformLocation(shaderProgram.GetProgramID(), "transformMatrix");
	scaleUL = glGetUniformLocation(shaderProgram.GetProgramID(), "scale");
	positionUL = glGetUniformLocation(shaderProgram.GetProgramID(), "position");
	blitUL = glGetUniformLocation(shaderProgram.GetProgramID(), "blit");
	textureMatrixUL = glGetUniformLocation(shaderProgram.GetProgramID(), "textureMatrix");
	textureUL = glGetUniformLocation(shaderProgram.GetProgramID(), "texture");
}

BlitTextureRenderer::~BlitTextureRenderer() {
}

void BlitTextureRenderer::Push(VertexArrayObject* vao, GLfloat* scale, GLfloat* position, GLfloat* textureMatrix, GLfloat* blit, GLuint* texture) {
	positions.push_back(position);
	scales.push_back(scale);
	textures.push_back(texture);
	blits.push_back(blit);
	textureMatrices.push_back(textureMatrix);
	vaos.push_back(vao);
}

void BlitTextureRenderer::Render() {
	shaderProgram.UseProgram();
	for (int i = 0; i < vaos.size(); i++) {
		glUniform3fv(positionUL, 1, positions[i]);
		glUniform1f(scaleUL, *scales[i]);
		glUniformMatrix2fv(textureMatrixUL, 1, GL_FALSE, textureMatrices[i]);
		glUniform2fv(blitUL, 1, blits[i]);
		glUniformMatrix4fv(transformMatrixUL, 1, GL_FALSE, transformMatrix);
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, *textures[i]);
		glUniform1i(textureUL, 0);
		vaos[i]->DrawArrays(GL_QUADS, 0, 4);
	}
	positions.clear();
	scales.clear();
	textures.clear();
	blits.clear();
	textureMatrices.clear();
	vaos.clear();
}