#pragma once

#include"Manager.h"

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
*	@brief �������C�u�����Ǝ��f�o�b�O�p�֐�
*	exe�̓�����ꎞ�I�Ɏ~�߁A�G���[���b�Z�[�W��\������B
*	��������̑�������邱�Ƃŕ����\�B
*	@param format �o�͂���x�����̏����t��������̃A�h���X
* @return �Ȃ�
*/

inline void WarningSK(const char* format, ...){
#ifdef DEBUG
	 char tmpchar[256];
    sprintf_s(tmpchar, "�x�� : \n\n%s\n\n", format);
	printfDx(tmpchar);
	printfDx("PRESS ANY KEY TO CONTINUE...");
    ScreenFlip();
    WaitKey();
    clsDx();
    ClearDrawScreen();
#endif
}
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
class CPos{
public:
	CPos(){
		x=y=0;
	}
int x,y;
};

class CSystem{
public:
	CSystem();
	~CSystem();
	void Awake();
	int  GetLocalStandardTime();
	void SetUseThread_Awake(bool flag);
	bool GetUseThread_Awake();
	void SetLoadingGraph(const char *path);
	void SetLoadingMinimalTime(int time);
	void Wait_Loading();
	void Update();
	void Wait();
	void End();
	void TakeScreenShot();
	void GetScreenShot(int *GrHandleAdress);
	void Escape();
	bool GetEscapeFlag();
	int GetFrame();
	int GetNow();
	float GetFps();
	int GetRefreshRate();
	void SetTargetFps(float _fps);
	float GetTargetFps();
	//�V�����X���b�h�����B
	void CreateNewThread( void(*pFunc)() );
	HDC GetDisplayDC();
#ifdef USE_LUA
	lua_State* GetLua();
#endif
private:
	HDC display ;//�f�B�X�v���C�h���C�o
	int frame;
	int count;
	int startTime;
	int localStandardTime;
	int N;			//N�t���[���Ɉ��fps���Z�o����
	float fps;
	float targetFps;
	int now;
	int refreshRate;
	vector<HANDLE> handleChild;
	bool escapeFlag;
	int screenShot;
	bool screenShotFlag;
	int *screenShotGrHandleAdress;
	char loadingImgPath[256];
	int loadingImg;
	bool useThread_AwakeFlag;
	int loadingMinimalTime;
#ifdef USE_LUA
	lua_State *Lua;
#endif
};
void SukenExecute(char *URL);
class CIntData{///�}�C�i�X�ɂ͖��Ή�

public:
	CIntData(char *_DataName);
	char *DataName;
	void NewMake();
	void WriteData();
	void ReadData();
	int RightData[2000];
	int LeftData[2000];

};
class CStrData {

public:
	CStrData(char *_DataName);
	char *DataName;
	void NewMake();
	void WriteData();
	void ReadData();
	char Data[1000][128];

};
class CCaesar{

public:
	CCaesar(char finame[],char imname[],int key);
	char *FileName;
	char *ImaginaryName;
	int Key;
	bool CaesarCode();
	bool CaesarDecode();
	bool CaesarToBMP();
	bool CaesarFromBMP();

};
class CBox{

public:
	CBox();

	int Left;
	int Top;
	int Width;
	int Height;
	int Color;

	void Draw();

private:
	
};
class CommandButton{

public:
	CommandButton();
	CommandButton( int _left , int _right , int _width , int _height );
	int Left;
	int Top;
	int Width;
	int Height;
	int ForeColor;
	int BGColor; //BackGroundColor
	int FontSize;

	char *Caption;

	void (*Func)();

	void Update();
	void Draw();
	void Judge();
	void Click();

private:

};
class CKeyPush{

public:
	char BACK;//KEY_INPUT_BACK  // �o�b�N�X�y�[�X�L�[ 
	char TAB;//KEY_INPUT_TAB  // �^�u�L�[ 
	char RETURN;//KEY_INPUT_RETURN  // �G���^�[�L�[
	char LSHIFT;//KEY_INPUT_LSHIFT  // ���V�t�g�L�[ 
	char RSHIFT;//KEY_INPUT_RSHIFT  // �E�V�t�g�L�[ 
	char LCONTROL;//KEY_INPUT_LCONTROL  // ���R���g���[���L�[ 
	char RCONTROL;//KEY_INPUT_RCONTROL  // �E�R���g���[���L�[ 
	char ESCAPE;//KEY_INPUT_ESCAPE  // �G�X�P�[�v�L�[ 
	char SPACE;//KEY_INPUT_SPACE  // �X�y�[�X�L�[ 
	char LEFT;//KEY_INPUT_LEFT  // ���L�[ 
	char UP;//KEY_INPUT_UP  // ��L�[ 
	char RIGHT;//KEY_INPUT_RIGHT  // �E�L�[ 
	char DOWN;//KEY_INPUT_DOWN  // ���L�[ 
	char INSERT;//KEY_INPUT_INSERT  // �C���T�[�g�L�[ 
	char Delete;//KEY_INPUT_DELETE  // �f���[�g�L�[
	char LALT;//KEY_INPUT_LALT  // ���`�k�s�L�[ 
	char RALT;//KEY_INPUT_RALT  // �E�`�k�s�L�[ 
	char SCROLL;//KEY_INPUT_SCROLL  // ScrollLock�L�[
	char CAPSLOCK;//KEY_INPUT_CAPSLOCK  // CaspLock�L�[ 
	char PAUSE;//KEY_INPUT_PAUSE  // PauseBreak�L�[
	char MINUS ; // �|�L�[ 
	char YEN ;  // ���L�[ 
	char PREVTRACK ; // �O�L�[ 
	char PERIOD ; // �D�L�[ 
	char SLASH ; // �^�L�[ 
	char SEMICOLON ; // �G�L�[ 
	char COLON ; // �F�L�[ 
	char LBRACKET ; // �m�L�[ 
	char RBRACKET ; // �n�L�[ 
	char AT ; // ���L�[ 
	char BACKSLASH ; // �_�L�[ 
	char COMMA ; // �C�L�[ 
	char F1 ; // �e�P�L�[ 
	char F2 ; // �e�Q�L�[ 
	char F3 ; // �e�R�L�[ 
	char F4 ; // �e�S�L�[ 
	char F5 ; // �e�T�L�[ 
	char F6 ; // �e�U�L�[ 
	char F7 ; // �e�V�L�[ 
	char F8 ; // �e�W�L�[ 
	char F9 ; // �e�X�L�[ 
	char F10 ; // �e�P�O�L�[ 
	char F11 ; // �e�P�P�L�[ 
	char F12 ; // �e�P�Q�L�[
	char A ; // �`�L�[ 
	char B ; // �a�L�[ 
	char C ; // �b�L�[ 
	char D ; // �c�L�[ 
	char E ; // �d�L�[ 
	char F ; // �e�L�[ 
	char G ; // �f�L�[ 
	char H ; // �g�L�[ 
	char I ; // �h�L�[ 
	char J ; // �i�L�[ 
	char K ; // �j�L�[ 
	char L ; // �k�L�[ 
	char M ; // �l�L�[ 
	char N ; // �m�L�[ 
	char O ; // �n�L�[ 
	char P ; // �o�L�[ 
	char Q ; // �p�L�[ 
	char R ; // �q�L�[ 
	char S ; // �r�L�[ 
	char T ; // �s�L�[ 
	char U ; // �t�L�[ 
	char V ; // �u�L�[ 
	char W ; // �v�L�[ 
	char X ; // �w�L�[ 
	char Y ; // �x�L�[ 
	char Z ; // �y�L�[ 
	char Key0 ; // �O�L�[ 
	char Key1 ; // �P�L�[ 
	char Key2 ; // �Q�L�[ 
	char Key3 ; // �R�L�[ 
	char Key4 ; // �S�L�[ 
	char Key5 ; // �T�L�[ 
	char Key6 ; // �U�L�[ 
	char Key7 ; // �V�L�[ 
	char Key8 ; // �W�L�[ 
	char Key9 ; // �X�L�[ 

	void ALLKEYCHECK();

};
void Awake();
void GameLoop();
int Clng( char *Str ,int n = 0) ;
int ClngTo ( char *Str ,char Word );
int ClngFrom ( char *Str ,char Word );
double Scos(int Angle);
double Ssin(int Angle);
double Stan(int Angle);
int AngleFromRad(double Angle);
int Power2(int x, int y);
bool CheckWord(char *Str ,char Word );
unsigned long FileGetSize(char *FileName);
void GetHttpFile(char *&Buf,char *Http,unsigned long ReadSize = 65536);

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

///�G���[&�f�o�b�O�o�͗p�֐�///////////////////////////////////////////////////////
#define ERRORDX(...)     ErrorDx(__LINE__, __FUNCTION__, __FILE__,  __VA_ARGS__)
#define WARNINGDX(...) WarningDx(__LINE__, __FUNCTION__, __FILE__,  __VA_ARGS__)
#define DEBUGDX(...)     DebugDx(__LINE__, __FUNCTION__, __FILE__,  __VA_ARGS__)
 
 
inline void myprintLog(const char* filename, const char* format, va_list args){
    #ifndef MYLOG_DISABLE
        FILE *fp;
        errno_t error;
        char txtfilename[1024];
        sprintf_s(txtfilename, "%s.txt", filename);
        if(error = fopen_s(&fp, txtfilename, "a") != 0){
            return;
        }else{
            char tmpchar[1024];
            vsprintf_s(tmpchar, format, args);
            fprintf_s(fp, "[%s]:%s\n", GetNowSystemTimeString().c_str(), tmpchar);
            fclose(fp);
        }
    #endif
}
inline void myLog(const char* format, ...){
    va_list args;
    va_start(args, format);
    myprintLog("MyLog", format, args);
    va_end(args);
}
inline void myLogf(const char* filename, const char* format, ...){
    va_list args;
    va_start(args, format);
    myprintLog(filename, format, args);
    va_end(args);
}
inline void myprintfDx(const char* format, va_list args, const char* filename=NULL, int line=0){
    char string[1024];
    vsprintf_s(string, format, args);   //va_start��va_end�͌Ăяo�����ł���
    if (filename!=NULL) sprintf_s(string, "%s\n->%s(%d)\n", string, filename, line);
 
    myLogf("MyLog_Printed", "PRINT: %s", string);
    printfDx(string);
    ScreenFlip();
    WaitKey();
    clsDx();
    ClearDrawScreen();
}
inline void ErrorDx(int line, const char* func, const char* filename, const char* format, ...){
    char tmpchar[256];
    va_list args;   va_start(args, format);
    sprintf_s(tmpchar, "Error->%s\n->%s", format, func);
    myprintfDx(tmpchar, args, filename, line);
    va_end(args);
}
inline void ErrorDx(const char* format, char* filename, int line, ...){
    va_list args;
    va_start(args, line);
    myprintfDx(format, args, filename, line);
    va_end(args);
}
inline void ErrorDx(const char* format, ...){
    va_list args;
    va_start(args, format);
    myprintfDx(format, args);
    va_end(args);
}
inline void WarningDx(int line, const char* func, const char* filename, const char* format, ...){
    #ifndef WARNINGDX_DISABLE 
        char tmpchar[256];
        va_list args;   va_start(args, format);
        sprintf_s(tmpchar, "Warning->%s\n->%s", format, func);
        myprintfDx(tmpchar, args, filename, line);
        va_end(args);
    #endif
}
inline void WarningDx(const char* format, char* filename, int line, ...){
    #ifndef WARNINGDX_DISABLE 
        va_list args;
        va_start(args, line);
        myprintfDx(format, args, filename, line);
        va_end(args);
    #endif
}
inline void WarningDx(const char* format, ...){
    #ifndef WARNINGDX_DISABLE 
        va_list args;
        va_start(args, format);
        myprintfDx(format, args);
        va_end(args);
    #endif
}
inline void DebugDx(int line, const char* func, const char* filename, const char* format, ...){
    #ifndef DEBUGDX_DISABLE 
        char tmpchar[256];
        va_list args;   va_start(args, format);
        sprintf_s(tmpchar, "Debug->%s\n->%s", format, func);
        myprintfDx(tmpchar, args, filename, line);
        va_end(args);
    #endif
}
inline void DebugDx(const char* format, char* filename, int line, ...){
    #ifndef DEBUGDX_DISABLE 
        va_list args;
        va_start(args, line);
        myprintfDx(format, args, filename, line);
        va_end(args);
    #endif
}
inline void DebugDx(const char* format, ...){
    #ifndef DEBUGDX_DISABLE 
        va_list args;
        va_start(args, format);
        myprintfDx(format, args);
        va_end(args);
    #endif
}
/////////////////////////////////////////////////////////////

//////////////////////////////////////

void AddFontFromPath(char *path);

namespace suken{
///////////////////////////////////////////////////////////////////////
///�񎟌����W�p�N���X�i���x�Ȃǂɕ֗��j///////////////////////////////////
///���Z�q�I�[�o�[���[�h��DxLib��VECTOR�p�֐��Ɠ����悤�Ɏg����֐��Q��/////
///////////////////////////////////////////////////////////////////////

class CVector{  //�錾�Ɠ����ɒ�`�������Ă���̂̓C�����C�������邽��
public:
    CVector( float _x , float _y );
    CVector();
    float x;
    float y;
 
    void Set( float _x , float _y);
    void Set(CVector _vec);
    CVector Add( float _x , float _y);
    CVector Add(CVector _vec);
    // +���Z�q�I�[�o�[���[�h
    CVector operator+(const CVector &obj);
    // +=���Z�q�I�[�o�[���[�h
    CVector& operator+=(const CVector &obj);
    // -���Z�q�I�[�o�[���[�h
    CVector operator-(const CVector &obj);
    // -=���Z�q�I�[�o�[���[�h
    CVector& operator-=(const CVector &obj);
    //*���Z�q�I�[�o�[���[�h
    CVector operator*(const float _num);
    //*=���Z�q�I�[�o�[���[�h
    CVector& operator*=(const float _num);
	//  /���Z�q�I�[�o�[���[�h
    CVector operator/(const float _num);
    ///=���Z�q�I�[�o�[���[�h
    CVector& operator/=(const float _num);
	///==���Z�q�I�[�o�[���[�h
    bool operator==(const CVector &obj);
	///=���Z�q�I�[�o�[���[�h
	CVector& operator =(const CVector &obj);
    //operator*�̃I�[�o�[���[�h�ɂ����͂�s�v�Ȋ֐�
    void Multiple(float _num);
    float GetLength();
private:
};

//////////////////////////////////////////////
//////DxLib��VECTOR�p�֐��̃I�[�o�[���[�h///////
//////////////////////////////////////////////
__inline CVector VGet(float _x,float _y){
	CVector temp;
	temp.x=_x;
	temp.y=_y;
	return temp;
}
__inline CVector VAdd(CVector v1,CVector v2){
	CVector temp;
	temp.x=v1.x+v2.x;
	temp.y=v1.y+v2.y;
	return temp;
}
__inline CVector VSub(CVector v1,CVector v2){
	CVector temp;
	temp.x=v1.x-v2.x;
	temp.y=v1.y-v2.y;
	return temp;
}
__inline float VDot(CVector v1,CVector v2){
	return (v1.x*v2.x+v1.y*v2.y);
}
__inline VECTOR VCross(CVector v1,CVector v2){
	VECTOR temp;
	temp.z=(float)v1.x*v2.y-v1.y*v2.x;
	return temp;
}
__inline float VCrossLength(CVector v1,CVector v2){
	return ((v1.x*v2.y)-(v1.y*v2.x));
}
__inline CVector VScale(CVector v1,float scale){
	CVector temp;
	temp.x=v1.x*scale;
	temp.y=v1.y*scale;
	return temp;
}
__inline float VSize(CVector v1){
	return sqrt( (float)(v1.x * v1.x + v1.y * v1.y) ) ;
}
__inline float VSquareSize(CVector v1){
	return  (v1.x * v1.x + v1.y * v1.y);
}
__inline CVector VNorm(CVector v1){
	float size=VSize(v1);
	CVector temp;
	temp.x=v1.x/size;
	temp.y=v1.y/size;
	return temp;
}

__inline float GetDistance(CVector v1 ,CVector v2){
	
	return sqrt(pow(abs(v1.x-v2.x),2.0f)+pow(abs(v1.y-v2.y),2.0f));
	
}
__inline float GetSquareDistance(CVector v1 ,CVector v2){
	
	return pow(abs(v1.x-v2.x),2.0f)+pow(abs(v1.y-v2.y),2.0f);
	
}
__inline int DrawLine(CVector &v1 , CVector &v2 ,int color){
	return DxLib::DrawLine((int)v1.x,(int)v1.y,(int)v2.x,(int)v2.y,color);
}
__inline int DrawCircle(CVector &v,int r,int color,bool fillFlag){
	return DxLib::DrawCircle((int)v.x,(int)v.y,r,color,fillFlag);
}
__inline int DrawBox(CVector &v1,CVector &v2,int color,bool fillFlag){
	return DxLib::DrawBox((int)v1.x,(int)v1.y,(int)v2.x,(int)v2.y,color,fillFlag);
}
_inline int DrawOval(CVector &v,CVector &r,int color,bool fillFlag){
	return DxLib::DrawOval((int)v.x,(int)v.y,(int)r.x,(int)r.y,color,fillFlag);
}
_inline int DrawOval(CVector &v,int rx,int ry,int color,bool fillFlag){
	return DxLib::DrawOval((int)v.x,(int)v.y,rx,ry,color,fillFlag);
}
_inline int DrawTriangle(CVector &v1,CVector &v2,CVector &v3,int color,bool fillFlag){
	return DxLib::DrawTriangle((int)v1.x,(int)v1.y,(int)v2.x,(int)v2.y,(int)v3.x,(int)v3.y,color,fillFlag);
}
_inline int DrawPixel(CVector &v,int color){
	return DxLib::DrawPixel((int)v.x,(int)v.y,color);
}
}//namespace suken end

using namespace suken;

unsigned int fanctorial(unsigned int num);			//
unsigned int combination(unsigned int n , unsigned int r);					//nCr�Ƃ���邠��B�g�ݍ��킹

typedef vector<CVector> BEZIER ;
//�x�W�F�Ȑ��̕`��i GetBezier�֐��ō쐬�����f�[�^���K�v�@�j
////GetBezier�֐��ō쐬�����f�[�^��p���ăx�W�F�Ȑ���`�悷��
//����
// data  : GetBezier�֐��ō쐬�����x�W�F�Ȑ��f�[�^
// color : �`��F���w��
void DrawBezier( BEZIER &data ,  int color );
	//�x�W�F�Ȑ����_�f�[�^�̍쐬
////�x�W�F�Ȑ��̌v�Z���}�C�t���[������͖̂��ʂȂ̂Ōv�Z�ς݂̃f�[�^���쐬����
//����
// In�@�@�@�@: ����_�iCVector�^�j���w�肷��i2�ȏ�j
// vertexNum : �쐬����f�[�^�ׂ̍������w��i�x�W�F�Ȑ��̍\�����_�̐��j
BEZIER GetBezier(vector<CVector> &In , unsigned int vertexNum );

CVector GetIntersection( int a1 , int b1 , int a2 , int b2 );

class CTransform{
public:
	CTransform();
	CVector position;
	CVector velocity;
	CVector acceralate;

	CVector prePosition;

	float rotation;
	/*static*/ float airResistance;
	/*static*/ CVector gravity;
	void TransLate(CVector _v);
	void Loop();
};
class CSuperGameObject{
public:
	CSuperGameObject(){
	
	}
	virtual void Awake(){
	
	}
	virtual void Loop(){
		transform.Loop();
		
	}

	CTransform transform;
};
class CRect{
public:
	CRect();
	CTransform	center;
	float direction;
	static const int figureType = SHAPE_RECT; 
	void Set(int sizeX,int sizeY);
	CVector GetCenterPos();
	CVector GetSize();
	float GetArea();
	CVector GetRightTop();
	CVector GetLeftTop();
	CVector GetLeftBottom();
	CVector GetRightBottom();
	void Draw(int color);
	void Loop();
	float GetRadius();
	void AddEventLisnerOnCollision(void (*pFunc)());
	void RemoveEventLisnerOnCollision(void (*pFunc)());
	void OnCollision();
private:
	vector<void(*)()> onCollisionTaskVoid;
	float rad;
	float radius;
	CVector size;
};
class CCircle{
public:
	CCircle();
	CTransform center;
	float radius;
	float mass;
	float bound;
	bool IsKinematic;
	bool onCollision;
	static const int figureType = SHAPE_CIRCLE; 
	CVector GetCenterPos();
	float GetArea();
	void Loop();
	void AddEventLisnerOnCollision(void (*pFunc)());
	void RemoveEventLisnerOnCollision(void (*pFunc)());
	void OnCollisionFunc();
	void AddCollisionFalse(CCircle *c);
	void RemoveCollisionFalse(CCircle *c);
	bool GetIsNoCollision(CCircle *c);
private:
	vector<void(*)()> onCollisionTaskVoid;
	vector<CCircle*> noCollision;
};

class CCollisionManager{
public:
	CCollisionManager();
	~CCollisionManager();
	void Awake();
	void Loop();
	void DrawLoop();
	void CollisionCircleCalc(CCircle &A , CCircle &B ,float time);
	bool CollisionCircle(CCircle &A , CCircle &B );
	bool CollisionRect(CRect &A , CRect &B);
	void AddChild(CCircle *_circle , bool moveFlag);
	bool RemoveChild(CCircle *_circle);
	void AddChild(CRect *_rect , bool moveFlag);
	bool RemoveChild(CRect *_rect);
	vector<CCircle*> physicsCircle;
	vector<CCircle*> fixedCircle;
	vector<CRect*> fixedRect;
	vector<CRect*> physicsRect;
};

//���͗p�f�[�^�N���X
class CKeyIn{
public:
	CKeyIn(){
		pFuncVoid = NULL;
		pFuncInt = NULL;
		pInt = NULL;
	}
	int keyCode;
	void (*pFuncVoid)();
	void (*pFuncInt)(int);
	int *pInt;
	int Int;
};
class CMouseIn{
public:
	CMouseIn(){
		pFuncVoid = NULL;
		pFuncInt = NULL;
		pInt = NULL;
	}
	int x1,x2,y1,y2;
	void (*pFuncVoid)();
	void (*pFuncInt)(int);
	int *pInt;
	int Int;
	int type;
	
};
class CpMouseIn{
public:
	CpMouseIn(){
		pFuncVoid = NULL;
		pFuncInt = NULL;
		pInt = NULL;
	}
	int *x1,*x2,*y1,*y2;
	void (*pFuncVoid)();
	void (*pFuncInt)(int);
	int *pInt;
	int Int;
	int type;
	
};
class CKeyBoolIn{
public:
	int keyCode;
	bool *pBool;
};
class CMouseBoolIn{
public:
	int x1,x2,y1,y2;
	bool *pBool;
	int type;
	

};
class CpMouseBoolIn{
public:
	int *x1,*x2,*y1,*y2;
	bool *pBool;
	int type;
	
};
class CFrame{
public:
	CFrame(){
		pFuncVoid = NULL;
		pFuncInt = NULL;
		pInt = NULL;
	}
	void (*pFuncVoid)();
	void (*pFuncInt)(int);
	int *pInt;
	int Int;
};
class CBoolean{
public:
	CBoolean(){
		pFuncVoid = NULL;
		pFuncInt = NULL;
		pInt = NULL;
	}
	void (*pFuncVoid)();
	void (*pFuncInt)(int);
	int *pInt;
	int Int;
	bool* pBool;
};

class CKey{
public:
	CKey(){

      

	}

	static const int BACK = KEY_INPUT_BACK	;
    static const int TAB = KEY_INPUT_TAB	;
    static const int RETURN = KEY_INPUT_RETURN	;

    static const int LSHIFT = KEY_INPUT_LSHIFT	;
    static const int RSHIFT = KEY_INPUT_RSHIFT	; 
    static const int LCONTROL = KEY_INPUT_LCONTROL	;
    static const int RCONTROL = KEY_INPUT_RCONTROL	; 
    static const int ESCAPE = KEY_INPUT_ESCAPE	; 
    static const int SPACE = KEY_INPUT_SPACE	; 
    static const int PGUP = KEY_INPUT_PGUP	; 
    static const int PGDN = KEY_INPUT_PGDN	;
    static const int END = KEY_INPUT_END	; 
    static const int HOME = KEY_INPUT_HOME	;
    static const int LEFT = KEY_INPUT_LEFT	; 
    static const int UP = KEY_INPUT_UP	; 
    static const int RIGHT = KEY_INPUT_RIGHT	; 
    static const int DOWN = KEY_INPUT_DOWN	; 
    static const int INSERT = KEY_INPUT_INSERT	; 
    static const int _DELETE = KEY_INPUT_DELETE	;

    static const int MINUS = KEY_INPUT_MINUS	; 
    static const int YEN = KEY_INPUT_YEN	; 
    static const int PREVTRACK = KEY_INPUT_PREVTRACK	; 
    static const int PERIOD = KEY_INPUT_PERIOD	;
    static const int SLASH = KEY_INPUT_SLASH	;
    static const int LALT = KEY_INPUT_LALT	;
    static const int RALT = KEY_INPUT_RALT	; 
    static const int SCROLL = KEY_INPUT_SCROLL	; 
    static const int SEMICOLON = KEY_INPUT_SEMICOLON	;
    static const int COLON = KEY_INPUT_COLON	; 
    static const int LBRACKET = KEY_INPUT_LBRACKET	;
    static const int RBRACKET = KEY_INPUT_RBRACKET	; 
    static const int AT = KEY_INPUT_AT	; 
    static const int BACKSLASH = KEY_INPUT_BACKSLASH	; 
    static const int COMMA = KEY_INPUT_COMMA	; 
    static const int CAPSLOCK = KEY_INPUT_CAPSLOCK	;
    static const int PAUSE = KEY_INPUT_PAUSE	; 

    static const int NUMPAD0 = KEY_INPUT_NUMPAD0	;
    static const int NUMPAD1 = KEY_INPUT_NUMPAD1	; 
    static const int NUMPAD2 = KEY_INPUT_NUMPAD2	; 
    static const int NUMPAD3 = KEY_INPUT_NUMPAD3	; 
    static const int NUMPAD4 = KEY_INPUT_NUMPAD4	; 
    static const int NUMPAD5 = KEY_INPUT_NUMPAD5	; 
    static const int NUMPAD6 = KEY_INPUT_NUMPAD6	; 
    static const int NUMPAD7 = KEY_INPUT_NUMPAD7	; 
    static const int NUMPAD8 = KEY_INPUT_NUMPAD8	; 
    static const int NUMPAD9 = KEY_INPUT_NUMPAD9	; 
    static const int MULTIPLY = KEY_INPUT_MULTIPLY	; 
    static const int ADD = KEY_INPUT_ADD	; 
    static const int SUBTRACT = KEY_INPUT_SUBTRACT	;
    static const int DECIMAL = KEY_INPUT_DECIMAL	; 
    static const int DIVIDE = KEY_INPUT_DIVIDE	; 
    static const int NUMPADENTER = KEY_INPUT_NUMPADENTER	; 

    static const int F1 = KEY_INPUT_F1	; 
    static const int F2 = KEY_INPUT_F2	;
    static const int F3 = KEY_INPUT_F3	; 
    static const int F4 = KEY_INPUT_F4	; 
    static const int F5 = KEY_INPUT_F5	; 
    static const int F6 = KEY_INPUT_F6	; 
    static const int F7 = KEY_INPUT_F7	;
    static const int F8 = KEY_INPUT_F8	; 
    static const int F9 = KEY_INPUT_F9	; 
    static const int F10 = KEY_INPUT_F10	; 
    static const int F11 = KEY_INPUT_F11	; 
    static const int F12 = KEY_INPUT_F12	; 

    static const int A = KEY_INPUT_A	;  
    static const int B = KEY_INPUT_B	;  
    static const int C = KEY_INPUT_C	;  
    static const int D = KEY_INPUT_D	;  
    static const int E = KEY_INPUT_E	;  
    static const int F = KEY_INPUT_F	;  
    static const int G = KEY_INPUT_G	;  
    static const int H = KEY_INPUT_H	;  
    static const int I = KEY_INPUT_I	;  
    static const int J = KEY_INPUT_J	;  
    static const int K = KEY_INPUT_K	;  
    static const int L = KEY_INPUT_L	;  
    static const int M = KEY_INPUT_M	; 
    static const int N = KEY_INPUT_N	;  
    static const int O = KEY_INPUT_O	;  
    static const int P = KEY_INPUT_P	; 
    static const int Q = KEY_INPUT_Q	;  
    static const int R = KEY_INPUT_R	;  
    static const int S = KEY_INPUT_S	;  
    static const int T = KEY_INPUT_T	;  
    static const int U = KEY_INPUT_U	;  
    static const int V = KEY_INPUT_V	;  
    static const int W = KEY_INPUT_W	;  
    static const int X = KEY_INPUT_X	;  
    static const int Y = KEY_INPUT_Y	;  
    static const int Z = KEY_INPUT_Z	;  
    static const int NUM0 = KEY_INPUT_0	;  
    static const int NUM1 = KEY_INPUT_1	;  
    static const int NUM2 = KEY_INPUT_2	;  
    static const int NUM3 = KEY_INPUT_3	;  
    static const int NUM4 = KEY_INPUT_4	;  
    static const int NUM5 = KEY_INPUT_5	;  
    static const int NUM6 = KEY_INPUT_6	;  
    static const int NUM7 = KEY_INPUT_7	;  
    static const int NUM8 = KEY_INPUT_8	;  
    static const int NUM9 = KEY_INPUT_9	; 


	void Loop();
	bool GetPush(int keyCode);
	bool GetDown(int keyCode);
	bool GetUp(int keyCode);
	int GetCount(int keyCode);
private:
	float count[256];
};
//�}�E�X��`�N���X
class CMouse{
public:
	CMouseIn Off( int _x1 , int _y1 , int _x2 , int _y2 );
	bool GetOff( int _x1 , int _y1 , int _x2 , int _y2 );
	CpMouseIn Off( int *_x1 , int *_y1 , int *_x2 , int *_y2 );
	bool GetOff( int *_x1 , int *_y1 , int *_x2 , int *_y2 );
	CMouseIn On( int _x1 , int _y1 , int _x2 , int _y2 );
	bool GetOn( int _x1 , int _y1 , int _x2 , int _y2 );
	CpMouseIn On( int *_x1 , int *_y1 , int *_x2 , int *_y2 );
	bool GetOn( int *_x1 , int *_y1 , int *_x2 , int *_y2 );
	CMouseIn Click( int _x1 , int _y1 , int _x2 , int _y2 );
	bool GetClick( int _x1 , int _y1 , int _x2 , int _y2 );
	CpMouseIn Click( int *_x1 , int *_y1 , int *_x2 , int *_y2 );
	bool GetClick( int *_x1 , int *_y1 , int *_x2 , int *_y2 );
	CMouseIn Release( int _x1 , int _y1 , int _x2 , int _y2 );
	bool GetRelease( int _x1 , int _y1 , int _x2 , int _y2 );
	CpMouseIn Release( int *_x1 , int *_y1 , int *_x2 , int *_y2 );
	bool GetRelease( int *_x1 , int *_y1 , int *_x2 , int *_y2 );
	void Loop();
	void SetLeft();
	void SetRight();
	int mouseX,mouseY;
	bool mouseInput,preMouseInput;
	
private:
	bool IsLeft;
};
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
extern CEvent Event;
//���̓C�x���g�Ǘ��N���X
class CInput{
public:
	CInput();
	void AddEventListener( int inputCode , void func() );
	void AddEventListener( int inputCode , void func(int) , int *pArgument );
	void AddEventListener( int inputCode , void func(int) , int Argument );
	void RemoveEventListener( int inputCode , void func()  );
	void RemoveEventListener( int inputCode , void func(int) , int *pArgument  );
	void RemoveEventListener( int inputCode , void func(int) , int Argument  );
	void AddEventListener( CMouseIn input , void func()  );
	void AddEventListener( CMouseIn input , void func(int) , int *pArgument  );
	void AddEventListener( CMouseIn input , void func(int) , int Argument  );
	void RemoveEventListener( CMouseIn input , void func()  );
	void RemoveEventListener( CMouseIn input , void func(int) , int *pArgument  );
	void RemoveEventListener( CMouseIn input , void func(int) , int Argument  );
	void AddEventListener( CpMouseIn input , void func()  );
	void AddEventListener( CpMouseIn input , void func(int) , int *pArgument  );
	void AddEventListener( CpMouseIn input , void func(int) , int Argument  );
	void RemoveEventListener( CpMouseIn input , void func()  );
	void RemoveEventListener( CpMouseIn input , void func(int) , int *pArgument  );
	void RemoveEventListener( CpMouseIn input , void func(int) , int Argument  );
	void AddEventListener( char input , void func()  );
	void AddEventListener( char input , void func(int) , int *pArgument  );
	void AddEventListener( char input , void func(int) , int Argument  );
	void RemoveEventListener( char input , void func()  );
	void RemoveEventListener( char input , void func(int) , int *pArgument  );
	void RemoveEventListener( char input , void func(int) , int Argument  );
	void AddEventListener( bool* input , void func()  );
	void AddEventListener( bool* input , void func(int) , int *pArgument  );
	void AddEventListener( bool* input , void func(int) , int Argument  );
	void RemoveEventListener( bool* input , void func()  );	
	void RemoveEventListener( bool* input , void func(int) , int *pArgument  );
	void RemoveEventListener( bool* input , void func(int) , int Argument  );

	void Loop();
	void DrawLoop();

	bool useKey,useMouse;
	int mouseX,mouseY;
private:
	CKeyIn keyTemp;
	vector<CKeyIn> keyTask;

	CMouseIn mouseTemp;
	vector<CMouseIn> mouseTask;

	CpMouseIn pMouseTemp;
	vector<CpMouseIn> pMouseTask;

	CFrame frameTemp;
	vector<CFrame> frameTask;

	CBoolean boolTemp;
	vector<CBoolean> boolTask;

	vector<CKeyIn> keyTask_Draw;
	vector<CMouseIn> mouseTask_Draw;
	vector<CpMouseIn> pMouseTask_Draw;
	vector<CFrame> frameTask_Draw;
	vector<CBoolean> boolTask_Draw;

	bool mouseInput,preMouseInput;
};

class CButton{
public:
	CButton(){
		IsUseGraph = false;
		IsReact = false;
	}
	char *title;
	int x1,x2,y1,y2;
	int backColor,stringColor;
	int graphHandle;
	bool IsUseGraph;
	int graphHandle_on;
	int graphHandle_off;
	bool IsReact;			//�}�E�X�ɔ������邩�ۂ�
};
class CpButton{
public:
	CpButton(){
		IsUseGraph = false;
		IsReact =false;
	}
	char *title;
	int *x1,*x2,*y1,*y2;
	int backColor,stringColor;
	int graphHandle;
	bool IsUseGraph;
	int graphHandle_on;
	int graphHandle_off;
	bool IsReact;			//�}�E�X�ɔ������邩�ۂ�
};

//�V�[���N���X
class CScene{
public:
	CScene();
	void Loop();
	void ButtonLoop();
	CCollisionManager collision;
	CInput input;
	vector<CButton> buttonChild;
	vector<CpButton> pButtonChild;
	CScene *sceneChild;
	
	void SetFocus(bool _focus);
	bool GetFocus();
	void AddChild(CScene *_scene);
	void RemoveChild();
	void SetButton( int x1 , int y1 , int x2 , int y2 , int backColor , char *title , int stringColor , void (*pFunc)() );
	void SetButton( int x1 , int y1 , int x2 , int y2 , int backColor , char *title , int stringColor , void (*pFunc)(int) , int *pInt );
	void SetButton( int x1 , int y1 , int x2 , int y2 , int backColor , char *title , int stringColor , void (*pFunc)(int) , int Int );
	void SetButton( int x1 , int y1 , int x2 , int y2 , int graph, void (*pFunc)() );
	void SetButton( int x1 , int y1 , int x2 , int y2 , int graph, void (*pFunc)(int) , int *pInt );
	void SetButton( int x1 , int y1 , int x2 , int y2 , int graph, void (*pFunc)(int) , int Int );
	void SetButton( int x1 , int y1 , int x2 , int y2 , char* graphPath, void (*pFunc)() );
	void SetButton( int x1 , int y1 , int x2 , int y2 , char* graphPath, void (*pFunc)(int) , int *pInt );
	void SetButton( int x1 , int y1 , int x2 , int y2 , char* graphPath, void (*pFunc)(int) , int Int );
	void SetButton( int x1 , int y1 , int x2 , int y2 , char* Off_graphPath , char* On_graphPath , void (*pFunc)() );
	void SetButton( int x1 , int y1 , int x2 , int y2 , char* Off_graphPath , char* On_graphPath , void (*pFunc)(int) , int *pInt );
	void SetButton( int x1 , int y1 , int x2 , int y2 , char* Off_graphPath , char* On_graphPath , void (*pFunc)(int) , int Int );
	void SetButton( int *x1 , int *y1 , int *x2 , int *y2 , int backColor , char *title , int stringColor , void (*pFunc)() );
	void SetButton( int *x1 , int *y1 , int *x2 , int *y2 , int backColor , char *title , int stringColor , void (*pFunc)(int) ,int *pInt );
	void SetButton( int *x1 , int *y1 , int *x2 , int *y2 , int backColor , char *title , int stringColor , void (*pFunc)(int) ,int Int );
	void SetButton( int *x1 , int *y1 , int *x2 , int *y2 , int graph , void (*pFunc)() );
	void SetButton( int *x1 , int *y1 , int *x2 , int *y2 , int graph , void (*pFunc)(int) ,int *pInt );
	void SetButton( int *x1 , int *y1 , int *x2 , int *y2 , int graph , void (*pFunc)(int) ,int Int );
	void SetButton( int *x1 , int *y1 , int *x2 , int *y2 , char* graphPath , void (*pFunc)() );
	void SetButton( int *x1 , int *y1 , int *x2 , int *y2 , char* graphPath , void (*pFunc)(int) , int *pInt );
	void SetButton( int *x1 , int *y1 , int *x2 , int *y2 , char* graphPath , void (*pFunc)(int) , int Int );
	void SetButton( int *x1 , int *y1 , int *x2 , int *y2 , char* Off_graphPath , char* On_graphPath , void (*pFunc)() );
	void SetButton( int *x1 , int *y1 , int *x2 , int *y2 , char* Off_graphPath , char* On_graphPath , void (*pFunc)(int) , int *pInt );
	void SetButton( int *x1 , int *y1 , int *x2 , int *y2 , char* Off_graphPath , char* On_graphPath , void (*pFunc)(int) , int Int );
	//�������C�u���������֐��i�g�p�֎~�j
	void ResetSceneNum();
	unsigned int GetSerialNum();
private:
	bool focus;
	static unsigned int sceneNum;
	unsigned int serialNum;
};
//�Q�[���V�X�e�������N���X
class CGame{
public:
	CGame();
	~CGame();
	void Awake();
	void AddChild(CScene* _scene);
	void RemoveChild(CScene* _scene);
	void RemoveChild();
	void Loop();

	void SetUseDrawLoop(bool flag);
	bool GetUseDrawLoop();
	vector<CScene*> sceneChild;
	CScene rootScene;
private:
	bool useDrawLoopFlag;
	
	
};