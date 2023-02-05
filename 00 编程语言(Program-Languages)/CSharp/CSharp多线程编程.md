# CSharp多线程编程

内容主要来自《C# 核心技术指南》 第十四章

## 线程的基本操作

### 创建线程

创建线程之前得先定义一个线程绑定的函数或方法，因为创建线程的时候需要绑定一个函数。例如：

```csharp
// 创建一个函数
        static void WriteY()
        {
            for (int i = 0; i < 10; ++i)
                Console.WriteLine("Y");
        }

        static public void ThreadDemo()
        {
            // 创建一个线程，并绑定线程函数
            Thread t = new Thread(WriteY);

            t.Start();
            
            for (int i = 0; i < 10; ++i)
                Console.WriteLine("X");

        }
```

在单核计算机上，操作系统会为每一个线程划分时间片（Windows系统的典型值为20毫秒）来模拟并发执行。
因此上述代码会出现连续的x和y。
而在一个多核心的机器上，两个线程可以并行执行（会和机器上其他执行的进程进行竞争）.
虽然我们还是会得到连续的x和y，但这却是由于Console处理并发请求的机制导致的。

线程一旦启动，其IsAlive属性就会返回true，直至线程停止。
当Thread的构造函数接收的委托执行完毕之后，线程就会停止。
线程停止之后就无法再启动了。

每一个线程都有一个Name属性用作调试用途。
这个属性在Visual Studio中尤其有用，因为线程的名称会显示在“Thread”窗口和“DebugLocation”工具栏上。
线程的名称只能够设置一次，试图修改线程的名称会抛出异常。

静态属性Thread.CurrentThread将返回当前正在执行的线程：
```csharp
Console.WriteLine(Thread.CurrentThread);
```

### 等待线程休眠

```csharp
Thread.Join()
```

### 暂停线程的操作

```csharp
Thread.Sleep()
```

### 线程的阻塞

当线程由于特定原因暂停执行，那么它就是阻塞的。例如，调用Sleep休眠或者Join等待其他线程执行结束。阻塞的线程会立刻交出它的处理器时间片，并从此开始不再消耗处理器时间。直至阻塞条件结束。可以使用ThreadState属性测试线程的阻塞状态：

```csharp
bool blocked = (t.ThreadState & ThreadState.WaitSleepJoin) != 0;
```

ThreadState限定为以下四个有用的值之一：Unstarted、Running、WaitSleepJoin、Stopped：

```csharp

```

ThreadState属性适用于诊断调试工作，但是不适合实现同步。因为线程的状态可能在测试ThreadState和获取这个信息的时间段内发生变化。当线程被阻塞或者解除阻塞时，操作系统就会进行一次上下文切换（context switch）。这会导致细小的开销，一般在1到2毫秒左右。

## I/O密集和计算密集

如果一个操作的绝大部分时间都在等待事件的发生，则称为I/O密集，例如下载网页或者调用Console.ReadLine。
（I/O密集操作一般都会涉及输入或者输出，但是这并非硬性要求。例如Thread.Sleep也是一种I/O密集的操作）。

而相反的，如果操作的大部分时间都用于执行大量的CPU操作，则称为计算密集。

### 阻塞与自旋

I/O密集操作主要表现为以下两种形式：
要么在当前线程同步进行等待，直至操作完成（例如Console.ReadLine、Thread.Sleep以及Thread.Join）；
要么异步进行操作，在操作完成的时候或者之后某个时刻触发回调函数（之后将详细介绍）。

同步的I/O密集操作的大部分时间都花费在阻塞线程上，但是也可能在一个定期循环中自旋：

```csharp
while (DateTime.Now < nextStartTime)
    Thread.Sleep(100);
```

虽然有更好的办法实现这种效果（例如使用定时器或者使用信号发送结构），但另外一种选择是令线程持续性自旋：

```csharp
while (DateTime.Now < nextStartTime)
```

