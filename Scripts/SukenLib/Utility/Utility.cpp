#include"Utility.h"



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

/*

void GetHttpFile(char *&Buf, char *Http,DWORD ReadSize){
	HINTERNET hInternet;HINTERNET hFile;
	BOOL bResult;
	DWORD RealRead = ReadSize;
	// WININET������ 
	hInternet = InternetOpenA("WININET Sample Program",INTERNET_OPEN_TYPE_PRECONFIG,	NULL,NULL,0);
	if(!hInternet)return;
	// URL�̃I�[�v�� 
	hFile = InternetOpenUrlA(hInternet,Http,	NULL,0,	INTERNET_FLAG_RELOAD,0);
	if(!hFile){if(hInternet)InternetCloseHandle(hInternet);return;}
	bResult = InternetReadFile(hFile,Buf,RealRead,&ReadSize);
	if(!bResult) {return;if(hFile)InternetCloseHandle(hFile);if(hInternet)InternetCloseHandle(hInternet);}
	Buf[ReadSize] = '\0';
	if(hFile)InternetCloseHandle(hFile);
	if(hInternet)InternetCloseHandle(hInternet);
}

�����s���G���[�̂��߃R�����g�A�E�g
1>Utility.obj : error LNK2019: �������̊O���V���{�� __imp__InternetReadFile@16 ���֐� "void __cdecl GetHttpFile(char * &,char *,unsigned long)" (?GetHttpFile@@YAXAAPADPADK@Z) �ŎQ�Ƃ���܂����B
1>Utility.obj : error LNK2019: �������̊O���V���{�� __imp__InternetCloseHandle@4 ���֐� "void __cdecl GetHttpFile(char * &,char *,unsigned long)" (?GetHttpFile@@YAXAAPADPADK@Z) �ŎQ�Ƃ���܂����B
1>Utility.obj : error LNK2019: �������̊O���V���{�� __imp__InternetOpenUrlA@24 ���֐� "void __cdecl GetHttpFile(char * &,char *,unsigned long)" (?GetHttpFile@@YAXAAPADPADK@Z) �ŎQ�Ƃ���܂����B
1>Utility.obj : error LNK2019: �������̊O���V���{�� __imp__InternetOpenA@20 ���֐� "void __cdecl GetHttpFile(char * &,char *,unsigned long)" (?GetHttpFile@@YAXAAPADPADK@Z) �ŎQ�Ƃ���܂����B

*/



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

