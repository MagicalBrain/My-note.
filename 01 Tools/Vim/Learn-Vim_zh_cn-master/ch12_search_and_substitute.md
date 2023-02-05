# 搜索和替换

本章涵盖两个独立但相关的概念:搜索和替代。很多时候，您要搜索的文本并不简单，你必须寻找一个共同的模式。通过学习如何在搜索和替换中使用有意义的模式而不是文字，您将能够快速定位任何文本。

附带说明一下，在本章中，当谈论搜索时，我将主要使用`/`。您可以使用`/`进行的所有操作也可以使用`?`完成。

# 智能区分大小写

尝试匹配搜索词的大小写可能会很棘手。如果要搜索文本"Learn Vim"，则很容易错误键入一个字母的大小写，并得到错误的搜索结果。如果可以匹配任何情况，会不会更轻松，更安全？这是选项`ignorecase`闪亮的地方。只需在 vimrc 中添加`setignorecase`，所有搜索词就不区分大小写。现在，您不必再执行`/Learn Vim`了。 `/learn vim`将起作用。

但是，有时您需要搜索特定于案例的短语。一种方法是用 `set ignorecase` 关闭`ignorecase`选项，但是每次需要搜索区分大小写的短语时，都要打开和关闭很多工作。

是否有一种设置可以让您在大多数时间进行不区分大小写的搜索，但又知道在需要时进行区分大小写的搜索？原来有办法。

如果搜索模式*至少包含一个大写字符*，Vim 有一个`smartcase`选项来覆盖`ignorecase`。当您输入所有小写字符时，您可以将"ignorecase"和"smartcase"结合使用以执行不区分大小写的搜索，而输入一个或多个大写字符时则执行区分大小写的搜索。

在您的 vimrc 中，添加:

```
set ignorecase smartcase
```

如果您有这些文字:

```
hello
HELLO
Hello
```

您可以使用搜索词的大小写来控制不区分大小写:

- `/hello` 匹配"hello"，"HELLO"和"Hello"。
- `/HELLO` 仅匹配"HELLO"。
- `/Hello` 仅匹配"Hello"。

有一个缺点。 如果只需要搜索小写字符串怎么办？
当您执行`/hello`时，Vim 将始终匹配其大写变体。
如果您不想匹配它们怎么办？您可以在搜索词前使用`\C`模式来告诉 Vim，
后续搜索词将区分大小写。如果执行`/\Chello`，它将严格匹配"hello"，而不是"HELLO"或"Hello"。

# 一行中的第一个和最后一个字符

您可以使用`^`匹配行中的第一个字符，并使用`$`匹配行中的最后一个字符。

如果您有以下文字:

```
hello hello
```

您可以使用`/^hello`来定位第一个"hello"。 ^后面的字符必须是一行中的第一个字符。 要定位最后一个"hello"，请运行`/hello$`。 \$之前的字符必须是一行中的最后一个字符。

如果您有以下文字:

```
hello hello friend
```

运行`/hello$`将匹配不到任何内容，因为"friend"是该行的最后一项，而不是"hello"。

# 重复搜索

您可以使用"//"重复上一个搜索。如果您只是搜索`/hello`，则运行`//`等同于运行`/hello`。此快捷键可以为您节省一些按键操作，尤其是在您搜索了很长时间的情况下。还记得您还可以使用"n"和"N"分别以相同方向和相反方向重复上一次搜索。

如果您想快速回忆起*n*个最后一个搜索字词怎么办？您可以先遍历`/`，然后按“向上"/“向下"箭头键（或`Ctrl-N`/`Ctrl-P`），快速遍历搜索历史，直到找到所需的搜索词。要查看所有搜索历史，可以运行`:history/`。

在搜索过程中到达文件末尾时，Vim 会引发错误:`"搜索未找到匹配项的底部:<your-search>"`(`"Search hit the BOTTOM without match for: <your-search>"`)。有时，这可以防止过度搜索，但是有时您又想将搜索重新循环到顶部。您可以使用`set wrapscan`选项使 Vim 在到达文件末尾时在文件顶部进行搜索。要关闭此功能，请执行`set nowrapscan`。

