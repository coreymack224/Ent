//Events.h
//Input handler and that sort of thing

#pragma once

#include"Include.h"

class Events {
	bool mouseButtons[3];
	const Uint8* keys;
	SDL_Event events;
	bool mouseHitVar, keyHitVar;
	int mouseX, mouseY;
public:
	inline int GetX() {
		return mouseX;
	}
	inline int GetY() {
		return mouseY;
	}
	inline bool Exit() {
		return (events.type == SDL_QUIT);
	}
	bool KeyDown(SDL_Scancode key);
	bool KeyHit(SDL_Scancode key);
	bool MouseDown(int button);
	bool MouseHit(int button);

	void Update();

	Events();
};