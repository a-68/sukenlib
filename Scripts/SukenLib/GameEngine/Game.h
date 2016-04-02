#pragma once
//for std::vector
#include"Manager.h"
//for CScene
#include"Scene.h"

namespace suken{

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


}


extern suken::CGame Game;