package com.example.week2_7;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;
import android.net.Uri;
import androidx.appcompat.app.AppCompatActivity;
import android.widget.RadioButton;
import android.widget.ImageView;


public class MainActivity extends AppCompatActivity {
    EditText userInput;
    Button button1;
    Button button2;
    RadioButton r_btn1,r_btn2;
    ImageView imageView;
    
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        userInput=(EditText)findViewById(R.id.editText1);
        button1=(Button)findViewById(R.id.button);
        button1.setOnClickListener(new View.OnClickListener() {

            @Override
            public void onClick(View view) {
            Toast.makeText(getApplicationContext(),userInput.getText(),Toast.LENGTH_SHORT).show();
            }
        });


        button2=(Button)findViewById(R.id.button2);
        button2.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                String url = userInput.getText().toString().trim();
                Uri urlstr=Uri.parse(url);
                Intent i=new Intent();
                i.setData(urlstr);
                i.setAction(Intent.ACTION_VIEW);
                startActivity(i);
            }
        });
        
        r_btn1=(RadioButton) findViewById(R.id.rg_btn1);
        r_btn2=(RadioButton) findViewById(R.id.rg_btn2);
        imageView=(ImageView)findViewById(R.id.imageView);
        r_btn1.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                imageView.setImageResource(R.drawable.green);
            }
        });
        r_btn2.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                imageView.setImageResource(R.drawable.red);
            }
        });
    }
}

