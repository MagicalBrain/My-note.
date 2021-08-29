# OpenCV 矩阵函数详解

标签（空格分隔）： OpenCV

---

**在自己电脑上的路径：**
C:\OpenCV 3.3\opencv\sources\modules\core\src

## 点乘
```c++
double Mat::dot(InputArray _mat) const
{
    CV_INSTRUMENT_REGION()

    Mat mat = _mat.getMat();
    int cn = channels();
    DotProdFunc func = getDotProdFunc(depth());
    CV_Assert( mat.type() == type() && mat.size == size && func != 0 );
    //若括号中的表达式值为false，则返回一个错误信息。

    if( isContinuous() && mat.isContinuous() )
    {
        size_t len = total()*cn;
        if( len == (size_t)(int)len )
            return func(data, mat.data, (int)len);
    }

    const Mat* arrays[] = {this, &mat, 0};
    uchar* ptrs[2];
    NAryMatIterator it(arrays, ptrs);
    int len = (int)(it.size*cn);
    double r = 0;

    for( size_t i = 0; i < it.nplanes; i++, ++it )
        r += func( ptrs[0], ptrs[1], len );

    return r;
}

}
```

## 相关函数
### getDotProdFunc()
```c++
static DotProdFunc getDotProdFunc(int depth)
{
    static DotProdFunc dotProdTab[] =
    {
        (DotProdFunc)GET_OPTIMIZED(dotProd_8u), (DotProdFunc)GET_OPTIMIZED(dotProd_8s),
        (DotProdFunc)dotProd_16u, (DotProdFunc)dotProd_16s,
        (DotProdFunc)dotProd_32s, (DotProdFunc)GET_OPTIMIZED(dotProd_32f),
        (DotProdFunc)dotProd_64f, 0
    };

    return dotProdTab[depth];
}
```



