# python 文件读写操作

标签（空格分隔）： Python

---

## 导入pickle模块
### 保存文件
```python
# 假设有game_data这个数据要存

# 开
# save_file 为文件变量
save_file = open("save.dat","wb")
# 存
pickle.dump(game_data,save_file)
# 关
save_file.close()
```

### 读取文件
```python
# 假设有save_data.dat这个文件要读

# 开
# load_file 为文件变量
load_file = open("save_data.dat","wb")
# 存
game_data = pickle.load("save_data.dat","rb")
# 关
load_file.close()
```




