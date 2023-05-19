#include <jni.h>
#include <string>
#include "PhoneBook.h"

extern "C" JNIEXPORT jstring JNICALL

//PhoneBook book;

Java_com_example_phonebookdominigames_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {

    PhoneBook book;

//    std::string hello = "Hello, DominiGames, from C++";
//    return env->NewStringUTF(hello.c_str());
    std::string s = book.GetFirstItem();
    return env->NewStringUTF(s.c_str());
}
