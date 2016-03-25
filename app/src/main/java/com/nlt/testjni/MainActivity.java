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
        int c = getSum(1, 2);
        tx.setText("sum: " + c);
    }

    public native int getSum(int a, int b);

    static
    {
        System.loadLibrary("JniTest");
    }
}
