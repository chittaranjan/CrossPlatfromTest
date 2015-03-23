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

	if (args.Length() != 2)
    {
        return NanThrowError("Invalid number of arguments");  
    }

   if (!args[1]->IsFunction())
    {
        return NanThrowTypeError("Last argument must be a function.");
    }
	int64_t timer = args[0]->IntegerValue();
 	#ifdef _WIN32
    Sleep(timer);
    #else
    usleep(timer * 1000);
    #endif

    NanMakeCallback(NanGetCurrentContext()->Global(), args[1].As<Function>(), 0, NULL);

    NanReturnUndefined();

}

void Init(Handle<Object> exports) {
    exports->Set(NanNew("delay"), NanNew<FunctionTemplate>(Print)->GetFunction());
}

NODE_MODULE(myaddon, Init);
