#include"Include.h"
#include"Events.h"
#include"SDLWindowGLContext.h"
#include"LoadTexture.h"
#include"PrimitiveComponent.h"
#include"FullTextureRenderer.h"

int main(int argc, char **argv) {
	SDLWindowGLContext thing;
	Events events;
	GLuint texture = LoadTexture("point_light.bmp", NULL, NULL);
	GLfloat coords[] = {
		0.0f, 0.0f, 0.0f,
		64.0f, 0.0f, 0.0f,
		64.0f, 64.0f, 0.0f,
		0.0f, 64.0f, 0.0f
	};
	GLfloat texCoords[] = {
		0.0f, 0.0f,
		256.0f, 0.0f,
		256.0f, 256.0f,
		0.0f, 256.0f
	};
	GLfloat colors[] = {
		1.0f, 1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f, 1.0f
	}; 
	glm::mat4 transformMatrix = {
		1.0f / 320.0f, 0.0f, 0.0f, 0.0f,
		0.0f, -1.0f / 240.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		-1.0f, 1.0f, 0.0, 1.0f
	};
	glm::mat2 textureMatrix = {
		1.0f / 512.0f, 0.0f, 0.0f, 1.0f / 512.0f
	};
	glm::vec2 frame = { 0.0f, 0.0f }, frameSize = { 256.0f, 256.0f }, blit = frame * frameSize;

	VertexArrayObject vao(3);
	vao.Bind();
	vao.SendData(coords, sizeof(coords), 3, ABCoord, GL_STATIC_DRAW);
	vao.SendData(colors, sizeof(colors), 4, ABColor, GL_STATIC_DRAW);
	vao.SendData(texCoords, sizeof(texCoords), 2, ABTexCoord, GL_STATIC_DRAW);
	glm::vec3 p = { 0.0f, 0.0f, 0.0f };

	PrimitiveRenderer pr(&transformMatrix[0][0]);
	PositionComponent pos({ 0.0f, 0.0f, 0.0f });
	PrimitiveComponent pc(&pr, &pos);
	pc.vao.Bind();
	pc.vao.SendData(coords, sizeof(coords), 3, ABCoord, GL_STATIC_DRAW);
	pc.vao.SendData(colors, sizeof(colors), 4, ABColor, GL_STATIC_DRAW);

	FullTextureRenderer ftr(&transformMatrix[0][0]);
	GLfloat scale = 1.0f;
	while (!events.Exit()) {
		events.Update();
		thing.Clear();
		pos.Update();
		ftr.Push(&p[0], &vao, &scale, &texture);

		ftr.Render();
		
		thing.Flip();
	}
	
	glDeleteTextures(1, &texture);
	
	return 0;
}