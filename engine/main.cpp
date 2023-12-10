#include "process/memory.h"
#include <cstdio>
#include <jni/jni.h>
#include <vector>
#include "Entity.h"
#include "overlay/render.h"



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

// ENGINE_API long get_process_id(const char *process_name) {

//   long process_id = g_Memory.get_process_by_name(process_name);
//   g_Memory.~Memory();

//   return process_id;
// }

JNIEXPORT void JNICALL Java_com_vsantos1_web_engine_CEngine_start(JNIEnv *p_env, jobject jobj) {

 while (entry_hwnd == NULL) {
		LOG("Start the game");
		pid = process.get_procid();
		entry_hwnd = get_process_wnd(pid);
	}


	client = process.get_modulebase("client.dll");


	setup_window();
	init_wndparams(own_hwnd);
	main_loop();
}

JNIEXPORT void JNICALL Java_test_CMemory_cleanup(JNIEnv *p_env, jobject jobj) {
  process.~Memory();
}

JNIEXPORT jlong JNICALL Java_test_CMemory_getProcessId(JNIEnv *p_env, jobject jobj) {

  long process_id = process.get_procid();

  process.~Memory();

  return process_id;
}

JNIEXPORT jlong JNICALL Java_test_CMemory_getModuleBase(JNIEnv *p_env, jobject jobj, jstring process_name) {
  const char *native_str = p_env->GetStringUTFChars(process_name, nullptr);

  jlong res = static_cast<jlong>(process.get_modulebase(native_str));

  p_env->ReleaseStringUTFChars(process_name, native_str);
  process.~Memory();

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


