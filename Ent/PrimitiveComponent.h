//PrimitiveComponent.h
#pragma once
#include"ComponentBase.h"
#include"PositionComponent.h"
#include"PrimitiveRenderer.h"

class PrimitiveComponent : public ComponentBase {
	PrimitiveRenderer* pr;	//poop
	PositionComponent* pos;
public:
	GLfloat scale;
	VertexArrayObject vao;
	inline void Update() {
		pr->Push(&pos->x, &vao, &scale);
	}
	inline PrimitiveComponent(PrimitiveRenderer* pr, PositionComponent* pos) : vao(2), pr(pr), pos(pos), scale(1.0f) {}
	~PrimitiveComponent();
};

