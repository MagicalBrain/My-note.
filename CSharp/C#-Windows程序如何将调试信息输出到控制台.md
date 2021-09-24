# C#Windows程序如何将调试信息输出到控制台

以下方法的前提是在项目的属性页里将输出类型改成控制台应用程序

## 修改输出程序类型

试过了，貌似没用

## 使用C语言库里的AllocConsole和FreeConsole函数

试过了，貌似没用

```csharp
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.Windows.Threading;

// 注意这个using程序集是Dllimport所必须的
using System.Runtime.InteropServices;


namespace Embed
{
    /// <summary>
    /// MainWindow.xaml 的交互逻辑
    /// </summary>
    public partial class MainWindow : Window
    {
        /// <summary>
        /// Allocates a new console for current process.
        /// </summary>
        [DllImport("kernel32.dll")]
        public static extern Boolean AllocConsole();

        /// <summary>
        /// Frees the console.
        /// </summary>
        [DllImport("kernel32.dll")]
        public static extern Boolean FreeConsole();
        
        public MainWindow()
        {
            InitializeComponent();
 
            Loaded += MainWindow_Loaded;
            Closed += MainWindow_Closed;
            
            var timer = new DispatcherTimer
            {
                Interval = TimeSpan.FromSeconds(1)
            };
            timer.Tick += Timer_Tick;
            timer.Start();
        }

        private void Timer_Tick(object sender, EventArgs e)
        {
            Debug.WriteLine("Debug");
            Trace.WriteLine("Trace");
            Console.WriteLine("Console");
        }

        private void MainWindow_Loaded(object sender, RoutedEventArgs e)
        {
            AllocConsole();
        }

        private void MainWindow_Closed(object sender, EventArgs e)
        {
            FreeConsole();
        }
    }
}
```

## AttachConsole

```csharp

```
