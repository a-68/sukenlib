#pragma once
#include"Manager.h"
#include"../Utility/Utility.h"
#include"../GameEngine/Physics/Vector2D.h"
#include "wininet.h"


//�Z�[�t�J���[�ɂ���
//0�A51�A102�A153�A204�A255��6�i�K��RGB�Ōv216�g���܂��B

#define RED GetColor( 255 , 0 , 0 )
#define GREEN GetColor( 0 , 255 , 0 )
#define BLUE GetColor( 0 , 0 , 255 )
#define BLACK GetColor( 0 , 0 , 0 )
#define WHITE GetColor( 255 , 255 , 255 )
#define GRAY GetColor( 128 , 128 , 128 )
#define LIGHTBLUE GetColor( 128 , 128 , 255 )
#define LIGHTGREEN GetColor( 128 , 255 , 128 )
#define M_PINK GetColor( 255 , 128 , 128 )
#define YELLOW GetColor( 255 , 255 , 0)








/**
*	@brief �_�C�A���O���J���āA�B
*	�}�b�v�G�f�B�^�Ȃǂ����Ƃ��ɕ֗�����
*	@param  filename �J�������t�@�C�������i�[����������
*	@param filetype ���ݖ���
* @return true
*/
extern bool SelectOpenFile( char *filename , char *filetype = "all file(*.*)\0*.*\0\0");
/**
*	@brief �_�C�A���O���J���āA�t�@�C����ۑ�����B
*	�}�b�v�G�f�B�^�Ȃǂ����Ƃ��ɕ֗�����
*	@param  filename �ۑ��������t�@�C�������i�[����������
*	@param filetype ���ݖ���
* @return true
*/
extern bool SaveFile(char *filename ,char *filetype =  "all file(*.*)\0*.*\0\0");
/*
�����s���G���[�̂��߃R�����g�A�E�g
void GetHttpFile(char *&Buf,char *Http,unsigned long ReadSize = 65536);
*/
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



/////FROM NUNULIB
//���ݎ����擾�֐�///////////////////////////////////////////
SYSTEMTIME GetNowSystemTime();  //SYSTEMTIME�^�œ��{�������擾
std::string GetNowSystemTimeString();  //string�^(00/00/00 00:00:00 000)�Ō��ݓ��{�������擾

inline int DrawCenterString(int cx, int y, const TCHAR *String, int color, bool centerY=false){ //x�����E�̒��S�ɂ���DrawString�ŕ����`��i��y�͏㉺���S�ł͂Ȃ���Ӂj
    if (centerY){
        return DxLib::DrawString(cx-GetDrawStringWidth(String, strlen(String))/2, y-GetFontSize()/2, String, color);    //�����܂Ŗڈ� 
    }else{
        return DxLib::DrawString(cx-GetDrawStringWidth(String, strlen(String))/2, y, String, color); 
    }
}
int DrawCenterString(int cx, int y, int color, const TCHAR* format, ...);
int DrawCenterString(int cx, int y, int color, bool centerY, const TCHAR* format, ...);

/////////////////////////////////////////////////////////////

//////////////////////////////////////

void AddFontFromPath(char *path);


void SukenExecute(char *URL);

unsigned int fanctorial(unsigned int num);			//
unsigned int combination(unsigned int n , unsigned int r);					//nCr�Ƃ���邠��B�g�ݍ��킹

typedef vector<suken::Vector2D> BEZIER ;
//�x�W�F�Ȑ��̕`��i GetBezier�֐��ō쐬�����f�[�^���K�v�@�j
////GetBezier�֐��ō쐬�����f�[�^��p���ăx�W�F�Ȑ���`�悷��
//����
// data  : GetBezier�֐��ō쐬�����x�W�F�Ȑ��f�[�^
// color : �`��F���w��
void DrawBezier( BEZIER &data ,  int color );
	//�x�W�F�Ȑ����_�f�[�^�̍쐬
////�x�W�F�Ȑ��̌v�Z���}�C�t���[������͖̂��ʂȂ̂Ōv�Z�ς݂̃f�[�^���쐬����
//����
// In�@�@�@�@: ����_�isuken::Vector2D�^�j���w�肷��i2�ȏ�j
// vertexNum : �쐬����f�[�^�ׂ̍������w��i�x�W�F�Ȑ��̍\�����_�̐��j
BEZIER GetBezier(vector<suken::Vector2D> &In , unsigned int vertexNum );
