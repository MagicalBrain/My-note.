# C++二进制数的处理

## 如何判断二进制数中的某一位为1

```cpp

int funcion(int data,int position)
{
    int base = static_cast<int>(pow(2, position));
	int io_value = static_cast<int>(result / base % 2);
    return io_value;
}
```
