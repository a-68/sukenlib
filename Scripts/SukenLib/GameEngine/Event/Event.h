#pragma once
#include"Key.h"
#include"Mouse.h"

namespace suken{
const char FRAME_EVENT	=	'E';


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
//Singleton
extern suken::CEvent Event;
