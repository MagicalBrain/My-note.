# Linux如何在root下打开vscode

## 终端进入root模式

```bash
sudo su
```

## 尝试运行vscode

```bash
code .

# 报错提示

You are trying to start Visual Studio Code as a super user which isn't recommended. If this was intended, please add the argument `--no-sandbox` and specify an alternate user data directory using the `--user-data-dir` argument.
```

```bash
code . --no-sandbox --user-data-dir ="~/.vscode-root"
```
