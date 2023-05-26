package com.example.phonebookdominigames;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.EditText;
import android.widget.Toast;
import com.google.gson.Gson;
import com.google.gson.GsonBuilder;

public class AddNewContactActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_add_new_contact);
    }

    public void CreateContactOnClick(View v) {
        EditText newName = findViewById(R.id.editTextName);
        EditText newPhoneNumber = findViewById(R.id.editTextPhoneNumber);

        if (newName.getText().length() == 0) {
            // Всплывающая подсказка
            Toast.makeText(this, "Введите имя", Toast.LENGTH_SHORT).show();
        }
        else if (newPhoneNumber.getText().length() == 0) {
            Toast.makeText(this, "Введите номер телефона", Toast.LENGTH_SHORT).show();
        }
        else {
            Person new_contact = new Person(
                    newName.getText().toString(),
                    newPhoneNumber.getText().toString()
            );

            Gson gson = new Gson();
            String jsonData = gson.toJson(new_contact);
            SetNewContactToJNI(jsonData);

            Intent intent = new Intent(this, MainActivity.class);
            startActivity(intent);
        }
    }

    public native void SetNewContactToJNI(String jsonData);
}