# 搭建WordPress个人博客

## 基于centos系统

### 下载Nginx

## ubuntu

接下来要配置LAMP环境
（Linux、Apache、MySQL、Php）

### 下载Apache2

```
sudo apt-get install apache2 -y
```

### 安装php7.0

```
sudo apt-get install php7.0 -y
```

#### 安装相关组件

```
sudo apt-get install libapache2-mod-php7.0
```

**安装过程中可能会报错**：
```
Unable to locate package libapache2-mod-php7.0
```

使用以下命令解决：
```
sudo apt-add-repository ppa:ondrej/php
sudo apt-get update
sudo apt-get install php7.0
```

### 安装MySQL

```
sudo apt-get install mysql-server -y
```

安装相关组件：
```
sudo apt-get install php7.0-mysql
```
该命令可能会由于链接超时而出错，多试几次就好了。

### 安装phpmyadmin

密码：sa

```
sudo apt-get install phpmyadmin -y
```

```
sudo ln -s /usr/share/phpmyadmin /var/www/html/phpmyadmin
```

```
sudo service mysql restart
```

```
sudo systemctl restart apache2.service
```

## 安装WordPress

```
wget https://cn.wordpress.org/wordpress-4.7.4-zh_CN.zip
```

解压安装包
```
sudo unzip wordpress-4.7.4-zh_CN.zip
```