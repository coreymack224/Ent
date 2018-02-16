//SDLWindowGLContext
//Class that holds the SDL window and the OpenGL Context

#pragma once

#include"Include.h"

class SDLWindowGLContext {
	SDL_Window *window;
	SDL_GLContext context;
public:
	inline void Flip() {
		SDL_GL_SwapWindow(window);
	}
	inline void Clear() {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	SDLWindowGLContext();
	~SDLWindowGLContext();
};