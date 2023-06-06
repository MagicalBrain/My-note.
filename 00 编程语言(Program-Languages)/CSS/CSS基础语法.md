# CSS基础语法

CSS语言的基本语法包括：

1. CSS规则由选择器和声明块组成。
2. 选择器指定要应用规则的元素。
3. 声明块由一系列属性-值对组成。
4. 每个属性-值对之间用分号分隔。
5. CSS注释用/*和*/括起来。
6. 选择器可以组合使用，以匹配更具体的元素。
7. CSS属性有优先级，可以使用!important来提高优先级。
8. 可以使用CSS预处理器来扩展CSS语言，如Sass和Less。

## 代码示例

```html
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8"> 
<title>菜鸟教程(runoob.com)</title> 
<style>
p
{
	color:red;
	text-align:center;
} 
</style>
</head>

<body>
<p>Hello World!</p>
<p>这个段落采用CSS样式化。</p>
</body>
</html>
```

<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8"> 
<title>菜鸟教程(runoob.com)</title> 
<style>
p
{
	color:red;
	text-align:center;
} 
</style>
</head>

<body>
<p>Hello World!</p>
<p>这个段落采用CSS样式化。</p>
</body>
</html>

## id 选择器

id 选择器可以为标有特定 id 的 HTML 元素指定特定的样式。

HTML元素以id属性来设置id选择器,CSS 中 id 选择器以 "#" 来定义。

以下的样式规则应用于元素属性 id="para1":

实例
```html
#para1
{
    text-align:center;
    color:red;
}
```

## class选择器
