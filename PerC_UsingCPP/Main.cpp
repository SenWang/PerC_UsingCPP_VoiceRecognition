#include<iostream>
#include "util_pipeline.h"
using namespace std ;

class MyPipeline: public UtilPipeline 
{
	public:
 
		MyPipeline(PXCSession *session=0):UtilPipeline(session) 
		{
			EnableVoiceRecognition();
		}
		virtual void PXCAPI OnRecognized(PXCVoiceRecognition::Recognition *data) 
		{
			//cout << "偵測到的語音 : " << data->dictation ;
			wprintf_s(L"You say : <%s>\n",data->dictation);
		}
};

int main(int argc, char* argv[]) 
{	
	MyPipeline pp;
	pp.LoopFrames();
	return 0;
}