#include "VertexArrayObject.h"

VertexArrayObject::VertexArrayObject(GLuint numBuffers) {
	size = numBuffers;
	count = 0;
	bufferObject = new GLuint[numBuffers];
	attributeBindingPoints = new AttributeBinding[numBuffers];
	arrayObject = new GLuint;
	elementArray = new GLuint;
	streamCoord = streamTex = false;

	glGenVertexArrays(1, arrayObject);
	glGenBuffers(size, bufferObject);
	glGenBuffers(1, elementArray);
}

VertexArrayObject::~VertexArrayObject() {
	glDeleteBuffers(size, bufferObject);
	glDeleteBuffers(1, elementArray);
	glDeleteVertexArrays(1, arrayObject);
	delete arrayObject;
	delete elementArray;
	delete[] attributeBindingPoints;
	delete[] bufferObject;
}