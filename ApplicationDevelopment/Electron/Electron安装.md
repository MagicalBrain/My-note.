# Electron安装

## 下载安装npm

### Linux

Ubuntu:
```bash
sudo apt-get install npm
```

#### Ubuntu18 安装

==**建议直接用ubuntu20及以上，要不就装旧版的**==

```bash
sudo apt-get install nodejs-dev node-gyp libssl1.0-dev
sudo apt-get install npm
```


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

#### ubuntu 20

#### ubuntu 22


```bash
sudo apt-get install nodejs-dev node-gyp libssl1.0-dev
sudo apt-get install npm
```

`sudo apt-get install nodejs-dev node-gyp libssl1.0-dev`这里会报错：

```bash
sudo apt-get install nodejs-dev node-gyp libssl1.0-dev

Reading package lists... Done
Building dependency tree... Done
Reading state information... Done
Package libssl1.0-dev is not available, but is referred to by another package.
This may mean that the package is missing, has been obsoleted, or
is only available from another source

Package nodejs-dev is not available, but is referred to by another package.
This may mean that the package is missing, has been obsoleted, or
is only available from another source
However the following packages replace it:
  libnode-dev

E: Package 'nodejs-dev' has no installation candidate
E: Package 'libssl1.0-dev' has no installation candidate
```

尝试`sudo apt-get install libnode-dev`来替代

查看版本

```bash
# 查看 node.js 版本号
node -v
# 查看npm版本
npm -v
```


<!-- 然后直接npm安装electron

```bash
mkdir -p $USER/electron_demo
npm install electron --save-dev
```

然后过程有点慢： -->


因为要从github下载？

解决办法：

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

### ubuntu22 安装过慢

```bash
npm install --save-dev electron
# 报错：
npm ERR! code 1
npm ERR! path /home/hrl/hrl/electron-demo/electron_app_01/node_modules/electron
npm ERR! command failed
npm ERR! command sh -c node install.js
npm ERR! RequestError: read ECONNRESET
npm ERR!     at ClientRequest.<anonymous> (/home/hrl/hrl/electron-demo/electron_app_01/node_modules/got/dist/source/core/index.js:970:111)
npm ERR!     at Object.onceWrapper (events.js:421:26)
npm ERR!     at ClientRequest.emit (events.js:326:22)
npm ERR!     at ClientRequest.origin.emit (/home/hrl/hrl/electron-demo/electron_app_01/node_modules/@szmarczak/http-timer/dist/source/index.js:43:20)
npm ERR!     at TLSSocket.socketErrorListener (_http_client.js:427:9)
npm ERR!     at TLSSocket.emit (events.js:314:20)
npm ERR!     at emitErrorNT (internal/streams/destroy.js:92:8)
npm ERR!     at emitErrorAndCloseNT (internal/streams/destroy.js:60:3)
npm ERR!     at processTicksAndRejections (internal/process/task_queues.js:84:21)
npm ERR!     at TLSWrap.onStreamRead (internal/stream_base_commons.js:209:20)

npm ERR! A complete log of this run can be found in:
npm ERR!     /home/hrl/.npm/_logs/2023-06-06T02_07_56_932Z-debug-0.log
```

解决办法：

使用`cnpm`

```bash
npm install cnpm -g --registry=https://registry.npm.taobao.org
```

如果出现以下报错：

```bash
npm install cnpm -g --registry=https://registry.npm.taobao.org
# 报错信息
npm ERR! code EACCES
npm ERR! syscall rename
npm ERR! path /usr/local/lib/node_modules/cnpm
npm ERR! dest /usr/local/lib/node_modules/.cnpm-cj8ySp5Q
npm ERR! errno -13
npm ERR! Error: EACCES: permission denied, rename '/usr/local/lib/node_modules/cnpm' -> '/usr/local/lib/node_modules/.cnpm-cj8ySp5Q'
npm ERR!  [Error: EACCES: permission denied, rename '/usr/local/lib/node_modules/cnpm' -> '/usr/local/lib/node_modules/.cnpm-cj8ySp5Q'] {
npm ERR!   errno: -13,
npm ERR!   code: 'EACCES',
npm ERR!   syscall: 'rename',
npm ERR!   path: '/usr/local/lib/node_modules/cnpm',
npm ERR!   dest: '/usr/local/lib/node_modules/.cnpm-cj8ySp5Q'
npm ERR! }
npm ERR! 
npm ERR! The operation was rejected by your operating system.
npm ERR! It is likely you do not have the permissions to access this file as the current user
npm ERR! 
npm ERR! If you believe this might be a permissions issue, please double-check the
npm ERR! permissions of the file and its containing directories, or try running
npm ERR! the command again as root/Administrator.

npm ERR! A complete log of this run can be found in:
npm ERR!     /home/hrl/.npm/_logs/2023-06-06T07_25_49_010Z-debug-0.log
```

那么就是权限不够，使用sudo权限执行：

```bash
sudo npm install cnpm -g --registry=https://registry.npm.taobao.org
```

如果出现：

```bash
cnpm -v
# 回显信息
cnpm@9.2.0 (/usr/local/lib/node_modules/cnpm/lib/parse_argv.js)
npm@9.6.7 (/usr/local/lib/node_modules/cnpm/node_modules/npm/index.js)
node@18.16.0 (/usr/local/bin/node)
npminstall@7.9.0 (/usr/local/lib/node_modules/cnpm/node_modules/npminstall/lib/index.js)
prefix=/usr/local 
linux x64 5.19.0-43-generic 
registry=https://registry.npmmirror.com
```

则说明安装成功，否则安装失败

安装失败的话则更新npm和node之后再尝试安装



```bash
sudo npm install -g n

# latest #(升级node.js到最新版) stable #（升级node.js到最新稳定版）
sudo n stable 
```

然后新开一个terminal来查看版本

```bash
# 查看node版本
node -v
# 查看 npm 版本
npm -v
```

然后再去安装cnpm

----

```bash
npm install -g cnpm --registry=https://registry.npmmirror.com
```

```bash
echo '\n#alias for cnpm\nalias cnpm="npm --registry=https://registry.npmmirror.com \
  --cache=$HOME/.npm/.cache/cnpm \
  --disturl=https://npmmirror.com/mirrors/node \
  --userconfig=$HOME/.cnpmrc"' >> ~/.bashrc && source ~/.bashrc
```

## 参考链接

https://www.electronjs.org/zh/docs/latest/tutorial/installation
