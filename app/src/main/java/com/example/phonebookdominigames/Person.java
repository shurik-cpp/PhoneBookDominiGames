package com.example.phonebookdominigames;


import androidx.annotation.NonNull;

public class Person {
    Person(String name, String number) {
        Name = name;
        Number = number;
    }
    private String Name;
    private String Number;

    public String GetName() {
        return new String(Name);
    }
    public String GetNumber() {
        return new String(Number);
    }

    @NonNull
    public String toString() {
        return Name + " " + Number;
    }
}
