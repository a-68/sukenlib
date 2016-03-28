#include "Suken.h"
#include "DxLib.h"
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include "windows.h"//execute�p
#include <wininet.h>
#pragma comment(lib, "wininet.lib")

CSystem System;
CGame game;
CEvent Event;

void null(){

}




bool SelectOpenFile(  char *filename , char *filetype)
{
    OPENFILENAME ofn;

    ZeroMemory(&ofn, sizeof(OPENFILENAME));
    ofn.lStructSize = sizeof(OPENFILENAME);
    //ofn.hwndOwner = hWnd;
    ofn.lpstrFilter = filetype;
    ofn.lpstrFile = filename;
    ofn.nMaxFile = MAX_PATH;
    ofn.nMaxFileTitle = 100;
    ofn.Flags = OFN_FILEMUSTEXIST | OFN_HIDEREADONLY;
    ofn.lpstrTitle = "�t�@�C�����J��";
    if (!GetOpenFileName(&ofn)) return FALSE; // �L�����Z��

    return TRUE;
}

bool SaveFile(char *filename ,char *filetype){
	static OPENFILENAME     ofn;
    static TCHAR            szPath[ MAX_PATH ];
    static TCHAR            szFile[ MAX_PATH ];
    
    if ( szPath[0] == TEXT('\0') ){
        GetCurrentDirectory( MAX_PATH, szPath );
    }
    if ( ofn.lStructSize == 0 ){
        ofn.lStructSize         = sizeof(OPENFILENAME);
		ofn.hwndOwner           = DxLib::GetMainWindowHandle();
        ofn.lpstrInitialDir     = szPath;       // �����t�H���_�ʒu
        ofn.lpstrFile           = filename;       // �I���t�@�C���i�[
        ofn.nMaxFile            = MAX_PATH;
        ofn.lpstrDefExt         = TEXT(".*");
        ofn.lpstrFilter         = filetype;
        ofn.lpstrTitle          = TEXT("�t�@�C����ۑ����܂��B");
        ofn.Flags               = OFN_FILEMUSTEXIST | OFN_OVERWRITEPROMPT;
    }
    if ( GetSaveFileName(&ofn) ){
        MessageBox( GetMainWindowHandle(), filename, TEXT("�t�@�C������t���ĕۑ�"), MB_OK );
    }

	return true;
}

//double M_PI = 3.1415926536;

void SukenExecute(char *URL){
		OSVERSIONINFO OSver;
		OSver.dwOSVersionInfoSize =sizeof(OSVERSIONINFO);
		GetVersionEx(&OSver);
		if(OSver.dwMajorVersion < 6 ){//XP�ȉ�
			ShellExecute( NULL, "open", "IExplore",URL, NULL,SW_SHOWNORMAL );
		}else{//Vista�ȏ�
			ShellExecute( NULL, "open",URL, NULL, NULL,SW_SHOWNORMAL );
		}
}

double Scos(int Angle){
	return  cos( (double)Angle * M_PI / 180.0   ) ;
}
double Ssin(int Angle){
	return  sin( (double)Angle * M_PI / 180.0   ) ;
}
double Stan(int Angle){
	return  tan( (double)Angle * M_PI  / 180.0 ) ;
}
int AngleFromRad(double Angle){
	return (int)( Angle * 180 / M_PI) ;
}
int Power2(int x, int y){
    int i,result;
    for( i=1, result = 1; i <= y; i++) {result *= x;}
    return result;
}
int Clng ( char *Str ,int n ){
	char s[10];int ns = 0; int ret = 0;
	while(!(Str[n] == '\0' )  && ns < 10){
		switch (Str[n]){
		case '0': s[ns] = 0 ;ns++;break;case '1': s[ns] = 1 ;ns++;break;  
		case '2': s[ns] = 2 ;ns++;break;case '3': s[ns] = 3 ;ns++;break;  
		case '4': s[ns] = 4 ;ns++;break;case '5': s[ns] = 5 ;ns++;break;  
		case '6': s[ns] = 6 ;ns++;break;case '7': s[ns] = 7 ;ns++;break;  
		case '8': s[ns] = 8 ;ns++;break;case '9': s[ns] = 9 ;ns++;break;   
		}
		n++;
	}
	int ss = 0;ns--;
	while(ns >= 0){
		ret += s[ns] * Power2(10,ss);
		ns--; ss++;
	}
	return ret ;
}

int ClngFrom ( char *Str ,char Word ){
	char s[10];int ns = 0; int ret = 0;
	int n = 0;
	while(!(Str[n] == '\0' || Str[n] == Word )  && ns < 10){n++;}
	while(!(Str[n] == '\0' )  && ns < 10){
		switch (Str[n]){
		case '0': s[ns] = 0 ;ns++;break;case '1': s[ns] = 1 ;ns++;break;  
		case '2': s[ns] = 2 ;ns++;break;case '3': s[ns] = 3 ;ns++;break;  
		case '4': s[ns] = 4 ;ns++;break;case '5': s[ns] = 5 ;ns++;break;  
		case '6': s[ns] = 6 ;ns++;break;case '7': s[ns] = 7 ;ns++;break;  
		case '8': s[ns] = 8 ;ns++;break;case '9': s[ns] = 9 ;ns++;break;   
		}
		n++;
	}
	int ss = 0;ns--;
	while(ns >= 0){
		ret += s[ns] * Power2(10,ss);
		ns--; ss++;
	}
	return ret ;
}

