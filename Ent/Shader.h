//Shader.h

#pragma once

#include"Include.h"
#include"AttributeBinding.h"

bool CheckError(GLuint shader, const char *name);

class Shader {
	GLuint vertexShader, fragmentShader, geometryShader;
	GLuint program;
	bool geometryUse;
public:
	inline GLuint GetProgramID() {
		return program;
	}
	inline void UseProgram() {
		glUseProgram(program);
	}
	inline void Link() {
		glLinkProgram(program);
	}
	Shader(const char *vertexFile, const char *fragmentFile, const char *geometryFile);
	~Shader();
};