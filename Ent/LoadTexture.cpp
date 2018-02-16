//LoadTexture.cpp

#include "LoadTexture.h"
//#include "Debug.h"

GLuint LoadTexture(string filename, GLfloat* width, GLfloat* height) {
	GLuint texture;
	SDL_Surface* surface = SDL_LoadBMP(filename.c_str());;
	//DebugFile& Dbg = DebugFile::GetInstance();
	if (surface != NULL) {
		if (width != NULL)
			*width = surface->w;
		if (height != NULL)
			*height = surface->h;
		glGenTextures(1, &texture);
		glBindTexture(GL_TEXTURE_2D, texture);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, surface->w, surface->h, 0, GL_BGR, GL_UNSIGNED_BYTE, surface->pixels);
/*		//color key
		GLuint size = (*width) * (*height);
		GLuint *pixels = new GLuint[size];
		glGetTexImage(GL_TEXTURE_2D, 0, GL_BGR, GL_UNSIGNED_BYTE, pixels);
		for (int i = 0; i < size; ++i)
		{
			//Get pixel colors
			GLubyte* colors = (GLubyte*)&(pixels[i]);
			//Color matches
			if (colors[0] == 255 && colors[1] == 0 && colors[2] == 255)
			{
				//Make transparent
				colors[0] = 255;
				colors[1] = 255;
				colors[2] = 255;
				colors[3] = 000;
			}
		}
		
		glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, *width, *height, GL_RGBA, GL_UNSIGNED_BYTE, pixels);
		delete pixels;
*/
		SDL_FreeSurface(surface);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		return texture;
	} else {
	//	Dbg.Print("failed to load texture");
	//	Dbg.Print(filename.c_str());
	}
}