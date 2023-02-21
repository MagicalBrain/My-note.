# Electron安装

## 下载安装npm

### Linux

Ubuntu:
```bash
sudo apt-get install npm
```

#### Ubuntu18 安装不了解决办法

==**建议直接用ubuntu20及以上，要不就装旧版的**==

```bash
sudo apt-get install npm
# 安装不了，报错
Reading package lists... Done
Building dependency tree       
Reading state information... Done
Some packages could not be installed. This may mean that you have
requested an impossible situation or if you are using the unstable
distribution that some required packages have not yet been created
or been moved out of Incoming.
The following information may help to resolve the situation:

The following packages have unmet dependencies:
 npm : Depends: node-gyp (>= 0.10.9) but it is not going to be installed
E: Unable to correct problems, you have held broken packages.
```

```bash
sudo apt-get install nodejs-dev node-gyp libssl1.0-dev
sudo apt-get install npm
```


### Window

待补充

### MacOS

待补充

## 安装 Electron

```bash
npm install electron --save-dev
```

注意：这个命令虽说是安装electron的，但是会直接将运行命令的目录当作是当前工作项目目录（就是将当前目录当成是项目目录并创建了一些文件）；
所以如果能够安装成功的话，最好把文件删除了，然后新建一个工作项目目录[初始化Electron项目]

### ubuntu18 安装出错

```bash
npm install electron --save-dev
# 报错
npm WARN enoent ENOENT: no such file or directory, open '/home/hrl/package.json'
npm WARN hrl No description
npm WARN hrl No repository field.
npm WARN hrl No README data
npm WARN hrl No license field.
npm ERR! Linux 5.4.0-137-generic
npm ERR! argv "/usr/bin/node" "/usr/bin/npm" "install" "electron" "--save-dev"
npm ERR! node v8.10.0
npm ERR! npm  v3.5.2
npm ERR! path /home/hrl/node_modules/.staging/@types/cacheable-request-e8fe65f8/package.json
npm ERR! code ENOTDIR
npm ERR! errno -20
npm ERR! syscall open

npm ERR! ENOTDIR: not a directory, open '/home/hrl/node_modules/.staging/@types/cacheable-request-e8fe65f8/package.json'
npm ERR! 
npm ERR! If you need help, you may report this error at:
npm ERR!     <https://github.com/npm/npm/issues>

npm ERR! Please include the following file with any support request:
npm ERR!     /home/hrl/npm-debug.log
```

更新node

```bash
sudo npm install n -g
sudo n stable
```

然后新开一个terminal来查看node的版本

```bash
node --version
# 报错
node: /lib/x86_64-linux-gnu/libc.so.6: version `GLIBC_2.28' not found (required by node)
```

glibc版本问题，不建议去硬弄，这个是ubuntu系统版本问题，建议直接换系统或者更新系统

## 参考链接

https://www.electronjs.org/zh/docs/latest/tutorial/installation