int ClngTo ( char *Str ,char Word ){
	char s[10];int ns = 0; int ret = 0;
	int n = 0;
	while(!(Str[n] == '\0' || Str[n] == Word)  && ns < 10){
		switch (Str[n]){
		case '0': s[ns] = 0 ;ns++;break;case '1': s[ns] = 1 ;ns++;break;  
		case '2': s[ns] = 2 ;ns++;break;case '3': s[ns] = 3 ;ns++;break;  
		case '4': s[ns] = 4 ;ns++;break;case '5': s[ns] = 5 ;ns++;break;  
		case '6': s[ns] = 6 ;ns++;break;case '7': s[ns] = 7 ;ns++;break;  
		case '8': s[ns] = 8 ;ns++;break;case '9': s[ns] = 9 ;ns++;break;   
		}
		n++;
	}
	int ss = 0;ns--;
	while(ns >= 0){
		ret += s[ns] * Power2(10,ss);
		ns--; ss++;
	}
	return ret ;
}

bool CheckWord(char *Str ,char Word ){
	int n = 0 ;
	while(!(Str[n] == '\0' )){
		if(Str[n] == Word )return 1 ;
		n++;
	}
	return 0 ;
}

unsigned long FileGetSize(char *FileName){ 
	int filesize;
	FILE* fp = fopen( FileName, "rb" );
	if (fp ==NULL)return 0;
	fseek( fp, 0L, SEEK_END );
	filesize = ftell( fp );
	fclose( fp );
	return filesize;
}


CCaesar::CCaesar (char finame[],char imname[],int key){
	FileName = finame;Key = key;ImaginaryName = imname; 
}

bool CCaesar::CaesarToBMP(){

	FILE *fi,*fo;int value;
	unsigned long FileSize =FileGetSize(FileName);
	switch(FileSize){case 0:case 4294967295:return 0;}
	fi = fopen(FileName,"rb");if (fi == NULL) return 0;
	fo = fopen(ImaginaryName,"wb");if (fo == NULL) return 0;

	putc(0x42,fo);putc(0x4d,fo);
	putc(0x00,fo);putc(0x00,fo);putc(0x00,fo);putc(0x00,fo);
	putc(0x00,fo);putc(0x00,fo);putc(0x00,fo);putc(0x00,fo);
	putc(0x36,fo);putc(0x00,fo);putc(0x00,fo);putc(0x00,fo);
	putc(0x28,fo);putc(0x00,fo);putc(0x00,fo);putc(0x00,fo);

	putc(0x04,fo);putc(0x00,fo);putc(0x00,fo);putc(0x00,fo);//Width
	//////////////////////////////////////////////////////////Height
	int File4 = (int)(FileSize / 12);
	int FileMod12 = FileSize % 12;
	if(FileMod12 != 0)File4++;
	int F0,F1,F2,F3;
	F3 = (int)(File4 / (Power2(2,24)));
	F2 = (int)((File4 -(F3 * Power2(2,24))) / (Power2(2,16)));
	F1 = (int)((File4 -(F3 * Power2(2,24)) -(F2 * Power2(2,16))) / (Power2(2,8)));
	F0 = File4 - F3 * Power2(2,24) - F2 * Power2(2,16) - F1 * Power2(2,8);

	putc(F0,fo);putc(F1,fo);putc(F2,fo);putc(F3,fo);

	putc(0x01,fo);putc(0x00,fo);putc(0x18,fo);putc(0x00,fo);
	putc(0x00,fo);putc(0x00,fo);putc(0x00,fo);putc(0x00,fo);

	putc(0x00,fo);putc(0x00,fo);putc(0x00,fo);putc(0x00,fo);
	putc(0x00,fo);putc(0x00,fo);putc(0x00,fo);putc(0x00,fo);
	putc(0x00,fo);putc(0x00,fo);putc(0x00,fo);putc(0x00,fo);
	putc(0x00,fo);putc(0x00,fo);putc(0x00,fo);putc(0x00,fo);
	putc(0x00,fo);putc(0x00,fo);putc(0x00,fo);putc(0x00,fo);
	if(FileMod12 != 0){for (int i = 0; i < 12 - FileMod12  ;i++){putc(0x72,fo);}}

	while ((value = getc(fi)) != EOF){putc(value + Key,fo);}
	fclose(fo);fclose(fi);
	remove(FileName);
	return 1;
}

