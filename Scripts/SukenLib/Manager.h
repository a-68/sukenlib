#pragma once

//#define DEBUG
#define DEBUG_DRAW
//#define USE_LUA  //Lua�X�N���v�g���g���Ȃ�R�����g�A�E�g����������
//�����ăv���W�F�N�g������lua5.1.dll��z�u
//����ł������Ȃ��Ȃ�uC\lua�v�ƁuC\lua\include�v���K�؂ɔz�u����Ă��邩���m�F����


#define WINDOW_WIDTH 900
#define WINDOW_HEIGHT 600

//#define BETA
#include"queue"
#include"stack"
#include<vector>
#include"DxLib.h"
#include"String.h"
#include "algorithm"
#include "stdio.h"
#include "stdlib.h"
#include"iostream"
#include "cstdlib"
#include "new"
#include "memory"
using namespace std;
#include "crtdbg.h"
#define _CRTDBG_MAP_ALLOC
#define _USE_MATH_DEFINES
#include"math.h"
#ifdef USE_LUA
#include "lua.hpp"
#endif
#include <wininet.h>
//for MIDI
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib,"winmm")

//#define USE_GRAVITY
const int INF		= 10000000;

const float AIR_REGISTANCE= 30.0f;			//��C��R�i�����̂��₷���j




///�O���[�o���錾

/////Suken.h�p

namespace suken{};


const int DIALOG_MAX_CHAR = 100;
const int MAX_CHAR = 100;

#define GRAVITY VGet( 0.0f , 0.0f )

const int MOUSE_OFF		=	10;
const int MOUSE_ON		=	11;
const int MOUSE_PUSH	=	12;
const int MOUSE_CLICK	=	13;
const int MOUSE_RELEASE =	14;

const char FRAME_EVENT	=	'E';

void Awake();
void GameLoopEnter();
void GameLoopExit();


///FIGURE TYPE
const int SHAPE_RECT	= 1;
const int SHAPE_CIRCLE	= 2;

class CSystem;
extern CSystem System;

class CGame;
extern CGame game;



class CEvent;
extern CEvent Event;

class CMidi;
extern CMidi MD;


