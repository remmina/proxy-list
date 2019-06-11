<!--
 * @Author: Remmina
 * @LastEditors: EagleXiang
 * @Email: 
 * @Github: 
 * @Date: 
 * @LastEditTime: 2019-06-11 22:40:30
 -->
 
# Proxy List

## 目录结构

+ `proxylist.txt`：需要代理的域名列表
+ `directlist.txt`：直连域名列表
+ `clear`：列表后缀去重、排序程序

## 文件结构

列表每行一个域名（或域名后缀，如.cn），对请求域名与列表进行后缀匹配即可（[参考](./rule.txt)）

## 去重程序（`clear`）

由 C++ 编写，使用 Trie 树进行后缀去重，可以保证列表不存在某一行是另一行的后缀，去重后按字典序排序输出

使用方法：`./clear [filename]`，如：`./clear proxylist.txt`

理论最大能处理的字符总数为一千万（文件不得大于9.5兆）（当然你可以通过修改`clear.cpp`来调整）

## 其他

实际上一开始是为 eagle.tunnel 项目（一个稳定的代理工具）收集的这个列表

+ eagle.tunnel：[eagle.tunnel.go](https://github.com/eaglexiang/eagle.tunnel.go)
+ 以及我写的图形化外壳：[ET-electron](https://github.com/remmina/et-electron)

`proxylist.txt`主要借鉴于[gfwlist](https://github.com/gfwlist/gfwlist)

`directlist.txt`主要借鉴于[gfw_whitelist](https://github.com/breakwa11/gfw_whitelist)

在此特别感谢

另外现在列表并不是特别完全，欢迎提交 PR