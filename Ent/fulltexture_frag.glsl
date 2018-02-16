#version 150

uniform sampler2D texture;

varying vec4 outColor;
varying vec2 tCoords;

void main() {
	gl_FragColor = outColor * texture2D(texture, tCoords);
}