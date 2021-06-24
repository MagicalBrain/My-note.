# Doxygen支持的注释类型

## C/C++的注释类型

### C++/Java风格

```cpp
/**
 * ... text ...
 */
```

### Qt风格

```cpp
/*!
* \brief 
*
* 
*/
```

### C++行注释风格

```cpp
/// \brief 
/// 
/// 
```

```cpp
//!
//!... text ...
//!
```

```cpp
/////////////////////////////////////////////////
/// ... text ...
/////////////////////////////////////////////////
```

### markdown支持

注释里还支持直接使用markdown语法来写注释

## 命令类型

html类型
xml类型

### html类型

标签比较多，使用比较灵活

还可以给Doxygen注释加注释，以下注释里的文本不会被Doxygen加到文档里：
```cpp
/*! <!-- This is a comment with a comment block --> Visible text */
```

[参考官方网站][commands]

[commands]:https://www.doxygen.nl/manual/commands.html

## 总结

其实就是以上任意一种注释风格 + 一种命令类型

```cpp

```