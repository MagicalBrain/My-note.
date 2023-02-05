# C#格式化输出

## Console.WriteLine()

```csharp
MaxCompletionPortThreads = 10;
Console.WriteLine(
    $"最大可用辅助线程数目为{MaxCompletionPortThreads}，最大可用异步 I/O 线程数目为{MaxCompletionPortThreads}"
);
```

```csharp
Console.WriteLine(
    @"设置线程池中辅助线程的最大数目为{0}， 线程池中异步 I/O 线程的最大数目为{1}同时运行30个长时运行线程，每个线程中运行一个同步方法，看是否30个线程是否都能运行。", 
    MaxWorkerThreads, 
    MaxCompletionPortThreads
);
```
