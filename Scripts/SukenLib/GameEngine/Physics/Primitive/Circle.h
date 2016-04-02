#pragma once
#include"Primitive.h"


namespace suken{

class CCircle : public suken::CPrimitive {
public:
	CCircle();
//�Ǝ�
	float radius;
	float mass;
	float bound;
	bool IsKinematic;
	static const int figureType = SHAPE_CIRCLE; 
	suken::Vector2D GetCenterPos();
	float GetArea();
	void Loop();
	void AddCollisionFalse(CCircle *c);
	void RemoveCollisionFalse(CCircle *c);
	bool GetIsNoCollision(CCircle *c);
private:
	std::vector<CCircle*> noCollision;
};

}