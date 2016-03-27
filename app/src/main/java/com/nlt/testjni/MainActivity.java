package com.nlt.testjni;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.widget.TextView;

import java.util.ArrayList;

public class MainActivity extends AppCompatActivity
{

    @Override
    protected void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        TextView tx = (TextView) findViewById(R.id.tx);

//        String tmp = subString("hello world!", 8, 15);
//        tx.setText("SubString: " + tmp);

        ArrayList<Student> students = new ArrayList<>();
        ArrayList<Integer> ages = new ArrayList<>();


        Student s = new Student("lihua", "001");
        students.add(s);
        s = new Student("wangmeimei", "002");
        students.add(s);
        s = new Student("sanwu", "003");
        students.add(s);

        ages.add(12);
        ages.add(14);
        ages.add(15);

        students = setStudentAge(students, ages);
        for (Student tmp : students)
        {
            Log.e("java: ", "ID: " + tmp.ID + " Name: " + tmp.Name + " Age: " + tmp.Age);
        }

    }

    private class Student
    {
        public String Name;
        public int Age;
        public String ID;

        public Student(String name, String ID)
        {
            Name = name;
            this.ID = ID;
        }


    }

    public native int getSum(int a, int b);

    public native String subString(String sting, int start, int len);

    public native ArrayList<Student> setStudentAge(ArrayList<Student> students, ArrayList<Integer> ages);

    static
    {
        System.loadLibrary("JniTest");
    }
}
