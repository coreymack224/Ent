//SDLWindowGLContext.cpp

#include"SDLWindowGLContext.h"

SDLWindowGLContext::SDLWindowGLContext() {
	SDL_Init(SDL_INIT_EVERYTHING);
	//create the stuff
	window = SDL_CreateWindow("Ent - Engine v0", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_OPENGL);
	context = SDL_GL_CreateContext(window);
	
	//init some stuff and set some stuff
	glewInit();
	
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_COLOR);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glEnable(GL_TEXTURE_2D);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClearDepth(10.0);
}

SDLWindowGLContext::~SDLWindowGLContext() {
	SDL_DestroyWindow(window);
	SDL_GL_DeleteContext(context);

	SDL_Quit();
}