//VertexArrayObject.h
//object that contains all things VAOs

#pragma once
#include"Include.h"
#include"AttributeBinding.h"

class VertexArrayObject {
	GLuint *bufferObject;
	GLuint *elementArray;
	GLuint *arrayObject;
	AttributeBinding *attributeBindingPoints;
	bool streamTex, streamCoord;
	int streamTexIndex, streamCoordIndex;
	GLuint count, size;
public:
	inline void Bind() {
		glBindVertexArray(*arrayObject);
	}
	inline void DrawArrays(GLenum mode, GLint first, GLsizei count) {
		Bind();
		for(int i = 0; i < size; i++)
			glEnableVertexAttribArray(attributeBindingPoints[i]);
		glDrawArrays(mode, first, count);
		for (int i = 0; i < size; i++)
			glDisableVertexAttribArray(attributeBindingPoints[i]);
	}
	inline void DrawIndices(GLenum mode, GLsizei count) {
		Bind();
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, *elementArray);
		for (int i = 0; i < size; i++)
			glEnableVertexAttribArray(attributeBindingPoints[i]);
		glDrawElements(mode, count, GL_UNSIGNED_SHORT, (void*)0);
		for (int i = 0; i < size; i++)
			glDisableVertexAttribArray(attributeBindingPoints[i]);
	}
	inline void SendData(GLfloat *data, GLsizeiptr sizeOf, GLint dataLength, AttributeBinding attributePoint, GLenum usage) {
		if (usage == GL_STREAM_DRAW) {
			if (streamCoord == false && attributePoint == ABCoord) {
				streamCoord = true;
				streamCoordIndex = count;
				count++;
			} else if (streamTex == false && attributePoint == ABTexCoord) {
				streamTex = true;
				streamTexIndex = count;
				count++;
			}
			if (attributePoint == ABCoord) {
				glBindBuffer(GL_ARRAY_BUFFER, bufferObject[streamCoordIndex]);
			}
			else {
				glBindBuffer(GL_ARRAY_BUFFER, bufferObject[streamTexIndex]);
			}
			glBufferData(GL_ARRAY_BUFFER, sizeOf, data, usage);
			glEnableVertexAttribArray(attributePoint);
			glVertexAttribPointer(attributePoint, dataLength, GL_FLOAT, GL_FALSE, 0, 0);
		} else {
			attributeBindingPoints[count] = attributePoint;
			glBindBuffer(GL_ARRAY_BUFFER, bufferObject[count]);
			glBufferData(GL_ARRAY_BUFFER, sizeOf, data, usage);
			glEnableVertexAttribArray(attributePoint);
			glVertexAttribPointer(attributePoint, dataLength, GL_FLOAT, GL_FALSE, 0, 0);
			count++;
		}
	}
	inline void SendIndices(GLushort *data, GLsizeiptr sizeOf) {
		attributeBindingPoints[count] = ABElement;
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, *elementArray);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeOf, data, GL_STATIC_DRAW);
		count++;
	}
	VertexArrayObject(GLuint numBuffers);
	~VertexArrayObject();
};