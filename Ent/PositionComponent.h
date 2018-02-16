//PositionComponent.h
#pragma once
#include"ComponentBase.h"

//Cuz these classes are short and sweet

class PositionComponent : public ComponentBase, public glm::vec3 {
public:
	glm::vec3 offset;
	inline void Update() { *this += offset; }
	inline PositionComponent(glm::vec3 offset) : offset(offset) {
		x = y = z = 0.0f;
	}
};