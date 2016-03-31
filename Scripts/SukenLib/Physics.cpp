#include"Physics.h"
#include"System.h"
#include"Utility.h"



suken::CTransform::CTransform(){
	//prePosition = position = velocity = acceralate = VGet(0,0);
	rotation = 0.0f;
	gravity = GRAVITY;
	airResistance = 0 ;
}
void suken::CTransform::TransLate(suken::Vector2D _v){
	position += _v;
}
void suken::CTransform::Loop(){
		
	//prePosition = position;
		
	///空気抵抗
	acceralate *= ( 1 - ( airResistance / System.GetFps() ));
		
	///速度
	velocity += (acceralate + gravity ) / System.GetFps();
	velocity *= ( 1 - ( airResistance / System.GetFps() ));
	///位置
	prePosition = position;
	position += velocity / System.GetFps();
	if( velocity.y > 0.0f ){
		rotation = acos(VNorm(velocity).x);
	}else{
		rotation = -acos(VNorm(velocity).x);
	}
}

suken::CRect::CRect(){
	direction=0.0f;
	Set(1,1);
}
void suken::CRect::Set(int sizeX,int sizeY){
	size = VGet((float)sizeX,(float)sizeY);
	rad = atan2(size.y,size.x);
	radius = ( size.GetLength() / 2.0f );
}
suken::Vector2D suken::CRect::GetCenterPos(){
	return center.position;						
}
suken::Vector2D suken::CRect::GetSize(){			
	return size;								
}
float suken::CRect::GetArea(){			
	return ( size.x * size.y );					
}
suken::Vector2D suken::CRect::GetRightTop(){				
	return ( center.position + VScale(VGet((float)cos(direction+rad),(float)sin(direction+rad)),radius) );	
}
suken::Vector2D suken::CRect::GetLeftTop(){				
	return ( center.position + VScale(VGet((float)cos(direction-rad),(float)sin(direction-rad)),radius) );	
}
suken::Vector2D suken::CRect::GetLeftBottom(){		
	return ( center.position + VScale(VGet((float)cos(direction-M_PI+rad),(float)sin(direction-M_PI+rad)),radius) );	
}
suken::Vector2D suken::CRect::GetRightBottom(){			
	return ( center.position + VScale(VGet((float)cos(direction+M_PI-rad),(float)sin(direction+M_PI-rad)),radius) );	
}
void suken::CRect::Draw(int color){
	DrawLine(GetLeftTop(),GetRightTop(),RED);
	DrawLine(GetRightTop(),GetRightBottom(),BLUE);
	DrawLine(GetRightBottom(),GetLeftBottom(),GREEN);
	DrawLine(GetLeftBottom(),GetLeftTop(),WHITE);
}
void suken::CRect::Loop(){

	center.Loop();
#ifdef DEBUG_DRAW
	Draw(WHITE);
		
#endif
}
float suken::CRect::GetRadius(){
	return radius;
}
void suken::CRect::AddEventLisnerOnCollision(void (*pFunc)()){
	onCollisionTaskVoid.push_back(pFunc);
}
void suken::CRect::RemoveEventLisnerOnCollision(void (*pFunc)()){

	if(!onCollisionTaskVoid.empty()){
		vector<void(*)()>::iterator it = onCollisionTaskVoid.begin();
		while( ( it != onCollisionTaskVoid.end() ) ){

			if( *it ==  pFunc  ){

				onCollisionTaskVoid.erase( it );
				break;
			}
			it++;
		}
	}	
}
void suken::CRect::OnCollision(){
	if(!onCollisionTaskVoid.empty()){
		vector<void(*)()>::iterator it=onCollisionTaskVoid.begin();

		while( it != onCollisionTaskVoid.end() ) {

			(*it)();					
				it++;
		}

	}
}



