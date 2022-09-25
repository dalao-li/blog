<!--
 * @Description: 
 * @Version: 1.0
 * @Author: daLao
 * @Email: dalao@xxx.com
 * @Date: 2022-09-13 23:28:35
 * @LastEditors: daLao
 * @LastEditTime: 2022-09-15 00:17:45
-->

## thread

### 函数

#### 无参数函数


```c++
void func()
{
    for (int i = 0; i < 10; ++i)
    {
        std::cout << "func" << std::endl;
    }
}


std::thread t(func);

t.join();
```


#### 含参数函数


#### 类成员函数



### 同步


#### join

#### detach