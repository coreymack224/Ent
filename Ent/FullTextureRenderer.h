//FullTextureRenderer.h
#pragma once

#include"RendererBase.h"

class FullTextureRenderer : public RendererBase {
	vector<GLfloat*> positions;
	vector<VertexArrayObject*> vaos;
	vector<GLfloat*> scales;
	vector<GLuint*> textures;
	GLfloat* transformMatrix;
	int positionUL, scaleUL, textureUL, transformMatrixUL;
public:
	inline void Push(GLfloat* position, VertexArrayObject* vao, GLfloat* scale, GLuint* texture) {
		positions.push_back(position);
		vaos.push_back(vao);
		scales.push_back(scale);
		textures.push_back(texture);
	}
	void Render();
	FullTextureRenderer(GLfloat* transformMatrix);
	~FullTextureRenderer();
};

