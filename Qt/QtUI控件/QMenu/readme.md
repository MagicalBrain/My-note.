# QMenu

这是Qt里用来实现文件菜单的类

## 构造函数、析构函数及函数

```cpp
QAction *	actionAt(const QPoint &pt) const
QRect	actionGeometry(QAction *act) const
QAction *	activeAction() const
QAction *	addAction(const QString &text)
QAction *	addAction(const QIcon &icon, const QString &text)
QAction *	addAction(const QString &text, const QObject *receiver, const char *member, const QKeySequence &shortcut = 0)
QAction *	addAction(const QIcon &icon, const QString &text, const QObject *receiver, const char *member, const QKeySequence &shortcut = 0)
QAction *	addAction(const QString &text, Functor functor, const QKeySequence &shortcut = 0)
QAction *	addAction(const QString &text, const QObject *context, Functor functor, const QKeySequence &shortcut = 0)
QAction *	addAction(const QIcon &icon, const QString &text, Functor functor, const QKeySequence &shortcut = 0)
QAction *	addAction(const QIcon &icon, const QString &text, const QObject *context, Functor functor, const QKeySequence &shortcut = 0)
QAction *	addMenu(QMenu *menu)
QMenu *	addMenu(const QString &title)
QMenu *	addMenu(const QIcon &icon, const QString &title)
QAction *	addSection(const QString &text)
QAction *	addSection(const QIcon &icon, const QString &text)
QAction *	addSeparator()
void	clear()
QAction *	defaultAction() const
QAction *	exec()
QAction *	exec(const QPoint &p, QAction *action = nullptr)
void	hideTearOffMenu()
QIcon	icon() const
QAction *	insertMenu(QAction *before, QMenu *menu)
QAction *	insertSection(QAction *before, const QString &text)
QAction *	insertSection(QAction *before, const QIcon &icon, const QString &text)
QAction *	insertSeparator(QAction *before)
bool	isEmpty() const
bool	isTearOffEnabled() const
bool	isTearOffMenuVisible() const
QAction *	menuAction() const
void	popup(const QPoint &p, QAction *atAction = nullptr)
bool	separatorsCollapsible() const
void	setActiveAction(QAction *act)
void	setAsDockMenu()
void	setDefaultAction(QAction *act)
void	setIcon(const QIcon &icon)
void	setSeparatorsCollapsible(bool collapse)
void	setTearOffEnabled(bool)
void	setTitle(const QString &title)
void	setToolTipsVisible(bool visible)
void	showTearOffMenu(const QPoint &pos)
void	showTearOffMenu()
QString	title() const
NSMenu *	toNSMenu()
bool	toolTipsVisible() const
```
