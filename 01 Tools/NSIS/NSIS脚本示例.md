<!--
 * @Author: MB's X13 374870361@qq.com
 * @Date: 2023-12-25 17:50:23
 * @LastEditors: MB's X13 374870361@qq.com
 * @LastEditTime: 2023-12-25 17:50:31
 * @Description: 
-->
# NSIS脚本示例

当使用NSIS（Nullsoft Scriptable Install System）打包程序时，你需要编写一个NSIS脚本来描述安装程序的安装过程和配置。以下是一个简单的NSIS脚本示例：

```nsis
; 设置安装程序的名称和版本号
Name "My Application"
Outfile "MyApplicationSetup.exe"
InstallDir $PROGRAMFILES\MyApplication

; 默认安装选项
Var INSTALL_OPTION
Var INSTALL_LOCATION

; 页面：选择安装选项
Page Components
Page Directory
Page InstFiles

Section
    ; 设置安装过程的UI界面
    SetSilent silent

    ; 创建快捷方式
    CreateDirectory $SMPROGRAMS\MyApplication
    CreateShortCut $SMPROGRAMS\MyApplication\MyApplication.lnk $INSTDIR\MyApplication.exe

    ; 完成安装
    MessageBox MB_OK "Installation completed successfully."
SectionEnd

Function .onInit
    ; 初始化安装选项和安装位置
    StrCpy $INSTALL_OPTION "1"
    StrCpy $INSTALL_LOCATION $PROGRAMFILES
FunctionEnd
```

在这个示例中，NSIS脚本定义了安装程序的名称为 "My Application"，生成的安装文件为 "MyApplicationSetup.exe"。安装目录默认为 `$PROGRAMFILES\MyApplication`。

NSIS脚本中的 `Section` 部分定义了安装过程的具体操作。在示例中，创建了一个快捷方式，并显示了一个安装完成的消息框。

`Function .onInit` 部分用于初始化安装选项和安装位置的变量。在这个示例中，安装选项设置为 "1"，安装位置设置为 `$PROGRAMFILES`。

编写完NSIS脚本后，你可以使用NSIS编译器来编译脚本并生成可执行的安装程序。打开NSIS编译器，将以上示例脚本保存为 `MyApplicationScript.nsi` 文件，然后点击编译按钮生成安装程序。

生成的安装程序 `MyApplicationSetup.exe` 可以在目标系统上运行，按照脚本中定义的安装过程进行安装。

请注意，这只是一个简单的NSIS脚本示例，实际的脚本可能需要更多的配置和操作来满足你的需求。你可以根据自己的需求，进一步学习和了解NSIS的脚本语法和功能，以编写更复杂和完善的安装程序。NSIS的官方网站提供了完整的文档和教程，可供参考：https://nsis.sourceforge.io/Documentation/

---

## 如何执行NSIS脚本生成打包程序

### 1. 安装NSIS编译器

- 访问 [NSIS官网](https://nsis.sourceforge.io/Download) 下载并安装 NSIS。
- 安装完成后，系统会有 `makensis.exe` 命令行工具和图形界面 `NSIS Compiler`。

### 2. 编写NSIS脚本

- 将你的NSIS脚本保存为 `.nsi` 文件，例如：`MyApplicationScript.nsi`。

### 3. 编译NSIS脚本

#### 方法一：使用图形界面编译

1. 打开“NSIS Compiler”（或“NSIS 宏编译器”）。
2. 点击“浏览”选择你的 `.nsi` 脚本文件。
3. 点击“编译脚本”按钮。
4. 编译完成后，会在脚本中 `Outfile` 指定的位置生成安装程序（如 `MyApplicationSetup.exe`）。

#### 方法二：使用命令行编译

1. 打开命令提示符（Windows Terminal/CMD）。
2. 切换到脚本所在目录，例如：
   ```sh
   cd D:\MyProject
   ```
3. 执行以下命令：
   ```sh
   makensis MyApplicationScript.nsi
   ```
4. 编译成功后，会在 `Outfile` 指定的位置生成安装程序。

如果makensis命令找不到如何解决？

### 4. 运行生成的安装程序

- 双击生成的 `MyApplicationSetup.exe`，即可按照脚本定义的流程进行安装。

---

## 常见问题

- 如果脚本有语法错误，NSIS编译器会在输出窗口提示错误信息，请根据提示修改脚本。
- 如果需要在命令行中指定输出目录，可以在脚本中修改 `Outfile` 路径，或用 `/D` 参数传递宏。

---

## 参考命令

```sh
# 编译NSIS脚本
makensis MyApplicationScript.nsi

# 带宏参数编译（可选）
makensis /DMyVar=Value MyApplicationScript.nsi
```

---

这样你就可以通过NSIS脚本快速生成自己的打包安装程序了！
