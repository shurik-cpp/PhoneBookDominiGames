package com.example.phonebookdominigames;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.widget.TextView;
import androidx.recyclerview.widget.RecyclerView;

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

        // Example of a call to a native method
        TextView tv = binding.sampleText;
        tv.setText(stringFromJNI());
        //RecyclerView personsList = binding.PersonsList;

    }

    /**
     * A native method that is implemented by the 'phonebookdominigames' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();
}