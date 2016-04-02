#pragma once
#include"EventData.h"
#include <vector>

namespace suken{

	//���̓C�x���g�Ǘ��N���X
class CInput{
public:
/**
*	@brief ����
*/
	CInput();
/**
*	@brief ����
*	@param value ����
*/
	void AddEventListener( int inputCode , void func() );
/**
*	@brief ����
*	@param value ����
*/
	void AddEventListener( int inputCode , void func(int) , int *pArgument );
/**
*	@brief ����
*	@param value ����
*/
	void AddEventListener( int inputCode , void func(int) , int Argument );
/**
*	@brief ����
*	@param value ����
*/
	void RemoveEventListener( int inputCode , void func()  );
/**
*	@brief ����
*	@param value ����
*/
	void RemoveEventListener( int inputCode , void func(int) , int *pArgument  );
/**
*	@brief ����
*	@param value ����
*/
	void RemoveEventListener( int inputCode , void func(int) , int Argument  );
/**
*	@brief ����
*	@param value ����
*/
	void AddEventListener( CMouseIn input , void func()  );
/**
*	@brief ����
*	@param value ����
*/
	void AddEventListener( CMouseIn input , void func(int) , int *pArgument  );
/**
*	@brief ����
*	@param value ����
*/
	void AddEventListener( CMouseIn input , void func(int) , int Argument  );
/**
*	@brief ����
*	@param value ����
*/
	void RemoveEventListener( CMouseIn input , void func()  );
/**
*	@brief ����
*	@param value ����
*/
	void RemoveEventListener( CMouseIn input , void func(int) , int *pArgument  );
/**
*	@brief ����
*	@param value ����
*/
	void RemoveEventListener( CMouseIn input , void func(int) , int Argument  );
/**
*	@brief ����
*	@param value ����
*/
	void AddEventListener( CpMouseIn input , void func()  );
/**
*	@brief ����
*	@param value ����
*/
	void AddEventListener( CpMouseIn input , void func(int) , int *pArgument  );
/**
*	@brief ����
*	@param value ����
*/
	void AddEventListener( CpMouseIn input , void func(int) , int Argument  );
/**
*	@brief ����
*	@param value ����
*/
	void RemoveEventListener( CpMouseIn input , void func()  );
/**
*	@brief ����
*	@param value ����
*/
	void RemoveEventListener( CpMouseIn input , void func(int) , int *pArgument  );
/**
*	@brief ����
*	@param value ����
*/
	void RemoveEventListener( CpMouseIn input , void func(int) , int Argument  );
/**
*	@brief ����
*	@param value ����
*/
	void AddEventListener( char input , void func()  );
/**
*	@brief ����
*	@param value ����
*/
	void AddEventListener( char input , void func(int) , int *pArgument  );
/**
*	@brief ����
*	@param value ����
*/
	void AddEventListener( char input , void func(int) , int Argument  );
/**
*	@brief ����
*	@param value ����
*/
	void RemoveEventListener( char input , void func()  );
/**
*	@brief ����
*	@param value ����
*/
	void RemoveEventListener( char input , void func(int) , int *pArgument  );
/**
*	@brief ����
*	@param value ����
*/
	void RemoveEventListener( char input , void func(int) , int Argument  );
/**
*	@brief ����
*	@param value ����
*/
	void AddEventListener( bool* input , void func()  );
/**
*	@brief ����
*	@param value ����
*/
	void AddEventListener( bool* input , void func(int) , int *pArgument  );
/**
*	@brief ����
*	@param value ����
*/
	void AddEventListener( bool* input , void func(int) , int Argument  );
/**
*	@brief ����
*	@param value ����
*/
	void RemoveEventListener( bool* input , void func()  );	
/**
*	@brief ����
*	@param value ����
*/
	void RemoveEventListener( bool* input , void func(int) , int *pArgument  );
/**
*	@brief ����
*	@param value ����
*/
	void RemoveEventListener( bool* input , void func(int) , int Argument  );
/**
*	@brief ����
*/
	void Loop();
/**
*	@brief ����
*/
	void DrawLoop();

	bool useKey,useMouse;
	int mouseX,mouseY;
private:
	CKeyIn keyTemp;
	std::vector<CKeyIn> keyTask;

	CMouseIn mouseTemp;
	std::vector<CMouseIn> mouseTask;

	CpMouseIn pMouseTemp;
	std::vector<CpMouseIn> pMouseTask;

	CFrame frameTemp;
	std::vector<CFrame> frameTask;

	CBoolean boolTemp;
	std::vector<CBoolean> boolTask;

	std::vector<CKeyIn> keyTask_Draw;
	std::vector<CMouseIn> mouseTask_Draw;
	std::vector<CpMouseIn> pMouseTask_Draw;
	std::vector<CFrame> frameTask_Draw;
	std::vector<CBoolean> boolTask_Draw;

	bool mouseInput,preMouseInput;
};



}