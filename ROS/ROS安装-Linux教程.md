# ROS安装-Linux教程

[toc]

推荐使用Ubuntu

[安装参考链接][install]

## 下载

Configure your Ubuntu repositories
Configure your Ubuntu repositories to allow "restricted," "universe," and "multiverse." You can follow the Ubuntu guide for instructions on doing this.

首先设置你的Ubuntu软件库，使得允许 "restricted," "universe," and "multiverse."

Setup your sources.list
Setup your computer to accept software from packages.ros.org.

安装sources.list到你的电脑

```bash
sudo sh -c 'echo "deb http://packages.ros.org/ros/ubuntu $(lsb_release -sc) main" > /etc/apt/sources.list.d/ros-latest.list'
```

设置你的软件源库密钥（官方的命令，可能有问题）：
Set up your keys

```bash
sudo apt install curl # if you haven't already installed curl
curl -s https://raw.githubusercontent.com/ros/rosdistro/master/ros.asc | sudo apt-key add -
```

----

上面的官方命令如果到安装的时候`sudo apt update`命令不出问题就好了，实际情况则是没什么卵(luan)用。

1、换中科大的源

```bash
sudo sh -c '. /etc/lsb-release && echo "deb http://mirrors.ustc.edu.cn/ros/ubuntu/ `lsb_release -cs` main" > /etc/apt/sources.list.d/ros-latest.list'
```

2、设置公钥

```bash
sudo apt-key adv --keyserver 'hkp://keyserver.ubuntu.com:80' --recv-key C1CF6E31E6BADE8868B172B4F42ED6FBAB17C654
```

到这才可以继续往下走。

## 安装

```bash
sudo apt update
```

推荐命令：
```bash
sudo apt install ros-melodic-desktop-full
```

## 设置环境变量

这是一个脚本可以方便地设置ROS的环境变量
It's convenient if the ROS environment variables are automatically added to your bash session every time a new shell is launched:

```bash
echo "source /opt/ros/melodic/setup.bash" >> ~/.bashrc
source ~/.bashrc
```

如果你的电脑同时安装不止一个版本的ROS，使用source命令的时候一定要对应版本的`setup.bash`
If you have more than one ROS distribution installed, ~/.bashrc must only source the setup.bash for the version you are currently using.

如果你只是想改变你当前的shell的环境变量，可以使用一下命令：
If you just want to change the environment of your current shell, instead of the above you can type:

```bash
source /opt/ros/melodic/setup.bash
```

如果你使用的是zsh而不是bash的话，则可以运行一下命令：
If you use zsh instead of bash you need to run the following commands to set up your shell:

```bash
echo "source /opt/ros/melodic/setup.zsh" >> ~/.zshrc
source ~/.zshrc
```

## 安装生成包所需的依赖

到了这一步，你已经安装好了运行roscore包所需的一切。
但是为了生成并管理你自己的ros包，这里还有一些根据不同ros版本发布的工具需要安装。
例如rosinstall是一个经常使用的命令，能够让你只需要一个命令就能轻易下载ros包所需的资源。
Up to now you have installed what you need to run the core ROS packages. To create and manage your own ROS workspaces, there are various tools and requirements that are distributed separately. For example, rosinstall is a frequently used command-line tool that enables you to easily download many source trees for ROS packages with one command.

为了下载这个工具和其它用来生成ros包的依赖，运行命令：
To install this tool and other dependencies for building ROS packages, run:

```bash
sudo apt install python-rosdep python-rosinstall python-rosinstall-generator python-wstool build-essential
```



## 初始化rosdep

在你使用ros工具之前，你将会需要初始化rosdep。
rosdep能够让你轻松下载系统所需的依赖
如果你还没有下载rosdep，运行如下命令：
Before you can use many ROS tools, you will need to initialize rosdep. rosdep enables you to easily install system dependencies for source you want to compile and is required to run some core components in ROS. If you have not yet installed rosdep, do so as follows.

```bash
sudo apt install python-rosdep
```

继续运行如下命令，就能初始化rosdep：
With the following, you can initialize rosdep.

```bash
sudo rosdep init
rosdep update
```

**注意**
由于`raw.githubuserscontent`被墙了，所以这两行命令大概率不行。

### rosdep init问题及解决方案

```bash
ERROR: cannot download default sources list from:
https://raw.githubusercontent.com/ros/rosdistro/master/rosdep/sources.list.d/20-default.list
Website may be down.
```

这个问题本质就是因为`raw.githubuserscontent`被墙了，`20-default.list`下载不下来，可以手动下载或者编辑创建一个：