bool CCaesar::CaesarFromBMP(){

	FILE *fi,*fo;int value;
	fo = fopen(ImaginaryName,"rb");if (fo == NULL) return 0;
	fi = fopen(FileName,"wb");if (fi == NULL) return 0;
	for(int i = 0;i<54;i++){value = getc(fo);}
	value = getc(fo);
		while (value == 0x72){value = getc(fo);}
	putc(value- Key,fi);
	while ((value = getc(fo)) != EOF){putc(value- Key,fi);}
	fclose(fo);fclose(fi);
	remove(ImaginaryName);
	return 1;
}

bool CCaesar::CaesarCode(){

	FILE *fi,*fo;int value;
	fi = fopen(FileName,"rb");if (fi == NULL) return 0;
	fo = fopen(ImaginaryName,"wb");if (fo == NULL) return 0;
	
	while ((value = getc(fi)) != EOF){putc(value + Key,fo);}
	fclose(fo);fclose(fi);
	remove(FileName);
	return 1;
}

bool CCaesar::CaesarDecode(){

	FILE *fi,*fo;int value;
	fo = fopen(ImaginaryName,"rb");if (fo == NULL) return 0;
	fi = fopen(FileName,"wb");if (fi == NULL) return 0;

	while ((value = getc(fo)) != EOF){putc(value- Key,fi);}
	fclose(fo);fclose(fi);
	remove(ImaginaryName);
	return 1;
}

CIntData::CIntData(char *_DataName){
	int Len;
	Len = std::strlen (_DataName);
	DataName = new char [Len + 1];
	strcpy(DataName , _DataName);
	DataName[Len] = '\0';
}

void CIntData::NewMake(){
	FILE *fp;
	fp = fopen( DataName , "w+");/////////////��������
	if (fp == NULL){
		DataName = "iMaGiNaRy.imr";
		fp = fopen( DataName , "w+");
	}
	for(int i = 0; i <2000 ;i++){
	fputs("0:0\r\n" , fp);//��������
	}
	fclose(fp);
}

void CIntData::ReadData(){
	FILE *fp;	
	char s[64];
	fp = fopen( DataName , "a"); //�t�@�C���������ɍ쐬or�m��
	if (fp == NULL){
		DataName = "iMaGiNaRy.imr";
		fp = fopen( DataName , "a");
	}	
	fclose(fp);
	fp = fopen( DataName , "r+");/////////////�ǂݍ���
	int n = 0;
	while (fgets(s, 64, fp) != NULL && n < 2000) {
		LeftData[n] = ClngTo(s,':');
		RightData[n] = ClngFrom(s,':');
		n++;
	}
	fclose(fp);
	if(n == 0){NewMake ();ReadData() ;}
}

void CIntData::WriteData(){
	FILE *fp;	
	fp = fopen( DataName , "a"); //�t�@�C���������ɍ쐬or�m��
	if (fp == NULL){
		DataName = "iMaGiNaRy.imr";
		fp = fopen( DataName , "a");
	}	
	fclose(fp);
	fp = fopen( DataName , "r+");/////////////�ǂݍ���
 
	for(int i=0;i<2000;i++){/////////////��������	
	fprintf( fp, "%d:%d\r\n",LeftData[i],RightData[i] );
	}
	fclose(fp);

}

CStrData::CStrData(char *_DataName){
	int Len;
	Len = std::strlen (_DataName);
	DataName = new char [Len];
	std::strcpy(DataName , _DataName);
}

void CStrData::NewMake (){
	FILE *fp;
	fp = fopen( DataName , "w+");/////////////��������
	if (fp == NULL){
		DataName = "ImAgInArY.imr";
		fp = fopen( DataName , "w+");
	}
	for(int i = 0; i <1000 ;i++){
	fputs("NoName\r\n" , fp);//��������
	}
	fclose(fp);
}

void CStrData::ReadData(){
	FILE *fp;	
	fp = fopen( DataName , "a"); 
	if (fp == NULL){
		DataName = "ImAgInArY.imr";
		fp = fopen( DataName , "a");
	}
	fclose(fp);//�t�@�C���������ɍ쐬or�m��
	fp = fopen( DataName , "r+");/////////////�ǂݍ���
	int n = 0;
	while (fgets(Data[n], 128, fp) != NULL && n < 1000 ) {n++;}
	fclose(fp);
	if(n == 0){NewMake ();ReadData(); }
}

void CStrData::WriteData(){
	FILE *fp;	
	fp = fopen( DataName , "a");
	if (fp == NULL){
		DataName = "ImAgInArY.imr";
		fp = fopen( DataName , "a");
	}
	fclose(fp);//�t�@�C���������ɍ쐬or�m��
	fp = fopen( DataName , "r+");/////////////�ǂݍ���
	char s[128];
	for(int i=0;i<1000;i++){/////////////��������
		std::strcpy (s,Data[i]);
		std::strcat (s,"");
		fputs( s ,fp);
		
	}
	fclose(fp);
}



void KEYCHECK(char &CC ,int INPUT  ){
	switch(CC){
		case 0:
		CC =INPUT;
		break;
		case 1:
		CC++ ;
		break;
		default:
		if(!INPUT)CC =0;
		else if(CC<125)CC++;
		break;
	}
	return;
}

