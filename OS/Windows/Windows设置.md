<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao@xxx.com
 * @Date: 2022-07-06 20:08:07
 * @LastEditors: dalao
 * @LastEditTime: 2023-04-05 02:23:42
-->

# Winodws设置


## 设置Host

```sh
C:\Windows\System32\drivers\etc\host
```


## 关闭window defener


```sh
reg add "HKEY_LOCAL_MACHINE\SOFTWARE\Policies\Microsoft\Windows Defender" /v "DisableAntiSpyware" /d 1 /t REG_DWORD /f
```


## MBR->GPT


```sh
# 查询所有磁盘
list disk

# 选中目标盘
select disk 需转换格式磁盘的数字编号

# 清空磁盘
clean

# 转换位gpt分区
convert gpt
```
