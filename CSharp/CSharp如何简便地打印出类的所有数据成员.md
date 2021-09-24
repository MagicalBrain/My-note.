# CSharp如何简便地打印出类的所有成员

## 打印所有成员的名字

```csharp
using System.Reflection;

    private void button1_Click(object sender, EventArgs e)
    {
        Type t = typeof(System.Drawing.Color);
        string className = t.Name;
        MessageBox.Show(className);

        //获取所有方法
        System.Reflection.MethodInfo[] methods = t.GetMethods();
        this.textBox1.Text = "";
        foreach (System.Reflection.MethodInfo method in methods)
        {
            this.textBox1.Text += method.Name + System.Environment.NewLine;
        }
        
        //获取所有成员
        System.Reflection.MemberInfo[] members = t.GetMembers();

        //获取所有属性
        System.Reflection.PropertyInfo[] properties = t.GetProperties();
        foreach (System.Reflection.PropertyInfo property in properties)
        {
            this.lstColors.Items.Add(property.Name);
        }
    }
```

```csharp
using System.Reflection;

public calss Values
{
	public int ID = 1;
	public double Value1 = 1.5;
	public double Value2 = 2.6;

        /// <summary>
        /// 显示所有字段内容。
        /// </summary>
        public void Show()
        {
            foreach (FieldInfo fi in GetType().GetFields())
                Console.WriteLine($"{fi.FieldType} {fi.Name}: {fi.GetValue(this)}");
        }
}     

```
