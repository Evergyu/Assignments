package com.example.project10_3;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        setTitle("액티비티 테스트 예제");
        android.util.Log.i("액티비티 테스트", "onCreate()");

        Button btnDial = findViewById(R.id.btnDial);
        Button btnFinish = findViewById(R.id.btnFinish);

        btnDial.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Uri uri = Uri.parse("tel:01012345678");
                Intent intent = new Intent(Intent.ACTION_DIAL, uri);
                startActivity(intent);
            }
        });

        btnFinish.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                finish();
            }
        });


    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        android.util.Log.i("액티비티테스트", "onDestroy()");
    }

    @Override
    protected void onPause() {
        super.onPause();
        android.util.Log.i("액티비티테스트", "onPause()");
    }

    @Override
    protected void onStop() {
        super.onStop();
        android.util.Log.i("액티비티테스트", "onStop()");
    }

    @Override
    protected void onRestart() {
        super.onRestart();
        android.util.Log.i("액티비티테스트", "onRestart()");
    }

    @Override
    protected void onStart() {
        super.onStart();
        android.util.Log.i("액티비티테스트", "onStart()");
    }

    @Override
    protected void onResume() {
        super.onResume();
        android.util.Log.i("액티비티테스트", "onResume()");
    }
}