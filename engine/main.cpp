#include <cstdio>
#include <jni/jni.h>

// LANG_PACKAGE_CLASSNAME_FUNCTION(args)

extern "C" {
__declspec(dllexport) void __stdcall Java_test_CTest_hello() { printf("Hello world from c++"); }
__declspec(dllexport) int Java_test_CTest_sumNumber(int a, int b) { return a + b; }

JNIEXPORT jint JNICALL Java_test_CTest_jniSum(JNIEnv *env, jobject obj, jint a, jint b) { return a + b; }

JNIEXPORT jlong JNICALL Java_test_CMemory_getProcessId(JNIEnv *p_env,jobject jobj ,jstring process_name) {
    const char* native_str = p_env->GetStringUTFChars(process_name,nullptr);

  printf("Process name %s \n", native_str);

  p_env->ReleaseStringUTFChars(process_name,native_str);
  return 12345678910;
}

}