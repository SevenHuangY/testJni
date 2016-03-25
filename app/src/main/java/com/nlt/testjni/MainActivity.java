package com.nlt.testjni;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity
{

    @Override
    protected void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        TextView tx = (TextView) findViewById(R.id.tx);

        String tmp = subString("hello world!", 8, 15);
        tx.setText("SubString: " + tmp);
    }

    public native int getSum(int a, int b);

    public native String subString(String sting, int start, int len);

    static
    {
        System.loadLibrary("JniTest");
    }
}
