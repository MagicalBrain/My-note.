# CSharp如何读入一行输入的数字

由于C#默认输入都是用字符串类型来存储的。
所以处理起来有点麻烦。

```csharp
//输入一行
string value = Console.ReadLine();

//用标点分开
string[] vals = value.Split(',');

string[] vals = value.Split(' ');
```
