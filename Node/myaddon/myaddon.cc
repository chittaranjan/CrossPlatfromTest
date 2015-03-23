#include <nan.h>
#include <iostream>
#include <string.h>

#ifndef _WIN32
#include <unistd.h>
#endif

using namespace v8;
using namespace std;


NAN_METHOD(Print) {
	//cout<<"I am a native addon and I AM ALIVE!"<<endl;

	NanScope();

	if (args.Length() != 1)
    {
        return NanThrowError("Invalid number of arguments");  
    }

	Local<Number> timer = args[0].As<Number>();
 	#ifdef _WIN32
    Sleep(timer);
    #else
    usleep(timer * 1000);
    #endif

 	Local<String> str = args[0].As<String>();
 	int strlength = strlen(*String::Utf8Value(str));
	
	Local<Number> strLength = NanNew<Number>(strlength);

	NanReturnValue(strLength);
}

void Init(Handle<Object> exports) {
    exports->Set(NanNew("length"), NanNew<FunctionTemplate>(Print)->GetFunction());
}

NODE_MODULE(myaddon, Init);
