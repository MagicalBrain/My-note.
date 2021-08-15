# 相机SDK的使用

项目名：HYSDK
项目地址：https://e.gitee.com/shenzhen-hinyeung/repos/shenzhen-hinyeung/hysdk

开发工具：Visual Studio 2019 （最新版）
版本管理工具：Git

第三方库：
PCL 1.11.1：点云库
QT 5.15.1：GUI开发库
CUDA 11.0.3：Nvidia GPU加速库
ABB Robot Runtime: ABB机器人通讯运行环境，为Hypick运行依赖项
.NET Framework Runtime:.NET运行环境，为ABB Robot Runtime运行依赖项，一般在安装Visual Studio 2019时顺带安装。

辅助软件：
MVS：海康工业相机驱动以及配置软件

## 工具及库安装

### 安装 Visual Studio 2019

先从官网下载安装工具```vs_community__1971407823.1597128975.exe```
双击 ```vs_community__1971407823.1597128975.exe``` 进行安装即可，安装时注意选择 **使用C++的桌面开发** 的开发套件

此外还需安装2个插件：
**Qt for VS 2019**：提供Qt在VS下的集成，包括创建Qt工程、新建Qt相关的文件（ui文件、资源文
件、翻译文件）、自动添加Qt的编译支持（moc工具、uic工具的自动调用）
**Microsoft Visual Studio Installer Projects**：提供安装包生成工程的支持。未安装此插件的情况
下， HyCapture/InstallerBuild 、 HyPick/InstallerBuild 两个子项目无法正常打开。

关闭Visual Studio，双击 qt-vsaddin-msvc2019-2.5.2-rev.01.vsix 安装Qt for VS 2019插件；双击
InstallerProjects.vsix 安装Microsoft Visual Studio Installer Projects插件即可。

### 安装 CUDA 11.0.3

在有NVIDIA显卡的电脑上双击 ```cuda_11.0.3_451.82_win10.exe``` 安装即可。如果电脑上安装有之前版
本的CUDA，建议先卸载后再安装CUDA 11.0。
安装完成后，系统变量中应新增了 CUDA_PATH 、 CUDA_PATH_V11_0 等环境变量，且CUDA动态库的路
径被加入了 PATH 环境变量里

### 安装 PCL 1.11.1

首先运行 PCL-1.11.1-AllInOne-msvc2019-win64.exe ，勾选 Add PCL to the system PATH for
all users 或 Add PCL to the system PATH for current user 以自动添加环境变量:

![]()

在安装PCL的过程中会自动弹出OpenNI 2的安装程序（OpenNI 2是PCL的依赖项），同样点击安装即
可。
安装完成后，系统变量中应新增了 PCL_ROOT 环境变量:

![]()

且PCL及PCL依赖项（FLANN、Qhull、VTK、OpenNI2）的动态库路径应被加入了 PATH 环境变量

![]()

由于 ```PCL-1.11.1-AllInOne-msvc2019-win64.exe``` 安装的VTK未与Qt集成，不方便在Qt中使用VTK控
件，因此需要覆盖安装一个VTK的预编译版本。
解压 VTK 8.2.0 WithQt.zip （VTK 8.2.0与Qt 5.15.1
混合编译的包）到 %PCL安装路径%/3rdParty/VTK 目录，覆盖PCL自带的VTK即可。

### 安装 Qt 5.15.1

解压 预编译包/Qt 5.15.1.zip 到 Qt 5.15.1 ，将解压文件夹复制到需要的位置，并将 Qt
5.15.1/msvc2019_64/bin 添加到系统PATH环境变量

![]()

Qt 5.15.1/Qt Creator 4.13.1 为Qt Creator的安装包，由于我们使用Visual Studio 2019作为IDE，
可以不用安装Qt Creator。

#### 在VS2019中配置 Qt插件

在VS 2019中，依次选择 ```扩展 -> Qt VS Tools -> Qt option```

![](asset/配置Qt插件.png)

在弹出的对话框中点击```Add```:

![](asset/Qt插件Add.png)

路径选择为 Qt 5.15.1/msvc 2019_64 的安装路径即可

![](asset/Qt插件路径.png)

### 安装 MVS

运行 ```MVS_STD_3.0.0_180723.exe``` 安装即可，安装完成后，MVS的运行时环境路径应被添加到 PATH 环
境变量中：



注意：如果win10系统更新了，也要去海康威视机器人公司官网下载最新版的MVS软件，否则系统无法识别出相机。

### 安装 ABB Robot Runtime

运行 ```ABB Robot Communication Runtime.exe``` 安装即可

### 安装 Git

官网下载工具安装即可。

## 项目库克隆及其使用

### 克隆库

参考Git使用手册。

新建一个空文件夹作为存放库，鼠标右击空白处，点击```Git Bash here```

初始化git本地仓库:
```
git init
```

设置用户名和email
```
git --config user.name [你的用户名]
git --config user.email [你的电子邮箱]
```

生成ssh密钥：
```
ssh-keygen -o
```

生成后打开```id_rsa.pub```文件复制里面的公钥：
```
cat ~/.ssh/id_rsa.pub
```

如果你忘记了电脑是否已经生成了ssh密钥，那么你可以使用以下命令查看：
```
cd ~/.ssh
```

如果```id_rsa.pub```已经存在，那么就是已经生成了ssh密钥。

在gitee账号设置的ssh密钥里新建设备并添加密钥：

![](asset/gitee添加密钥.png)

![](asset/gitee添加密钥2.png)

标题时用来区分你的设备的，起一个方便区分的名字即可。
公钥即```id_rsa.pub```文件里面的内容。



### HYSDK的使用

将HYSDK添加进系统环境变量即可。
