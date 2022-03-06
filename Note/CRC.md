<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2022-03-06 23:43:42
 * @LastEditors: DaLao
 * @LastEditTime: 2022-03-07 00:04:49
-->

https://bigjar.github.io/2018/04/09/%E9%9A%90%E8%97%8F%E5%9C%A8%E5%9B%BE%E7%89%87%E4%B8%AD%E7%9A%84%E5%AF%86%E9%92%A5/#%E4%BE%8B%E5%AD%90

https://blog.csdn.net/u013073067/article/details/86621770?spm=1001.2101.3001.6650.1&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7ELandingCtr%7ERate-1.queryctrv4

https://www.cxymm.net/article/u014646950/51144476

https://www.lddgo.net/encrypt/crc

https://its401.com/article/lucboll/96480410

![](https://cdn.hurra.ltd/img/20220307000126.png)

![](https://cdn.hurra.ltd/img/20191025144036545.png)

![](https://cdn.hurra.ltd/img/20220307000418.png)

PNG图片中的CRC算法为CRC32。其多项式表示为0x04C11DB7或者0xEDB88320(反转)

```c
unsigned int getCrc32(unsigned char* inStr, unsigned int len) {
    unsigned int CRC32Table[256];
    unsigned int i,j;
    unsigned int CRC;
    for (i = 0; i < 256; i++) {
        CRC = i;
        for (j = 0; j < 8; j++) {
            if (CRC & 1)
                CRC = (CRC >> 1) ^ 0xEDB88320;
            else
                CRC >>= 1;
        }
        CRC32Table[i] = CRC;
    }
    CRC = 0xffffffff;
    for (unsigned int m = 0; m < len; m++) {
        CRC = (CRC >> 8) ^ CRC32Table[(CRC & 0xFF) ^ inStr[m]];
    }
    
    CRC ^= 0xFFFFFFFF;
    return CRC;
}
```