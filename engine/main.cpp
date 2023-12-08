#include "process/memory.h"
#include <cstdio>
#include <jni/jni.h>
#include <vector>
#include "Entity.h"


// LANG_PACKAGE_CLASSNAME_FUNCTION(args,...)

// Ljava/lang/String - String.class
// V - void
// F - 32/64 bit float
// I - 32/64 bit int
// Z - boolean
// D - double
// C - unicode char
// S - short(int)
// J - long
// B - byte
// [ - one-dimensional array
// [] - array

//(IZLjava/lang/String;[BC)V
// void randomFunction(int,boolean,string,byte[])

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

JNIEXPORT jlong JNICALL Java_test_CMemory_getModuleBase(JNIEnv *p_env, jobject jobj, jstring process_name) {
  const char *native_str = p_env->GetStringUTFChars(process_name, nullptr);

  jlong res = static_cast<jlong>(g_Memory.get_module_base(native_str));

  p_env->ReleaseStringUTFChars(process_name, native_str);
  g_Memory.~Memory();

  return res;
}

JNIEXPORT jobjectArray JNICALL Java_test_CMemory_getEntities(JNIEnv *p_env, jobject jobj) {



  std::vector<Entity_t> entites = { {"Unknown",123.0f,20} ,{"Unknown", 100.0f, 100}, {"Unknown", 30.0f, 40}, {"Unknown", 50.0f, 80}};
  
  jclass entity_class = p_env->FindClass("test/CEntity");

  jmethodID ctor = p_env->GetMethodID(entity_class, "<init>", "(Ljava/lang/String;FI)V");

  if (entity_class == nullptr)
    return nullptr;

    jobjectArray entities = p_env->NewObjectArray(entites.size(), entity_class, nullptr);

     for (int i = 0; i < entites.size(); i++) {
        jstring name = p_env->NewStringUTF(entites[i].name.c_str());

        jobject playerObj = p_env->NewObject(entity_class, ctor, name, entites[i].distance, entites[i].health);

        p_env->SetObjectArrayElement(entities, i, playerObj);

        p_env->DeleteLocalRef(name);
        p_env->DeleteLocalRef(playerObj);

    
     
    }

    return entities;
}

}


