# brews

[官网](https://docs.brew.sh/Installation)

## 下载安装

如果提示 brew 命令不存在，需要先安装 Homebrew。安装步骤如下：

### 命令行安装

#### 逼乎大佬

优先尝试这个

```bash
/bin/zsh -c "$(curl -fsSL https://gitee.com/cunkai/HomebrewCN/raw/master/Homebrew.sh)"
```

----

如需卸载，使用指令：

```bash
/bin/zsh -c "$(curl -fsSL https://gitee.com/cunkai/HomebrewCN/raw/master/HomebrewUninstall.sh)"
```

[链接](https://zhuanlan.zhihu.com/p/372576355)

#### 官网教程

1. 打开终端，执行以下命令：
```bash
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
```

2. 等待安装完成。安装过程中可能会提示输入系统密码。

3. 安装完成后，需要将 Homebrew 添加到 PATH。根据你的 shell 类型，选择对应的命令：

   对于 Zsh（macOS Catalina 及以后的默认 shell）：
   ```bash
   echo 'eval "$(/opt/homebrew/bin/brew shellenv)"' >> ~/.zshrc
   eval "$(/opt/homebrew/bin/brew shellenv)"
   ```

   对于 Bash：
   ```bash
   echo 'eval "$(/opt/homebrew/bin/brew shellenv)"' >> ~/.bash_profile
   eval "$(/opt/homebrew/bin/brew shellenv)"
   ```

4. 验证安装：
```bash
brew --version
```

如果显示 Homebrew 的版本信息，说明安装成功。现在你可以继续使用 `brew install cmake` 来安装 CMake 了。

注意：
- 安装 Homebrew 需要有稳定的网络连接
- 如果下载速度较慢，可以考虑使用国内镜像源
- 确保系统已安装 Command Line Tools for Xcode，如果没有安装，可以运行：
  ```bash
  xcode-select --install
  ```

## 用法