# 搜索替代词

通常一次搜索多个单词。 如果您需要搜索"hello vim"或"hola vim"，而不是"salve vim"或"bonjour vim"，则可以使用||管道替代语法。

给予这样一段文本:

```
hello vim
hola vim
salve vim
bonjour vim
```

要同时匹配"hello"和"hola"，可以执行`/hello\|hola`。 您必须转义（`\`）管道（`|`）运算符，否则 Vim 将按字面意义搜索字符串"|"。

如果您不想每次都输入`\|`，则可以在搜索开始时使用`魔术`语法（`\v`）:`/\vhello|hola`。 我不会在本章中介绍“魔术"，但是有了"\v"，您就不必再转义特殊字符了。 要了解有关`\v`的更多信息，请随时查看`:h \v`。

# 设置比赛的开始和结束

也许您需要搜索作为复合词一部分的文本。 如果您有这些文字:

```
11vim22
vim22
11vim
vim
```

如果您需要选择"vim"，但仅当它以"11"开头并以"22"结束时，可以使用`\zs`（开始匹配）和`\ze`（结束匹配）运算符。 执行:

```
/11\zsvim\ze22
```

Vim 仍然必须匹配整个模式"11vim22"，但是仅突出显示介于`\zs`和`\ze`之间的模式。 另一个例子:

```
foobar
foobaz
```

如果需要在"foobaz"中搜索"foo"，而不是在"foobar"中搜索，请运行:

```
/foo\zebaz
```

# 搜索范围字符

到目前为止，您所有的搜索字词都是文字搜索。在现实生活中，您可能必须使用通用模式来查找文本。最基本的模式是字符范围"[]"。

如果您需要搜索任何数字，则可能不想输入`/0\|1\|2\|3\|4\|5\|6\|7\|8\|9\|0`每一次。相反，请使用`/[0-9]`来匹配一位数字。 "0-9"表达式表示 Vim 尝试匹配的数字范围 0-9，因此，如果要查找 1 到 5 之间的数字，请使用"/[1-5]"。

数字不是 Vim 可以查找的唯一数据类型。您也可以执行`/[a-z]`来搜索小写字母，而`/[A-Z]`来搜索大写字母。

您可以将这些范围组合在一起。如果您需要搜索数字 0-9 以及从 a 到 f（十六进制）的小写字母和大写字母，可以执行`/[0-9a-fA-F]`。

要进行否定搜索，可以在字符范围括号内添加"^"。要搜索非数字，请运行`/[^0-9]`。 Vim 可以匹配任何字符，只要它不是数字即可。请注意，范围括号内的插入符号（`^`）与行首插入符号（例如:`/^hello`）不同。如果插入号在一对方括号之外，并且是搜索词中的第一个字符，则表示“一行中的第一个字符"。如果插入符号在一对方括号内，并且是方括号内的第一个字符，则表示否定搜索运算符。 `/^abc`匹配行中的第一个"abc"，而`/[^abc]`匹配除"a"，"b"或"c"以外的任何字符。

# 搜索重复字符

如果需要在此文本中搜索两位数:

```
1aa
11a
111
```

您可以使用`/[0-9][0-9]`来匹配两位数字字符，但是该方法不可缩放。 如果您需要匹配二十个数字怎么办？ 打字 20 次[[0-9]]并不是一种有趣的体验。 这就是为什么您需要一个`count`参数。

您可以将`count`传递给您的搜索。 它具有以下语法:

```
{n,m}
```

顺便说一句，当在 Vim 中使用它们时，这些“计数"花括号需要被转义。 count 运算符放在您要递增的单个字符之后。

这是`count`语法的四种不同变体: -`{n}`是完全匹配。 `/[0-9]\{2\}`匹配两个数字:"11"和"111"中的"11"。 -`{n,m}`是范围匹配。 `/[0-9]\{2,3\}`匹配 2 到 3 位数字:"11"和"111"。 -`{,m}`是符合条件的。 `/[0-9]\{,3\}`最多匹配 3 个数字:"1"，"11"和"111"。 -`{n,}`是至少匹配项。 `/[0-9]\{2,\}`至少匹配 2 个或多个数字:"11"和"111"。

计数参数`\{0,\}`（零或多个）和`\{1,\}`（一个或多个）是常见的搜索模式，Vim 为它们提供了特殊的运算符:`*`和`+`（ `+`需要被转义，而`*` 可以正常运行而无需转义）。 如果执行`/[0-9]*`，则与`/[0-9]\{0,\}`相同。 它搜索零个或多个数字。 它将匹配“"，"1"，"123"。 顺便说一句，它也将匹配非数字，例如"a"，因为在技术上，字母"a"中的数字为零。 在使用"\*"之前，请仔细考虑。 如果执行`/[0-9]\+`，则与`/[0-9]\{1,\}`相同。 它搜索一个或多个数字。 它将匹配"1"和"12"。

# 预定义范围

Vim 为常见字符（例如数字和字母）提供了预定义范围。 我不会在这里逐一介绍，但可以在`:h /character-classes`中找到完整列表。 这是有用的:

```
\d    数字[0-9]
\D    非数字[^ 0-9]
\s    空格字符（空格和制表符）
\S    非空白字符（除空格和制表符外的所有字符）
\w    文字字符[0-9A-Za-z_]
\l    小写字母[a-z]
\u    大写字符[A-Z]
```

您可以像使用范围字符一样使用它们。 要搜索任何一位数字，可以使用`/\d`以获得更简洁的语法，而不使用`/[0-9]`。

# 更多搜索示例

## 在一对相似字符之间捕获文本

如果要搜索由双引号引起来的短语:

```
"Vim is awesome!"
```

运行这个:

`/"[^"]\+"`

