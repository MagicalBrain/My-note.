# QDockWidget类

这个类是Qt用来实现停靠悬浮窗口(QDockWidget)的

参考链接：
https://www.cnblogs.com/huipengbo/p/8228130.html

Qt实现窗口停靠和悬浮使用类QDockWidget，

## 设置停靠特性和停靠区域

1.它有两个重要方法用来设置停靠特性以及停靠区域，

```cpp
dw1->setFeatures(QDockWidget::DockWidgetMovable | QDockWidget::DockWidgetClosable);//设置停靠窗口特性，可移动，可关闭
dw1->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);//设置可停靠区域为主窗口左边和右边
```

## 将一个空间插入停靠窗体

2.将一个空间插入停靠窗体使用setWidget方法

```cpp
dw1->setWidget(dte);
```



4.在主窗口加入悬浮窗使用addDockWidget，并且可以指定停靠区域

```cpp
addDockWidget(Qt::RightDockWidgetArea,dw1);
```

## QDockWidget::visibilityChanged

`QDockWidget::visibilityChanged`的用法示例：

```cpp
title = QString::fromLocal8Bit("处理");
pdw = new ProcessDockWidget(this);
pdw->setWindowTitle(title);
pdw->setFeatures(QDockWidget::DockWidgetMovable | QDockWidget::DockWidgetClosable);
this->addDockWidget(Qt::DockWidgetArea::LeftDockWidgetArea, pdw);
// 绑定代码
connect(pdw, &ProcessDockWidget::visibilityChanged, this, &MainWindow::slotProcessDockDisplay);
// 注释下面这条代码可以控制是否显示 处理 这个界面
dock_map_[title] = pdw;
pdw->refreshAlgorithmPlugin(); 
// 设置 processwidget为docksensor的tab
this->tabifyDockWidget(dock_sensor_, pdw);

//
void MainWindow::slotProcessDockDisplay()
{
    if (this->dock_map_[QString::fromLocal8Bit("处理")]->isVisible())
    HY_LOG_E("the ProcessDock display!");
}
```

## 创建停靠窗口完整代码

```cpp
#include "dockwindow.h"
#include<QTextEdit>
#include <QDockWidget>

DockWindow::DockWindow(QWidget *parent)
    : QMainWindow(parent)
{

    setWindowTitle("停靠窗口");

    QTextEdit *te = new QTextEdit("MainWindow",this);
    te->setAlignment(Qt::AlignCenter);
    setCentralWidget(te);

    //停靠窗口1
    QDockWidget *dw1 = new QDockWidget("停靠窗口1",this);//构建停靠窗口，指定父类

    dw1->setFeatures(QDockWidget::DockWidgetMovable | QDockWidget::DockWidgetClosable);//设置停靠窗口特性，可移动，可关闭

    dw1->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);//设置可停靠区域为主窗口左边和右边

    QTextEdit *dte = new QTextEdit("DockWindow First");
    dw1->setWidget(dte);
    addDockWidget(Qt::RightDockWidgetArea,dw1);

    //停靠窗口2
    QDockWidget *dw2 = new QDockWidget("停靠窗口2",this);//构建停靠窗口，指定父类

    dw2->setFeatures(QDockWidget::DockWidgetFloatable | QDockWidget::DockWidgetClosable);//设置停靠窗口特性，可浮动,可关闭

    QTextEdit *dte2 = new QTextEdit("DockWindow Second");
    dw2->setWidget(dte2);
    addDockWidget(Qt::RightDockWidgetArea,dw2);

    //停靠窗口3
    QDockWidget *dw3 = new QDockWidget("停靠窗口3",this);//构建停靠窗口，指定父类

    dw3->setFeatures(QDockWidget::AllDockWidgetFeatures);//设置停靠窗口特性，具有全部停靠窗口的特性

    QTextEdit *dte3 = new QTextEdit("DockWindow Third");
    dw3->setWidget(dte3);
    addDockWidget(Qt::RightDockWidgetArea,dw3);
}
```

## 构造函数、析构函数和函数列表

### 构造函数

3.它的构造方法之一是：指定标题和父窗口

```cpp
QDockWidget *dw1 = new QDockWidget("停靠窗口1",this);//构建停靠窗口，指定父类
```

```cpp
QDockWidget(QWidget *parent = nullptr, Qt::WindowFlags flags = Qt::WindowFlags())
QDockWidget(const QString &title, QWidget *parent = nullptr, Qt::WindowFlags flags = Qt::WindowFlags())
virtual	~QDockWidget()

public:
Qt::DockWidgetAreas	allowedAreas() const
QDockWidget::DockWidgetFeatures	features() const
bool	isAreaAllowed(Qt::DockWidgetArea area) const
bool	isFloating() const
void	setAllowedAreas(Qt::DockWidgetAreas areas)
void	setFeatures(QDockWidget::DockWidgetFeatures features)
void	setFloating(bool floating)
void	setTitleBarWidget(QWidget *widget)
void	setWidget(QWidget *widget)
QWidget *	titleBarWidget() const
QAction *	toggleViewAction() const
QWidget *	widget() const
```

## Signals

```cpp
void	allowedAreasChanged(Qt::DockWidgetAreas allowedAreas)
void	dockLocationChanged(Qt::DockWidgetArea area)
void	featuresChanged(QDockWidget::DockWidgetFeatures features)
void	topLevelChanged(bool topLevel)
void	visibilityChanged(bool visible)
```
