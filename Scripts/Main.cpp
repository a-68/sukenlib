#include"Suken.h"
CScene gameMain;
#define POWER (0.06f*60)
CCircle c[3][3];
class CMe{
public:
	void Init(){
		transform.center.position = VGet(50,50);
		transform.radius = 5;
		gameMain.collision.AddChild(&transform,true);
	}
	void Loop(){
		for(int i=0;i<100;i++){
			if( useBullet[i] ){
				//�Փˌ��m
				if( bullet[i].GetCollisionState() || bullet[i].center.position.x > WINDOW_WIDTH || bullet[i].center.position.x < 0 ||bullet[i].center.position.y > WINDOW_HEIGHT || bullet[i].center.position.y < 0 ){
					//�Փ˕\��
					DrawCircle(bullet[i].center.position,30,RED,false);
					//�ՓˊǗ��V�X�e������o�^����
					useBullet[i] = false;
					gameMain.collision.RemoveChild(&bullet[i]);
				}
			}
		}
		//���@����
		if(Event.key.GetPush(Event.key.UP)){
			transform.center.velocity += VGet(0.0f,-POWER); 
		}
		if(Event.key.GetPush(Event.key.DOWN)){
			transform.center.velocity += VGet(0.0f,POWER); 
		}
		if(Event.key.GetPush(Event.key.RIGHT)){
			transform.center.velocity += VGet(POWER,0.0f); 
		}
		if(Event.key.GetPush(Event.key.LEFT)){
			transform.center.velocity += VGet(-POWER,0.0f); 
		}
		//�͂ݏo���h�~
		if( me.transform.center.position.x < 0 ){
			me.transform.center.velocity.x = abs(me.transform.center.velocity.x);
		}
		if( me.transform.center.position.x > WINDOW_WIDTH ){
			me.transform.center.velocity.x = -abs(me.transform.center.velocity.x);
		}
		if( me.transform.center.position.y < 0 ){
			me.transform.center.velocity.y = abs(me.transform.center.velocity.y);
		}
		if( me.transform.center.position.y > WINDOW_HEIGHT ){
			me.transform.center.velocity.y = -abs(me.transform.center.velocity.y);
		}
		DrawLine(transform.center.position,transform.center.position+VNorm(transform.center.velocity)*10,YELLOW);
		//�e���˂̓X�y�[�X�L�[���������ꂽ�u�Ԃ̂�
		if(Event.key.GetDown(Event.key.SPACE)){
			//�󂫒e�ےT��
			for(int i=0;i<100;i++){
				if( !useBullet[i] ){
					bullet[i].center.position = transform.center.position;
					bullet[i].radius = 2;
					//�O�i�����ɔ���
					bullet[i].center.velocity = VNorm(transform.center.velocity)*500;
					//���@�Ƃ̏Փ˂𖳌���
					bullet[i].AddCollisionFalse(&transform);
					//�ՓˊǗ��V�X�e���ɓo�^
					useBullet[i] = true;
					gameMain.collision.AddChild(&bullet[i],true);
					break;
				}
			}
		}
	}
	CCircle transform;
	CCircle bullet[100];
	bool useBullet[100];
} me;
void GameMainLoop(){
	me.Loop();
}
void Awake(){
	//��Q��
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			c[i][j].center.position = VGet(200*i+200,200*j+100);
			c[i][j].IsKinematic = true;
			c[i][j].radius = 20;
			gameMain.collision.AddChild(&c[i][j],true);
		}
	}
	me.Init();
	gameMain.input.AddEventListener(Event.EVERY_FRAME,GameMainLoop);
	Game.AddChild(&gameMain);
}
void GameLoopEnter(){
}
void GameLoopExit(){
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			DrawCenterString(200*i+200,200*j+100,YELLOW,true,"��Q��");
		}
	}
}