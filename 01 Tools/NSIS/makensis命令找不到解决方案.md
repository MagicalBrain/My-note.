# makensis命令找不到解决方案

如果makensis命令找不到如何解决？

### 解决方法

1. **确认已安装NSIS**
   - 首先确保你已经正确安装了NSIS。可以在[NSIS官网](https://nsis.sourceforge.io/Download)下载安装包并完成安装。

2. **检查环境变量**
   - 安装NSIS后，`makensis.exe` 通常位于 `C:\Program Files (x86)\NSIS` 或 `C:\Program Files\NSIS` 目录下。
   - 需要将该目录添加到系统的 `PATH` 环境变量中。
   - 操作步骤（以Windows 10/11为例）：
     1. 右键“此电脑” → 属性 → 高级系统设置 → 环境变量
     2. 在“系统变量”中找到 `Path`，点击“编辑”
     3. 新增一行，填入 NSIS 的安装路径（如 `C:\Program Files (x86)\NSIS`）
     4. 确认保存，重启命令行窗口

3. **命令行窗口重启**
   - 修改环境变量后，需关闭并重新打开命令行窗口（CMD/PowerShell/Terminal），否则新设置不会生效。

4. **直接指定完整路径**
   - 也可以在命令行中直接使用完整路径运行：
     ```sh
     "C:\Program Files (x86)\NSIS\makensis.exe" MyScript.nsi
     ```

5. **验证安装**
   - 在命令行输入 `makensis -VERSION`，如果能显示版本号说明配置成功。

---

这样就可以解决 `makensis` 命令找不到的问题。如果还有问题，建议重新安装NSIS并确保安装路径无中文或特殊字符。
