<!--
 * @Author: MB's X13 374870361@qq.com
 * @Date: 2023-12-26 16:43:43
 * @LastEditors: MB's X13 374870361@qq.com
 * @LastEditTime: 2023-12-26 16:44:48
 * @Description: 
-->
# 运行PowerShell脚本报错

```bash
.\Find_All_Dlls.ps1
.\Find_All_Dlls.ps1 : 无法加载文件 F:\hrl\MyNotes\04 Script\PowerShell脚本\Find_All_Dlls.ps1，因为在此系统上禁止运行脚
本。有关详细信息，请参阅 https:/go.microsoft.com/fwlink/?LinkID=135170 中的 about_Execution_Policies。
所在位置 行:1 字符: 1
+ .\Find_All_Dlls.ps1
+ ~~~~~~~~~~~~~~~~~~~
    + CategoryInfo          : SecurityError: (:) []，PSSecurityException
    + FullyQualifiedErrorId : UnauthorizedAccess
```

## 解决办法

这个错误是由于 PowerShell 的执行策略（Execution Policy）限制导致的。默认情况下，PowerShell 限制运行未签名的脚本。

你可以尝试以下几种方法来解决这个问题：

1. 修改执行策略：在管理员权限的 PowerShell 窗口中执行以下命令来修改执行策略为 `RemoteSigned`，允许运行本地未签名的脚本：

   ```powershell
   Set-ExecutionPolicy -ExecutionPolicy RemoteSigned -Scope CurrentUser
   ```

   然后再次尝试运行脚本。

2. 临时解决方案：在 PowerShell 窗口中使用 `-ExecutionPolicy Bypass` 参数来临时绕过执行策略限制运行脚本：

   ```powershell
   PowerShell -ExecutionPolicy Bypass -File .\Find_All_Dlls.ps1
   ```

   这将临时解除执行策略限制，并允许运行脚本。

3. 签名脚本：使用有效的数字证书对脚本进行签名。这将使脚本被认为是受信任的，并且可以在任何执行策略下运行。有关如何签名脚本的详细信息，请参阅 PowerShell 文档中的相关章节。

请注意，修改执行策略可能需要管理员权限，而且可能受到组织或计算机策略的限制。在进行任何更改之前，请确保你了解组织或计算机策略，并遵循相应的安全规定。
