# stdio库函数 整理记录

主要是整理遇见过，可能有用的函数

### 1	int fclose(FILE *stream)

关闭流 stream。刷新所有的缓冲区。

### 2	void clearerr(FILE *stream)

清除给定流 stream 的文件结束和错误标识符。
### 3	int feof(FILE *stream)

测试给定流 stream 的文件结束标识符。

### 4	int ferror(FILE *stream)

测试给定流 stream 的错误标识符。

### 5	int fflush(FILE *stream)

刷新流 stream 的输出缓冲区。

### 6	int fgetpos(FILE *stream, fpos_t *pos)

获取流 stream 的当前文件位置，并把它写入到 pos。

### 7	FILE *fopen(const char *filename, const char *mode)

使用给定的模式 mode 打开 filename 所指向的文件。

### 8	size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream)

从给定流 stream 读取数据到 ptr 所指向的数组中。

### 9	FILE *freopen(const char *filename, const char *mode, FILE *stream)

把一个新的文件名 filename 与给定的打开的流 stream 关联，同时关闭流中的旧文件。

### 10	int fseek(FILE *stream, long int offset, int whence)

设置流 stream 的文件位置为给定的偏移 offset，参数 offset 意味着从给定的 whence 位置查找的字节数。

### 11	int fsetpos(FILE *stream, const fpos_t *pos)

设置给定流 stream 的文件位置为给定的位置。参数 pos 是由函数 fgetpos 给定的位置。

### 12	long int ftell(FILE *stream)

返回给定流 stream 的当前文件位置。

### 13	size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream)

把 ptr 所指向的数组中的数据写入到给定流 stream 中。

### 14	int remove(const char *filename)

删除给定的文件名 filename，以便它不再被访问。

### 15	int rename(const char *old_filename, const char *new_filename)

把 old_filename 所指向的文件名改为 new_filename。

### 16	void rewind(FILE *stream)

设置文件位置为给定流 stream 的文件的开头。

### 17	void setbuf(FILE *stream, char *buffer)

定义流 stream 应如何缓冲。

### 18	int setvbuf(FILE *stream, char *buffer, int mode, size_t size)

另一个定义流 stream 应如何缓冲的函数。

### 19	FILE *tmpfile(void)

以二进制更新模式(wb+)创建临时文件。

### 20	char *tmpnam(char *str)

生成并返回一个有效的临时文件名，该文件名之前是不存在的。

### 21	int fprintf(FILE *stream, const char *format, ...)

发送格式化输出到流 stream 中。

### 22	int printf(const char *format, ...)

发送格式化输出到标准输出 stdout。

### 23	int sprintf(char *str, const char *format, ...)

发送格式化输出到字符串。

用法示例：
```cpp
sprintf(b, "%.2f",temp);
```

将double类型的temp以保留2位小数的形式存到字符串b中。

### 24	int vfprintf(FILE *stream, const char *format, va_list arg)

使用参数列表发送格式化输出到流 stream 中。

### 25	int vprintf(const char *format, va_list arg)

使用参数列表发送格式化输出到标准输出 stdout。

### 26	int vsprintf(char *str, const char *format, va_list arg)

使用参数列表发送格式化输出到字符串。

### 27	int fscanf(FILE *stream, const char *format, ...)

从流 stream 读取格式化输入。

### 28	int scanf(const char *format, ...)

从标准输入 stdin 读取格式化输入。

### 29	int sscanf(const char *str, const char *format, ...)

从字符串读取格式化输入。

用法示例：
```cpp
sscanf(a, "%lf", &temp);
```
从字符串a中，读取一个double类型并存入temp，与```scanf```用法类似

### 30	int fgetc(FILE *stream)

从指定的流 stream 获取下一个字符（一个无符号字符），并把位置标识符往前移动。

### 31	char *fgets(char *str, int n, FILE *stream)

从指定的流 stream 读取一行，并把它存储在 str 所指向的字符串内。当读取 (n-1) 个字符时，或者读取到换行符时，或者到达文件末尾时，它会停止，具体视情况而定。
### 32	int fputc(int char, FILE *stream)

把参数 char 指定的字符（一个无符号字符）写入到指定的流 stream 中，并把位置标识符往前移动。

### 33	int fputs(const char *str, FILE *stream)

把字符串写入到指定的流 stream 中，但不包括空字符。

### 34	int getc(FILE *stream)

从指定的流 stream 获取下一个字符（一个无符号字符），并把位置标识符往前移动。

### 35	int getchar(void)

从标准输入 stdin 获取一个字符（一个无符号字符）。

### 36	char *gets(char *str)

从标准输入 stdin 读取一行，并把它存储在 str 所指向的字符串中。当读取到换行符时，或者到达文件末尾时，它会停止，具体视情况而定。

### 37	int putc(int char, FILE *stream)

把参数 char 指定的字符（一个无符号字符）写入到指定的流 stream 中，并把位置标识符往前移动。

### 38	int putchar(int char)

把参数 char 指定的字符（一个无符号字符）写入到标准输出 stdout 中。

### 39	int puts(const char *str)

把一个字符串写入到标准输出 stdout，直到空字符，但不包括空字符。换行符会被追加到输出中。

### 40	int ungetc(int char, FILE *stream)

把字符 char（一个无符号字符）推入到指定的流 stream 中，以便它是下一个被读取到的字符。

### 41	void perror(const char *str)

把一个描述性错误消息输出到标准错误 stderr。首先输出字符串 str，后跟一个冒号，然后是一个空格。

### 42	int snprintf(char *str, size_t size, const char *format, ...)

格式字符串到 str 中。
