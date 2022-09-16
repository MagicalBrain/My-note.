# Linux通配符的用法

## `*`

匹配0个或多个字符

## `?`

匹配1个字符

## [abc]

匹配范围内的一个字符

## [abc]

不匹配范围内的一个字符

## 例子

假设有几个字符串：

```bash
ssh
ssh-add
ssh-agent
ssh-argv0
ssh-copy-id
ssh-keygen
ssh-keyscan
```

```bash
# 上面的全都可以匹配到
find ssh*

# 除了 ssh-argv0 都可以匹配到
find ssh*[a-z]
```