void CKeyPush::ALLKEYCHECK (){
	KEYCHECK(A, CheckHitKey(KEY_INPUT_A));
	KEYCHECK(B, CheckHitKey(KEY_INPUT_B));
	KEYCHECK(C, CheckHitKey(KEY_INPUT_C));
	KEYCHECK(D, CheckHitKey(KEY_INPUT_D));
	KEYCHECK(E, CheckHitKey(KEY_INPUT_E));
	KEYCHECK(F, CheckHitKey(KEY_INPUT_F));
	KEYCHECK(G, CheckHitKey(KEY_INPUT_G));
	KEYCHECK(H, CheckHitKey(KEY_INPUT_H));
	KEYCHECK(I, CheckHitKey(KEY_INPUT_I));
	KEYCHECK(J, CheckHitKey(KEY_INPUT_J));
	KEYCHECK(K, CheckHitKey(KEY_INPUT_K));
	KEYCHECK(L, CheckHitKey(KEY_INPUT_L));
	KEYCHECK(M, CheckHitKey(KEY_INPUT_M));
	KEYCHECK(N, CheckHitKey(KEY_INPUT_N));
	KEYCHECK(O, CheckHitKey(KEY_INPUT_O));
	KEYCHECK(P, CheckHitKey(KEY_INPUT_P));
	KEYCHECK(Q, CheckHitKey(KEY_INPUT_Q));
	KEYCHECK(R, CheckHitKey(KEY_INPUT_R));
	KEYCHECK(S, CheckHitKey(KEY_INPUT_S));
	KEYCHECK(T, CheckHitKey(KEY_INPUT_T));
	KEYCHECK(U, CheckHitKey(KEY_INPUT_U));
	KEYCHECK(V, CheckHitKey(KEY_INPUT_V));
	KEYCHECK(W, CheckHitKey(KEY_INPUT_W));
	KEYCHECK(X, CheckHitKey(KEY_INPUT_X));
	KEYCHECK(Y, CheckHitKey(KEY_INPUT_Y));
	KEYCHECK(Z, CheckHitKey(KEY_INPUT_Z));
	KEYCHECK(Key0, CheckHitKey(KEY_INPUT_0));
	KEYCHECK(Key1, CheckHitKey(KEY_INPUT_1));
	KEYCHECK(Key2, CheckHitKey(KEY_INPUT_2));
	KEYCHECK(Key3, CheckHitKey(KEY_INPUT_3));
	KEYCHECK(Key4, CheckHitKey(KEY_INPUT_4));
	KEYCHECK(Key5, CheckHitKey(KEY_INPUT_5));
	KEYCHECK(Key6, CheckHitKey(KEY_INPUT_6));
	KEYCHECK(Key7, CheckHitKey(KEY_INPUT_7));
	KEYCHECK(Key8, CheckHitKey(KEY_INPUT_8));
	KEYCHECK(Key9, CheckHitKey(KEY_INPUT_9));
	KEYCHECK(F1, CheckHitKey(KEY_INPUT_F1));
	KEYCHECK(F2, CheckHitKey(KEY_INPUT_F2));
	KEYCHECK(F3, CheckHitKey(KEY_INPUT_F3));
	KEYCHECK(F4, CheckHitKey(KEY_INPUT_F4));
	KEYCHECK(F5, CheckHitKey(KEY_INPUT_F5));
	KEYCHECK(F6, CheckHitKey(KEY_INPUT_F6));
	KEYCHECK(F7, CheckHitKey(KEY_INPUT_F7));
	KEYCHECK(F8, CheckHitKey(KEY_INPUT_F8));
	KEYCHECK(F9, CheckHitKey(KEY_INPUT_F9));
	KEYCHECK(F10, CheckHitKey(KEY_INPUT_F10));
	KEYCHECK(F11, CheckHitKey(KEY_INPUT_F11));
	KEYCHECK(F12, CheckHitKey(KEY_INPUT_F12));
	KEYCHECK( BACK, CheckHitKey(KEY_INPUT_BACK));//KEY_INPUT_BACK  // �o�b�N�X�y�[�X�L�[ 
	KEYCHECK( TAB, CheckHitKey(KEY_INPUT_TAB));//KEY_INPUT_TAB  // �^�u�L�[ 
	KEYCHECK( RETURN, CheckHitKey(KEY_INPUT_RETURN));//KEY_INPUT_RETURN  // �G���^�[�L�[
	KEYCHECK( LSHIFT, CheckHitKey(KEY_INPUT_LSHIFT));//KEY_INPUT_LSHIFT  // ���V�t�g�L�[ 
	KEYCHECK( RSHIFT, CheckHitKey(KEY_INPUT_RSHIFT));//KEY_INPUT_RSHIFT  // �E�V�t�g�L�[ 
	KEYCHECK( LCONTROL, CheckHitKey(KEY_INPUT_LCONTROL));//KEY_INPUT_LCONTROL  // ���R���g���[���L�[ 
	KEYCHECK( RCONTROL, CheckHitKey(KEY_INPUT_RCONTROL));//KEY_INPUT_RCONTROL  // �E�R���g���[���L�[ 
	KEYCHECK( ESCAPE, CheckHitKey(KEY_INPUT_ESCAPE));//KEY_INPUT_ESCAPE  // �G�X�P�[�v�L�[ 
	KEYCHECK( SPACE, CheckHitKey(KEY_INPUT_SPACE));//KEY_INPUT_SPACE  // �X�y�[�X�L�[ 
	KEYCHECK( LEFT, CheckHitKey(KEY_INPUT_LEFT));//KEY_INPUT_LEFT  // ���L�[ 
	KEYCHECK( UP, CheckHitKey(KEY_INPUT_UP));//KEY_INPUT_UP  // ��L�[ 
	KEYCHECK( RIGHT, CheckHitKey(KEY_INPUT_RIGHT));//KEY_INPUT_RIGHT  // �E�L�[ 
	KEYCHECK( DOWN, CheckHitKey(KEY_INPUT_DOWN));//KEY_INPUT_DOWN  // ���L�[ 
	KEYCHECK( INSERT, CheckHitKey(KEY_INPUT_INSERT));//KEY_INPUT_INSERT  // �C���T�[�g�L�[ 
	KEYCHECK( Delete, CheckHitKey(KEY_INPUT_DELETE));//KEY_INPUT_DELETE  // �f���[�g�L�[
	KEYCHECK( LALT, CheckHitKey(KEY_INPUT_LALT));//KEY_INPUT_LALT  // ���`�k�s�L�[ 
	KEYCHECK( RALT, CheckHitKey(KEY_INPUT_RALT));//KEY_INPUT_RALT  // �E�`�k�s�L�[ 
	KEYCHECK( SCROLL, CheckHitKey(KEY_INPUT_SCROLL));//KEY_INPUT_SCROLL  // ScrollLock�L�[
	KEYCHECK( CAPSLOCK, CheckHitKey(KEY_INPUT_CAPSLOCK));//KEY_INPUT_CAPSLOCK  // CaspLock�L�[ 
	KEYCHECK( PAUSE, CheckHitKey(KEY_INPUT_PAUSE));//KEY_INPUT_PAUSE  // PauseBreak�L�[
	KEYCHECK( MINUS , CheckHitKey(KEY_INPUT_MINUS)); // �|�L�[ 
	KEYCHECK( YEN , CheckHitKey(KEY_INPUT_YEN));  // ���L�[ 
	KEYCHECK( PREVTRACK , CheckHitKey(KEY_INPUT_PREVTRACK)); // �O�L�[ 
	KEYCHECK( PERIOD , CheckHitKey(KEY_INPUT_PERIOD)); // �D�L�[ 
	KEYCHECK( SLASH , CheckHitKey(KEY_INPUT_SLASH)); // �^�L�[ 
	KEYCHECK( SEMICOLON , CheckHitKey(KEY_INPUT_SEMICOLON)); // �G�L�[ 
	KEYCHECK( COLON , CheckHitKey(KEY_INPUT_COLON)); // �F�L�[ 
	KEYCHECK( LBRACKET , CheckHitKey(KEY_INPUT_LBRACKET)); // �m�L�[ 
	KEYCHECK( RBRACKET , CheckHitKey(KEY_INPUT_RBRACKET)); // �n�L�[ 
	KEYCHECK( AT , CheckHitKey(KEY_INPUT_AT)); // ���L�[ 
	KEYCHECK( BACKSLASH , CheckHitKey(KEY_INPUT_BACKSLASH)); // �_�L�[ 
	KEYCHECK( COMMA , CheckHitKey(KEY_INPUT_COMMA)); // �C�L�[ 
}


