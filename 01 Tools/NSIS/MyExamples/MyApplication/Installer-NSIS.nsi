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
    SetOutPath $INSTDIR\Release

    ; 设置安装过程的UI界面
    SetSilent silent

    ; 创建快捷方式
    CreateDirectory $SMPROGRAMS\MyApplication
    CreateShortCut $SMPROGRAMS\MyApplication\MyApplication.lnk $INSTDIR\MyApplication.exe

    ; 完成安装
    MessageBox MB_OK "Installation completed successfully."
SectionEnd

Function .onInit
    StrCpy $INSTALL_OPTION "1"
    StrCpy $INSTALL_LOCATION $PROGRAMFILES
FunctionEnd
