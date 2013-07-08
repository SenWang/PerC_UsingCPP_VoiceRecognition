#include<iostream>
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
		}
};

int main(int argc, char* argv[]) 
{	
	MyPipeline pp;
	pp.LoopFrames();
	return 0;
}

