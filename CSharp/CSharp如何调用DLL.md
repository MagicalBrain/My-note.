# CSharp如何调用DLL

## 调用DLL遇到的错误

System.TypeInitializationException
  HResult=0x80131534
  Message=“HYDeviceCSharp.Test”的类型初始值设定项引发异常。
  Source=HYDeviceCSharpAPI
  StackTrace:
   at HYDeviceCSharp.Test.test() in C:\Users\37487\Documents\hrl\HYDeviceCSharpAPI\HYDeviceCSharp\HYTest.cs:line 34
   at HYDeviceCSharp.Program.Main(String[] args) in C:\Users\37487\Documents\hrl\HYDeviceCSharpAPI\HYDeviceCSharp\Program.cs:line 16

内部异常 1:
TypeLoadException: 未能从程序集“HYDeviceCSharpAPI, Version=1.0.0.0, Culture=neutral, PublicKeyToken=null”中加载类型“HYDeviceCSharpAPI.HYSensor”。

~~这个错误目前未有解决方案。~~
目前只能重新创建一个解决方案了。
