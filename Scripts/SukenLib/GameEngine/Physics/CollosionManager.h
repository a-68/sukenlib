#pragma once
//for CCircle
#include"Primitive\Circle.h"
//for CRect
#include"Primitive\Rect.h"

///////////////////////////////////////////////////////////////////////
////////////�Ǝ��̃v���~�e�B�u�ǉ��p�C���N���[�h ��������//////////////
///////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////
////////////�Ǝ��̃v���~�e�B�u�ǉ��p�C���N���[�h �����܂�//////////////
///////////////////////////////////////////////////////////////////////

namespace suken{

class CCollisionManager{
public:
	CCollisionManager();
	~CCollisionManager();
	void Awake();
	void Loop();
	void DrawLoop();
	void CollisionCircleCalc(CCircle &A , CCircle &B ,float time);
	bool CollisionCircle(CCircle &A , CCircle &B );
	bool CollisionRect(suken::CRect &A , suken::CRect &B);
	void AddChild(CCircle *_circle , bool moveFlag);
	bool RemoveChild(CCircle *_circle);
	void AddChild(suken::CRect *_rect , bool moveFlag);
	bool RemoveChild(suken::CRect *_rect);
	vector<CCircle*> physicsCircle;
	vector<CCircle*> fixedCircle;
	vector<CRect*> fixedRect;
	vector<CRect*> physicsRect;
};


}