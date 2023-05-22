package com.example.phonebookdominigames;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.widget.ArrayAdapter;
import android.widget.ListView;
import android.widget.TextView;

import com.example.phonebookdominigames.databinding.ActivityMainBinding;

import java.util.ArrayList;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'phonebookdominigames' library on application startup.
    static {
        System.loadLibrary("phonebookdominigames");
    }

    private ActivityMainBinding binding;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        binding = ActivityMainBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());


        ArrayList<Person> PhoneBookData = new ArrayList<Person>();
        PhoneBookData.add(new Person("name", "number"));
        PhoneBookData.add(new Person("name1", "number1"));
        PhoneBookData.add(new Person("name2", "number2"));


        ListView lv = binding.personsListView;
        ArrayAdapter<String> adapter = new ArrayAdapter(this,
                android.R.layout.simple_list_item_1, PhoneBookData);
        lv.setAdapter(adapter);

        TextView tv = binding.sampleText;
        //tv.setText(GetPhoneBookDataFromJNI());

    }

    /**
     * A native method that is implemented by the 'phonebookdominigames' native library,
     * which is packaged with this application.
     */
    public native String GetPhoneBookDataFromJNI();
    public native String stringFromJNI();
}