一般来说，上述做法非常浪费处理器时间。因为CLR和操作系统都会认为这个线程正在执行重要的运算，因此就会为其分配相应的资源。因此从效果上来说我们将一个I/O密集的操作转变成了一个计算密集型操作

自旋与阻塞有一些细微的差别。首先，非常短暂的自旋在条件可以很快得到满足的场景（例如几毫秒）下是非常高效的，因为它避免了上下文切换带来的延迟和开销。.NET Framework提供了一些特殊的辅助方法和类来进行这一操作，请参见http://albahari.com/threading/的SpinLockand SpinWait。

其次，阻塞并非零开销。这是因为每一个线程在存活时会占用1MB的内存，并对CLR和操作系统带来持续性的管理开销。因此，阻塞可能会给繁重的I/O密集型程序（例如要处理成百上千的并发操作）带来麻烦。因此，这些程序更适于使用回调的方式，在等待时完全解除这些线程。我们将在后面讨论异步模式的时候介绍这种方法。

## 异常处理

## 前台线程与后台线程

一般情况下，显式创建的线程称为前台线程（Foreground thread）。
只要有一个前台线程还在运行，应用程序就仍然保持运行状态。

而后台线程（background thread）则不然。
当所有前台线程结束时，应用程序就会停止，且所有运行的后台线程也会随之终止。

线程的前台/后台状态和线程的优先级（执行时间的分配）无关。可以使用线程的IsBackground属性来查询或修改线程的前后台状态：

```csharp

```

## 富客户端应用程序的线程

## 任务Task

线程是创建并发的底层工具，因此它有一定的局限性。
特别是：
1. 虽然在线程启动时不难向其中传递数据，但是当线程Join后却难以从中得到“返回值”。通常不得不创建一些共享字段（来得到“返回值”）。此外，捕获和处理线程中操作抛出的异常也是非常麻烦的。· 
2. 在线程完成之后，就无法再次启动它，相反只能够将其Join（并阻塞当前操作线程）。这些局限性会影响细粒度并发性的实现。换言之，这种方式难以将小的并发组合成为大的并发操作（这对于异步编程而言非常重要，后面的章节将对此进行介绍），并会增加手动同步处理（例如使用锁、信号发送等）的依赖，而且很容易造成问题。

Task类型可以解决所有这些问题。
与线程相比，Task是一个更高级的抽象概念，它代表了一个并发操作，而该操作并不一定依赖线程来完成。
Task是可以组合（compositional）的（你可以将它们通过延续（continuation）操作串联在一起）。它们可以使用线程池减少启动延迟，也可以通过TaskCompletionSource采用回调的方式避免多个线程同时等待I/O密集型操作。

Task类型是Framework 4.0时，作为并行编程库的组成部分引入的。然而它们后来经历了许多改进（通过使用awaiter），从而在常见的并发场景中发挥了越来越大的作用。

Task类型也是C#异步功能的基础类型。

## Task的基本操作

### 创建Task

**无返回值的方法**：

1、
```csharp
static public void CreateTask1()
{
    var t1 = new Task(
        () => {
            Console.WriteLine("任务开始工作……");
            //模拟工作过程, 休眠5秒
            Thread.Sleep(5000);
        }
    );

    t1.Start();
            
    Task.WaitAll(t1);
}
```

2、

### 启动Task

```csharp
Task.Run(
    () => Console.WriteLine("Run the Task.");
);
```

Task默认使用线程池中的线程，它们都是后台线程。这意味着当主线程结束时，所有的Task也会随之停止。
因此，要在控制台应用程序中运行这些例子，必须在启动Task之后阻塞主线程（例如在Task对象上调用Wait，或者调用Console.ReadLine()方法）

```csharp
static void Main() {
    Task.Run(
        () => Console.WriteLine("Run the Task.");
    );
    Console.Read();
}
```

### Task的阻塞

**Wait方法**

