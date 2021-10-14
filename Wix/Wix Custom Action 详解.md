# Wix Custom Action 详解

[官方链接][官方链接]

[官方链接]:https://wixtoolset.org/documentation/manual/v3/customactions/

WiX工具集包含几个自定义操作来处理配置资源，如`Internet Information Services web sites`和`virtual directories`、`SQL Server databases`和脚本、用户帐户、文件共享等。这些自定义操作在WiX扩展中提供。

The WiX toolset contains several custom actions to handle configuring resources such as Internet Information Services web sites and virtual directories, SQL Server databases and scripts, user accounts, file shares, and more. These custom actions are provided in WiX extensions.

To get started using standard custom actions, see the [Using Standard Custom Actions topic][Using Standard Custom Actions topic].

[Using Standard Custom Actions topic]:https://wixtoolset.org/documentation/manual/v3/customactions/using_standard_customactions.html

For information about specific types of standard custom actions, see the following topics:

FileShare custom action (located in WixUtilExtension) - create and configure file shares.
Internet shortcut custom action (located in WixUtilExtension) - create shortcuts that point to Web sites.
OSInfo custom actions (located in WixUtilExtension) - set properties for OS information and standard directories that are not provided by default by Windows Installer.
Performance Counter custom action (located in WixUtilExtension) - install and uninstall performance counters.
Quiet Execution custom action (located in WixUtilExtension) - launch console executables without displaying a window.
Secure Objects custom action (located in WixUtilExtension) - secure (using ACLs) objects that the LockPermissions table cannot.
Service Configuration custom action (located in WixUtilExtension) - configure attributes of a Windows service that the ServiceInstall table cannot.
ShellExecute custom action (located in WixUtilExtension) - launch document or URL targets via the Windows shell.
User custom actions (located in WixUtilExtension) - create and configure new users.
WixDirectXExtension - custom action that can be used to check the DirectX capabilities of the video card on the system.
WixExitEarlyWithSuccess (located in WixUtilExtension) - custom action that can be used to exit setup without installing the product. This can be useful in some major upgrade scenarios.
WixFailWhenDeferred (located in WixUtilExtension) - custom action that can be used to simulate installation failures to test rollback scenarios.
WixFirewallExtension - Firewall custom action that can be used to add exceptions to the Windows Firewall.
WixGamingExtension - Gaming custom action that can be used to add icons and tasks to Windows Game Explorer.
WixIIsExtension - Internet Information Services (IIS) custom actions that can be used to create and configure web sites, virtual directories, web applications, etc.
WixNetFxExtension - custom action to generate native code for .NET assemblies; properties to detect .NET Framework install state and service pack levels.
WixSqlExtension - SQL Server custom actions that can be used to create databases and execute SQL scripts and statements.
WixVSExtension - custom action to register help collections and Visual Studio packages; properties to detect install state and service pack levels for various Visual Studio editions.
XmlFile custom action (located in WixUtilExtension) - configure and modify XML files as part of your installation package.

## 参考链接

https://www.cnblogs.com/endv/p/6828668.html
