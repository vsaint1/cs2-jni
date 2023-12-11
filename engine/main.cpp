#include "memory/memory.h"
#include <cstdio>
#include <jni/jni.h>
#include <vector>
#include "overlay/render.h"
#include "features/cheat.h"

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
    processid = process.get_procid();
    entry_hwnd = get_process_wnd(processid);
  }

  client = process.get_modulebase("client.dll");

  setup_window();
  init_wndparams(own_hwnd);
  std::thread(cache_entities).detach();
  main_loop();
}

JNIEXPORT void JNICALL Java_com_vsantos1_web_engine_CAimbotConfig_configure(JNIEnv *p_env, jobject jobj) {
  LOG("Configure");
  jclass clazz = p_env->GetObjectClass(jobj);
  LOG("Class: %p", clazz);
  if (clazz == nullptr)
    return;

  settings::aimbot::aim_fov = p_env->GetFloatField(jobj, p_env->GetFieldID(clazz, "aimFov", "F"));
  LOG("Aim fov: %f", settings::aimbot::aim_fov);
  settings::aimbot::smooth = p_env->GetIntField(jobj, p_env->GetFieldID(clazz, "smooth", "I"));
  LOG("Smooth: %d", settings::aimbot::smooth);
  settings::aimbot::selectedhitbox = p_env->GetIntField(jobj, p_env->GetFieldID(clazz, "selectedHitbox", "I"));
  LOG("Selected hitbox: %d", settings::aimbot::selectedhitbox);
  settings::aimbot::aimbot = p_env->GetBooleanField(jobj, p_env->GetFieldID(clazz, "aimbot", "Z"));
  LOG("Aimbot: %d", settings::aimbot::aimbot);
  settings::aimbot::visible_check = p_env->GetBooleanField(jobj, p_env->GetFieldID(clazz, "visibleCheck", "Z"));
  LOG("Visible check: %d", settings::aimbot::visible_check);
  settings::aimbot::fov_circle = p_env->GetBooleanField(jobj, p_env->GetFieldID(clazz, "fovCircle", "Z"));
  LOG("Fov circle: %d", settings::aimbot::fov_circle);
  hotkeys::aimkey = p_env->GetIntField(jobj, p_env->GetFieldID(clazz, "selectedKey", "I"));
  LOG("Aim key: %d", hotkeys::aimkey);
}

JNIEXPORT void JNICALL Java_com_vsantos1_web_engine_CEspConfig_configure(JNIEnv *p_env, jobject jobj) {
  LOG("Configure");
  jclass clazz = p_env->GetObjectClass(jobj);
  LOG("Class: %p", clazz);
  if (clazz == nullptr)
    return;

  settings::visuals::esp = p_env->GetBooleanField(jobj, p_env->GetFieldID(clazz, "esp", "Z"));
  LOG("Esp: %d", settings::visuals::esp);
  settings::visuals::bSkeleton = p_env->GetBooleanField(jobj, p_env->GetFieldID(clazz, "skeleton", "Z"));
  LOG("Skeleton: %d", settings::visuals::bSkeleton);
  settings::visuals::bHealth = p_env->GetBooleanField(jobj, p_env->GetFieldID(clazz, "health", "Z"));
  LOG("Health: %d", settings::visuals::bHealth);
  settings::visuals::bName = p_env->GetBooleanField(jobj, p_env->GetFieldID(clazz, "name", "Z"));
  LOG("Name: %d", settings::visuals::bName);
  settings::visuals::bSnaplines = p_env->GetBooleanField(jobj, p_env->GetFieldID(clazz, "snapLines", "Z"));
  LOG("Snaplines: %d", settings::visuals::bSnaplines);
  settings::visuals::bDistance = p_env->GetBooleanField(jobj, p_env->GetFieldID(clazz, "distance", "Z"));
  LOG("Distance: %d", settings::visuals::bDistance);
  settings::visuals::bBox = p_env->GetBooleanField(jobj, p_env->GetFieldID(clazz, "box", "Z"));
  LOG("Box: %d", settings::visuals::bBox);
  settings::visuals::bWeapon = p_env->GetBooleanField(jobj, p_env->GetFieldID(clazz, "weapon", "Z"));
  LOG("Weapon: %d", settings::visuals::bWeapon);

}

JNIEXPORT void JNICALL Java_test_CMemory_cleanup(JNIEnv *p_env, jobject jobj) { process.~Memory(); }

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

// JNIEXPORT jobjectArray JNICALL Java_test_CMemory_getEntities(JNIEnv *p_env, jobject jobj) {

//   std::vector<Entity_t> entites = { {"Unknown",123.0f,20} ,{"Unknown", 100.0f, 100}, {"Unknown", 30.0f, 40}, {"Unknown", 50.0f, 80}};

//   jclass entity_class = p_env->FindClass("test/CEntity");

//   jmethodID ctor = p_env->GetMethodID(entity_class, "<init>", "(Ljava/lang/String;FI)V");

//   if (entity_class == nullptr)
//     return nullptr;

//     jobjectArray entities = p_env->NewObjectArray(entites.size(), entity_class, nullptr);

//      for (int i = 0; i < entites.size(); i++) {
//         jstring name = p_env->NewStringUTF(entites[i].name.c_str());

//         jobject playerObj = p_env->NewObject(entity_class, ctor, name, entites[i].distance, entites[i].health);

//         p_env->SetObjectArrayElement(entities, i, playerObj);

//         p_env->DeleteLocalRef(name);
//         p_env->DeleteLocalRef(playerObj);

//     }

//     return entities;
// }
}
