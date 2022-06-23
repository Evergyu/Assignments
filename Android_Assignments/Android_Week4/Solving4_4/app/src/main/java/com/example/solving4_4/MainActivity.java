package com.example.solving4_4;

import androidx.appcompat.app.AppCompatActivity;

import android.app.AlertDialog;
import android.content.DialogInterface;
import android.os.Bundle;
import android.widget.*;
import android.view.View;

public class MainActivity extends AppCompatActivity {
    TextView text1,text2;
    Switch switch1;
    RadioGroup Rgroup;
    RadioButton Rbtn1,Rbtn2,Rbtn3;
    Button button1,button2;
    ImageView Image;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        text1 = (TextView) findViewById(R.id.text1);
        switch1=(Switch) findViewById(R.id.switch1);

        text2 = (TextView) findViewById(R.id.text2);
        Rgroup=(RadioGroup) findViewById(R.id.radioGroup);
        Rbtn1 = (RadioButton) findViewById(R.id.rBtn1);
        Rbtn2 = (RadioButton) findViewById(R.id.rBtn2);
        Rbtn3 = (RadioButton) findViewById(R.id.rBtn3);

        button1 = (Button) findViewById(R.id.button1);
        button2=(Button)findViewById(R.id.button2);
        Image = (ImageView) (findViewById(R.id.Image));

        switch1.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(CompoundButton compoundButton, boolean b) {
                if(b){
                    text2.setVisibility(View.VISIBLE);
                    Rgroup.setVisibility(View.VISIBLE);
                    button1.setVisibility(View.VISIBLE);
                    button2.setVisibility(View.VISIBLE);
                    Image.setVisibility(View.VISIBLE);
                }else{
                    text2.setVisibility(View.INVISIBLE);
                    Rgroup.setVisibility(View.INVISIBLE);
                    button1.setVisibility(View.INVISIBLE);
                    button2.setVisibility(View.INVISIBLE);
                    Image.setVisibility(View.INVISIBLE);
                }
            }
        });
        Rgroup.setOnCheckedChangeListener(new RadioGroup.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(RadioGroup radioGroup, int i) {
                String result;
                if(i==R.id.rBtn1){
                    Image.setImageResource(R.drawable.android10);
                }
                else if(i==R.id.rBtn2){
                    Image.setImageResource(R.drawable.android11);
                }
                else if(i==R.id.rBtn3){
                    Image.setImageResource(R.drawable.android12);
                }
            }
        });
        button1.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                AlertDialog.Builder builder = new AlertDialog.Builder(MainActivity.this);
                builder.setMessage("정말로 종료하시겠습니까?");
                builder.setTitle("종료 알림창")
                        .setCancelable(false)
                        .setPositiveButton("Yes", new DialogInterface.OnClickListener() {
                            @Override
                            public void onClick(DialogInterface dialog, int i) {
                                finish();
                            }
                        })
                        .setNegativeButton("No", new DialogInterface.OnClickListener() {
                            @Override
                            public void onClick(DialogInterface dialog, int i) {
                                dialog.cancel();
            }
        });
                AlertDialog alert = builder.create();
                alert.setTitle("종료 알림창");
                alert.show();
            }
        });
        button2.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                switch1.setChecked(false);
                Rbtn1.setChecked(false);
                Rbtn2.setChecked(false);
                Rbtn3.setChecked(false);
                Image.setImageBitmap(null);
            }
        });
    }
}