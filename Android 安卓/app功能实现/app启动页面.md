# Android Studio 制作app启动页面

## 新建一个activity

## AndroidManifest多出来的代码

```xml
<intent-filter>
                <action android:name="android.intent.action.MAIN" />
 
                <category android:name="android.intent.category.LAUNCHER" />
            </intent-filter>

```

## 对应Java文件代码

```java
public class SplashActivity extends Activity {
 
   // private final int SPLASH_DISPLAY_LENGHT = 2000; // 两秒后进入系统
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        getWindow().addFlags(WindowManager.LayoutParams.FLAG_FULLSCREEN);//隐藏状态栏
        //getSupportActionBar().hide();//隐藏标题栏
        setContentView(R.layout.activity_splash);
        Thread myThread=new Thread(){//创建子线程
            @Override
            public void run() {
                try{
                    sleep(5000);//使程序休眠五秒
                    Intent it=new Intent(getApplicationContext(),MainActivity.class);//启动MainActivity
                    startActivity(it);
                    finish();//关闭当前活动
                }catch (Exception e){
                    e.printStackTrace();
                }
            }
        };
        myThread.start();//启动线程
 
    }
}

```

## 修改activity_splash的内容

## 参考链接

https://blog.csdn.net/qq_39732867/article/details/86512712

## 我自己的尝试

### AndroidManifest.xml代码

```xml
<?xml version="1.0" encoding="utf-8"?>
<manifest xmlns:android="http://schemas.android.com/apk/res/android"
    package="com.example.a37487.launcher_application">

    <application
        android:allowBackup="true"
        android:icon="@mipmap/ic_launcher"
        android:label="@string/app_name"
        android:roundIcon="@mipmap/ic_launcher_round"
        android:supportsRtl="true"
        android:theme="@style/AppTheme">
        <activity android:name=".MainActivity">
            <intent-filter>
                <action android:name="android.intent.action.MAIN" />

                <!--
                这是原来主界面的代码:
                是设置其为启动页面的
                <category android:name="android.intent.category.LAUNCHER" />
                -->

            </intent-filter>
        </activity>
        <activity android:name=".Launcher_Activity">
            <intent-filter>
                <action android:name="android.intent.action.MAIN" />

                <category android:name="android.intent.category.LAUNCHER" />
            </intent-filter>
        </activity>
    </application>

</manifest>
```

其实所有的app都有启动页面，只不过默认是一开始创建的主界面（Main_Activity）
只要把AndroidManifest文件中的activity_main里的
```xml
<category android:name="android.intent.category.LAUNCHER" />
```
放到我们设置的启动页面对应的androidManifest文件中对应的xml代码块里

### 主界面

其实没什么的，只有一个textview

#### java代码

```java
package com.example.a37487.launcher_application;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }
}

```

#### xml代码

```xml
<?xml version="1.0" encoding="utf-8"?>
<android.support.constraint.ConstraintLayout xmlns:android="http://schemas.android.com/apk/res/android"
    xmlns:app="http://schemas.android.com/apk/res-auto"
    xmlns:tools="http://schemas.android.com/tools"
    android:layout_width="match_parent"
    android:layout_height="match_parent"
    tools:context="com.example.a37487.launcher_application.MainActivity">

    <TextView
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"

        android:text="我是主页面!"
        android:textSize="24dp"
        android:textColor="#000"

        app:layout_constraintBottom_toBottomOf="parent"
        app:layout_constraintLeft_toLeftOf="parent"
        app:layout_constraintRight_toRightOf="parent"
        app:layout_constraintTop_toTopOf="parent"
        />

</android.support.constraint.ConstraintLayout>

```