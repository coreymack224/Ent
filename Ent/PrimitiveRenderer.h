//PrimitveRenderer.h
#pragma once
#include"RendererBase.h"

class PrimitiveRenderer : public RendererBase {
	vector<GLfloat*> positions;
	vector<VertexArrayObject*> vaos;
	vector<GLfloat*> scales;
	GLfloat* transformMatrix;
	int positionUL, transformMatrixUL, scaleUL;
public:
	inline void Push(GLfloat* pos, VertexArrayObject* vao, GLfloat* scale) {
		positions.push_back(pos);
		vaos.push_back(vao);
		scales.push_back(scale);
	}
	void Render();
	PrimitiveRenderer(GLfloat *transformMatrix);
	~PrimitiveRenderer();
};