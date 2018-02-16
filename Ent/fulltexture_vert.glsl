#version 150

uniform vec3 position;
uniform float scale;
uniform mat4 transformMatrix;

attribute vec3 coords;
attribute vec2 texCoords;
attribute vec4 color;

varying vec2 tCoords;
varying vec4 outColor;

void main() {
	tCoords = texCoords;
	outColor = color;

	gl_Position = transformMatrix * vec4(scale * coords + position, 1.0f);
}