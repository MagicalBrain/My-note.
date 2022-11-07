# Colcon-Build命令详解

## colcon build --symlink-install

```bash
colcon build --symlink-install
```
Use symlinks instead of copying files where possible

尽可能使用符号链接而不是复制文件

表示编译时如果 install 中文件已经存在于 src 或者 build 文件夹中，就用超链接指向该文件，避免浪费空间，也可以实现同步更新。

## colcon build --packages-select

```bash
colcon build --packages-select [package_name]  
```

选择编译某个包

## 详细信息

```bash
usage: colcon build [-h] [--build-base BUILD_BASE]
                    [--install-base INSTALL_BASE] [--merge-install]
                    [--symlink-install] [--test-result-base TEST_RESULT_BASE]
                    [--continue-on-error] [--executor {parallel,sequential}]
                    [--parallel-workers NUMBER]
                    [--event-handlers [name1+ [name2- ...]]]
                    [--ignore-user-meta] [--metas [PATH [PATH ...]]]
                    [--base-paths [PATH [PATH ...]]]
                    [--packages-ignore [PKG_NAME [PKG_NAME ...]]]
                    [--packages-ignore-regex [PATTERN [PATTERN ...]]]
                    [--paths [PATH [PATH ...]]]
                    [--packages-up-to [PKG_NAME [PKG_NAME ...]]]
                    [--packages-up-to-regex [PATTERN [PATTERN ...]]]
                    [--packages-above [PKG_NAME [PKG_NAME ...]]]
                    [--packages-above-and-dependencies [PKG_NAME [PKG_NAME ...]]]
                    [--packages-above-depth DEPTH [PKG_NAME ...]]
                    [--packages-select-by-dep [PKG_NAME [PKG_NAME ...]]]
                    [--packages-skip-by-dep [PKG_NAME [PKG_NAME ...]]]
                    [--packages-skip-up-to [PKG_NAME [PKG_NAME ...]]]
                    [--packages-select-build-failed | --packages-skip-build-finished | --packages-select-test-failures | --packages-skip-test-passed]
                    [--packages-select [PKG_NAME [PKG_NAME ...]]]
                    [--packages-skip [PKG_NAME [PKG_NAME ...]]]
                    [--packages-select-regex [PATTERN [PATTERN ...]]]
                    [--packages-skip-regex [PATTERN [PATTERN ...]]]
                    [--packages-start PKG_NAME] [--packages-end PKG_NAME]
                    [--allow-overriding PKG_NAME [PKG_NAME ...]]
                    [--cmake-args [* [* ...]]] [--cmake-target CMAKE_TARGET]
                    [--cmake-target-skip-unavailable] [--cmake-clean-cache]
                    [--cmake-clean-first] [--cmake-force-configure]
                    [--ament-cmake-args [* [* ...]]]
                    [--catkin-cmake-args [* [* ...]]]
                    [--catkin-skip-building-tests]

Build a set of packages.

optional arguments:
  -h, --help            show this help message and exit
  --build-base BUILD_BASE
                        The base path for all build directories (default:
                        build)
  --install-base INSTALL_BASE
                        The base path for all install prefixes (default:
                        install)
  --merge-install       Merge all install prefixes into a single location
  --symlink-install     Use symlinks instead of copying files where possible
  --test-result-base TEST_RESULT_BASE
                        The base path for all test results (default: --build-
                        base)
  --continue-on-error   Continue other packages when a package fails to build
                        (packages recursively depending on the failed package
                        are skipped)

Executor arguments:
  --executor {parallel,sequential}
                        The executor to process all packages (default:
                        parallel)
                        * parallel: Process multiple packages in parallel
                        * sequential: Process one package at a time
  --parallel-workers NUMBER
                        The maximum number of packages to process in parallel
                        (default: 16)

Event handler arguments:
  --event-handlers [name1+ [name2- ...]]
                        Enable (+) or disable (-) event handlers (default:
                        compile_commands+ console_cohesion- console_direct-
                        console_package_list- console_start_end+
                        console_stderr+ desktop_notification+ event_log+ log+
                        log_command+ status+ store_result+ summary+
                        terminal_title+)
                        * compile_commands: Generate a `compile_commands.json`
                        file for the whole workspace
                        * console_cohesion: Pass task output at once to stdout
                        * console_direct: Pass output directly to stdout/err
                        * console_package_list: Output list of queued job
                        names
                        * console_start_end: Output task name on start/end
                        * console_stderr: Output all stderr of a task at once
                        * desktop_notification: Desktop notification of the
                        summary
                        * event_log: Log all events to a global log file
                        * log: Output task specific log files
                        * log_command: Log a 'debug' message for each command
                        * status: Continuously update a status line
                        * store_result: Persist the result of a job in a file
                        in its build directory
                        * summary: Output summary of all tasks
                        * terminal_title: Show status in the terminal title

Discovery arguments:
  --ignore-user-meta    Ignore `*.meta` files in the user config directory
                        `/home/hrl/.colcon/metadata`
  --metas [PATH [PATH ...]]
                        The directories containing a `colcon.meta` file or
                        paths to arbitrary files containing the same meta
                        information (default: ./colcon.meta)
  --base-paths [PATH [PATH ...]]
                        The base paths to recursively crawl for packages
                        (default: .)
  --packages-ignore [PKG_NAME [PKG_NAME ...]]
                        Ignore packages as if they were not discovered
  --packages-ignore-regex [PATTERN [PATTERN ...]]
                        Ignore packages where any of the patterns match the
                        package name
  --paths [PATH [PATH ...]]
                        The paths to check for a package. Use shell wildcards
                        (e.g. `src/*`) to select all direct subdirectories

Package selection arguments:
  --packages-up-to [PKG_NAME [PKG_NAME ...]]
                        Only process a subset of packages and their recursive
                        dependencies
  --packages-up-to-regex [PATTERN [PATTERN ...]]
                        Only process a subset of packages and their recursive
                        dependencies, where any of the patterns match the
                        package name
  --packages-above [PKG_NAME [PKG_NAME ...]]
                        Only process a subset of packages and packages which
                        recursively depend on them
  --packages-above-and-dependencies [PKG_NAME [PKG_NAME ...]]
                        Only process a subset of packages and packages which
                        recursively depend on them including all their
                        recursive dependencies
  --packages-above-depth DEPTH [PKG_NAME ...]
                        Only process a subset of packages and packages which
                        recursively depend on them up to a given depth
  --packages-select-by-dep [PKG_NAME [PKG_NAME ...]]
                        Only process packages which (recursively) depend on
                        this
  --packages-skip-by-dep [PKG_NAME [PKG_NAME ...]]
                        Skip packages which (recursively) depend on this
  --packages-skip-up-to [PKG_NAME [PKG_NAME ...]]
                        Skip a subset of packages and their recursive
                        dependencies
  --packages-select-build-failed
                        Only process a subset of packages which have failed to
                        build previously (aborted packages are not considered
                        errors)
  --packages-skip-build-finished
                        Skip a set of packages which have finished to build
                        previously
  --packages-select-test-failures
                        Only process a subset of packages which had test
                        failures previously
  --packages-skip-test-passed
                        Skip a set of packages which had no test failures
                        previously
  --packages-select [PKG_NAME [PKG_NAME ...]]
                        Only process a subset of packages
  --packages-skip [PKG_NAME [PKG_NAME ...]]
                        Skip a set of packages
  --packages-select-regex [PATTERN [PATTERN ...]]
                        Only process a subset of packages where any of the
                        patterns match the package name
  --packages-skip-regex [PATTERN [PATTERN ...]]
                        Skip a set of packages where any of the patterns match
                        the package name
  --packages-start PKG_NAME
                        Skip packages before this in flat topological ordering
  --packages-end PKG_NAME
                        Skip packages after this in flat topological ordering
  --allow-overriding PKG_NAME [PKG_NAME ...]
                        Allow building packages that exist in underlay
                        workspaces

Arguments for 'cmake' packages:
  --cmake-args [* [* ...]]
                        Pass arguments to CMake projects. Arguments matching
                        other options must be prefixed by a space,
                        e.g. --cmake-args " --help" (stdout might not be shown
                        by default, e.g. add `--event-handlers
                        console_cohesion+`)
  --cmake-target CMAKE_TARGET
                        Build a specific target instead of the default target
  --cmake-target-skip-unavailable
                        Skip building packages which don't have the target
                        passed to --cmake-target
  --cmake-clean-cache   Remove CMake cache before the build (implicitly
                        forcing CMake configure step)
  --cmake-clean-first   Build target 'clean' first, then build (to only clean
                        use '--cmake-target clean')
  --cmake-force-configure
                        Force CMake configure step

Arguments for 'ros.ament_cmake' packages:
  --ament-cmake-args [* [* ...]]
                        Pass arguments to 'ament_cmake' packages. Arguments
                        matching other options must be prefixed by a space

Arguments for 'ros.catkin' packages:
  --catkin-cmake-args [* [* ...]]
                        Pass arguments to 'catkin' packages. Arguments
                        matching other options must be prefixed by a space
  --catkin-skip-building-tests
                        By default the 'tests' target of 'catkin' packages is
                        invoked. If running 'colcon test' later isn't intended
                        this can be skipped
```
