package com.example.phonebookdominigames;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Build;
import android.os.Bundle;
import android.widget.TextView;

public class SysInfoActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_sys_info);

        TextView tvDeviceBrand = findViewById(R.id.tvDeviceBrand);
        TextView tvDeviceModel = findViewById(R.id.tvDeviceModel);
        TextView tvOsVersion = findViewById(R.id.tvOsVersion);

        tvDeviceBrand.setText("Бренд: " + Build.BRAND);
        tvDeviceModel.setText("Модель: " + Build.MODEL);
        tvOsVersion.setText("Версия ОС: " + Build.VERSION.RELEASE);
    }
}