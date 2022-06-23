package com.example.project4_1;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.EditText;
import android.widget.Button;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {
    Button plus;
    Button minus;
    Button multiple;
    Button divide;
    EditText editText1;
    EditText editText2;
    TextView result;
    String num1,num2;
    Integer resul;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        editText1=(EditText)findViewById(R.id.editText1);
        editText2=(EditText)findViewById(R.id.editText2);
        result=(TextView) findViewById(R.id.textresult);
        plus=(Button) findViewById(R.id.plus);
        minus=(Button) findViewById(R.id.minus);
        multiple=(Button) findViewById(R.id.multiple);
        divide=(Button) findViewById(R.id.divide);

        plus.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                num1=editText1.getText().toString();
                num2=editText2.getText().toString();
                resul=Integer.parseInt(num1)+Integer.parseInt(num2);
                result.setText("계산 결과 : " + resul.toString());
            }
        });

        minus.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                num1=editText1.getText().toString();
                num2=editText2.getText().toString();
                resul=Integer.parseInt(num1)-Integer.parseInt(num2);
                result.setText("계산 결과 : " + resul.toString());

            }
        });

        multiple.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                num1=editText1.getText().toString();
                num2=editText2.getText().toString();
                resul=Integer.parseInt(num1)*Integer.parseInt(num2);
                result.setText("계산 결과 : " + resul.toString());

            }
        });

        divide.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                num1=editText1.getText().toString();
                num2=editText2.getText().toString();
                resul=Integer.parseInt(num1)/Integer.parseInt(num2);
                result.setText("계산 결과 : " + resul.toString());

            }
        });



    }
}