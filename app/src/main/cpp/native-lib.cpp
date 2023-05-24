#include <jni.h>
#include <string>
#include <sstream>
#include "PhoneBook.h"
#include "nlohmann/json.hpp"
#include <jni.h>

using Json = nlohmann::json;

extern "C" JNIEXPORT jstring
Java_com_example_phonebookdominigames_MainActivity_GetPhoneBookDataFromJNI(
        JNIEnv* env,
        jobject /* this */) {

    Json json = PhoneBook::GetInstance()->GetAllData();
    return env->NewStringUTF(json.dump().c_str());
}

extern "C" JNIEXPORT jstring
Java_com_example_phonebookdominigames_MainActivity_GetContactsByNameFromJNI(
        JNIEnv* env,
        jobject,
        jstring name) {

    std::string cppName(env->GetStringUTFChars(name, nullptr));
    Json json = PhoneBook::GetInstance()->GetPersonsByName(cppName);
    return env->NewStringUTF(json.dump().c_str());
}
