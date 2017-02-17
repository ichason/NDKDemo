package com.cn.chason.ndkdemo;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    private TextView Stram;

    //静态代码块，会首先执行
    static {
        /*
        加载生成的动态库，动态库加载的时候，Jni_onLoad 函数（c中的函数）会被调用
        在C函数中，java虚拟机通过函数表的形式将JNI函数和java类中Native函数对应起来，（两个名字必须一致）
         */
        System.loadLibrary("jni-lib");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Stram= (TextView) findViewById(R.id.Stram);

        Stram.setText(getStramInfo());

    }


    private static native String getStramInfo ();




}
