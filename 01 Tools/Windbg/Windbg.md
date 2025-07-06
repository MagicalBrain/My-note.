# Windbg

笔记更新请移步 [Cpp-Advanced-Notes]()

----

Windows平台的强大的调试工具
Windbg之于Windows，就如GDB之于Linux

## Windbg分析bug的两种方式

### 静态分析

静态调试生成的dump文件

### 动态分析

在目标进程运行的过程中动态调试，也可以导出dump文件事后分析

## dump文件分类

### mini dump文件

文件小，几个MB左右

### mini dump生成的方法

### full dump文件

文件比较大，文件大小接近目标进程所占的虚拟内存的大小

### full dump生成的方法

可以在进程运行的时候直接使用任务管理器来进行导出：

打开任务管理器 -> 详细信息 -> 右击目标进程 -> 创建转储文件 -> 打开转储文件所在位置

## dump文件生成的方法

### 调用Windows系统api

调用 SetUnhandledExceptionFilter 设置异常回调，在回调函数中调用 MiniDumpWriteDump 生成dump文件
这种方式需要给每个线程挂载异常回调函数

```cpp
void CreateDump(struct_EXCEPTION_POINTERS*pExceptionPointers)
{
    //生成minicrashdump
    CString sFile:
    char szCrashReportPath[MAX_PATH]:
    sprintf（szCrashReportPath，"%s\\CrashReport"，A2cT(getenv("TEMP"))):
    if（!PathFileExists（szCrashReportPath）)
    {
        CreateDirectory(szCrashReportPath,NULL):
    }


    SYSTEMTIME time;
    ::GetLocalTime（&time):
    //Create the dump file name
    USESCONVERSION:
    sFile.Format（_T("%s\\CrashReport\\%s_%04d-%02d-%02d-%02d-%02d-%02d-%03d_unhandle.dmp"),
        A2CT(getenv("TEMP")),_T("TestDlg"),
        time.wYear,time.wMonth,time.wDay,time.wHour,time.wMinute,time.wSecond,time.wMilliseconds);

    HANDLEhDumpFile;
    hDumpFile= CreateFile(sFile,GENERIC_READ GENERIC_WRITE,
        FILE_SHARE_WRITEFILE_SHARE_READ,O,CREATE_ALWAYS，O,O);

    MINIDUMP_EXCEPTION_INFORMATIONExpParam;
    ExpParam.ThreadId=GetCurrentThreadId();
    ExpParam.ExceptionPointers=pExceptionPointers:
    ExpParam.ClientPointers=TRUE:

    MINIDUMP_TYPE MiniDumpWithDataSegs=(MINIDUMP_TYPE)(MiniDumpNorma
        | MiniDumpWithHandleData
        | MiniDumpWithUnloadedModules
        | MiniDumpWithIndirectlyReferencedMemory
        | MiniDumpScanMemory
        | MiniDumpWithProcessThreadData
        | MiniDumpWithThreadInfo);

    BOOLbMiniDumpSuccessful=FALSE
    bMiniDumpSuccessful=MiniDumpWriteDump(GetCurrentProcess()，GetCurrentProcessId(),
        hDumpFile,MiniDumpWithDataSegs,&ExpParam,NULL,NULL);

    return;
}
```

或：

```cpp
// unhandled exception callback set with SetUnhandledExceptionFilter()
static LONG WINAPI SEHUnhandledExceptionFilter(EXCEPTION_POINTERS* pExInfo)
{
        HANDLE hDumpFile;
        hDumpFile = CreateFile(sFile, GENERIC_READ | GENERIC_WRITE,
                FILE_SHARE_WRITE | FILE_SHARE_READ, 0, CREATE_ALWAYS, 0, 0);
 
        MINIDUMP_EXCEPTION_INFORMATION ExpParam;
        ExpParam.ThreadId = GetCurrentThreadId();
        ExpParam.ExceptionPointers = pExceptionPointers;
        ExpParam.ClientPointers = TRUE;
 
        MINIDUMP_TYPE MiniDumpWithDataSegs = (MINIDUMP_TYPE)(MiniDumpNormal
                | MiniDumpWithHandleData
                | MiniDumpWithUnloadedModules
                | MiniDumpWithIndirectlyReferencedMemory
                | MiniDumpScanMemory
                | MiniDumpWithProcessThreadData
                | MiniDumpWithThreadInfo);
 
        BOOL bMiniDumpSuccessful = FALSE;
        bMiniDumpSuccessful = MiniDumpWriteDump(GetCurrentProcess(), GetCurrentProcessId(),
                hDumpFile, MiniDumpWithDataSegs, &ExpParam, NULL, NULL);
        
    return EXCEPTION_EXECUTE_HANDLER;
}
 
// Install structured exception handler
LPTOP_LEVEL_EXCEPTION_FILTER pOldExceptionFilter = SetUnhandledExceptionFilter( SEHUnhandledExceptionFilter );
```

### 使用异常捕获库

#### asd

#### CrashRpt库

google开源的


该库尝试给每个模块的线程挂载异常回调函数，但实现方式有缺陷，有些线程没有挂载上。后来使用微软的detours开源代码对该库进行改进

#### Chrome浏览器开源代码中的Breakpad/gBreakpad/Crashpad

Breakpad是一个跨平台的异常捕获库，在捕获到异常时自动生成包含异常上下文的dump文件。
目前使用Breakpad的有谷歌浏览器，火狐，谷歌的Picasa，卡米诺，谷歌地球，和其他项目

## 参考链接

[b站视频](https://www.bilibili.com/video/BV1kN411y7NS/?spm_id_from=333.337.search-card.all.click&vd_source=609ea3e03254fd4423dd28a470f51108)