```bash
sudo mkdir -p /etc/ros/rosdep/sources.list.d/
sudo vim /etc/ros/rosdep/sources.list.d/20-default.list
```

把如下内容拷贝进20-default.list文件中即可；

```bash
# os-specific listings first
yaml https://raw.githubusercontent.com/ros/rosdistro/master/rosdep/osx-homebrew.yaml osx
 
# generic
yaml https://raw.githubusercontent.com/ros/rosdistro/master/rosdep/base.yaml
yaml https://raw.githubusercontent.com/ros/rosdistro/master/rosdep/python.yaml
yaml https://raw.githubusercontent.com/ros/rosdistro/master/rosdep/ruby.yaml
gbpdistro https://raw.githubusercontent.com/ros/rosdistro/master/releases/fuerte.yaml fuerte
 
# newer distributions (Groovy, Hydro, ...) must not be listed anymore, they are being fetched from the rosdistro index.yaml instead
```

然后直接运行rosdep update即可；如果再运行 sudo rosdep init 可能依然会提示无法下载或者提示以存在。

[解决方案链接][init]

### rosdep update问题及解决方案

```bash
read operation timed out
```

其实不管超时还是什么奇奇怪怪的错误，其本质都是网络被墙。

需要修改链接的文件：
没有特别说明的就是在url前面加 "https://ghproxy.com/"

1、 
`/usr/lib/python2.7/dist-packages/rosdep2/sources_list.py`    

72 line 

675 行 download_rosdep_data函数的try语句块里的第一句加上 如下代码：

```bash
url = "https://ghproxy.com/" + url
```

2、
`/usr/lib/python2.7/dist-packages/rosdistro/__init__.py`
里面的`DEFAULT_INDEX_URL`进行如下替换：

```bash
DEFAULT_INDEX_URL = 'https://ghproxy.com/https://raw.githubusercontent.com/ros/rosdistro/master/index-v4.yaml'
```

3、
`/usr/lib/python2.7/dist-packages/rosdep2/gbpdistro_support.py` 36 Line

204 Line(206Line) 添加如下代码：

```bash
gbpdistro_url = "https://ghproxy.com/" + gbpdistro_url
```

4、
`/usr/lib/python2.7/dist-packages/rosdep2/rep3.py` 39 line

5、
`/usr/lib/python2.7/dist-packages/rosdistro/manifest_provider/github.py` 68 line 119 line

再次尝试

```bash
sudo rosdep update
```

问题解决

**注意：**
当你按以下链接修改`.py`文件的时候，在url前添加"https://ghproxy.com/"

[解决方案链接][update]

## 测试安装

输入命令`roscore`启动ros

如果显示如下：

```bash
... logging to /home/hrl/.ros/log/41e60760-36c9-11ec-aea9-d4258b01eb3b/roslaunch-hrl-GL62VR-7RFX-26850.log
Checking log directory for disk usage. This may take a while.
Press Ctrl-C to interrupt
Done checking log file disk usage. Usage is <1GB.

started roslaunch server http://hrl-GL62VR-7RFX:38589/
ros_comm version 1.14.12


SUMMARY
========

PARAMETERS
 * /rosdistro: melodic
 * /rosversion: 1.14.12

NODES

auto-starting new master
process[master]: started with pid [26860]
ROS_MASTER_URI=http://hrl-GL62VR-7RFX:11311/

setting /run_id to 41e60760-36c9-11ec-aea9-d4258b01eb3b
process[rosout-1]: started with pid [26871]
started core service [/rosout]

```

则说明安装成功，ros可以正常启动了。

### 可能会遇到的问题

运行`roscore`报错：

```bash
Traceback (most recent call last):
  File "/opt/ros/melodic/lib/python2.7/dist-packages/roslaunch/__init__.py", line 279, in main
    write_pid_file(options.pid_fn, options.core, options.port)
  File "/opt/ros/melodic/lib/python2.7/dist-packages/roslaunch/__init__.py", line 111, in write_pid_file
    with open(pid_fn, "w") as f:
IOError: [Errno 13] Permission denied: '/home/hrl/.ros/roscore-11311.pid'
```

**解决方案**：

You should run 'sudo rosdep fix-permissions' and invoke 'rosdep update' again without sudo.

```bash
sudo rosdep fix-permissions
rosdep update
```

这个问题其实前面运行`rosdep update`命令的时候前面不小心加了sudo

## 参考链接

[install]:https://blog.csdn.net/KIK9973/article/details/118755045

[init]:https://blog.csdn.net/qq_35813104/article/details/117332670

[update]:https://blog.csdn.net/leida_wt/article/details/115120940
