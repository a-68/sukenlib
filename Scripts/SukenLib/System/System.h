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
	HDC display ;///<  @brief ����//�f�B�X�v���C�h���C�o
	int frame;///<  @brief ����
	int count;///<  @brief ����
	int startTime;///<  @brief ����
	int localStandardTime;///<  @brief ����
	int N;		///<  @brief ����	//N�t���[���Ɉ��fps���Z�o����
	float fps;///<  @brief ����
	float targetFps;///<  @brief ����
	int now;///<  @brief ����
	int refreshRate;///<  @brief ����
	std::vector<HANDLE> handleChild;///<  @brief ����
	bool escapeFlag;///<  @brief ����
	int screenShot;///<  @brief ����
	bool screenShotFlag;///<  @brief ����
	int *screenShotGrHandleAdress;///<  @brief ����
	char loadingImgPath[256];///<  @brief ����
	int loadingImg;///<  @brief ����
	bool useThread_AwakeFlag;///<  @brief ����
	int loadingMinimalTime;///<  @brief ����
#ifdef USE_LUA
	lua_State *Lua;///<  @brief ����
#endif
};
}
//Singleton
extern suken::CSystem System;///<  @brief ����
