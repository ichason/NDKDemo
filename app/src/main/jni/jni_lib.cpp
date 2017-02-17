//
// Created by Administrator on 2017/2/17 0017.
//

#include "jni_lib.h"

//                                 尤其注意： 找到与之相关联的java代码。
#define JNI_AN_MainActivity        "com/cn/chason/ndkdemo/MainActivity"

#define METHOD_NUM 1
JNINativeMethod g_nativeMethod[METHOD_NUM]={
        {"getStramInfo","()Ljava/lang/String;",(void*)getStramInfo}
};

/*
 * 被虚拟机自动调用, JNI_OnLoad  被虚拟机自动调用
 */
jint JNI_OnLoad(JavaVM* vm, void* reserved) {
    JNIEnv *env;
    if (vm->GetEnv((void **) &env, JNI_VERSION_1_6) != JNI_OK)
        return JNI_ERR;

    jclass jClass = env->FindClass(JNI_AN_MainActivity);
    env->RegisterNatives(jClass,g_nativeMethod,METHOD_NUM);
    env->DeleteLocalRef(jClass);
    return JNI_VERSION_1_6;
}

void JNI_OnUnload(JavaVM* vm, void* reserved) {
    JNIEnv *env;
    int nJNIVersionOK = vm->GetEnv((void **)&env, JNI_VERSION_1_6) ;
    jclass jClass = env->FindClass(JNI_AN_MainActivity);
    env->UnregisterNatives(jClass);
    env->DeleteLocalRef(jClass);
}

jstring getStramInfo(JNIEnv *env, jobject callObj)
{
    return env->NewStringUTF("String From Jni With c++");
}