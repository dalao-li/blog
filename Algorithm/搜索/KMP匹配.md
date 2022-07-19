<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-11-13 20:57:00
 * @LastEditors: DaLao
 * @LastEditTime: 2022-05-10 22:44:11
-->

## KMP

```c
// 获得next数组
void setNext(string str, int next[]){
    next[0] = -1;
    int i = 0;
    // -1作为越界判断标识
    int j = -1;
    while (i < str.length()){
        // 如果越界(到了开头)或者匹配上了
        if (j == -1 || str[i] == str[j]){
            // 都往后移
            i++;
            j++;
            next[i] = j;
        }else{
            // 否则j指针回溯, 回溯位置为next[j]
            j = next[j];
        }
    }
}

// 字符串匹配, 返回值是p串在s串中首次匹配到的位置
int kmp(string &s, string &p, int next[]) {
    // i表示s字符串匹配到的位置
    int i = 0;
    // j表示p字符串匹配到的位置
    int j = 0;
    while (i < s.length()) {
        // 若在p字符串起始位置或者完成了匹配
        if (j == -1 || s[i] == p[j]) {
            i++;
            j++;
            // 若已经将p匹配完, 则跳出循环
            if (j == p.length()) {
                break;
            }
        }
        else {
            j = next[j];
        }
    }
    if (j == p.length()) {
        return i - j;
    }
    return -1;
}
```