suken::CCircle::CCircle(){
	mass = 1.0f;
	radius = 1.0f;
	bound = 1.0f;
	IsKinematic = false;
}
suken::Vector2D suken::CCircle::GetCenterPos(){		
	return center.position;					
}
float suken::CCircle::GetArea(){			
	return (float)( M_PI * radius * radius );		
}
void suken::CCircle::Loop(){
	center.Loop();
#ifdef DEBUG_DRAW
	DxLib::DrawCircle((int)(center.position.x +0.5), (int)(center.position.y+0.5) , (int)(radius+0.5) ,WHITE ,false );
#endif
}
void suken::CCircle::AddEventLisnerOnCollision(void (*pFunc)()){
	onCollisionTaskVoid.push_back(pFunc);
}
void suken::CCircle::RemoveEventLisnerOnCollision(void (*pFunc)()){

	if(!onCollisionTaskVoid.empty()){
		vector<void(*)()>::iterator it = onCollisionTaskVoid.begin();
		while( ( it != onCollisionTaskVoid.end() ) ){

			if( *it ==  pFunc  ){
				onCollisionTaskVoid.erase( it );
				break;
			}
			it++;
		}
	}	
}
void suken::CCircle::OnCollisionFunc(){
	if(!onCollisionTaskVoid.empty()){
		vector<void(*)()>::iterator it=onCollisionTaskVoid.begin();

		while( it != onCollisionTaskVoid.end() ) {

			(*it)();					
			it++;
		}

	}
}
void suken::CCircle::AddCollisionFalse(CCircle *c){
	noCollision.push_back(c);
}
void suken::CCircle::RemoveCollisionFalse(CCircle *c){
	if(!noCollision.empty()){
		vector<CCircle*>::iterator it = noCollision.begin();
		while( ( it != noCollision.end() ) ){

			if( *it ==  c  ){

				noCollision.erase( it );
				break;
			}
			it++;
		}
	}
}
bool suken::CCircle::GetIsNoCollision(CCircle *c){
	if(!noCollision.empty()){
		vector<CCircle*>::iterator it = noCollision.begin();
		while( ( it != noCollision.end() ) ){

			if( *it ==  c  ){

				return true;
			}
			it++;
		}
	}
	return false;
}
suken::CCollisionManager::CCollisionManager(){
	
}
suken::CCollisionManager::~CCollisionManager(){
	
}
void suken::CCollisionManager::Awake(){
	
}
void suken::CCollisionManager::Loop(){
		
	for(unsigned int i=0;i<physicsCircle.size();i++){
		physicsCircle[i]->onCollision = false;
		physicsCircle[i]->Loop();
	}
	for(unsigned int i=0;i<fixedCircle.size();i++){
		fixedCircle[i]->onCollision = false;
		fixedCircle[i]->Loop();
	}
	for(unsigned int i=0;i<physicsCircle.size();i++){
		for(unsigned int j=i+1;j<physicsCircle.size();j++){
			if( !physicsCircle[i]->GetIsNoCollision(physicsCircle[j]) && !physicsCircle[j]->GetIsNoCollision(physicsCircle[i])){
				CollisionCircle(*physicsCircle[i],*physicsCircle[j]);
			}
		}
		for(unsigned int j=0;j<fixedCircle.size();j++){
			if( !physicsCircle[i]->GetIsNoCollision(fixedCircle[j]) && !fixedCircle[j]->GetIsNoCollision(physicsCircle[i])){
				CollisionCircle(*physicsCircle[i],*fixedCircle[j]);
			}
		}
	}
	for(unsigned int i=0;i<physicsRect.size();i++){
		physicsRect[i]->Loop();
		for(unsigned int j=i+1;j<physicsRect.size();j++){
			if( !CollisionRect(*physicsRect[i],*physicsRect[j]) ){
				CollisionRect(*physicsRect[j],*physicsRect[i]);
			}
		}
		for(unsigned int j=0;j<fixedRect.size();j++){
			if( !CollisionRect(*physicsRect[i],*fixedRect[j]) ){
				CollisionRect(*fixedRect[j],*physicsRect[i]);
			}
		}
	}
	/*for(unsigned int i=0;i<physicsCircle.size();i++){
		if(physicsCircle[i]->center.position.x < 0){
			physicsCircle[i]->center.velocity.x = -(physicsCircle[i]->center.velocity.x);
			physicsCircle[i]->center.position.x = 0;
		}
		if(physicsCircle[i]->center.position.x > WINDOW_WIDTH ){
			physicsCircle[i]->center.velocity.x = -(physicsCircle[i]->center.velocity.x);
			physicsCircle[i]->center.position.x = WINDOW_WIDTH ;
		}
		if(physicsCircle[i]->center.position.y < 0){
			physicsCircle[i]->center.velocity.y = -(physicsCircle[i]->center.velocity.y);
			physicsCircle[i]->center.position.y = 0;
		}
		if(physicsCircle[i]->center.position.y > WINDOW_HEIGHT ){
			physicsCircle[i]->center.velocity.y = -(physicsCircle[i]->center.velocity.y);
			physicsCircle[i]->center.position.y = WINDOW_HEIGHT;
		}
	}*/
		
}
void suken::CCollisionManager::DrawLoop(){
	
}
void suken::CCollisionManager::CollisionCircleCalc(CCircle &A , CCircle &B ,float time){
		
	float totalWeight = A.mass + B.mass;				//質量和
	float reflectionRate = (1 + A.bound * B.bound );	// 反発率
	suken::Vector2D C = VNorm( B.center.position - A.center.position ); // 衝突軸ベクトル
	float dot = VDot( ( A.center.velocity - B.center.velocity ), C ); // 内積算出
	suken::Vector2D constVec = C * ( reflectionRate * dot / totalWeight ); // 定数ベクトル

	//速度書き換え
	// 衝突後位置の算出
	if(!A.IsKinematic){
		A.center.velocity += constVec * (-B.mass);
		A.center.position += (A.center.velocity) * 0.05f;
	}
	if(!B.IsKinematic){
		B.center.velocity += constVec  * A.mass ;
		B.center.position += (B.center.velocity) * 0.05f;
	}

}
bool suken::CCollisionManager::CollisionCircle(CCircle &A , CCircle &B){
	// 前位置及び到達位置におけるパーティクル間のベクトルを算出
	suken::Vector2D C0 = B.center.prePosition - A.center.prePosition;
	suken::Vector2D C1 = B.center.position - A.center.position;
	suken::Vector2D D = C1 - C0;

	// 衝突判定用の2次関数係数の算出
	float P = VSquareSize( D ); 
	// 同じ方向に移動
	if(P==0){ 
		return false; 
	}
	float Q = VDot( C0, D );
	float R = VSquareSize( C0 );

	// 距離
	float r = A.radius + B.radius;

	 // 衝突判定式
	float Judge = Q*Q - P*(R-r*r);

	if( Judge < 0 ){
	// 衝突していない
		return false;
	}

	// 衝突時間の算出
	float t_plus = (-Q + sqrt( Judge ) ) / P;
	float t_minus = ( -Q - sqrt( Judge ) ) / P;

	// 衝突位置の決定
	suken::Vector2D pOut_colli_A = A.center.prePosition + ( A.center.position - A.center.prePosition) * t_minus;
	suken::Vector2D pOut_colli_B = B.center.prePosition + ( B.center.position - B.center.prePosition) * t_minus;

   // 衝突時間の決定（t_minus側が常に最初の衝突）
   float pOut_t0 = t_minus;
   float pOut_t1 = t_plus;

	// 時間内衝突できるか？
   // t_minusが1より大きいと届かず衝突していない
   // t_plus、t_minusが両方ともマイナスだと反対方向なので衝突しない
   if( (t_minus > 1) || (t_minus < 0 && t_plus < 0) ){
      return false;
   }

   //衝突処理
   A.onCollision=true;
   B.onCollision=true;

   A.OnCollisionFunc();
   B.OnCollisionFunc();
#ifdef DEBUG_DRAW
   DxLib::DrawCircle((int)(A.center.position.x +0.5), (int)(A.center.position.y+0.5) , (int)(A.radius+0.5) ,GREEN ,true );
   DxLib::DrawCircle((int)(B.center.position.x +0.5), (int)(B.center.position.y+0.5) , (int)(B.radius+0.5) ,GREEN ,true );
#endif
   CollisionCircleCalc(A ,B ,( 1.0f - abs(pOut_t0) ) / 60.0f );
   return true; // 衝突報告

}
bool suken::CCollisionManager::CollisionRect(CRect &A , CRect &B){
	if(pow((A.GetRadius()+B.GetRadius()),2.0f) > GetSquareDistance(A.center.position,B.center.position)){
	suken::Vector2D v[4]={VSub(A.GetRightTop(),A.GetLeftTop()),VSub(A.GetRightBottom(),A.GetRightTop()),VSub(A.GetLeftBottom(),A.GetRightBottom()),VSub(A.GetLeftTop(),A.GetLeftBottom())};
	suken::Vector2D s[4]={A.GetLeftTop(),A.GetRightTop(),A.GetRightBottom(),A.GetLeftBottom()};
	suken::Vector2D vertex[4]={B.GetLeftTop(),B.GetRightTop(),B.GetRightBottom(),B.GetLeftBottom()};
	bool IsCollision[4]={true,true,true,true};
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			if( VCrossLength(v[j],VSub(vertex[i],s[j])) < 0 ){
				IsCollision[i]=false;
			}
		}
		if(IsCollision[i]){
			A.OnCollision();
			B.OnCollision();
#ifdef DEBUG_DRAW
			A.Draw(GREEN);
			B.Draw(GREEN);
			//DrawBox(A.center.position+VGet(20,20),A.center.position-VGet(20,20),RED,true);
#endif
			return true;
		}
	}
		
	}else{
#ifdef DEBUG_DRAW
		//DrawBox(A.center.position+VGet(20,20),A.center.position-VGet(20,20),BLUE,true);
#endif
	}
	return false;
}
void suken::CCollisionManager::AddChild(CCircle *_circle , bool moveFlag){
	if(moveFlag){
		physicsCircle.push_back(_circle);
	}else{
		fixedCircle.push_back(_circle);
		_circle->mass = INF ;
	}
}
bool suken::CCollisionManager::RemoveChild(CCircle *_circle){

	vector<CCircle*>::iterator it_p = physicsCircle.begin();
	for(unsigned int i=0;i<physicsCircle.size();i++){
		if( physicsCircle[i] == _circle ){
			physicsCircle.erase(it_p);
			return true;
		}
		it_p++;
	}

	vector<CCircle*>::iterator it_f = fixedCircle.begin();
	for(unsigned int i=0;i<fixedCircle.size();i++){
		if( fixedCircle[i] == _circle ){
			fixedCircle.erase(it_f);
			return true;
		}
		it_f++;
	}

	return false;
}
void suken::CCollisionManager::AddChild(CRect *_rect , bool moveFlag){
	if(moveFlag){
		physicsRect.push_back(_rect);
	}else{
		fixedRect.push_back(_rect);
	}
}
bool suken::CCollisionManager::RemoveChild(CRect *_rect){

	vector<CRect*>::iterator it_p = physicsRect.begin();
	for(unsigned int i=0;i<physicsRect.size();i++){
		if( physicsRect[i] == _rect ){
			physicsRect.erase(it_p);
			return true;
		}
		it_p++;
	}

	vector<CRect*>::iterator it_f = fixedRect.begin();
	for(unsigned int i=0;i<fixedRect.size();i++){
		if( fixedRect[i] == _rect ){
			fixedRect.erase(it_f);
			return true;
		}
		it_f++;
	}

	return false;
}
