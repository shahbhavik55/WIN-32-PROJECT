#include<windows.h>
#include<stdio.h>

TCHAR buff[256];
char filename[256],str[256];
DWORD noofbytegetread;
	
extern "C" __declspec(dllexport) void CountNosOfWords(TCHAR *wfilename,HWND hWnd)
{
	wcstombs(filename,wfilename, wcslen(wfilename) + 1);//wcslen(wfilename) + 1
	
	OFSTRUCT lpofstructwgetevent;
	
	HFILE hfile=OpenFile(filename,&lpofstructwgetevent,OF_READ);
	
	if(hfile == -1)
	{
					wsprintf(buff,TEXT("File %s is not present."),wfilename);
					MessageBox(hWnd,buff,L"ERROR",MB_OK);
	}
	else
	{
		HANDLE handel = CreateFile(wfilename, FILE_READ_DATA, FILE_SHARE_READ,NULL, OPEN_ALWAYS, 0, NULL);
	
		int wcnt=0;
		
		do
		{
			ReadFile(handel,str,256,&noofbytegetread,NULL);
		
			for(int i=0;i<noofbytegetread;i++)
				if(str[i]==' ')
					wcnt++;
		}while(noofbytegetread!=0);
		
		wsprintf(buff,TEXT("%s file have %d words."),wfilename,wcnt);
		MessageBox(hWnd,buff,TEXT("Info"),MB_OK );
	}
}

extern "C" __declspec(dllexport) void CountNosOfChar(TCHAR *wfilename,HWND hWnd)
{
	wcstombs(filename,wfilename, wcslen(wfilename) + 1);
		
	OFSTRUCT lpofstructwgetevent;
				
	HFILE hfile=OpenFile(filename,&lpofstructwgetevent,OF_READ);
		
	if(hfile == -1)
	{
		wsprintf(buff,TEXT("File %s is not present."),wfilename);
		MessageBox(hWnd,buff,L"ERROR",MB_OK);
	}
	else
	{
		HANDLE handel =CreateFile(wfilename, FILE_READ_DATA, FILE_SHARE_READ,NULL, OPEN_ALWAYS, 0, NULL);
				
		int ccnt=0;
					
		do
		{
			ReadFile(handel,str,256,&noofbytegetread,NULL);
			ccnt+=noofbytegetread;
		}while(noofbytegetread!=0);
						
		wsprintf(buff,TEXT("%s file have %d char."),wfilename,ccnt);
		MessageBox(hWnd,buff,TEXT("Info"),MB_OK);
	}
}