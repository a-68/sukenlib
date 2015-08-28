#include"Suken.h"



int WINAPI WinMain(HINSTANCE,HINSTANCE,LPSTR,int){
	//�����ݒ�@��������//////////////////////////////////////////////
	System.SetTargetFps(60.0);				//�ڕW�̃t���[�����[�g��ݒ�
	System.SetLoadingGraph("loading.png");	//���[�f�B���O��ʂɕ\������摜�̃A�h���X���w��
	System.SetUseThread_Awake(false);		//void Awake()�̎��s���o�b�N�O���E���h�ōs�����ǂ���
	game.SetUseDrawLoop(false);				//�����ƕ`������S�������邩�ǂ���
	System.SetSyncDrawLoop(false);			//game.SetUseDrawLoop()��true�ɂ����Ƃ������ƕ`��𓯊����邩�ǂ���
	System.SetLoadingMinimalTime(1000);		//Loading��ʂ̍Œ�\�����Ԃ��~���b�Őݒ�
	//�����ݒ�@�����܂�//////////////////////////////////////////////


	System.Awake();
	
	if(System.GetUseThread_Awake()){
		System.CreateNewThread(Awake);
	}else{
		Awake();
	}
	System.Wait_Loading();

	if(game.GetUseDrawLoop()){
		System.CreateNewThread(GameDrawLoop);
	}

	while(!ProcessMessage()&&!System.GetEscapeFlag()){
		if(!game.GetUseDrawLoop()){
			ScreenFlip();
			ClearDrawScreen();
		}else if(game.GetUseDrawLoop()&&System.GetSyncDrawLoop()){
			ScreenFlip();
			ClearDrawScreen();
		}
		System.Update();
		GameLoopEnter();
		game.Loop();
		if(game.GetUseDrawLoop()&&System.GetSyncDrawLoop()){
			game.DrawLoop();
		}
		GameLoopExit();
		System.Wait();
		
	}
        
	System.End();
	return 0;
} 


void GameDrawLoop(){
	
	while(!ProcessMessage()&&!System.GetEscapeFlag()){
		if(!System.GetSyncDrawLoop()){
			ScreenFlip();
			ClearDrawScreen();
		}
		game.DrawLoop();
	}
	
}
