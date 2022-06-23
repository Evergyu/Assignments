package com.cookandroid.solve10_3;

import androidx.activity.result.ActivityResult;
import androidx.activity.result.ActivityResultCallback;
import androidx.activity.result.ActivityResultLauncher;
import androidx.activity.result.contract.ActivityResultContracts;
import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.RadioButton;
import android.widget.RadioGroup;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    private ActivityResultLauncher<Intent> resultLauncher;
    private Button btnNewActivity;
    private RadioButton rdoAdd,rdoDiv,rdoMul,rdoMinus;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        final EditText edtNum1 = (EditText) findViewById(R.id.edtNum1);
        final EditText edtNum2 = (EditText) findViewById(R.id.edtNum2);
        btnNewActivity = (Button) findViewById(R.id.btnNewActivity);
        final RadioGroup rdoGroup = (RadioGroup) findViewById(R.id.rdoGroup);
        rdoAdd = (RadioButton) findViewById(R.id.rdoAdd);
        rdoMinus = (RadioButton) findViewById(R.id.rdoMinus);
        rdoMul = (RadioButton) findViewById(R.id.rdoMul);
        rdoDiv = (RadioButton) findViewById(R.id.rdoDiv);

        resultLauncher = registerForActivityResult(
                new ActivityResultContracts.StartActivityForResult(),
                new ActivityResultCallback<ActivityResult>() {
                    @Override
                    public void onActivityResult(ActivityResult result) {
                        if(result.getResultCode() == RESULT_OK){
                            int hap = result.getData().getIntExtra("Hap",0);
                            Toast.makeText(getApplicationContext(),"합계 : " + hap,Toast.LENGTH_LONG).show();
                        }
                    }
                }
        );

        btnNewActivity.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(getApplicationContext(),secondActivity.class);

                switch (rdoGroup.getCheckedRadioButtonId()){
                    case R.id.rdoAdd:
                        intent.putExtra("result","+");
                        break;
                    case R.id.rdoMinus:
                        intent.putExtra("result","-");
                        break;
                    case R.id.rdoMul:
                        intent.putExtra("result","*");
                        break;
                    case R.id.rdoDiv:
                        intent.putExtra("result","/");
                        break;
                    default:
                        break;
                }
                intent.putExtra("Num1",Integer.parseInt(edtNum1.getText().toString()));
                intent.putExtra("Num2",Integer.parseInt(edtNum2.getText().toString()));

                resultLauncher.launch(intent);
            }
        });


    }
}