让我们分解一下:

- `"` 是字面双引号。它匹配第一个双引号。
- `[^"]` 表示除双引号外的任何字符，只要不是双引号，它就与任何字母数字和空格字符匹配。
- `\+`表示一个或多个。由于 Vim 的前面是`[^"]`，因此 Vim 查找一个或多个不是双引号的字符。
- `"` 是字面双引号。它与右双引号匹配。

当看到第一个`“`时，它开始模式捕获。Vim 在一行中看到第二个双引号时，它匹配第二个`"`模式并停止模式捕获。同时，两个“"之间的所有非“"字符都被`[^"]\+` 模式捕获，在这种情况下，短语"Vim is awesome!"。由一对类似的定界符包围的词组:要捕获由单引号引起来的词组，可以使用`/'[^']\+'`。

## 捕获电话号码

如果要匹配以连字符(`-`)分隔的美国电话号码，例如`123-456-7890`，则可以使用:

```
/\v\d\{3\}-\d\{3\}-\d\{4\}
```

美国电话号码由一组三位数字组成，其后是另外三位数字，最后是四位数字。 让我们分解一下:

- `\d\{3\}`与精确重复三次的数字匹配
- `-`是字面的连字符

此模式还可用于捕获任何重复的数字，例如 IP 地址和邮政编码。

这涵盖了本章的搜索部分。 现在开始替代。

# 基本替代

Vim 的替代命令是一个有用的命令，用于快速查找和替换任何模式。 替换语法为:

```
:s/old-pattern/new-pattern/
```

让我们从一个基本用法开始。 如果您有以下文字:

```
vim is good
```

让我们用"awesome"代替"good"，因为 Vim 很棒。 运行`:s/good/awesome/.`您应该看到:

```
vim is awesome
```

# 重复最后一次替换

您可以使用普通命令`&`或运行`:s`来重复最后一个替代命令。 如果您刚刚运行`:s/good/awesome/`，则运行`&`或`:s`都会重复执行。

另外，在本章前面，我提到您可以使用"//"来重复先前的搜索模式。 此技巧可用于替代命令。 如果`/good`是最近完成的，并且将第一个替换模式参数留为空白，例如在`:s//awesome/`中，则与运行`:s/good/awesome/`相同。

# 替代范围

