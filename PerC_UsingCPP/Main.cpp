#include<iostream>
#include<Windows.h>
#include "util_pipeline.h"
using namespace std ;

static vector<wstring> cmds ; 
class MyPipeline: public UtilPipeline 
{
	public:
 
		MyPipeline(PXCSession *session=0):UtilPipeline(session) 
		{
			EnableVoiceRecognition();
			cmds.push_back(L"move") ;
			cmds.push_back(L"previous") ;
			SetVoiceCommands(cmds);
		}
		virtual void PXCAPI OnRecognized(PXCVoiceRecognition::Recognition *data) 
		{
			wprintf_s(L"You say : <%s>\n",data->dictation);
			if( data->dictation[0] == 'm')
				Move(50) ;
			else if ( data->dictation[0] == 'p')
				Move(-50) ;
		}
		void Move(int stepX)
		{
			cout << "移動滑鼠 : " << stepX << endl ;
			POINT p;
			if (GetCursorPos(&p))
				cout << "X:" << p.x << "  ,Y:" << p.y << endl ;
			
			SetCursorPos(p.x+stepX,p.y) ;
		}
};

int main(int argc, char* argv[]) 
{	
	MyPipeline pp;
	pp.LoopFrames();
	return 0;
}

