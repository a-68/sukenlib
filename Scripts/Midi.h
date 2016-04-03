#pragma once
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib,"winmm")

class CMidi{
	
private:
	HMIDIOUT hMidiOut;
	DWORD MIDIMSG(BYTE _status, BYTE _channel, BYTE  _data1, BYTE _data2){
		return (DWORD)((_status << 4) | _channel | (_data1 << 8) | (_data2 << 16));
	}
public:
	CMidi();
	~CMidi();
	//���̊֐����Ăяo���Ɩ炷���Ƃ��o����
	//BYTE �͐�����0~127���󂯕t����ƍl����Ƃ����B
	//_Height�͉��̍���(0~127)
	//_Velocity�͉��̋���(0~127)
	//_channel �͖炷�`�����l���A�����̊y��p�[�g���g�������Ƃ��Ɏg��
	void Lang(BYTE _Height, BYTE _Velocity, BYTE _channnel);
	//���̍����̉��̍Đ����~�߂�
	void Stop(BYTE _Height, BYTE _channnel);
	//�y���ς���
	void ChangeTimble(BYTE _Timble, BYTE _channnel);

};
//�Ⴆ�� MD.Lang(100, 72)��Midi��点��B