就像许多 Ex 命令一样，您可以将 range 参数传递给替代命令。 语法为:

```
:[range]s/old/new/
```

如果您具有以下表达式:

```
let one = 1;
let two = 2;
let three = 3;
let four = 4;
let five = 5;
```

要将第三行到第五行中的"let"替换为"const"，您可以执行以下操作:

```
:3,5s/let/const/
```

替代命令的范围语法与搜索（`{n,m}`）中的计数语法相似，但有细微差别。 这是通过范围的一些变化:

- `:,3/let/const/` - 如果逗号前没有给出任何内容，则表示当前行。 从当前行替换为第 3 行。
- `:1,s/let/const/` - 如果逗号后没有给出任何内容，则它也代表当前行。 从第 1 行替换为当前行。
- `:3s/let/const/` - 如果仅给出一个值作为范围（不带逗号），则仅在该行进行替换。

在 Vim 中，`%`通常表示整个文件。 如果运行`:%s/let/const/`，它将在所有行上进行替换。

# 模式匹配

接下来的几节将介绍基本的正则表达式。 强大的模式知识对于掌握替代命令至关重要。

如果您具有以下表达式:

```
let one = 1;
let two = 2;
let three = 3;
let four = 4;
let five = 5;
```

要在数字周围添加一对双引号:

```
:%s/\d/"\0"/
```

结果:

```
let one = "1";
let two = "2";
let three = "3";
let four = "4";
let five = "5";
```

让我们分解一下命令:

- `:%s` 定位整个文件以执行替换。
- `\d` 是 Vim 的数字预定义范围(`[0-9]`)。
- `"\0"` 双引号是文字双引号。 `\0`是一个特殊字符，代表“整个匹配模式"。 此处匹配的模式是单个数字`\d`。 在第一行，"\0"的值为"1"。 在第二行，值为"2"。 在第三行，值为"3"，依此类推。

另外，`&`也代表`\0`之类的“整个匹配模式"。 `:s/\d/"&"/`也可以。

让我们考虑另一个例子。 给出以下表达式:

```
one let = "1";
two let = "2";
three let = "3";
four let = "4";
five let = "5";
```

您需要用变量名交换所有的"let"。 为此，请运行:

```
:%s/\(\w\+\) \(\w\+\)/\2 \1/
```

上面的命令包含太多的反斜杠，很难阅读。 使用`\v`运算符更方便:

```
:%s/\v(\w+) (\w+)/\2 \1/
```

结果:

```
let one = "1";
let two = "2";
let three = "3";
let four = "4";
let five = "5";
```

太好了！ 让我们分解该命令:

- `:%s` 定位文件中的所有行
- `(\w+) (\w+)`对模式进行分组。`\w`是 Vim 预定义的单词字符范围(`[0-9A-Za-z_]`)之一。 包围在其中的`（）`捕获一个单词字符匹配。 请注意两个分组之间的空间。 `(\w+) (\w+)` 分为两组。 在第一行上，第一组捕获“one"，第二组捕获“two"。
- `\2 \1` 以相反的顺序返回捕获的组。 `\2`包含捕获的字符串"let"，而`\1`包含字符串"one"。 使`\2 \1`返回字符串"let one"。

回想一下`\0`代表整个匹配的模式。 您可以使用`( )`将匹配的字符串分成较小的组。 每个组都由`\1`, `\2`, `\3`等表示。

让我们再举一个例子来巩固这一匹配组的概念。 如果您有以下数字:

```
123
456
789
```

要颠倒顺序，请运行:

```
:%s/\v(\d)(\d)(\d)/\3\2\1/
```

结果是:

```
321
654
987
```

每个`(\d)`匹配并分组每个数字。 在第一行上，第一个`(\d)`的值为"1"，第二个`(\d)`的值为"2"，第三个`(\d)`的值为"3"。 它们存储在变量`\1`，`\2`和`\3`中。 在替换的后半部分，新模式`\3\2\1`在第一行上产生"321"值。

如果您运行了它，则:

```
:%s/\v(\d\d)(\d)/\2\1/
```

您将获得不同的结果:

