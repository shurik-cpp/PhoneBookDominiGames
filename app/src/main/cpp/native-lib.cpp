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

    std::string utfName(env->GetStringUTFChars(name, nullptr));
    Json json = PhoneBook::GetInstance()->GetPersonsByName(utfName);

    const jchar* jCharPtr = env->GetStringChars(name, nullptr);
    env->ReleaseStringChars(name, jCharPtr);

    return env->NewStringUTF(json.dump().c_str());
}

extern "C"
JNIEXPORT void JNICALL
Java_com_example_phonebookdominigames_AddNewContactActivity_SetNewContactToJNI(
        JNIEnv *env,
        jobject,
        jstring jsonData) {

    std::string utfJsonData(env->GetStringUTFChars(jsonData, nullptr));
    Json json = Json::parse(utfJsonData);
    try {
        Person person(
                json["Name"].get<std::string>(),
                PhoneNumber(json["Number"].get<std::string>())
                );
        PhoneBook::GetInstance()->AddPerson(person);
    }
    catch (std::exception& ex) {
        std::cerr << "cpp: SetNewContactToJNI(): "<< ex.what() << std::endl;
    }

    const jchar *jCharPtr = env->GetStringChars(jsonData, nullptr);
    env->ReleaseStringChars(jsonData, jCharPtr);
}