#include <jni.h>
#include <string>

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_phonebookdominigames_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello, DominiGames, from C++";
    return env->NewStringUTF(hello.c_str());
}