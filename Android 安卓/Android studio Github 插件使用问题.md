# Android studio Github 插件使用问题

## clone代码到本机问题

项目目录 app 下 build.gradle

```
apply plugin: 'com.android.application'

android {
    compileSdkVersion 26
    defaultConfig {
        applicationId "com.example.administrator.myapplication01"
        minSdkVersion 15
        targetSdkVersion 26
        versionCode 1
        versionName "1.0"
        testInstrumentationRunner "android.support.test.runner.AndroidJUnitRunner"
    }
    buildTypes {
        release {
            minifyEnabled false
            proguardFiles getDefaultProguardFile('proguard-android.txt'), 'proguard-rules.pro'
        }
    }
}

dependencies {
    implementation fileTree(dir: 'libs', include: ['*.jar'])
    implementation 'com.android.support:appcompat-v7:26.1.0'
    implementation 'com.android.support.constraint:constraint-layout:1.0.2'
    testImplementation 'junit:junit:4.12'
    androidTestImplementation 'com.android.support.test:runner:1.0.1'
    androidTestImplementation 'com.android.support.test.espresso:espresso-core:3.0.1'
}

```

其中 ```applicationId```项的值不通电脑会有不同

```

```

例如一个项目，我台式是

```
com.example.administrator.myapplication01
```

笔记本则是
```
com.example.a37487.myapplication01
```

### 从Github上同步问题

得现根据同步失败的提示删除 .idea目录下的vcs.xml文件再同步

## 设置忽略文件的问题

在 setting->VCS->ignoring file中按“+”号添加要忽略的文件或文件夹

由于不同的电脑编译出来的package是不同的，所以我忽略了app/build.gradle文件
