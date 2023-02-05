# Markdown中插入脚注

```markdown
Here's a simple footnote,[^1] and here's a longer one.[^bignote]

[^1]: This is the first footnote.

[^bignote]: Here's one with multiple paragraphs and code.

    Indent paragraphs to include them in the footnote.

    `{ my code }`

    Add as many paragraphs as you like.
```

效果如下（预览可见）：

Here's a simple footnote,[^1] and here's a longer one.[^bignote]

[^1]: This is the first footnote.

[^bignote]: Here's one with multiple paragraphs and code.

    Indent paragraphs to include them in the footnote.

    `{ my code }`

    Add as many paragraphs as you like.

**注意**

这个脚注也是可以支持中文的：

```markdown
[^错误1]

[^错误1]: 这个错误的解决方法就是把错误的地方删除。

```

效果如下：

[^错误1]

[^错误1]: 这个错误的解决方法就是把错误的地方删除。