void GetHttpFile(char *&Buf, char *Http,DWORD ReadSize){
	HINTERNET hInternet;HINTERNET hFile;
	BOOL bResult;
	DWORD RealRead = ReadSize;
	// WININET������ 
	hInternet = InternetOpen("WININET Sample Program",INTERNET_OPEN_TYPE_PRECONFIG,	NULL,NULL,0);
	if(!hInternet)return;
	// URL�̃I�[�v�� 
	hFile = InternetOpenUrl(hInternet,Http,	NULL,0,	INTERNET_FLAG_RELOAD,0);
	if(!hFile){if(hInternet)InternetCloseHandle(hInternet);return;}
	bResult = InternetReadFile(hFile,Buf,RealRead,&ReadSize);
	if(!bResult) {return;if(hFile)InternetCloseHandle(hFile);if(hInternet)InternetCloseHandle(hInternet);}
	Buf[ReadSize] = '\0';
	if(hFile)InternetCloseHandle(hFile);
	if(hInternet)InternetCloseHandle(hInternet);
}



CBox::CBox(){
	Color = GetColor( 128 , 128 , 128 );
}

void CBox::Draw(){
	DrawBox( Left , Top , Left + Width , Top + Height , Color , TRUE );
}

CommandButton::CommandButton(){
	Left = 32;
	Top = 32;
	Width = 32;
	Height = 32;
	FontSize = 24;
	ForeColor = GetColor( 0 , 0 , 0 );
	BGColor = GetColor( 128 , 128 , 128 );
}

