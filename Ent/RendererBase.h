//RendererBase.h
#pragma once
#include"Shader.h"
#include"VertexArrayObject.h"

class RendererBase {
protected:
	Shader shaderProgram;
	inline RendererBase(const char* vert, const char* frag, const char* geom) : shaderProgram(vert, frag, geom) {
		shaderProgram.Link();
	}
};