```csharp
static void Main() {
    Task task = Task.Run(
        () => {
            Thread.Sleep(2000);
            Console.WriteLine("Run the Task.");
        }
    );
    Console.WriteLine(task.IsCompleted);    // is false

    task.Wait();
    Console.WriteLine(task.IsCompleted);    // is true
}
```

### 长任务 LongTask

默认情况下，CLR会将Task运行在线程池线程上，这种线程非常适合执行短小的计算密集的Task。
如果要执行长时间阻塞的操作（如上面的例子）则可以按照以下方式避免使用线程池线程

```csharp
static void Main() {
    Task task = Task.Run(
        () => {
            Thread.Sleep(2000);
            Console.WriteLine("Run the Task.");
        },
        TaskCreationOptions.LongRunning
    );
   
}
```

在线程池上运行一个长时间执行的Task并不会造成问题.
但是如果要并行运行多个长时间运行的Task（特别是会造成阻塞的Task），则会对性能造成影响。
在这种情况下，相比于使用TaskCreationOptions.LongRunning而言，更好的方案是：

1. 如果运行的是I/O密集型Task，则使用TaskCompletionSource和异步函数（asynchronous functions）通过回调函数而非使用线程实现并发性。
2. 如果Task是计算密集型，则使用生产者/消费者队列可以控制这些Task造成的并发数量，避免出现线程和进程饥饿的问题（参见23.7节）。

### Task的返回值

Task有一个泛型子类`Task<TResult>`，它允许Task返回一个值。如果在调用Task. Run时传入一个`Func<TResult>`委托（或者兼容的Lambda表达式）替代Action就可以获得一个`Task<TResult>`对象：

```csharp
static void Main() {
    Task<int> task = Task.Run(
        () => {
            Thread.Sleep(2000);
            Console.WriteLine("Run the Task.");
            return 3;
        },
    );
}
```

此后，通过查询Result属性就可以获得Task的返回值。如果当前Task还没有执行完毕，则调用该属性会阻塞当前线程，直至Task结束。

```csharp
static void Main() {
    Task<int> task = Task.Run(
        () => {
            Thread.Sleep(2000);
            Console.WriteLine("Run the Task.");
            return 3;
        },
    );

    int re = task.Result;   // Blocks if not already finished
    Console.WriteLine(re);
}
```

#### 实例

创建了一个Task，它使用LINQ计算前三百万个整数（从2开始）中素数的个数：

```csharp
static void Main() {
    Task<int> task = Task.Run(
        () => Enumerable.Range(2, 3000000).Count(
            n => Enumerable.Range(2, (int)Math.Sqrt(n) - 1).All (
                i => n % i > 0
            )
        )
    );

    Console.WriteLine("Task running...");
    Console.WriteLine("The answer is: " + task.Result);
}
```

### Task的异常处理

任务可以方便地传播异常，这和线程是截然不同的。因此，如果任务中的代码抛出一个未处理异常（换言之，如果你的任务出错（fault）），那么调用Wait()或者访问`Task<TResult>`的Result属性时，该异常就会被重新抛出

```csharp
// Task 的异常处理
static void Main() {
    Task task = Task.Run(
        () => throw null
    );
    
    try
    {
        task.Wait();
    }
    catch (AggregateException error)
    {
        if (error.InnerException is NullReferenceException)
            Console.WriteLine("Catch the exception of null.");
        else
            throw;
    }
}
```

### Task awaiter 延续

调用任务的GetAwaiter方法将返回一个awaiter对象。这个对象的OnCompleted方法告知先导（antecedent）任务（primeNumberTask）当它执行完毕（或者出现错误）时调用一个委托。将延续附加到一个业已执行完毕的任务上是完全没有问题的，此时，延续的逻辑将会立即执行。