CommandButton::CommandButton( int _left , int _right , int _width , int _height ){
	Left = _left;
	Top = _right;
	Width = _width;
	Height = _height;
	FontSize = 24;
	ForeColor = GetColor( 0 , 0 , 0 );
	BGColor = GetColor( 128 , 128 , 128 );
}

void CommandButton::Draw(){
	int StringWidth;

	SetFontSize( FontSize );
	StringWidth = GetDrawFormatStringWidth( "%s" , Caption );
	DrawBox( Left , Top , Left + Width , Top + Height , BGColor , TRUE );
	DrawFormatString( Left + ((Width - StringWidth)/2) , Top + ((Height - FontSize)/2) , ForeColor , "%s" , Caption );
}

void CommandButton::Judge(){
if( !(GetMouseInput() & MOUSE_INPUT_LEFT) ){
	return;
}

	int x;
	int y;
	
	GetMousePoint( &x , &y );

	if ( x > Left && y > Top && x < Left+Width && y < Top + Height ){
		if( Func != NULL ){
			Func();
		} else {
			Click();
		}
	}
}

void CommandButton::Update(){
	Draw();
	Judge();
}

void CommandButton::Click(){}



CVector GetIntersection( int a1 , int b1 , int a2 , int b2 ){
	CVector Point;

	if( a1 != a2 ){
		Point.x = (float)( ( b2 - b1 ) / ( a1 - a2 ) );
	} else {
		Point.x = NULL;
		Point.y = NULL;
		return Point;
	}

	Point.y = (a1 * Point.x) + b1;

	return Point;
}




/// FROM NUNULIB
//���ݎ����擾�֐�///////////////////////////////////////////
SYSTEMTIME GetNowSystemTime(){
    SYSTEMTIME st;
    GetSystemTime(&st);
     
    FILETIME ft1;
    FILETIME ft2;
    SystemTimeToFileTime(&st, &ft1);
     
    //a ������ł�OK�B����͊m�F�ς݁B
    //long long int t = (long long int)(ft1.dwHighDateTime)<<32 | ft1.dwLowDateTime;
    //t += (long long int)9*60*60*1000*1000*10; //1���E�E�E24*60*60*1000*1000*10 
    //ft2.dwHighDateTime = t>>32; // & 0xFFFFFFFF;
    //ft2.dwLowDateTime = (int)t;   
     
    //b
    FileTimeToLocalFileTime(&ft1, &ft2);
 
    FileTimeToSystemTime(&ft2, &st);
    return st;
}
std::string GetNowSystemTimeString(){
    char currentTime[25] = { 0 };
    SYSTEMTIME st = GetNowSystemTime();
    wsprintf(currentTime, "%04d/%02d/%02d %02d:%02d:%02d %03d",
        st.wYear, st.wMonth, st.wDay,
        st.wHour, st.wMinute, st.wSecond, st.wMilliseconds); 
    std::string tmp = currentTime;
    return tmp;
}
//DrawCenterString Not�t�H�[�}�b�g��
int DrawCenterString(int cx, int y, int color, const TCHAR* format, ...){
    va_list args;
    char string[1024];
    int for_return;
 
    va_start( args, format );
    vsprintf_s( string, format, args );
    va_end( args );
 
    if(strlen(string)<1024){
        for_return = DrawCenterString((int)cx,(int)y,string,color); 
    }else{
        for_return=-1;
    }
 
    return for_return;  
}
int DrawCenterString(int cx, int y, int color, bool centerY, const TCHAR* format, ...){ //�t�H�[�}�b�g��
    va_list args;
    char string[1024];
    int for_return;
 
    va_start( args, format );
    vsprintf_s( string, format, args );
    va_end( args );
 
    if(strlen(string)<1024){
        for_return = DrawCenterString((int)cx,(int)y,string,color,centerY); 
    }else{
        for_return=-1;
    }
 
    return for_return;  
}
//�t�H���g�ǉ��i�p�X���͕K�{�j
void AddFontFromPath(char *path){

	LPCSTR font_path = path; // �ǂݍ��ރt�H���g�t�@�C���̃p�X
		if (AddFontResourceEx(font_path, FR_PRIVATE, NULL) > 0) {
		
		} else {
			// �t�H���g�Ǎ��G���[����
			MessageBox(NULL,"�t�H���g�Ǎ����s","",MB_OK);
		}
}
//�K��
unsigned int fanctorial(unsigned int num){
	if(num <= 1){
		return 1;
	}else{
		return ( num * fanctorial( num - 1 ) );
	}
}
//�g�ݍ��킹�in��r�͂��ꂼ��unCr�v��n��r�j
unsigned int combination(unsigned int n , unsigned int r){
	return ( fanctorial( n ) / ( fanctorial( n-r ) * fanctorial( r ) ) );
}

//�x�W�F�Ȑ�

