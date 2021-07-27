# Kuka机器人插件的测试

## 使用TCP助手测试

### 测试目的

1. 机器人是否收到XML报文
2. 机器人是否收到正确的XML报文

测试报文：

读取机器人当前坐标
```xml
<Robot><Pos><X>100</X><Y>100</Y><Z>100</Z><A>0</A><B>0</B><C>0</C></Pos><ready>TRUE</ready><chuck>FALSE</chuck><readRobotStatus>TRUE</readRobotStatus><onlySetIO>FALSE</onlySetIO></Robot>
```

修改坐标
```xml
<Robot><Pos><X>694.875427</X><Y>-14.495961</Y><Z>1400.047485</Z><A>151.908005</A><B>0.438921</B><C>177.193237</C></Pos><ready>TRUE</ready><chuck>FALSE</chuck><readRobotStatus>FALSE</readRobotStatus><onlySetIO>FALSE</onlySetIO></Robot>
```

```xml
<Robot><Pos><X>800</X><Y>-25</Y><Z>1400</Z><A>-178</A><B>50</B><C>-75</C></Pos><ready>TRUE</ready><chuck>FALSE</chuck><readRobotStatus>FALSE</readRobotStatus><onlySetIO>FALSE</onlySetIO></Robot>
```

当前坐标
```
<Robot><Pos><X>694.875427</X><Y>-14.495961</Y><Z>1275.047485</Z><A>151.908005</A><B>0.438921</B><C>177.193237</C></Pos><ready>0</ready><chuck>0</chuck><readRobotStatus></readRobotStatus><onlySetIO></onlySetIO></Robot>
```

放送的报文：
<Robot><Pos><X>694.875427</X><Y>-14.495961</Y><Z>1400.047485</Z><A>151.908005</A><B>0.438921</B><C>177.193237</C></Pos><ready>TRUE</ready><chuck>FALSE</chuck><readRobotStatus>FALSE</readRobotStatus><onlySetIO>FALSE</onlySetIO></Robot>

最终走到的坐标：
<Robot><Pos><X>492.929260</X><Y>24.421587</Y><Z>876.277100</Z><A>100.350853</A><B>0.909800</B><C>116.981949</C></Pos><ready>0</ready><chuck>0</chuck><readRobotStatus></readRobotStatus><onlySetIO></onlySetIO></Robot>

----

当前坐标：
<Robot><Pos><X>619.909790</X><Y>26.005966</Y><Z>1178.915649</Z><A>103.119728</A><B>-5.989623</B><C>171.398071</C></Pos><ready>0</ready><chuck>0</chuck><readRobotStatus></readRobotStatus><onlySetIO></onlySetIO></Robot>

发送报文：
```xml
<Robot><Pos><X>619.909790</X><Y>26.005966</Y><Z>1300.915649</Z><A>103.119728</A><B>-5.989623</B><C>171.398071</C></Pos><ready>TRUE</ready><chuck>FALSE</chuck><readRobotStatus>FALSE</readRobotStatus><onlySetIO>FALSE</onlySetIO></Robot>
```

最终走到的坐标：
不行，这玩意是往下走的，得调试看看怎么回事

----

使用WoV调试，查看点位变量变化情况：

当前坐标：
<Robot><Pos><X>598.171814</X><Y>33.578373</Y><Z>1157.414307</Z><A>94.299927</A><B>-5.953187</B><C>151.019241</C></Pos><ready>0</ready><chuck>0</chuck><readRobotStatus></readRobotStatus><onlySetIO></onlySetIO></Robot>

发送报文：
```xml
<Robot><Pos><X>598.171814</X><Y>33.578373</Y><Z>1200.414307</Z><A>94.299927</A><B>-5.953187</B><C>151.019241</C></Pos><ready>TRUE</ready><chuck>FALSE</chuck><readRobotStatus>FALSE</readRobotStatus><onlySetIO>FALSE</onlySetIO></Robot>
```

~~不知道哪里~~出问题了，坐标没有发出去。
可能是EtherNet编程这块出了问题，导致坐标发出去后，机器人收到了但没有存进存储器。

----

21-07-27

```xml
<Robot><Pos><X>562.156006</X><Y>38.401821</Y><Z>1080.961060</Z><A>87.447136</A><B>-5.970125</B><C>140.362366</C></Pos><ready>0</ready><chuck>0</chuck><readRobotStatus></readRobotStatus><onlySetIO></onlySetIO></Robot>
```

```xml
<Robot><Pos><X>562.156006</X><Y>38.401821</Y><Z>1200.961060</Z><A>87.447136</A><B>-5.970125</B><C>140.362366</C></Pos><ready>TRUE</ready><chuck>FALSE</chuck><readRobotStatus>FALSE</readRobotStatus><onlySetIO>FALSE</onlySetIO></Robot>
```

## 使用PluginTest.exe测试

### 测试目的

1. 插件是否能够连接上机器人
2. 是否能够设置速度
3. 是否能够修改点位坐标
4. 是否能够让机器人运动
5. 是否能够开始对机器人进行引导

## 在HYpick里使用KUKA插件测试

### 测试目的


