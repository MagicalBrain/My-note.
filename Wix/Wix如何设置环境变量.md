# Wix如何设置环境变量

平时我们使用别的软件或者SDK的时候，有时会用到安装程序。
这时我们就开心了，因为只要按照里面的提示走，那么安装多半会很顺利的。

一般在SDK的安装程序（例如opencv）里会有设置环境变量的选项。

## 示例代码

```xml
<?xml version="1.0" encoding="UTF-8"?>
<Wix xmlns="http://schemas.microsoft.com/wix/2006/wi">
    <Product Id="a960cf35-0779-43e8-923b-35638f2bfc42" Name="Minimal" Language="2052" Version="1.0.0.0" Manufacturer="Geffzhang"
           UpgradeCode="0bf7e020-5bbd-4a06-8e39-e715999edbf5">
        <Package InstallerVersion="200" Compressed="yes" Description="Minimal Windows Installer Sample"
             Comments="This installer database contains the logic and data required to install Minimal Windows Installer Sample."/>
 
        <Media Id="1" Cabinet="media1.cab" EmbedCab="yes" />
    
    <!-- 注意1 -->
    <Property Id="EnableEV" Value="1"></Property>
    
        <Directory Id="TARGETDIR" Name="SourceDir">
            <Directory Id="ProgramFilesFolder">
                <Directory Id="INSTALLLOCATION" Name="Minimal">
          <Component Id="Component1"
                     Guid="{1781A625-8ACB-45E7-A8BA-219D81760B2E}">
            <CreateFolder />
            
            <!-- 注意2 -->
            <Environment Id="TestMinVar"
                         Action="set"
                         Part="all"
                         Name="MinEnvVar"
                         Permanent="no"
                         System="yes"
                         Value="8" />
          </Component>
                </Directory>
            </Directory>
        </Directory>
 
    
        <Feature Id="ProductFeature" Title="Minimal" Level="1">
      <ComponentRef Id="Component1" />
        </Feature>
    
    <!-- 注意3 -->
    <InstallExecuteSequence>
      <WriteEnvironmentStrings>EnableEV=1</WriteEnvironmentStrings>
      
    </InstallExecuteSequence>

    <!-- 给安装程序添加UI界面的 -->
    <Property Id="WIXUI_INSTALLDIR" Value="INSTALLLOCATION" />
    <UIRef Id="WixUI_InstallDir" />
 
 
  </Product>
</Wix>
```

## 添加环境变量

1、设置`Property`元素

2、设置`Environment`元素

3、设置`InstallExecuteSequence`元素

### 添加系统环境变量的示例程序

```xml
<?xml version="1.0" encoding="UTF-8"?>
<Wix xmlns="http://schemas.microsoft.com/wix/2006/wi">
  <!-- 设置项目基本信息 -->
  <!-- Name：项目名称 -->
	<Product Id="*" Name="HYDeviceSDKSetup" Language="1033" Version="1.0.0.0" Manufacturer="HP Inc." UpgradeCode="bcea150c-f90d-4359-9a1c-f9c1f96a3436">
		<Package InstallerVersion="200" Compressed="yes" InstallScope="perMachine" />

		<MajorUpgrade DowngradeErrorMessage="A newer version of [ProductName] is already installed." />
		<MediaTemplate />

		<Feature Id="ProductFeature" Title="CompleteSetup" Level="1">
			<ComponentGroupRef Id="ProductComponents" />

      <ComponentGroupRef Id="IncludeComponents" />

      <ComponentGroupRef Id="SrcComponents" />
		</Feature>

    <InstallExecuteSequence>
      <WriteEnvironmentStrings>EnableEV=1</WriteEnvironmentStrings>

    </InstallExecuteSequence>
	</Product>
  
	<Fragment>

    <Property Id="EnableEV" Value="1"></Property>
    
		<Directory Id="TARGETDIR" Name="SourceDir">
			<Directory Id="ProgramFilesFolder">
        <Directory Id="INSTALLFOLDER" Name="HYDeviceSDK">
          <Directory Id="INCLUDEFOLDER" Name="include"/>

          <Directory Id="SRCFOLDER" Name="src"/>
          
        </Directory>
			</Directory>
		</Directory>
	</Fragment>

	<Fragment>
		<ComponentGroup Id="ProductComponents" Directory="INSTALLFOLDER">
			<!-- TODO: Remove the comments around this Component element and the ComponentRef below in order to add resources to this installer. -->
			<!-- <Component Id="ProductComponent"> -->
				<!-- TODO: Insert files, registry keys, and other resources here. -->
			<!-- </Component> -->
		</ComponentGroup>

    <ComponentGroup Id="IncludeComponents" Directory="INCLUDEFOLDER">
      <Component Id="IncludeHeader" Guid="{307EEAF4-94E2-4902-8E3D-E769600D7BE7}">
        <File Name="HYSensorPlugin.h" src="./include/device/HYSensorPlugin.h"/>
        <File Name="HYWebSocketPlugin.h" src="./include/device/HYWebSocketPlugin.h"/>

        <Environment Id="TestMinVar"
                         Action="set"
                         Part="all"
                         Name="MinEnvVar"
                         Permanent="no"
                         System="yes"
                         Value="8" />
        
      </Component>
    </ComponentGroup>

    <ComponentGroup Id="SrcComponents" Directory="SRCFOLDER">
      <Component Id="SourceFile" Guid="{DDAA069A-1CC1-4A88-89E6-613E9976BC3F}">
        <File Name="HYSensorPlugin.cpp" src="./src/device/HYSensorPlugin.cpp"/>
        <File Name="HYWebSocketPlugin.cpp" src="./src/device/HYWebSocketPlugin.cpp"/>
      </Component>
    </ComponentGroup>
	</Fragment>
</Wix>
```