```
312
645
978
```

这是因为您现在只有两个组。 被`(\d\d)`捕获的第一组存储在`\1`内，其值为"12"。 由`(\d)`捕获的第二组存储在`\2`内部，其值为"3"。 然后，`\2\1`返回"312"。

# 替代标志

如果您有以下句子:

```
chocolate pancake, strawberry pancake, blueberry pancake
```

要将所有 pancakes 替换为 donut，您不能只运行:

```
:s/pancake/donut
```

上面的命令将仅替换第一个匹配项，从而为您提供:

```
chocolate donut, strawberry pancake, blueberry pancake
```

有两种解决方法。 首先，您可以运行两次替代命令。 其次，您可以向其传递全局(`g`)标志来替换一行中的所有匹配项。

让我们谈谈全局标志。 运行:

```
:s/pancake/donut/g
```

Vim 迅速执行命令，将所有煎饼替换为甜甜圈。 全局命令是替代命令接受的几个标志之一。 您在替代命令的末尾传递标志。 这是有用的标志的列表:

```
&    重用上一个替代命令中的标志。 必须作为第一个标志传递。
g    替换行中的所有匹配项。
c    要求替代确认。
e    防止替换失败时显示错误消息。
i    执行不区分大小写的替换
I    执行区分大小写的替换
```

我上面没有列出更多标志。 要了解所有标志，请查看`:h s_flags`。

顺便说一句，重复替换命令（`&`和`:s`）不保留标志。 运行`&`只会重复`:s/pancake/donut/`而没有`g`。 要使用所有标志快速重复最后一个替代命令，请运行`:&&`。

# 更改定界符

如果您需要用长路径替换 URL:

```
https://mysite.com/a/b/c/d/e
```

要用单词"hello"代替它，请运行:

```
:s/https:\/\/mysite.com\/a\/b\/c\/d\/e/hello/
```

但是，很难说出哪些正斜杠（`/`）是替换模式的一部分，哪些是分隔符。 您可以使用任何单字节字符（除字母，数字或`“`，`|`和`\`之外的字符）来更改定界符。让我们将它们替换为`+`。上面的替换命令可以重写为 :

```
:s+https:\/\/mysite.com\/a\/b\/c\/d\/e+hello+
```

现在，更容易看到分隔符在哪里。

# 特殊替换

您还可以修改要替换的文本的大小写。 给出以下表达式:

```
let one = "1";
let two = "2";
let three = "3";
let four = "4";
let five = "5";

```

要大写变量“one"，“two"，“three"等，请运行:

```
%s/\v(\w+) (\w+)/\1 \U\2/

