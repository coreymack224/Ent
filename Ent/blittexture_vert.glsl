#version 150

attribute vec3 coord;
attribute vec4 color;
attribute vec2 texCoord;

uniform vec3 position;
uniform mat4 transformMatrix;
uniform float scale;

varying vec4 outColor;
varying vec2 tCoord;

void main() {
	outColor = color;
	tCoord = texCoord;
	gl_Position = transformMatrix * vec4(scale * coord + position, 1.0f);
}