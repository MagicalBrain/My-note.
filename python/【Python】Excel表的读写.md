# Python文件读写 高级应用01 Excel表的读写

标签（空格分隔）： Python

---

## 读取Excel表的数据
由于Excel表可以将转换成csv格式，而python又可以直接将csv格式的文件里的数据直接存入list，非常方便后面的操作

### 法一
xlrd第三方库

```python
import xlrd


def read_excel():
    workbook = xlrd.open_workbook(r'C:\Users\37487\Desktop\品种1猪数据.xlsx');

    print("所有工作簿名字：%s" % workbook.sheet_names())

    # sheet = workbook.sheet_by_index(0)
    sheet = workbook.sheet_by_name('Sheet1')
    # 以上两种二选一，均可读取对应的工作簿数据

    print('工作簿名字： %s\n' % sheet.name,'总行数： %s' % sheet.nrows,'总列数： %s' % sheet.ncols)

    # 获取整行和整列的值（数组）
    rows = sheet.row_values(3)  
    # 按行读取，获取第四行内容
    cols = sheet.col_values(2)  
    # 按列读取，获取第三列内容
    print(rows)
    print(cols)

    # 获取单元格内容
    # 如果是字符则需要：sheet.cell(1, 0).value.encode('utf-8')
    print(sheet.cell(1, 0).value)
    print(sheet.cell_value(1, 0))
    print(sheet.row(1)[0].value)
    # 以上三条语句均是读取同一个单元格的内容

    # 获取单元格内容的数据类型
    print(sheet.cell(1, 0).ctype)

read_excel()
```

### 法二
**读取csv文件数据**
```python
#codeing:utf-8
import csv

X = []
Y = []

with open('C:\\Users\\37487\\Desktop\\品种1猪数据.CSV') as csvfile:
    reader = csv.DictReader(csvfile)
    for row in reader:
        x = [row['温度平均值'],row['湿度'],row['肥瘦程度'],row['胎次'],row['疾病总和']]
        X.append(x)
        y = [row['总猪仔数'],row['健康猪数']]
        Y.append(y)
        i+=1
        print("\n")
        print(x)
        print("\n")
        print(y)

print(X)
print("\n")
print(Y)
```

## 写入

### 写入CSV

### 写入Excel文件
法一： 使用三方库xlwt
```python
writebook = xw.Workbook(r'C:\Users\Administrator\Desktop\机器学习与神经网络\自己练习数据\output01.xlsx')
table = writebook.add_sheet('sheet1')

for i in range(0,3325):
    table.write(i,0,i)
    table.write(i,1,C[i])

writebook.save(r'C:\Users\Administrator\Desktop\机器学习与神经网络\自己练习数据\output01.xls')
```


法二：使用三方库盘panda


