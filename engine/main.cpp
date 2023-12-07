#include "process/memory.h"
#include <cstdio>
#include <jni/jni.h>

// LANG_PACKAGE_CLASSNAME_FUNCTION(args)

extern "C" {

ENGINE_API long get_process_id(const char *process_name) {
  
  long process_id = g_Memory.get_process_by_name(process_name);
  g_Memory.~Memory();

  return process_id;
}

JNIEXPORT jlong JNICALL Java_test_CMemory_getProcessId(JNIEnv *p_env, jobject jobj, jstring process_name) {

  const char *native_str = p_env->GetStringUTFChars(process_name, nullptr);

  long process_id = g_Memory.get_process_by_name(native_str);

  p_env->ReleaseStringUTFChars(process_name, native_str);
  g_Memory.~Memory();

  return process_id;
}
}