#pragma once
#include"Manager.h"
#include"Scene.h"


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