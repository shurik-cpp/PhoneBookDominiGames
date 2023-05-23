package com.example.phonebookdominigames;


import androidx.annotation.NonNull;

public class Person {
    Person(String name, String number) {
        Name = name;
        Number = number;
    }
    public String Name;
    public String Number;

    @NonNull
    public String toString() {
        return Name + " " + Number;
    }
}
