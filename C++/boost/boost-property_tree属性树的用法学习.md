# boost property_tree属性树的用法学习

## 包含的头文件

```cpp
#include <boost/property_tree/exceptions.hpp>
#include <boost/property_tree/id_translator.hpp>
#include <boost/property_tree/info_parser.hpp>
#include <boost/property_tree/ini_parser.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/ptree_fwd.hpp>
#include <boost/property_tree/ptree_serialization.hpp>
#include <boost/property_tree/stream_translator.hpp>
#include <boost/property_tree/string_path.hpp>
#include <boost/property_tree/xml_parser.hpp>
```

应根据实际需要来包含。

## ptree类型的定义

什么是属性树？

The Property Tree library provides a data structure that stores an arbitrarily deeply nested tree of values, indexed at each level by some key. 
Each node of the tree stores its own value, plus an ordered list of its subnodes and their keys. 
The tree allows easy access to any of its nodes by means of a path, which is a concatenation of multiple keys.

属性树库提供了一种数据结构，该结构存储任意深度嵌套的值树，并在每一层用某个键索引。树的每个节点存储自己的值，以及子节点及其键的有序列表。树允许通过路径方便地访问它的任何节点，路径是多个键的连接。

In addition, the library provides parsers and generators for a number of data formats that can be represented by such a tree, including XML, INI, and JSON.

此外，该库还提供了许多可以用这种树表示的数据格式的解析器和生成器，包括XML、INI和JSON。

Property trees are versatile data structures, but are particularly suited for holding configuration data. The tree provides its own, tree-specific interface, and each node is also an STL-compatible Sequence for its child nodes.

属性树是通用的数据结构，但特别适合保存配置数据。树提供了自己的、特定于树的接口，每个节点也是其子节点的STL兼容序列。

Conceptually, then, a node can be thought of as the following structure:

从概念上讲，一个节点可以被认为是以下结构:

```cpp
struct ptree
{
   data_type data;                         // data associated with the node
   list< pair<key_type, ptree> > children; // ordered list of named children
};
```

Both key_type and data_type are configurable to some extent, but will usually be std::string or std::wstring, and the parsers only work with this kind of tree.

key_type和data_type在某种程度上都是可配置的，但通常是std::string或std::wstring，解析器只能用于这种树。

Many software projects develop a similar tool at some point of their lifetime, and property tree originated the same way. We hope the library can save many from reinventing the wheel.

## 定义一个`ptree`类型的对象

```cpp
boost::property_tree::ptree request;
```

## 官方链接

https://www.boost.org/doc/libs/1_65_1/doc/html/property_tree.html
