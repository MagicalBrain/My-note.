# C++如何使用正则表达式

在C++里只用正则表达式主要是用`regex`这个头文件。
而`regex`头文件是用的是ECMA Script正则表达式

## 使用实例

使用正则表达式查找违反此拼写规则的单词：“i除非在c后面，否则必须在e之前。”
即查找“i在e前面，同时i的前面没有c”的单词。

```cpp
#include <iostream>
#include <string>
#include <regex>

int main()
{
    std::string pattern("[^c]ei");
    pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";

    std::regex r(pattern);
    std::smatch results;

    std::string test_str = "receipt freind itself receive";

    if (std::regex_search(test_str, results, r))
        std::cout << results.str() << std::endl;

    std::cout << "Hello World!\n";
}
```

我们首先定义了一个string来保存希望查找的正则表达式。
正则表达式`[^c]`表明我们希望匹配任意不是`'c'`的字符，
而`[^c]ei`指出我们想要匹配这种字符后接ei的字符串。
此模式描述的字符串恰好包含三个字符。
我们想要包含此模式的单词的完整内容。为了与整个单词匹配，我们还需要一个正则表达式与这个三字母模式之前和之后的字母匹配。

这个正则表达式包含零个或多个字母后接我们的三字母的模式，然后再接零个或多个额外的字母。
默认情况下， regex使用的正则表达式语言是**ECMAScript**在ECMAScript中，模式`[[::alpha:]]*`匹配任意字母，符号+和＊分别表示我们希望“一个或多个”或“零个或多个”匹配。因此`[[::alpha:]]*`将匹配零个或多个字母