安装后查看环境变量如图：

![](asset/env-setting.png)

卸载后可删除环境变量：

![](asset/env-uninstalled.png)

### 添加Path环境变量的示例程序

```xml

```

**注意**：
```xml
<Environment Id="TestPathVar"
                         Action="set"
                         Part="last"
                         Name="Path"
                         Permanent="no"
                         System="yes"
                         Value="8" />
```

其中的`Environment`元素的`Part`字段一定要是`"last"`否则会将原来Path里的所有内容覆盖掉，导致原来安装的环境变量全部失效。

## Environment 元素详解

### Action

即设置环境变量的操作

1. create:
   1. 如果变量不存在就创建该变量
   2. 安装期间设置改变量
   3. 如果该变量已存在则不对其做任何操作
   4. 如果使用该操作方式则没有Part字段设置
2. set
   1. 如果变量不存在就创建该变量
   2. 安装期间设置改变量
   3. 如果该变量已存在则修改其值
3. remove
   1. 安装期间删除该变量
   2. 只有当变量名和变量的值都相同时才删除
   3. 如果变量值为空，则无论该变量为何值都将其删除

create
Creates the environment variable if it does not exist, then set it during installation. This has no effect on the value of the environment variable if it already exists.
set
Creates the environment variable if it does not exist, and then set it during installation. If the environment variable exists, set it during the installation.
remove
Removes the environment variable during an installation. The installer only removes an environment variable during an installation if the name and value of the variable match the entries in the Name and Value attributes. If you want to remove an environment variable, regardless of its value, do not set the Value attribute.

### Part

即环境变量操作开始的地方，或者直接覆盖

1. all
   1. 默认为此值，对环境变量操作的时候会对整个环境变量进行操作
   2. 如果已有值则全部覆盖
2. first
   1. 对环境变量操作的时候会从环境变量最前面开始进行操作
   2. 如果已有值则在最前面添加
3. last
   1. 对环境变量操作的时候会从环境变量最后面开始进行操作
   2. 如果已有值则在最后面添加

all
This value is the entire environmental variable. This is the default.
first
This value is prefixed.
last
This value is appended.

### Name

### Permanent

该值决定了设置了环境变量在运行卸载程序后是否会被移除。

1. yes
   1. 运行卸载程序后不会被移除
2. no
   1. 运行卸载程序后会被移除

Specifies that the environment variable should not be removed on uninstall.

### System

该值决定了设置了环境变量是系统变量还是用户变量。

1. yes
   1. 设置的是系统变量
2. no
   1. 设置的是用户变量

Specifies that the environment variable should be added to the system environment space. The default is 'no' which indicates the environment variable is added to the user environment space.

### Value

设置该环境变量的值
