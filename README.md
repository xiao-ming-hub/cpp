C++写的一些小项目

# 编译
```sh
make makabaka
```
`makabaka`：你要编译的代码去掉 `.cpp` 后缀后的名字。  
全部编译可以直接 `make all`

# 功能
| 文件                  | 作用                                |
| --------------------- | ----------------------------------- |
| brainfuck.cpp         | Bainfuck 解释器                     |
| golden-section.cpp    | 使用牛顿迭代法计算黄金分割          |
| rand-string.cpp       | 生成随机字符串                      |
| time.cpp              | 带进度条地显示时间                  |
| cube-scrambling.cpp   | 魔方打乱生成                        |
| hex-color.cpp         | 查看 16 进制颜色                    |
| unicode.c             | 基于unicode字符集的英语字体转换工具 |

# 使用
```
golden-section
```
`\n` 下一轮，`^D` 退出。

```
rand-string [n]
```
生成长度为 `n` 的随机字符串，`n` 默认为 10。

```
time
```  
显示时间，按 `q` 退出。以后也许会加上颜色。

```
brainfuck <file>
```
运行代码。以后用异或链表重写一遍。

```
hex-color <num>
```
传入 6 位小写 16 进制数，不带 0x。如 002a22。
