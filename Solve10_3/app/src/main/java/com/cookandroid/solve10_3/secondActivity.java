package com.cookandroid.solve10_3;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

public class secondActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_second);
        setTitle("Second");

        Intent intent = getIntent();

        String result = (intent.getStringExtra("result"));
        int resultValue = 0;
        if(result.equals("+")){
            resultValue = intent.getIntExtra("Num1",0) + intent.getIntExtra("Num2",0);

        }else if(result.equals("-")){
            resultValue = intent.getIntExtra("Num1",0) - intent.getIntExtra("Num2",0);
        }else if(result.equals("*")){
            resultValue = intent.getIntExtra("Num1",0) * intent.getIntExtra("Num2",0);
        }else{
            resultValue = intent.getIntExtra("Num1",0) / intent.getIntExtra("Num2",0);
        }

        final int retValue = resultValue;

        Button btnReturn = (Button)findViewById(R.id.btnReturn);

        btnReturn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent outIntent = new Intent(getApplicationContext(),MainActivity.class);
                outIntent.putExtra("Hap",retValue);
                setResult(RESULT_OK,outIntent);
                finish();
            }
        });
    }
}