```

你会得到:

```
let ONE = "1";
let TWO = "2";
let THREE = "3";
let FOUR = "4";
let FIVE = "5";
```

这是该命令的细分:

- `(\w+) (\w+)`捕获前两个匹配的组，例如"let"和"one"。
- `\1`返回第一个组的值"let"
- `\U\2`大写(`\U`)第二组(`\2`)。

该命令的窍门是表达式`\U\2`。`\U`指示以下字符大写。

让我们再举一个例子。 假设您正在编写 Vim 书籍，并且需要将一行中每个单词的首字母大写。

```
vim is the greatest text editor in the whole galaxy
```

您可以运行:

```
:s/\<./\u&/g
```

结果:

```
Vim Is The Greatest Text Editor In The Whole Galaxy
```

细目如下:

- `:s` 替换当前行
- `\<.` 由两部分组成:`\<`匹配单词的开头和`.`匹配任何字符。 "\<"运算符使以下字符成为单词的第一个字符。 由于`.`是下一个字符，因此它将匹配任何单词的第一个字符。
- `\u&` 将后续符号`&`大写。 回想一下，`&`（或`\0`）代表整个比赛。 它与拒绝单词的第一个字符匹配。
- `g`全局标志。 没有它，此命令将仅替换第一个匹配项。 您需要替换此行上的每个匹配项。

要了解替换的特殊替换符号（如`\u`和`\U`）的更多信息，请查看`:h sub-replace-special`。

# 替代模式

有时您需要同时匹配多个模式。 如果您有以下问候:

```
hello vim
hola vim
salve vim
bonjour vim
```

您仅需在包含单词"hello"或"hola"的行上用"friend"代替"vim"。 执行:

```
:%s/\v(hello|hola) vim)/\1 friend/g
```

结果:

```
hello friend
hola friend
salve vim
bonjour vim
```

这是细分:

- `%s` 在文件的每一行上运行替代命令。
- `(hello|hola)` 匹配\*"hello"或"hola"并将其视为一个组。
- `vim` 是字面意思"vim"。
- `\1` 是第一个匹配组，它是文本"hello"或"hola"。
- `friend` 是字面的“朋友"。

# 跨多个文件替换

最后，让我们学习如何在多个文件中替换短语。对于本节，假设您有两个文件: `food.txt` 和 `animal.txt`.

`food.txt`内:

```
corn dog
hot dog
chili dog
```

`animal.txt`内:

```
large dog
medium dog
small dog
```

假设您的目录结构如下所示:

```
├── food.txt
├── animal.txt
```

首先，在`:args`内同时捕获"food.txt"和"animal.txt"。回顾前面的章节，`:args`可用于创建文件名列表。在 Vim 内部有几种方法可以做到这一点:

```
:args *.txt                  捕获当前位置的所有txt文件
:args food.txt animal.txt    仅捕获索引和服务器js文件
:args **/*.txt               捕获每个txt文件
:args **                     捕获一切
```

您也可以在 Vim 外部运行上述命令，将文件作为 Vim 的* arguments *传递（因此称为"args"命令）。 从终端运行

```
vim food.txt animal.txt
```

当 Vim 启动时，您将在`:args`中找到`food.txt`和`animal.txt`。

无论哪种方式，当您运行`:args`时，您都应该看到:

```
[food.txt] animal.txt
```

要转到列表中的下一个或上一个参数，请输入`:next`或`:previous`。 现在所有相关文件都存储在参数列表中，您可以使用`:argdo`命令执行多文件替换。 执行:

```
:argdo %s/dog/chicken/
```

这将对`:args`列表中的所有文件进行替换。 最后，使用以下命令保存更改的文件:

```
:argdo update
```

`:args`和`:argdo`是在多个文件之间应用命令行命令的有用工具。 与其他命令一起尝试！

# 用宏替换多个文件

另外，您也可以跨多个带有宏的文件运行替代命令。 让我们从将相关文件放入 args 列表开始。 执行:

```
:args animal.txt food.txt
qq
:%s/dog/chicken/g
:wnext
q
99@q
```

以下是步骤的细分:

- `:args animal.txt food.txt` 会将相关文件列出到`:args`列表中。
- `qq` 启动"q"寄存器中的宏。
- `:%s/dog/chicken/g`在当前文件的所有行上用"chicken"替换"dog"。
- `:wnext` 写入（保存）文件，然后转到`args`列表中的下一个文件。就像同时运行`:w`和`:next`一样。
- `q` 停止宏录制。
- `99@q` 执行宏九十九次。 Vim 遇到第一个错误后，它将停止执行宏，因此 Vim 实际上不会执行该宏九十九次。

# 以聪明的方式学习搜索和替换

做好搜索的能力是编辑的必要技能。掌握搜索功能使您可以利用正则表达式的灵活性来搜索文件中的任何模式。花些时间学习这些。实际上，您可以自己完成本章中的搜索和替换。我曾经读过一本关于正则表达式的书，却没有真正去做，后来我几乎忘了读的所有东西。主动编码是掌握任何技能的最佳方法。

一种提高模式匹配技能的好方法是，每当您需要搜索模式时（例如"hello 123"），而不是查询文字搜索字词(`/hello 123`)，都可以尝试为它(`/\v(\l+) (\d+)`)。这些正则表达式概念中的许多不仅在使用 Vim 时，也适用于常规编程。

既然您已经了解了 Vim 中的高级搜索和替换，现在让我们学习功能最丰富的命令之一，即全局命令。