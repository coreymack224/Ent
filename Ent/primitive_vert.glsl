#version 150

attribute vec3 coord;
attribute vec4 color;
uniform vec3 position;
uniform float scale;
uniform mat4 transformMatrix;
varying vec4 outColor;

void main() {
	gl_Position = transformMatrix*vec4(scale * coord + position, 1.0f);
	outColor = color;
}
