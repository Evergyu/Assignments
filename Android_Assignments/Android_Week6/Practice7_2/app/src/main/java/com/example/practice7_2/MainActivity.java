package com.example.practice7_2;

import androidx.appcompat.app.AppCompatActivity;

import android.graphics.Color;
import android.os.Bundle;
import android.view.ContextMenu;
import android.widget.*;
import android.view.*;
import android.view.ContextMenu.*;

public class MainActivity extends AppCompatActivity {
    LinearLayout baselayout;
    Button button1,button2;

    @Override
    public void onCreateContextMenu(ContextMenu menu, View v, ContextMenuInfo menuInfo){
        super.onCreateContextMenu(menu,v,menuInfo);

        MenuInflater mInflater=getMenuInflater();
        if(v==button1){
            menu.setHeaderTitle("배경색 변경");
            mInflater.inflate(R.menu.menu1,menu);
        }
        if(v==button2){
            menu.setHeaderTitle("버튼 변경");
            mInflater.inflate(R.menu.menu2,menu);
        }
    }
    public boolean onContextItemSelected(MenuItem item) {
        switch (item.getItemId()){
            case R.id.itemRed: baselayout.setBackgroundColor(Color.RED); return true;
            case R.id.itemGreen: baselayout.setBackgroundColor(Color.GREEN); return true;
            case R.id.itemBlue: baselayout.setBackgroundColor(Color.BLUE); return true;
            case R.id.subRotate: ; return true;
            case R.id.subSize: ; return true;
        }
        return false;
    }
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        setTitle("배경색 바꾸기(컨텍스트 메뉴)");
        baselayout=(LinearLayout)findViewById(R.id.baseLayout);
        button1=(Button)findViewById(R.id.button1);
        registerForContextMenu(button1);
        button2=(Button)findViewById(R.id.button2);
        registerForContextMenu(button2);


    }


}