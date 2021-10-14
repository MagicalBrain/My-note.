# Wix如何设置安装到64位程序

一般Windows 64位的程序会安装在：
```bash
C:\Program Files
```

32位程序则是在
```bash
C:\Program Files (x86)
```

Wix打包出来的按照程序，一般默认是安装在`C:\Program Files (x86)`

如果要设置安装在`C:\Program Files`，则还需额外的设置：

1、设置Package Platform
```xml
<Package InstallerVersion="200" Compressed="yes" InstallScope="perMachine" Platform="x64"/>
```

2、
所有的Component都要设置 `Win64="yes"`

```xml
<?xml version="1.0" encoding="UTF-8"?>
<Wix xmlns="http://schemas.microsoft.com/wix/2006/wi">
  <!-- 设置项目基本信息 -->
  <!-- Name：项目名称 -->
	<Product Id="*" Name="HYDeviceSDKSetup" Language="1033" Version="1.0.0.0" Manufacturer="HP Inc." UpgradeCode="bcea150c-f90d-4359-9a1c-f9c1f96a3436">
        <!-- 设置：Platform="x64" -->
		<Package InstallerVersion="200" Compressed="yes" InstallScope="perMachine" Platform="x64"/>

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
			<Directory Id="ProgramFiles64Folder">
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
      <Component Id="IncludeHeader" Guid="{307EEAF4-94E2-4902-8E3D-E769600D7BE7}" Win64="yes">
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
      <Component Id="SourceFile" Guid="{DDAA069A-1CC1-4A88-89E6-613E9976BC3F}" Win64="yes">
        <File Name="HYSensorPlugin.cpp" src="./src/device/HYSensorPlugin.cpp"/>
        <File Name="HYWebSocketPlugin.cpp" src="./src/device/HYWebSocketPlugin.cpp"/>
      </Component>
    </ComponentGroup>
	</Fragment>
</Wix>
```
