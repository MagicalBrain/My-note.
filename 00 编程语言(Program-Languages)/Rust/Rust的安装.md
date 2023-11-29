# Rust的安装

## Windows

下载安装器：https://www.rust-lang.org/zh-CN/learn/get-started

## Linux

## WSL

直接在命令行里运行：

```bash
export RUSTUP_DIST_SERVER=https://mirrors.ustc.edu.cn/rust-static
export RUSTUP_UPDATE_ROOT=https://mirrors.ustc.edu.cn/rust-static/rustup

curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh
```

然后显示：

```bash
  stable-x86_64-unknown-linux-gnu installed - rustc 1.74.0 (79e9716c9 2023-11-13)


Rust is installed now. Great!

To get started you may need to restart your current shell.
This would reload your PATH environment variable to include
Cargo's bin directory ($HOME/.cargo/bin).

To configure your current shell, run:
source "$HOME/.cargo/env"
```

就说明是安装成功了


## IOS
