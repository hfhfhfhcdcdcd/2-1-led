## 一、python安装
1、python官网：https://www.python.org/

2、重启生效确认：python --version

3、安装所需库：pip install pyserial

4、如果需要升级，就按提示运行：python.exe -m pip install --upgrade pip



## 二、安装stcgal包
1、cmd → pip install stcgal

2、安装成功后 继续敲 where stcgal，如果显示路径，则安装成功

3、将路径复制下来（\stcgal.exe不复制）

4、stcgal -h。出现usage: stcgal [-h] [-e] [-a] ... 表示成功




## 三、配置VScode和EIDE插件

1、"C:/Users/lenovo/Desktop/KeilProject/ddd"

  "configurationProvider": "cl.eide"


2、修改烧录命令：python ./tools/stcflash.py -p COM8 "${hexFile}"

3、C/C++ 属性里：
| 步骤 | 内容 |
|:-----|:------|
| ①    |添加工程  的  头文件  的路径         |
| ②    | 芯片自己的头文件的路径，江协老师用的芯片是Atmel：路径在你安装的keil的安装目录下，我的是：E:\Keil_v5_C51\C51\INC\Atmel      |
