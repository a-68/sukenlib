#pragma once
#include <vector>
#include "Physics\CollosionManager.h"
#include "Event\Input.h"
#include "Event\Event.h"

namespace suken{

class CButton{
public:
	/**
*	@brief ����
*/
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
/**
*	@brief ����
*/
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
/**
*	@brief ����
*/
	CScene();
/**
*	@brief ����
*/
	void Loop();
/**
*	@brief ����
*/
	void ButtonLoop();
	suken::CCollisionManager collision;
	CInput input;
	std::vector<CButton> buttonChild;
	std::vector<CpButton> pButtonChild;
	CScene *sceneChild;
/**
*	@brief ����
*	@param value ����
*/
	void SetFocus(bool _focus);
/**
*	@brief ����
* @return �߂�l
*/
	bool GetFocus();
/**
*	@brief ����
*	@param value ����
*/
	void AddChild(CScene *_scene);
/**
*	@brief ����
*/
	void RemoveChild();
/**
*	@brief ����
*	@param value ����
*/
	void SetButton( int x1 , int y1 , int x2 , int y2 , int backColor , char *title , int stringColor , void (*pFunc)() );
/**
*	@brief ����
*	@param value ����
*/
	void SetButton( int x1 , int y1 , int x2 , int y2 , int backColor , char *title , int stringColor , void (*pFunc)(int) , int *pInt );
/**
*	@brief ����
*	@param value ����
*/
	void SetButton( int x1 , int y1 , int x2 , int y2 , int backColor , char *title , int stringColor , void (*pFunc)(int) , int Int );
/**
*	@brief ����
*	@param value ����
*/
	void SetButton( int x1 , int y1 , int x2 , int y2 , int graph, void (*pFunc)() );
/**
*	@brief ����
*	@param value ����
*/
	void SetButton( int x1 , int y1 , int x2 , int y2 , int graph, void (*pFunc)(int) , int *pInt );
/**
*	@brief ����
*	@param value ����
*/
	void SetButton( int x1 , int y1 , int x2 , int y2 , int graph, void (*pFunc)(int) , int Int );
/**
*	@brief ����
*	@param value ����
*/
	void SetButton( int x1 , int y1 , int x2 , int y2 , char* graphPath, void (*pFunc)() );
/**
*	@brief ����
*	@param value ����
*/
	void SetButton( int x1 , int y1 , int x2 , int y2 , char* graphPath, void (*pFunc)(int) , int *pInt );
/**
*	@brief ����
*	@param value ����
*/
	void SetButton( int x1 , int y1 , int x2 , int y2 , char* graphPath, void (*pFunc)(int) , int Int );
/**
*	@brief ����
*	@param value ����
*/
	void SetButton( int x1 , int y1 , int x2 , int y2 , char* Off_graphPath , char* On_graphPath , void (*pFunc)() );
/**
*	@brief ����
*	@param value ����
*/
	void SetButton( int x1 , int y1 , int x2 , int y2 , char* Off_graphPath , char* On_graphPath , void (*pFunc)(int) , int *pInt );
/**
*	@brief ����
*	@param value ����
*/
	void SetButton( int x1 , int y1 , int x2 , int y2 , char* Off_graphPath , char* On_graphPath , void (*pFunc)(int) , int Int );
/**
*	@brief ����
*	@param value ����
*/
	void SetButton( int *x1 , int *y1 , int *x2 , int *y2 , int backColor , char *title , int stringColor , void (*pFunc)() );
/**
*	@brief ����
*	@param value ����
*/
	void SetButton( int *x1 , int *y1 , int *x2 , int *y2 , int backColor , char *title , int stringColor , void (*pFunc)(int) ,int *pInt );
/**
*	@brief ����
*	@param value ����
*/
	void SetButton( int *x1 , int *y1 , int *x2 , int *y2 , int backColor , char *title , int stringColor , void (*pFunc)(int) ,int Int );
/**
*	@brief ����
*	@param value ����
*/
	void SetButton( int *x1 , int *y1 , int *x2 , int *y2 , int graph , void (*pFunc)() );
/**
*	@brief ����
*	@param value ����
*/
	void SetButton( int *x1 , int *y1 , int *x2 , int *y2 , int graph , void (*pFunc)(int) ,int *pInt );
/**
*	@brief ����
*	@param value ����
*/
	void SetButton( int *x1 , int *y1 , int *x2 , int *y2 , int graph , void (*pFunc)(int) ,int Int );
/**
*	@brief ����
*	@param value ����
*/
	void SetButton( int *x1 , int *y1 , int *x2 , int *y2 , char* graphPath , void (*pFunc)() );
/**
*	@brief ����
*	@param value ����
*/
	void SetButton( int *x1 , int *y1 , int *x2 , int *y2 , char* graphPath , void (*pFunc)(int) , int *pInt );
/**
*	@brief ����
*	@param value ����
*/
	void SetButton( int *x1 , int *y1 , int *x2 , int *y2 , char* graphPath , void (*pFunc)(int) , int Int );
/**
*	@brief ����
*	@param value ����
*/
	void SetButton( int *x1 , int *y1 , int *x2 , int *y2 , char* Off_graphPath , char* On_graphPath , void (*pFunc)() );
/**
*	@brief ����
*	@param value ����
*/
	void SetButton( int *x1 , int *y1 , int *x2 , int *y2 , char* Off_graphPath , char* On_graphPath , void (*pFunc)(int) , int *pInt );
/**
*	@brief ����
*	@param value ����
*/
	void SetButton( int *x1 , int *y1 , int *x2 , int *y2 , char* Off_graphPath , char* On_graphPath , void (*pFunc)(int) , int Int );
/**
*	@brief ����  //�������C�u���������֐��i�g�p�֎~�j
*/
	void ResetSceneNum();
/**
*	@brief ����
* @return �߂�l
*/
	unsigned int GetSerialNum();
private:
	bool focus;
	static unsigned int sceneNum;
	unsigned int serialNum;
};


}