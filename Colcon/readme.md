# Colcon

之前工作有接触过CMake，谁知道现在冒出了个柯南（Colcon）。

这个听说很牛逼，支持分布式部署

基本用法：

```bash
usage: colcon [-h] [--log-base LOG_BASE] [--log-level LOG_LEVEL]
              {build,extension-points,extensions,graph,info,list,metadata,test,test-result,version-check}
              ...

optional arguments:
  -h, --help            show this help message and exit
  --log-base LOG_BASE   The base path for all log directories (default: ./log,
                        to disable: /dev/null)
  --log-level LOG_LEVEL
                        Set log level for the console output, either by
                        numeric or string value (default: warning)

colcon verbs:
  build                 Build a set of packages
  extension-points      List extension points
  extensions            List extensions
  graph                 Generate a visual representation of the dependency graph
  info                  Package information
  list                  List packages, optionally in topological ordering
  metadata              Manage metadata of packages
  test                  Test a set of packages
  test-result           Show the test results generated when testing a set of
                        packages
  version-check         Compare local package versions with PyPI

  {build,extension-points,extensions,graph,info,list,metadata,test,test-result,version-check}
                        call `colcon VERB -h` for specific help

Environment variables:
  CMAKE_COMMAND         The full path to the CMake executable
  COLCON_ALL_SHELLS     Flag to enable all shell extensions
  COLCON_COMPLETION_LOGFILE
                        Set the logfile for completion time
  COLCON_DEFAULTS_FILE  Set path to the yaml file containing the default values
                        for the command line arguments (default:
                        $COLCON_HOME/defaults.yaml)
  COLCON_DEFAULT_EXECUTOR
                        Select the default executor extension
  COLCON_EXTENSION_BLOCKLIST
                        Block extensions which should not be used
  COLCON_HOME           Set the configuration directory (default: ~/.colcon)
  COLCON_LOG_LEVEL      Set the log level (debug|10, info|20, warn|30,
                        error|40, critical|50, or any other positive numeric
                        value)
  COLCON_WARNINGS       Set the warnings filter similar to PYTHONWARNINGS
                        except that the module entry is implicitly set to
                        'colcon.*'
  CTEST_COMMAND         The full path to the CTest executable
  POWERSHELL_COMMAND    The full path to the PowerShell executable

For more help and usage tips, see https://colcon.readthedocs.io
```
