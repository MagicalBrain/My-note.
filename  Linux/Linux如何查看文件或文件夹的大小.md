# Linux如何查看文件或文件夹的大小

文件

ls -lht

文件夹

du -sh 整个目录的大小

du -sh * 目录里的每个字目录的大小

du -ah 子目录以及子目录里的文件的大小

查看大于多少的文件

find /opt  -type f -size +500M  -print0 | xargs -0 ls -lh  | sort -nr

磁盘使用情况

df -lh
