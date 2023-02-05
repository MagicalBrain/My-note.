# CSharp如何进行类型转换

## CSharp自带的类型

## byte[] 与 string 转换

byte[] => string:

```csharp
byte[] bsend = new byte[1024];
string str = BitConverter.ToString(bsend);
```

string => byte[]:

```csharp
string str = "Hello, world!";
byte[] bsend = System.Text.Encoding.Default.GetBytes(str);  
```
