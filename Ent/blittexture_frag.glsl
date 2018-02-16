#version 150

varying vec4 outColor;
varying vec2 tCoord;

uniform sampler2D texture;
uniform mat2 textureMatrix;
uniform vec2 blit;

void main () {
	vec4 texColor = texture2D(texture, textureMatrix * (tCoord + blit));
	gl_FragColor = outColor * texColor;
}