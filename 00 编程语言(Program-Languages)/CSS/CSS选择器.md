# CSS选择器

## id 选择器

id 选择器可以为标有特定 id 的 HTML 元素指定特定的样式。

HTML元素以id属性来设置id选择器,CSS 中 id 选择器以 "#" 来定义。

以下的样式规则应用于元素属性 id="para1":

```html
#para1
{
    text-align:center;
    color:red;
}
```

## class选择器

class 选择器用于描述一组元素的样式，class 选择器有别于id选择器，class可以在多个元素中使用。

class 选择器在 HTML 中以 class 属性表示, 在 CSS 中，类选择器以一个点 . 号显示：

在以下的例子中，所有拥有 center 类的 HTML 元素均为居中。

实例
```html
.center {text-align:center;}
```

----

你也可以指定特定的 HTML 元素使用 class。

在以下实例中, 所有的 p 元素使用 class="center" 让该元素的文本居中:

实例

```html
p.center {text-align:center;}
```

----

多个 class 选择器可以使用空格分开：

实例
```html
.center { text-align:center; }
.color { color:#ff0000; }
```