//�x�W�F�Ȑ����_�f�[�^�̍쐬
////�x�W�F�Ȑ��̌v�Z���}�C�t���[������͖̂��ʂȂ̂Ōv�Z�ς݂̃f�[�^���쐬����
//����
// In�@�@�@�@: ����_�iCVector�^�j���w�肷��i2�ȏ�j
// vertexNum : �쐬����f�[�^�ׂ̍������w��i�x�W�F�Ȑ��̍\�����_�̐��j
BEZIER GetBezier(vector<CVector> &In , unsigned int vertexNum ){
	
	const int N = In.size();
	BEZIER vertexes;
	vertexes.push_back(In[0]);
	float t = 0.0f;

	for(unsigned int j = 0; j < vertexNum; j++){

		 t += ( 1.0f / (float)vertexNum ) ;

		CVector vertex ;
		
		for( int i = 0; i < N; i++ ){
			
			float temp = (float)( combination( N-1 , i ) * pow( 1-t , N-i-1  ) * pow( t , i ) );

			vertex += In[i] * temp;

		}

		vertexes.push_back(vertex);
	}
	
	return vertexes;
}
//�x�W�F�Ȑ��̕`��i GetBezier�֐��ō쐬�����f�[�^���K�v�@�j
////GetBezier�֐��ō쐬�����f�[�^��p���ăx�W�F�Ȑ���`�悷��
//����
// data  : GetBezier�֐��ō쐬�����x�W�F�Ȑ��f�[�^
// color : �`��F���w��
void DrawBezier( BEZIER &data ,  int color ){
	for(unsigned int i = 0; i < data.size() - 1; i++){
		DrawLine( (int)data[ i ].x ,(int)data[ i ].y , (int)data[ i+1 ].x , (int)data[ i+1 ].y , color );
	}
}

//
unsigned int CScene::sceneNum;


void CKey::Loop(){
	 //�S�ẴL�[�̉�����Ԃ��擾
	char buf[256];
	GetHitKeyStateAll( buf ) ;
	for(int i=0;i<256;i++){
		if( buf[i] == 0 ){
			count[i] += 1.0f;
		}else if( buf[i] == 1 ){
			if(count[i] < 1.0f){
				count[i] = 0.5f;
			}else{
				count[i] = 0.0f;
			}
		}
	}
}
bool CKey::GetPush(int keyCode){
	 //�L�[�R�[�h�`�F�b�N
		if( keyCode < 256 && keyCode >= 0 ){
		if( count[keyCode] < 1.0f ){
			if(Event.GetValid()){
				return true;
			}else{
				return false;
			}
		}else{
			return false;
		}
	 }else{
		WarningSK("CKey::GetPush�̈����ɕs���ȃL�[�R�[�h�����͂���܂���\n�L�[�R�[�h�@�F�@%d",keyCode);
		return false;
	 }
 }
 bool CKey::GetDown(int keyCode){
	 //�L�[�R�[�h�`�F�b�N
	 if( keyCode < 256 && keyCode >= 0 ){
		if( count[keyCode] == 0.0f ){
			if(Event.GetValid()){
				return true;
			}else{
				return false;
			}
		}else{
			return false;
		}
	 }else{
		WarningSK("CKey::GetDown�̈����ɕs���ȃL�[�R�[�h�����͂���܂���\n�L�[�R�[�h�@�F�@%d",keyCode);
		return false;
	 }
}
 bool CKey::GetUp(int keyCode){
	//�L�[�R�[�h�`�F�b�N
	if( keyCode < 256 && keyCode >= 0 ){
		if( count[keyCode] == 1.5f ){
			if(Event.GetValid()){
				return true;
			}else{
				return false;
			}
		}else{
			return false;			
		}
	}else{
		WarningSK("CKey::GetUp�̈����ɕs���ȃL�[�R�[�h�����͂���܂���\n�L�[�R�[�h�@�F�@%d",keyCode);
		return false;
	}
}
int CKey::GetCount(int keyCode){
	//�L�[�R�[�h�`�F�b�N
		if( keyCode < 256 && keyCode >= 0 ){
		return (int)(count[keyCode]);
	}else{
		WarningSK("CKey::GetCount�̈����ɕs���ȃL�[�R�[�h�����͂���܂���\n�L�[�R�[�h�@�F�@%d",keyCode);
		return -1;
	}
}

