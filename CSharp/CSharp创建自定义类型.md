# CSharp创建自定义类型

## 类

## 接口

### 自动属性

属性最常见的实现方式是使用get访问器/set访问器读写==私有==字段（该字段与属性类型相同）。
因而编译器会将自动属性声明自动转换为这种实现方式。因此我们可以将本节的第一个例子重新定义为：

```csharp
public class Stock
{
    public decimal CurrentPrice {get; set;}
}
```

[微软官方示例][auto-implemented-properties]：

[auto-implemented-properties]:https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/auto-implemented-properties

```csharp
// This class is mutable. Its data can be modified from
// outside the class.
class Customer
{
    // Auto-implemented properties for trivial get and set
    public double TotalPurchases { get; set; }
    public string Name { get; set; }
    public int CustomerId { get; set; }

    // Constructor
    public Customer(double purchases, string name, int id)
    {
        TotalPurchases = purchases;
        Name = name;
        CustomerId = id;
    }

    // Methods
    public string GetContactInfo() { return "ContactInfo"; }
    public string GetTransactionHistory() { return "History"; }

    // .. Additional methods, events, etc.
}

class Program
{
    static void Main()
    {
        // Intialize a new object.
        Customer cust1 = new Customer(4987.63, "Northwind", 90108);

        // Modify a property.
        cust1.TotalPurchases += 499.99;
    }
}
```

通过示例我们可以发现，这个自动属性，说白了就是摆脱了以往在OOP编程语言中读取和修改成员变量时需要定义get和set方法。

我们可以像普通的类数据成员那样读取或修改：

```csharp
Console.WriteLine(cust1.getTotalPurchases());
// =>
Console.WriteLine(cust1.TotalPurchases);

cust1.setTotalPurchases(499.99);
// =>
cust1.TotalPurchases = 499.99;
```

### 属性初始化器

对于自动属性，C# 6.0 开始提供了属性初始化器。

如上所述，get/set即属性初始化器

get，set可以设置不同的访问属性。

```csharp

```
