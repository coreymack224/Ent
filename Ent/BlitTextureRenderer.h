//BlitTextureRenderer.h
#pragma once
#include "RendererBase.h"

class BlitTextureRenderer :	public RendererBase {
	vector<VertexArrayObject*> vaos;
	vector<GLfloat*> scales;
	vector<GLfloat*> positions;
	vector<GLfloat*> textureMatrices;
	vector<GLfloat*> blits;
	vector<GLuint*> textures;
	GLfloat* transformMatrix;
	GLuint scaleUL, positionUL, textureMatrixUL, textureUL, transformMatrixUL, blitUL;
public:
	void Push(VertexArrayObject* vao, GLfloat* scale, GLfloat* position, GLfloat* textureMatrix, GLfloat* blit, GLuint* texture);
	void Render();
	BlitTextureRenderer(GLfloat* transformMatrix);
	~BlitTextureRenderer();
};

