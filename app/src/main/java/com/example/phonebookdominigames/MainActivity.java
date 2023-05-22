package com.example.phonebookdominigames;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.widget.TextView;

import com.example.phonebookdominigames.databinding.ActivityMainBinding;

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

        TextView tv = binding.sampleText;
        tv.setText(GetPhoneBookDataFromJNI());

    }

    /**
     * A native method that is implemented by the 'phonebookdominigames' native library,
     * which is packaged with this application.
     */
    public native String GetPhoneBookDataFromJNI();
    public native String stringFromJNI();
}