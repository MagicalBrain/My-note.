# K-means 算法

---

## 算法描述

第一步：
给定K个选定的中心点；

第二步：
计算每个点到中心点的距离

第三步：
根据算出来的距离把各个点分配给中心点

第四步：
重新计算每个族的中心点坐标

第五步：
重复2、3、4，直至中心点坐标不再变化（算法收敛）

## 示例

### 一个简单的例子（一维的）

假设有14个人，年龄分布如下，要把他们分成三类

```matlab
clear;
clc;

X = [1 3 5 8 9 11 12 13 37 43 45 49 51 65];

% k = 3;
% K = [1:1:k];
L = length(X);

K = [10 20 45];
L0 = length(K);

while(true)
    n1 = 1;n2 = 1; n3 = 1;
    
     X1 = [];
     X2 = [];
     X3 = [];
    for i = 1:L
    
        C1(i) = abs( X(i) - K(1) );
        C2(i) = abs( X(i) - K(2) );
        C3(i) = abs( X(i) - K(3) );
        
       
        switch(min([C1(i) C2(i) C3(i)]))
            case C1(i)
                X1(1,n1) = X(i);
                n1= n1 + 1;
            case C2(i)
                X2(1,n2) = X(i);
                n2 = n2+1;
            case C3(i)
                X3(1,n3) = X(i);
                n3 = n3 + 1;
            otherwise
                break;
        end
    
    end
    
    if ( ~isempty(X1) )
        K0(1) = round( mean(X1) );
    end
    if (~isempty(X2))
        K0(2) = round( mean(X2) );
    end
    if (~isempty(X3))
        K0(3) = round( mean(X3) );
    end

    if K0 == K
        break;
    else
        K = K0; 
    end
end


```

### python实现
不够完善

```python
'''
由于对算法理解的问题，这是个k-means算法而不是KNN
'''

import matplotlib.pyplot as plt
import numpy as np
import operator
from functools import reduce

'''
a = [[1,2,3], [4,6], [7,8,9,8]]
print(reduce(operator.add, a))
[1, 2, 3, 4, 6, 7, 8, 9, 8]
'''

def K_means(X,K,iter = 0):
    L = X.size
    K0 = K
    Lk = K.size

    C = np.empty(shape=[Lk, 1])
    F = np.empty(shape=[Lk, 1])
    Xn = np.empty(shape=[Lk, 1])
    '''
    C1 = np.empty(shape=[0, 1])
    C2 = np.empty(shape=[0, 1])
    C3 = np.empty(shape=[0, 1])

    F1 = np.empty(shape=[0, 1])
    F2 = np.empty(shape=[0, 1])
    F3 = np.empty(shape=[0, 1])

    X1 = np.empty(shape=[0, 1])
    X2 = np.empty(shape=[0, 1])
    X3 = np.empty(shape=[0, 1])
    '''


    iter_start = 0
    while True:
        for j in range(0,Lk):
            for i in range(0, L):
                C[0:] = np.append(C[0:], [[abs(X[i] - K[0])]], axis=0)
                C[1:] = np.append(C[1:], [[abs(X[i] - K[1])]], axis=0)
                C[2:] = np.append(C[2:], [[abs(X[i] - K[2])]], axis=0)

                flag = np.min(C[:i])
                if flag == C1[i]:
                    X1 = np.append(X1, [C1[i]], axis=0)
                    F1 = np.append(F1, [[X[i]]], axis=0)
                elif flag == C2[i]:
                    X2 = np.append(X2, [C2[i]], axis=0)
                    F2 = np.append(F2, [[X[i]]], axis=0)
                elif flag == C3[i]:
                    X3 = np.append(X3, [C3[i]], axis=0)
                    F3 = np.append(F3, [[X[i]]], axis=0)

        #if not np.isnan(F1):
        K0[0] = np.mean(F1)
        #if not np.isnan(F2):
        K0[1] = np.mean(F2)
        #if not np.isnan(F3):
        K0[2] = np.mean(F3)
        iter_start += 1

        if (iter == 0):
            if (K0 == K).all():
                break
            else:
                K = K0
        elif (iter_start >= iter):
            break
    #print(F1,F2,F3)
    #F = np.array([F1,F2,F3])
    return F1,F2,F3,K

X = np.array([1, 3, 5, 8, 9, 11, 12, 13, 37, 43, 45, 49, 51, 65])
K = np.array([5, 20,40])


[F1,F2,F3,K0] = K_means(X,K)

print(F1.transpose())
print(F2.transpose())
print(F3.transpose())

F1= F1.transpose()
F2= F2.transpose()
F3= F3.transpose()
print(K)
# print(F[1])
K1 = np.ones(F1.size)
K1 = np.dot(K1,K0[0])

K2 = np.ones(F2.size)
K2 = np.dot(K2,K0[1])

K3 = np.ones(F3.size)
K3 = np.dot(K3,K0[2])

F1 = reduce(operator.add, F1)
print(K1)
plt.scatter(F1,K1)
plt.scatter(F2,K2)
plt.scatter(F3,K3)
plt.show()

```

### 基于sklearn的实现
```python
import numpy as np
from sklearn.cluster import KMeans
 
 
def loadData(filePath):
    fr = open(filePath,'r+')
    lines = fr.readlines()
    retData = []
    retCityName = []
    for line in lines:
        items = line.strip().split(",")
        retCityName.append(items[0])
        retData.append([float(items[i]) for i in range(1,len(items))])
    return retData,retCityName
 
     
if __name__ == '__main__':
    data,cityName = loadData('city.txt')
    km = KMeans(n_clusters=4)
    label = km.fit_predict(data)
    expenses = np.sum(km.cluster_centers_,axis=1)
    #print(expenses)
    CityCluster = [[],[],[],[]]
    for i in range(len(cityName)):
        CityCluster[label[i]].append(cityName[i])
    for i in range(len(CityCluster)):
        print("Expenses:%.2f" % expenses[i])
        print(CityCluster[i])
```
