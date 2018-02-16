//Shader.cpp

#include"Shader.h"
//#include"Debug.h"
#include"LoadFile.h"

Shader::Shader(const char *vertexFile, const char *fragmentFile, const char *geometryFile) {
	program = glCreateProgram();

	//Vertex Shader
	string vertexString = LoadFile(vertexFile);
	const char *vertexSource = vertexString.c_str();
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexSource, NULL);
	glCompileShader(vertexShader);
	CheckError(vertexShader, vertexFile);
	glAttachShader(program, vertexShader);
	
	//Fragment Shader
	string fragmentString = LoadFile(fragmentFile);
	const char *fragmentSource = fragmentString.c_str();
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
	glCompileShader(fragmentShader);
	CheckError(fragmentShader, fragmentFile);
	glAttachShader(program, fragmentShader);

	//Geometry Shader
	if (geometryFile != NULL) {
		string geometryString = LoadFile(geometryFile);
		const char* geometrySource = geometryString.c_str();
		geometryUse = true;
		geometryShader = glCreateShader(GL_GEOMETRY_SHADER);
		glShaderSource(geometryShader, 1, &geometrySource, NULL);
		glCompileShader(geometryShader);
		if (CheckError(geometryShader, geometryFile)) {
			glDeleteShader(geometryShader);
			geometryUse = false;
		} else {
			glAttachShader(program, geometryShader);
		}
	} else {
		geometryUse = false;
	}

	//Attribute Locations
	glBindAttribLocation(program, ABCoord, "coord");
	glBindAttribLocation(program, ABColor, "color");
	glBindAttribLocation(program, ABTexCoord, "texCoord");
	glBindAttribLocation(program, ABNormal, "normal");
}

Shader::~Shader() {
	glDetachShader(program, vertexShader);
	glDeleteShader(vertexShader);
	glDetachShader(program, fragmentShader);
	glDeleteShader(fragmentShader);
	if (geometryUse == true) {
		glDetachShader(program, geometryShader);
		glDeleteShader(geometryShader);
	}
	glDeleteProgram(program);
}

bool CheckError(GLuint shader, const char* name) {
	GLchar err[512];
	GLint success;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if (!success) {
		//DebugFile& Dbg = DebugFile::GetInstance();
		glGetShaderInfoLog(shader, 512, NULL, err);
		cout << err << endl;
		//
		cout << "Error in shader: " << name << endl;
		cout << err << endl;
		//Dbg.Print("Error in shader");
		//Dbg.Print(name);
		//Dbg.Print(err);
		return true;
	}
	return false;
}