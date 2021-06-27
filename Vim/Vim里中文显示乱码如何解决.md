# Vim里显示中文乱码如何解决

打开终端输入：vim /etc/vim/vimrc，进入编辑模式，加入如下配置

```bash
set fileencodings=utf-8,gb2312,gbk,gb18030  
set termencoding=utf-8  
set encoding=prc 
```

[参考链接][参考链接]

[参考链接]:https://blog.csdn.net/smile_5me/article/details/80262745