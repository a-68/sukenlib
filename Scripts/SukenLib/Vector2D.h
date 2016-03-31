#include"Manager.h"



namespace suken{


///////////////////////////////////////////////////////////////////////
///�񎟌����W�p�N���X�i���x�Ȃǂɕ֗��j///////////////////////////////////
///���Z�q�I�[�o�[���[�h��DxLib��VECTOR�p�֐��Ɠ����悤�Ɏg����֐��Q��/////
///////////////////////////////////////////////////////////////////////

class Vector2D{  //�錾�Ɠ����ɒ�`�������Ă���̂̓C�����C�������邽��
public:
    Vector2D( float _x , float _y );
    Vector2D();

    float x;
    float y;
 
    void Set( float _x , float _y);
    void Set(Vector2D _vec);
    Vector2D Add( float _x , float _y);
    Vector2D Add(Vector2D _vec);
    // +���Z�q�I�[�o�[���[�h
    Vector2D operator+(const Vector2D &obj);
    // +=���Z�q�I�[�o�[���[�h
    Vector2D& operator+=(const Vector2D &obj);
    // -���Z�q�I�[�o�[���[�h
    Vector2D operator-(const Vector2D &obj);
    // -=���Z�q�I�[�o�[���[�h
    Vector2D& operator-=(const Vector2D &obj);
    //*���Z�q�I�[�o�[���[�h
    Vector2D operator*(const float _num);
    //*=���Z�q�I�[�o�[���[�h
    Vector2D& operator*=(const float _num);
	//  /���Z�q�I�[�o�[���[�h
    Vector2D operator/(const float _num);
    ///=���Z�q�I�[�o�[���[�h
    Vector2D& operator/=(const float _num);
	///==���Z�q�I�[�o�[���[�h
    bool operator==(const Vector2D &obj);
	///=���Z�q�I�[�o�[���[�h
	Vector2D& operator =(const Vector2D &obj);
    //operator*�̃I�[�o�[���[�h�ɂ����͂�s�v�Ȋ֐�
    void Multiple(float _num);
    float GetLength();
private:
};

//////////////////////////////////////////////
//////DxLib��VECTOR�p�֐��̃I�[�o�[���[�h///////
//////////////////////////////////////////////
__inline Vector2D VGet(float _x,float _y){
	Vector2D temp;
	temp.x=_x;
	temp.y=_y;
	return temp;
}
__inline Vector2D VAdd(Vector2D v1,Vector2D v2){
	Vector2D temp;
	temp.x=v1.x+v2.x;
	temp.y=v1.y+v2.y;
	return temp;
}
__inline Vector2D VSub(Vector2D v1,Vector2D v2){
	Vector2D temp;
	temp.x=v1.x-v2.x;
	temp.y=v1.y-v2.y;
	return temp;
}
__inline float VDot(Vector2D v1,Vector2D v2){
	return (v1.x*v2.x+v1.y*v2.y);
}
__inline VECTOR VCross(Vector2D v1,Vector2D v2){
	VECTOR temp;
	temp.z=(float)v1.x*v2.y-v1.y*v2.x;
	return temp;
}
__inline float VCrossLength(Vector2D v1,Vector2D v2){
	return ((v1.x*v2.y)-(v1.y*v2.x));
}
__inline Vector2D VScale(Vector2D v1,float scale){
	Vector2D temp;
	temp.x=v1.x*scale;
	temp.y=v1.y*scale;
	return temp;
}
__inline float VSize(Vector2D v1){
	return sqrt( (float)(v1.x * v1.x + v1.y * v1.y) ) ;
}
__inline float VSquareSize(Vector2D v1){
	return  (v1.x * v1.x + v1.y * v1.y);
}
__inline Vector2D VNorm(Vector2D v1){
	float size=VSize(v1);
	Vector2D temp;
	temp.x=v1.x/size;
	temp.y=v1.y/size;
	return temp;
}

__inline float GetDistance(Vector2D v1 ,Vector2D v2){
	
	return sqrt(pow(abs(v1.x-v2.x),2.0f)+pow(abs(v1.y-v2.y),2.0f));
	
}
__inline float GetSquareDistance(Vector2D v1 ,Vector2D v2){
	
	return pow(abs(v1.x-v2.x),2.0f)+pow(abs(v1.y-v2.y),2.0f);
	
}
__inline int DrawLine(Vector2D &v1 , Vector2D &v2 ,int color){
	return DxLib::DrawLine((int)v1.x,(int)v1.y,(int)v2.x,(int)v2.y,color);
}
__inline int DrawCircle(Vector2D &v,int r,int color,bool fillFlag){
	return DxLib::DrawCircle((int)v.x,(int)v.y,r,color,fillFlag);
}
__inline int DrawBox(suken::Vector2D &v1,suken::Vector2D &v2,int color,bool fillFlag){
	return DxLib::DrawBox((int)v1.x,(int)v1.y,(int)v2.x,(int)v2.y,color,fillFlag);
}
_inline int DrawOval(suken::Vector2D &v,suken::Vector2D &r,int color,bool fillFlag){
	return DxLib::DrawOval((int)v.x,(int)v.y,(int)r.x,(int)r.y,color,fillFlag);
}
_inline int DrawOval(suken::Vector2D &v,int rx,int ry,int color,bool fillFlag){
	return DxLib::DrawOval((int)v.x,(int)v.y,rx,ry,color,fillFlag);
}
_inline int DrawTriangle(suken::Vector2D &v1,suken::Vector2D &v2,suken::Vector2D &v3,int color,bool fillFlag){
	return DxLib::DrawTriangle((int)v1.x,(int)v1.y,(int)v2.x,(int)v2.y,(int)v3.x,(int)v3.y,color,fillFlag);
}
_inline int DrawPixel(suken::Vector2D &v,int color){
	return DxLib::DrawPixel((int)v.x,(int)v.y,color);
}


}//namespace suken end