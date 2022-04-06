package com.example.solving5_5;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

        EditText edit1,edit2;
        Button btnAdd,btnSub,btnMul,btnDiv;
        TextView textResult;
        String num1,num2;
        Integer result;

        Button[] numButtons = new Button[10];
        Integer[] numBtnIDs = {R.id.BtnNum0,R.id.BtnNum1,R.id.BtnNum2,R.id.BtnNum3,
                R.id.BtnNum4,R.id.BtnNum5,R.id.BtnNum6,R.id.BtnNum7,
                R.id.BtnNum8,R.id.BtnNum9};
        @Override
        protected void onCreate(Bundle savedInstanceState) {
                super.onCreate(savedInstanceState);
                setContentView(R.layout.activity_main);
                setTitle("테이블 레이아웃 계산기");

                edit1 = (EditText) findViewById(R.id.Edit1);
                edit2 = (EditText) findViewById(R.id.Edit2);
                btnAdd = (Button) findViewById(R.id.btnAdd);
                btnSub = (Button) findViewById(R.id.btnSub);
                btnMul = (Button) findViewById(R.id.btnMul);
                btnDiv = (Button) findViewById(R.id.btnDiv);
                textResult = (TextView) findViewById(R.id.TextResult);

                btnAdd.setOnClickListener(new View.OnClickListener() {
                        @Override
                        public void onClick(View v) {
                                num1 = edit1.getText().toString();
                                num2 = edit2.getText().toString();
                                result = Integer.parseInt(num1) + Integer.parseInt(num2);
                                textResult.setText("계산 결과 : " + result.toString());

                        }
                });
                btnSub.setOnClickListener(new View.OnClickListener() {
                        @Override
                        public void onClick(View v) {
                                num1 = edit1.getText().toString();
                                num2 = edit2.getText().toString();
                                result = Integer.parseInt(num1) - Integer.parseInt(num2);
                                textResult.setText("계산 결과 : " + result.toString());

                        }
                });
                btnMul.setOnClickListener(new View.OnClickListener() {
                        @Override
                        public void onClick(View v) {
                                num1 = edit1.getText().toString();
                                num2 = edit2.getText().toString();
                                result = Integer.parseInt(num1) * Integer.parseInt(num2);
                                textResult.setText("계산 결과 : " + result.toString());
                        }
                });
                btnDiv.setOnClickListener(new View.OnClickListener() {
                        @Override
                        public void onClick(View v) {
                                num1 = edit1.getText().toString();
                                num2 = edit2.getText().toString();
                                result = Integer.parseInt(num1) / Integer.parseInt(num2);
                                textResult.setText("계산 결과 : " + result.toString());
                        }
                });

                for(int i = 0;i<numBtnIDs.length;i++){
                        numButtons[i] = (Button) findViewById(numBtnIDs[i]);
                }

                for(int i = 0;i<numBtnIDs.length;i++){
                        final int index;
                        index = i;
                        numButtons[index].setOnClickListener(new View.OnClickListener() {
                                @Override
                                public void onClick(View v) {
                                        if(edit1.isFocused() == true){
                                                num1 = edit1.getText().toString() + numButtons[index].getText().toString();
                                                edit1.setText(num1);
                                        }else if(edit2.isFocused() == true){
                                                num2 = edit2.getText().toString() + numButtons[index].getText().toString();
                                                edit2.setText(num2);
                                        }else{
                                                Toast.makeText(getApplicationContext(), "먼저 에디트텍스트를 선택하세요", Toast.LENGTH_SHORT).show();
                                        }
                                }
                        });
                }
        }
}