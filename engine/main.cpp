#include <cstdio>
#include <jni/jni.h>

extern "C" {
__declspec(dllexport) void __stdcall Java_test_CTest_hello() { printf("Hello world from c++"); }
__declspec(dllexport) int Java_test_CTest_sumNumber(int a, int b) { return a + b; }


JNIEXPORT jint JNICALL Java_test_CTest_jniSum(JNIEnv *env, jobject obj, jint a, jint b) {
    return a + b;
}
}