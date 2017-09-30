package com.crayfish.ndkproject;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        TextView tv_hello = (TextView)super.findViewById(R.id.tv_hello);
//        tv_hello.setText(new NdkTest().getString());
        TextView textView = (TextView)super.findViewById(R.id.textView);
        TextView textView2 = (TextView)super.findViewById(R.id.textView2);
        String A = "1010";
        textView.setText("加密前："+A);
        textView2.setText("加密后："+new AESjni().myDecrypt(A));
    }
}
