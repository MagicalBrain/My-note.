# Android Studio build报错

## Manifest merger failed

### 问题描述

点击运行后，build命令行窗口报错：

```bash
Manifest merger failed : android:exported needs to be explicitly specified for <activity>. 
Apps targeting Android 12 and higher are required to specify an explicit value for `android:exported` 
    when the corresponding component has an intent filter defined. 
See https://developer.android.com/guide/topics/manifest/activity-element#exported for details.
```

### 解决方案

```bash
Manifest merger failed : android:exported needs to be explicitly specified for <activity>. 
```

android 是否导出需要在`<activity>`里指明

很简单，修改一下`AndroidManifest.xml`里的`<activity>`属性就行了，加一个

```xml
android:exported="true"
```

```xml
<manifest xmlns:android="http://schemas.android.com/apk/res/android"
    xmlns:tools="http://schemas.android.com/tools"
    package="com.dbinary.Oscilloscope">

    <application
        android:screenOrientation="landscape"
        android:allowBackup="true"
        android:icon="@mipmap/ic_launcher"
        android:label="@string/app_name"
        android:roundIcon="@mipmap/ic_launcher_round"
        android:supportsRtl="true"
        android:theme="@style/Theme.MyNDKApplication" >
        <activity
            android:name="android.app.NativeActivity"
            android:configChanges="orientation|keyboardHidden"
            android:theme="@android:style/Theme.NoTitleBar.Fullscreen"
            android:label="@string/app_name"
            android:exported="true">
            <meta-data
                android:name="android.app.lib_name"
                android:value="PainterEngineForAndroid" />
            <intent-filter>
                <action android:name="android.intent.action.MAIN" />
                <category android:name="android.intent.category.LAUNCHER" />
            </intent-filter>
        </activity>
    </application>
    <uses-permission android:name="android.permission.WRITE_EXTERNAL_STORAGE" />
    <uses-permission android:name="android.permission.READ_EXTERNAL_STORAGE" />
    <uses-permission android:name="android.permission.INTERNET" />
    <uses-permission android:name="android.permission.CHANGE_WIFI_STATE" />
    <uses-permission android:name="android.permission.ACCESS_WIFI_STATE" />
</manifest>
```

## Unable to load class 'javax.xml.bind.annotation.XmlSchema'.

### 问题描述

将自己几年前开发的Android Studio工程从github上拉下来，然后用新版的Android Studio来打开。

然后就会各种提示jdk、gradle有问题，下载了一堆东西后（升级了gradle），还是会有这个错：

```bash
Unable to load class 'javax.xml.bind.annotation.XmlSchema'.

This is an unexpected error. Please file a bug containing the idea.log file.
```
