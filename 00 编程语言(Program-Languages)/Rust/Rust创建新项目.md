# Rust创建新项目

创建新项目
我们将在新的 Rust 开发环境中编写一个小应用。首先用 Cargo 创建一个新项目。在您的终端中执行：

```bash
cargo new hello-rust
```

这会生成一个名为 hello-rust 的新目录，其中包含以下文件：

```bash
hello-rust
|- Cargo.toml
|- src
  |- main.rs
```

Cargo.toml 为 Rust 的清单文件。其中包含了项目的元数据和依赖库。

src/main.rs 为编写应用代码的地方。

cargo new 会生成一个新的“Hello, world!”项目！我们可以进入新创建的目录中，执行下面的命令来运行此程序：

```bash
cargo run
```

您应该会在终端中看到如下内容：

```bash
cargo run
   Compiling hello-rust v0.1.0 (/Users/ag_dubs/rust/hello-rust)
    Finished dev [unoptimized + debuginfo] target(s) in 1.34s
     Running `target/debug/hello-rust`
Hello, world!
```


