//Events.cpp

#include"Events.h"

bool Events::KeyDown(SDL_Scancode key) {
	return (keys[key] == 1);
}

bool Events::KeyHit(SDL_Scancode key) {
	if (events.type == SDL_KEYDOWN && keyHitVar == false) {
		keyHitVar = true;
		return (keys[key]);
	}
	return false;
}

bool Events::MouseDown(int button) {
	return mouseButtons[button - 1];
}

bool Events::MouseHit(int button) {
	if (events.type == SDL_MOUSEBUTTONDOWN && mouseHitVar == false) {
		mouseHitVar = true;
		return mouseButtons[button - 1];
	}
	return false;
}

void Events::Update() {
	SDL_PollEvent(&events);
	keys = SDL_GetKeyboardState(NULL);
	SDL_GetMouseState(&mouseX, &mouseY);
	for (int i = 0; i < 3; i++)
		mouseButtons[i] = false;
	if (events.type == SDL_MOUSEBUTTONDOWN)
		mouseButtons[events.button.button - 1] = true;
	if (events.type == SDL_KEYUP)
		keyHitVar = false;
	if (events.type == SDL_MOUSEBUTTONUP)
		mouseHitVar = false;
}

Events::Events() {
	Update();
	keyHitVar = mouseHitVar = false;
	for (int i = 0; i < 3; i++)
		mouseButtons[i] = false;
}