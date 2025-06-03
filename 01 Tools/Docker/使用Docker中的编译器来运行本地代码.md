# 使用Docker中的编译器来运行本地代码

有时候我们会直接使用docker里开发环境来编译本机的代码，典型应用常用：交叉编译

## cpp

假设我现在有一份cpp代码或者一个CMake项目，如何调用docker中的cpp容器来编译运行呢？

## 方法一：单个 C++ 文件

假设你有一个 `main.cpp` 文件在当前目录：

1. 拉取 gcc 镜像（如果没有）：
```bash
docker pull gcc:latest
```

2. 运行容器并挂载当前目录：
```bash
docker run --rm -v "$(pwd):/workspace" -w /workspace gcc:latest g++ main.cpp -o main
```

3. 运行编译后的程序：
```bash
docker run --rm -v "$(pwd):/workspace" -w /workspace gcc:latest ./main
```

## 方法二：CMake 项目

假设你有一个包含 `CMakeLists.txt` 的项目：

1. 拉取带有 CMake 的镜像：
```bash
docker pull gcc:latest
```

2. 创建构建目录：
```bash
mkdir -p build
```

3. 运行 CMake 配置：
```bash
docker run --rm -v "$(pwd):/workspace" -w /workspace/build gcc:latest cmake ..
```

4. 运行构建：
```bash
docker run --rm -v "$(pwd):/workspace" -w /workspace/build gcc:latest make
```

5. 运行编译后的程序（假设可执行文件名为 myapp）：
```bash
docker run --rm -v "$(pwd):/workspace" -w /workspace/build gcc:latest ./myapp
```

## 参数说明

- `--rm`：容器停止后自动删除
- `-v "$(pwd):/workspace"`：将当前目录挂载到容器的 `/workspace` 目录
- `-w /workspace`：设置工作目录为 `/workspace`

## 进阶用法

### 1. 创建开发容器（持续开发用）

```bash
docker run -it --name cpp_dev -v "$(pwd):/workspace" -w /workspace gcc:latest bash
```

这样可以进入容器的 shell，然后直接在容器内进行编译和运行。

### 2. 使用 Docker Compose（推荐）

创建 `docker-compose.yml` 文件：

```yaml
version: '3'
services:
  cpp:
    image: gcc:latest
    volumes:
      - .:/workspace
    working_dir: /workspace
```

然后可以使用：
```bash
# 编译
docker-compose run --rm cpp g++ main.cpp -o main

# 运行
docker-compose run --rm cpp ./main

# CMake 项目
docker-compose run --rm cpp cmake -B build
docker-compose run --rm cpp cmake --build build
```

### 3. 创建专用的 Dockerfile

```dockerfile
FROM gcc:latest

# 安装额外的工具
RUN apt-get update && apt-get install -y \
    cmake \
    gdb \
    valgrind \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /workspace
```

构建和使用：
```bash
docker build -t my-cpp-dev .
docker run --rm -v "$(pwd):/workspace" my-cpp-dev g++ main.cpp -o main
```

## 注意事项

1. 权限问题：
   - 如果遇到权限问题，可以添加 `--user $(id -u):$(id -g)` 参数

2. 性能优化：
   - 在 macOS 和 Windows 上，可以考虑使用 `:cached` 卷标记提高性能：
     ```bash
     docker run --rm -v "$(pwd):/workspace:cached" ...
     ```

3. 调试支持：
   - 如果需要调试，需要额外的配置和工具，建议使用 VS Code 的 Remote Container 扩展

4. 依赖管理：
   - 如果项目有外部依赖，建议在 Dockerfile 中预先安装
   - 可以使用多阶段构建来减小最终镜像大小

## python


