package com.example.phonebookdominigames;

import androidx.appcompat.app.AppCompatActivity;

import android.annotation.SuppressLint;
import android.os.Bundle;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.EditText;
import android.widget.ListView;
import android.widget.TextView;

import com.example.phonebookdominigames.databinding.ActivityMainBinding;
import com.google.gson.Gson;
import com.google.gson.reflect.TypeToken;

import java.lang.reflect.Type;
import java.util.List;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'phonebookdominigames' library on application startup.
    static {
        System.loadLibrary("phonebookdominigames");
    }

    private ActivityMainBinding binding;

    @SuppressLint("SetTextI18n")
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        binding = ActivityMainBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());

        List<Person> deserializedData = DeserializeJniData(GetPhoneBookDataFromJNI());

        ShowFindedCount(deserializedData.size());
        ShowContactsInListView(deserializedData);
    }

    private List<Person> DeserializeJniData(String serializedData) {
        Gson json = new Gson();
        Type founderListType = new TypeToken<List<Person>>(){}.getType();
        return json.fromJson(serializedData, founderListType);
    }

    private void ShowContactsInListView(List<Person> data) {
        ListView contactsListView = binding.contactsListView;
        ArrayAdapter<String> adapter = new ArrayAdapter(this,
                android.R.layout.simple_list_item_1, data);
        contactsListView.setAdapter(adapter);
    }

    private void ShowFindedCount(int count) {
        TextView tv = binding.sampleText;
        tv.setText("Найдено " + Integer.toString(count) + " контактов.");
    }

    public void FindContactOnClick(View view) {
        EditText editText = binding.editTextFindContact;
        String name = editText.getText().toString();
        List<Person> deserializedData = DeserializeJniData(GetContactsByNameFromJNI(name));
        ShowFindedCount(deserializedData.size());
        ShowContactsInListView(deserializedData);
    }

    /**
     * A native method that is implemented by the 'phonebookdominigames' native library,
     * which is packaged with this application.
     */
    public native String GetPhoneBookDataFromJNI();
    public native String GetContactsByNameFromJNI(String name);
}