# C++的RAII原则和机制

这是学习现代C++必须要了解的原则和基本机制

为了管理内存等资源， C++程序员通常采用RAII机制（资源获取即初始化， ResourceAcquisition Is Initialization），在类的构造函数里申请资源，然后使用，最终在析构函数中释放资源。
