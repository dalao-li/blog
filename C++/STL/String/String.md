<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2022-01-13 12:21:39
 * @LastEditors: DaLao
 * @LastEditTime: 2022-09-04 13:12:41
-->


## String


### c_str

```c
const char*c_str() const
```

c_str()函数返回一个指向正规C字符串的指针常量, 内容与本string串相同



### 函数


#### getline

输入一行可含空格的str

```c
std::string str;

getline(cin, str);
```


#### find

```c++
#include<iostream>
#include<string>

int main() {
    int sum = 0;
    std::string s1, s2;
    std::cin >> s1 >> s2;
    for(int i = 0; i < s1.size(); i++){
        if(s1.find(s2, i) != std::string::npos){
            sum++;
        }
    }
    std::cout << sum << std::endl;
    return 0;
}
```


#### erase

```c++
#include<iostream>
#include<string>

int main() {
    std::string str = " 123 456237";
    int index = 3;
    int length = 1;
    std::str.erase(index, length);
    std::cout << str << std::endl;
    return 0;
}
```