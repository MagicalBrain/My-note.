# cargo的用法

## 基本用法

Cargo 是 Rust 的默认构建系统和包管理器，用于管理和构建 Rust 项目。它提供了一组命令行工具，帮助您创建、构建、测试和发布 Rust 应用程序。

下面是一些常用的 Cargo 命令和用法的简单介绍：

1. `cargo new <项目名>`：创建一个新的 Rust 项目。这将在当前目录下创建一个包含项目结构和示例代码的文件夹。

2. `cargo build`：构建当前项目。它会自动下载和编译项目的依赖项，并生成可执行文件或库文件。

3. `cargo run`：编译并运行当前项目。它会自动构建项目并执行生成的可执行文件。

4. `cargo test`：运行项目中的测试。它会查找项目中的测试函数并执行它们，提供测试结果和输出。

5. `cargo check`：检查项目的语法和类型错误，但不生成可执行文件。这个命令用于快速检查项目中的错误，而无需进行完整的构建过程。

6. `cargo update`：更新项目的依赖项。它会检查并下载最新的依赖版本。

7. `cargo doc`：生成项目的文档。它会根据项目中的文档注释生成 HTML 格式的文档，并输出到指定目录。

8. `cargo publish`：发布您的 Rust 包到 crates.io，这是 Rust 的包仓库。在发布之前，您需要创建一个 crates.io 的帐户，并在 Cargo.toml 中配置包的元数据。

9. `cargo clean`：清理项目目录中生成的构建文件和输出文件。它可以帮助您清理构建过程中生成的临时文件。

此外，Cargo 还提供了许多其他功能和选项，如设置构建类型（debug 或 release）、管理依赖项、处理特性标志、处理环境变量等。您可以使用 `cargo --help` 命令查看 Cargo 的完整命令列表和帮助信息，或者参考 Rust 官方文档中的 Cargo 部分。

总体而言，Cargo 简化了 Rust 项目的管理和构建过程，使开发者可以更专注于代码编写和功能实现。它的简单易用性和强大功能使得 Rust 社区广泛采用和推崇。

## 用法

```bash
cargo -h
Rust's package manager

Usage: cargo [+toolchain] [OPTIONS] [COMMAND]
       cargo [+toolchain] [OPTIONS] -Zscript <MANIFEST_RS> [ARGS]...

Options:
  -V, --version             Print version info and exit
      --list                List installed commands
      --explain <CODE>      Provide a detailed explanation of a rustc error message
  -v, --verbose...          Use verbose output (-vv very verbose/build.rs output)
  -q, --quiet               Do not print cargo log messages
      --color <WHEN>        Coloring: auto, always, never
  -C <DIRECTORY>            Change to DIRECTORY before doing anything (nightly-only)
      --frozen              Require Cargo.lock and cache are up to date
      --locked              Require Cargo.lock is up to date
      --offline             Run without accessing the network
      --config <KEY=VALUE>  Override a configuration value
  -Z <FLAG>                 Unstable (nightly-only) flags to Cargo, see 'cargo -Z help' for details
  -h, --help                Print help

Commands:
    build, b    Compile the current package
    check, c    Analyze the current package and report errors, but don't build object files
    clean       Remove the target directory
    doc, d      Build this package's and its dependencies' documentation
    new         Create a new cargo package
    init        Create a new cargo package in an existing directory
    add         Add dependencies to a manifest file
    remove      Remove dependencies from a manifest file
    run, r      Run a binary or example of the local package
    test, t     Run the tests
    bench       Run the benchmarks
    update      Update dependencies listed in Cargo.lock
    search      Search registry for crates
    publish     Package and upload this package to the registry
    install     Install a Rust binary. Default location is $HOME/.cargo/bin
    uninstall   Uninstall a Rust binary
    ...         See all commands with --list

See 'cargo help <command>' for more information on a specific command.
```
