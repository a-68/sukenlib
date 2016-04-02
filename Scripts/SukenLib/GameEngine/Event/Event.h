#pragma once
//for CKey
#include"Key.h"
//for CMouse
#include"Mouse.h"

namespace suken{


//���̓C�x���g��`�N���X
class CEvent{
public:
	CEvent();
	void Loop();
	void Activate();
	void Deactivate();
	bool GetValid();
	char EVERY_FRAME;
	CKey key;
	CMouse LMouse;
	CMouse RMouse;
private:
	bool IsActivated;
};

}

extern suken::CEvent Event;