```csharp
static void Main() {
    Task<int> task = Task.Run(
                () => Enumerable.Range(2, 3000000).Count(
                    n => Enumerable.Range(2, (int)Math.Sqrt(n) - 1).All(
                        i => n % i > 0
                    )
                )
            );

            var awaiter = task.GetAwaiter();
            awaiter.OnCompleted(
                () =>
                {
                    int re = awaiter.GetResult();
                    Console.WriteLine(re);
                }
            );

            Console.WriteLine("Task running...");
            Console.WriteLine("The answer is: " + task.Result);
}
```

### TaskCompletionSource类

前面介绍了如何使用Task.Run创建一个任务，并在线程池线程（或者非线程池线程）上运行特定委托。而另一种创建任务的方法是使用TaskCompletionSource。

### Task.Delay方法

我们刚刚实现的Delay方法非常实用，实际上它也是Task类的一个静态方法：

```csharp
Task.Delay(5000).GetAwaiter().OnCompleted(
    () => Console.WriteLine(42)
);

Task.Delay(5000).ContinueWith(
    ant => Console.WriteLine(42)
);
```

Task.Delay是Thread.Sleep的异步版本。

## 同步与异步

**同步操作**
（synchronous operation）先完成其工作再返回调用者。

**异步操作**
（asynchronous operation）的大部分工作则是在返回给调用者之后才完成的。

我们平常编写和调用的大多数方法都是同步方法。例如，`Thread.Sleep`。
而异步方法则不常见。并且异步调用需要==并发创建==。
因为工作对于调用者来说是并行的。
异步方法通常都会非常迅速（甚至会立即）返回给调用者。
因此它们也称为非阻塞方法。

到目前为止，我们学习的异步方法都是通用方法：
1. Thread.Start
2. Task.Run
3. 给任务附加延续的方法

继续前面计算质数的例子：

```csharp
 static int GetPrimesCount(int start, int count)
        {
            return
                ParallelEnumerable.Range(start, count).Count(
                    n => Enumerable.Range(2, (int)Math.Sqrt(n) - 1).All(i => n % i > 0));
        }

static public void DisplayPrimeCounts()
        {
            for (int i = 0; i < 10; i++)
                Console.WriteLine(GetPrimesCount(i * 1000000 + 2, 1000000) +
                    " primes between " + (i * 1000000) + " and " + ((i + 1) * 1000000 - 1));
            Console.WriteLine("Done!");
        }
```

```csharp
//var awaiter = GetAwaiter();
            // 为计算创建粗粒度的并发性
            Task.Run(
                () => DisplayPrimeCounts()
            );
```

相反，如果采用细粒度的并发性，我们就需要编写异步的GetPrimesCount方法：

```csharp
static Task<int> GetPrimesCountAsync(int start, int count)
{
    return
        Task.Run(
            () =>
            ParallelEnumerable.Range(start, count).Count(
            n => Enumerable.Range(2, (int)Math.Sqrt(n) - 1).All(i => n % i > 0))
        );
}
```

```csharp
 // Task 计算前三百万个数中质数的个数 使用了asybc 异步编程技术
async static public Task PrimerNumberTaskasync()
{
    for (int i = 0; i < 10; i++)
        Console.WriteLine(await GetPrimesCountAsync(i * 1000000 + 2, 1000000) +
            " primes between " + (i * 1000000) + " and " + ((i + 1) * 1000000 - 1));
        Console.WriteLine("Done!");
}
```

```csharp
 static void Main(string[] args)
{
    /* ------ 测试线程的基本操作 ----- */
    TaskUsages.PrimerNumberTaskasync();
    for (int i = 0; i < 1000; i++)
        Console.WriteLine(Thread.CurrentThread.Name);
    Console.ReadKey();
}
```

## C#的异步函数

### 等待

```csharp
var result = await expression;
statement(S);
```

编译器会将上述代码转换为下面具有相同功能的代码：

```csharp
var awaiter = expression.GetAwaiter();
awaiter.OnCompleted(
    () => {
        var result = awaiter.GetResult();
        statement(s);
    }
);
```

### 
