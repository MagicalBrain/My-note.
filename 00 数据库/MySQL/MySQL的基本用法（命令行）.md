<!--
 * @Author: MB's X13 374870361@qq.com
 * @Date: 2023-12-19 13:18:00
 * @LastEditors: MB's X13 374870361@qq.com
 * @LastEditTime: 2023-12-19 23:58:55
 * @Description: 
-->

# MySQL的基本用法（命令行）

首先要对数据库里的数据有个基本概念：

数据库


## 数据库

### 创建一个数据库

```sql
CREATE DATABASE test;
```

### 查看当前所有数据库

```sql
SHOW DATABASES;
```

### 选择/切换数据库

要对已有的数据库进行操作之前，首先得选择数据库

```sql
USE database_name;
```

### 删除数据库

```sql
DROP DATABASE database_name;
```

例如，删除名为`mydatabase`的数据库：

```sql
DROP DATABASE mydatabase;
```

注意：删除数据库将永久删除其中的所有表和数据，请谨慎操作。

### 备份数据库

可以使用MySQL的mysqldump工具来备份数据库。以下是备份数据库的基本命令：

```bash
mysqldump -u username -p database_name > backup.sql
```

其中，`username`是MySQL用户名，`database_name`是要备份的数据库名称，`backup.sql`是备份文件的输出路径和文件名。

## 数据表操作

### 创建数据表

创建 MySQL 数据表需要以下信息：

1. 表名
2. 表字段名
3. 定义每个表字段的数据类型


以下为创建 MySQL 数据表的 SQL 通用语法：

```sql
CREATE TABLE table_name (
    column1 datatype,
    column2 datatype,
    ...
);
```

参数说明：

1. table_name 是你要创建的表的名称。
2. column1, column2, ... 是表中的列名。
3. datatype 是每个列的数据类型。

实例：
1. 表名：g_cardapply
   1. 字段名：g_applyno，类型为：varchar，长度：8   // 申请单号（关键字）
   2. 字段名：g_applydate，类型为：bigint，长度：8  // 申请日期
   3. 字段名：g_applystate，类型为：varchar，长度：2   // 申请状态

接下来创建上面这个表：

```sql
CREATE TABLE g_cardapply(
    g_applyno VARCHAR(8),
    g_applydate BIGINT(8),
    g_applystate VARCHAR(2)
);
```

还可以给字段添加约束：

```sql
CREATE TABLE users (
    id INT PRIMARY KEY,
    name VARCHAR(50) NOT NULL,
    email VARCHAR(100) UNIQUE
);
```

创建了一个名为users的数据表，包含id、name和email三列。id列是整数类型，并设置为主键约束；name列是最大长度为50的字符串类型，并设置为非空约束；email列是最大长度为100的字符串类型，并设置为唯一性约束。


### 查看表的结构

```sql
DESCRIBE table_name;
```

或者

```sql
SHOW COLUMNS FROM table_name;
```

这些命令将显示指定表的列信息，包括列名、数据类型、约束条件等。

### 插入数据

```sql
INSERT INTO table_name (column1, column2, column3, ...) VALUES (value1, value2, value3, ...);
```

这是向表中插入数据的基本语法。你需要指定表名和要插入的列名以及对应的值。

### 查询数据：

```sql
SELECT column1, column2, ... FROM table_name WHERE condition;
```

这是查询表中数据的基本语法。你需要指定要查询的列名和表名，并可以使用条件对数据进行筛选。

### 更新数据：

```sql
UPDATE table_name SET column1 = value1, column2 = value2, ... WHERE condition;
```

这是更新表中数据的基本语法。你需要指定要更新的列名、新的值，并可以使用条件来指定要更新的数据行。

### 删除数据：

```sql
DELETE FROM table_name WHERE condition;
```

这是从表中删除数据的基本语法。你需要指定表名，并可以使用条件来指定要删除的数据行。

### 删除表：

```sql
DROP TABLE table_name;
```

这是删除表的基本语法。你需要指定要删除的表名。

## 增删改查

### 增：插入数据

### 删：删除数据

### 改：修改数据

### 查：查询数据

## 关联字段


