#include <jni.h>
#include <string>
#include <sstream>
#include "PhoneBook.h"
#include "nlohmann/json.hpp"
#include <jni.h>

using Json = nlohmann::json;

extern "C" JNIEXPORT jstring
Java_com_example_phonebookdominigames_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {

    auto book = PhoneBook::GetInstance();
    std::stringstream stream;
    try {
        auto persons = book->GetPersonsByName("А");
        Json json = persons;
        stream << json;
    }
    catch (std::exception& ex) {
        stream << ex.what();
    }

    return env->NewStringUTF(stream.str().c_str());
}