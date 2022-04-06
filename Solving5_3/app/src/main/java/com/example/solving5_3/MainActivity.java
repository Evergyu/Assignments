package com.example.solving5_3;

import androidx.appcompat.app.AppCompatActivity;

import android.graphics.Color;
import android.os.Bundle;
import android.view.View;
import android.widget.LinearLayout;
import android.widget.*;

import org.w3c.dom.Text;

public class MainActivity extends AppCompatActivity {
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        // setContentView(R.layout.activity_main);

        LinearLayout.LayoutParams params = new LinearLayout.LayoutParams(
                LinearLayout.LayoutParams.MATCH_PARENT,
                LinearLayout.LayoutParams.MATCH_PARENT);

        LinearLayout baseLayout = new LinearLayout(this);
        baseLayout.setOrientation(LinearLayout.VERTICAL);
        setContentView(baseLayout,params);

        EditText editText=new EditText(this);
        baseLayout.addView(editText);

        Button btn= new Button(this);
        btn.setText("버튼입니다");
        btn.setBackgroundColor(Color.YELLOW);
        baseLayout.addView(btn);

        TextView textView=new TextView(this);
        textView.setTextColor(Color.rgb(139,0,255));
        textView.setTextSize(50);

        btn.setOnClickListener(new View.OnClickListener(){
            public void onClick(View arg0){
                String text= editText.getText().toString();
                textView.setText(text);
            }
        });

        baseLayout.addView(textView);

        TextView textView1=new TextView(this);
        textView1.setText("2018038083 이인규");
        textView.setTextSize(50);
        baseLayout.addView(textView1);

    }
}