CMouseIn CMouse::Off( int _x1 , int _y1 , int _x2 , int _y2 ){

	CMouseIn temp;

	temp.x1 = _x1;
	temp.x2 = _x2;
	temp.y1 = _y1;
	temp.y2 = _y2;

	temp.type = MOUSE_OFF;

	return temp;
}
bool CMouse::GetOff( int _x1 , int _y1 , int _x2 , int _y2 ){
	if(_x1>mouseX && _x2<mouseX ){
		if(_y1>mouseY && _y2<mouseY){
			return true;
		}
	}
	return false;
}
CpMouseIn CMouse::Off( int *_x1 , int *_y1 , int *_x2 , int *_y2 ){

	CpMouseIn temp;

	temp.x1 = _x1;
	temp.x2 = _x2;
	temp.y1 = _y1;
	temp.y2 = _y2;

	temp.type = MOUSE_OFF;

	return temp;
}
bool CMouse::GetOff( int *_x1 , int *_y1 , int *_x2 , int *_y2 ){
	if(*_x1>mouseX && *_x2<mouseX ){
		if(*_y1>mouseY && *_y2<mouseY){
			return true;
		}
	}
	return false;
}
CMouseIn CMouse::On( int _x1 , int _y1 , int _x2 , int _y2 ){
	
	CMouseIn temp;

	temp.x1 = _x1;
	temp.x2 = _x2;
	temp.y1 = _y1;
	temp.y2 = _y2;

	temp.type = MOUSE_ON;

	return temp;

}
bool CMouse::GetOn( int _x1 , int _y1 , int _x2 , int _y2 ){
	if(_x1<mouseX && _x2>mouseX ){
		if(_y1<mouseY && _y2>mouseY){
			if(Event.GetValid()){
				return true;
			}
		}
	}
	return false;
}
CpMouseIn CMouse::On( int *_x1 , int *_y1 , int *_x2 , int *_y2 ){
	
	CpMouseIn temp;

	temp.x1 = _x1;
	temp.x2 = _x2;
	temp.y1 = _y1;
	temp.y2 = _y2;

	temp.type = MOUSE_ON;

	return temp;

}
bool CMouse::GetOn( int *_x1 , int *_y1 , int *_x2 , int *_y2 ){
	if(*_x1<mouseX && *_x2>mouseX ){
		if(*_y1<mouseY && *_y2>mouseY){
			if(Event.GetValid()){
				return true;
			}
		}
	}
	return false;
}
CMouseIn CMouse::Click( int _x1 , int _y1 , int _x2 , int _y2 ){
		
	CMouseIn temp;

	temp.x1 = _x1;
	temp.x2 = _x2;
	temp.y1 = _y1;
	temp.y2 = _y2;

	temp.type = MOUSE_CLICK;

	return temp;

}
bool CMouse::GetClick( int _x1 , int _y1 , int _x2 , int _y2 ){
	if(_x1<mouseX && _x2>mouseX ){
		if(_y1<mouseY && _y2>mouseY){
			if(mouseInput && !preMouseInput ){
				if(Event.GetValid()){
					return true;		
				}
			} 
		}
	}
	return false;
}
CpMouseIn CMouse::Click( int *_x1 , int *_y1 , int *_x2 , int *_y2 ){
		
	CpMouseIn temp;

	temp.x1 = _x1;
	temp.x2 = _x2;
	temp.y1 = _y1;
	temp.y2 = _y2;

	temp.type = MOUSE_CLICK;

	return temp;

}
bool CMouse::GetClick( int *_x1 , int *_y1 , int *_x2 , int *_y2 ){
	if(*_x1<mouseX && *_x2>mouseX ){
		if(*_y1<mouseY && *_y2>mouseY){
			if(mouseInput && !preMouseInput ){
				if(Event.GetValid()){
					return true;	
				}
			} 
		}
	}
	return false;
}
CMouseIn CMouse::Release( int _x1 , int _y1 , int _x2 , int _y2 ){
		
	CMouseIn temp;

	temp.x1 = _x1;
	temp.x2 = _x2;
	temp.y1 = _y1;
	temp.y2 = _y2;

	temp.type = MOUSE_RELEASE;

	return temp;
}
bool CMouse::GetRelease( int _x1 , int _y1 , int _x2 , int _y2 ){
	if(_x1<mouseX && _x2>mouseX ){
		if(_y1<mouseY && _y2>mouseY){
			if( !mouseInput && preMouseInput ){
				if(Event.GetValid()){
					return true;
				}
			} 
		}	
	}
	return false;
}
CpMouseIn CMouse::Release( int *_x1 , int *_y1 , int *_x2 , int *_y2 ){
		
	CpMouseIn temp;

	temp.x1 = _x1;
	temp.x2 = _x2;
	temp.y1 = _y1;
	temp.y2 = _y2;

	temp.type = MOUSE_RELEASE;

	return temp;
}
bool CMouse::GetRelease( int *_x1 , int *_y1 , int *_x2 , int *_y2 ){
	if(*_x1<mouseX && *_x2>mouseX ){
		if(*_y1<mouseY && *_y2>mouseY){
			if( !mouseInput && preMouseInput ){
				if(Event.GetValid()){
					return true;
				}
			} 
		}	
	}
	return false;
}
void CMouse::Loop(){
	GetMousePoint( &mouseX, &mouseY );
	preMouseInput = mouseInput;
	if(IsLeft){
		mouseInput = (bool)( GetMouseInput() & MOUSE_INPUT_LEFT );
	}else{
		mouseInput = (bool)( GetMouseInput() & MOUSE_INPUT_RIGHT );
	}
}
void CMouse::SetLeft(){
	IsLeft = true;
}
void CMouse::SetRight(){
	IsLeft = false;
}