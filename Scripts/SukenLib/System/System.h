#pragma once
#include <vector>
#include "DxLib.h"
#include <Manager.h>

namespace suken{

class CSystem{
public:
/**
*	@brief ����
*/
	CSystem();
/**
*	@brief ����
*/
	~CSystem();
/**
*	@brief ����
*/
	void Awake();
/**
*	@brief ����
* @return �߂�l
*/
	int  GetLocalStandardTime();
/**
*	@brief ����
*	@param value ����
*/
	void SetUseThread_Awake(bool flag);
/**
*	@brief ����
* @return �߂�l
*/
	bool GetUseThread_Awake();
/**
*	@brief ����
*	@param value ����
*/
	void SetLoadingGraph(const char *path);
/**
*	@brief ����
*	@param value ����
*/
	void SetLoadingMinimalTime(int time);
/**
*	@brief ����
*/
	void Wait_Loading();
/**
*	@brief ����
*/
	void Update();
/**
*	@brief ����
*/
	void Wait();
/**
*	@brief ����
*/
	void End();
/**
*	@brief ����
*/
	void TakeScreenShot();
/**
*	@brief ����
*	@param value ����
*/
	void GetScreenShot(int *GrHandleAdress);
/**
*	@brief ����
*/
	void Escape();
/**
*	@brief ����
* @return �߂�l
*/
	bool GetEscapeFlag();
/**
*	@brief ����
* @return �߂�l
*/
	int GetFrame();
/**
*	@brief ����
* @return �߂�l
*/
	int GetNow();
/**
*	@brief ����
* @return �߂�l
*/
	float GetFps();
/**
*	@brief ����
* @return �߂�l
*/
	int GetRefreshRate();
/**
*	@brief ����
*	@param value ����
*/
	void SetTargetFps(float _fps);
/**
*	@brief ����
*	@param value ����
* @return �߂�l
*/
	float GetTargetFps();
/**
*	@brief ���� //�V�����X���b�h�����
*	@param value ����
*/
	void CreateNewThread( void(*pFunc)() );
/**
*	@brief ����
* @return �߂�l
*/
	HDC GetDisplayDC();
#ifdef USE_LUA
/**
*	@brief ����
* @return �߂�l
*/
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
	std::vector<HANDLE> handleChild;
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
}
//Singleton
extern suken::CSystem System;
