#pragma once
#include "DxLib.h"
#include <string>

namespace suken{
const int RED = GetColor( 255 , 0 , 0 );
const int GREEN = GetColor( 0 , 255 , 0 );
const int BLUE = GetColor( 0 , 0 , 255 );
const int BLACK = GetColor( 0 , 0 , 0 );
const int WHITE = GetColor( 255 , 255 , 255 );
const int GRAY = GetColor( 128 , 128 , 128 );
const int LIGHTBLUE = GetColor( 128 , 128 , 255 );
const int LIGHTGREEN = GetColor( 128 , 255 , 128 );
const int M_PINK = GetColor( 255 , 128 , 128 );
const int YELLOW = GetColor( 255 , 255 , 0);







/**
*	@brief �_�C�A���O���J���āA�B
*	�}�b�v�G�f�B�^�Ȃǂ����Ƃ��ɕ֗�����
*	@param  filename �J�������t�@�C�������i�[����������
*	@param filetype ���ݖ���
* @return true
*/
bool SelectOpenFile( char *filename , char *filetype = "all file(*.*)\0*.*\0\0");
/**
*	@brief �_�C�A���O���J���āA�t�@�C����ۑ�����B
*	�}�b�v�G�f�B�^�Ȃǂ����Ƃ��ɕ֗�����
*	@param  filename �ۑ��������t�@�C�������i�[����������
*	@param filetype ���ݖ���
* @return true
*/
bool SaveFile(char *filename ,char *filetype =  "all file(*.*)\0*.*\0\0");
/*
�����s���G���[�̂��߃R�����g�A�E�g
void GetHttpFile(char *&Buf,char *Http,unsigned long ReadSize = 65536);
*/



/////FROM NUNULIB
//���ݎ����擾�֐�///////////////////////////////////////////

/**
*	@brief ����
* @return �߂�l
*/
SYSTEMTIME GetNowSystemTime();  //SYSTEMTIME�^�œ��{�������擾

/**
*	@brief ����
* @return �߂�l
*/
std::string GetNowSystemTimeString();  //string�^(00/00/00 00:00:00 000)�Ō��ݓ��{�������擾

/**
*	@brief ����
*	@param value ����
* @return �߂�l
*/
inline int DrawCenterString(int cx, int y, const TCHAR *String, int color, bool centerY=false){ //x�����E�̒��S�ɂ���DrawString�ŕ����`��i��y�͏㉺���S�ł͂Ȃ���Ӂj
    if (centerY){
        return DxLib::DrawString(cx-GetDrawStringWidth(String, strlen(String))/2, y-GetFontSize()/2, String, color);    //�����܂Ŗڈ� 
    }else{
        return DxLib::DrawString(cx-GetDrawStringWidth(String, strlen(String))/2, y, String, color); 
    }
}

/**
*	@brief ����
*	@param value ����
* @return �߂�l
*/
int DrawCenterString(int cx, int y, int color, const TCHAR* format, ...);

/**
*	@brief ����
*	@param value ����
* @return �߂�l
*/
int DrawCenterString(int cx, int y, int color, bool centerY, const TCHAR* format, ...);

/////////////////////////////////////////////////////////////

//////////////////////////////////////

/**
*	@brief ����
*	@param value ����
*/
void AddFontFromPath(char *path);

/**
*	@brief ����
*	@param value ����
*/
void SukenExecute(char *URL);


/**
*	@brief ����
*	@param value ����
* @return �߂�l
*/
unsigned int fanctorial(unsigned int num);			//

/**
*	@brief ����
*	@param value ����
* @return �߂�l
*/
unsigned int combination(unsigned int n , unsigned int r);					//nCr�Ƃ���邠��B�g�ݍ��킹


}
