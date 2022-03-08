<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2022-03-01 21:46:15
 * @LastEditors: DaLao
 * @LastEditTime: 2022-03-08 21:23:16
-->

## PNG


### 文件结构

PNG文件结构，主要有数据块(Chunk Block)组成，最少包含4个数据块

- PNG标识符

- 文件头数据块（IHDR）

- 图像数据块(IDAT)

...

- 结束数据块(IEND)


### 数据块结构

PNG文件中，每个数据块由4个部分组成

| 名称                           | 字节数   | 说明                                                |
| ------------------------------ | -------- | --------------------------------------------------- |
| Length（长度）                 | 4字节    | 指定数据块中数据域的长度                            |
| Chunk Type Code (数据块类型码) | 4字节    | 数据块类型码由ASCII字母(A-Z和a-z)组成的"数据块符号" |
| Chunk Data (数据块数据)        | 可变长度 | 存储按照Chunk Type Code指定的数据                   |
| CRC (循环冗余检测)             | 4字节    | 存储用来检测是否有错误的循环冗余码                  |

![](https://cdn.hurra.ltd/img/07121302_p6Qz.png)

![](https://cdn.hurra.ltd/img/20220302224513.png)


### 图像标识符

```sh
hexyl 07121302_p6Qz.png  
```

![](https://cdn.hurra.ltd/img/20220302224715.png)

文件头位置总是由位固定的字节来描述的：

| 进制       | 数值                     |
| ---------- | ------------------------ |
| 十进制数   | 137 80 78 71 13 10 26 10 |
| 十六进制数 | 89 50 4E 47 0D 0A 1A 0A  |

JPEG，PNG,GIF,BMP等图片都具有不同的图像标识符号，判读一个文件的正确mimeType类型，更应该通过标识符,而不是通过后缀名判断


### IHDR数据块

文件头数据块IHDR(header chunk)：它包含有PNG文件中存储的图像数据的基本信息，并要作为第一个数据块出现在PNG数据流中，而且一个PNG数据流中只能有一个文件头数据块。

文件头数据块由13字节组成，它的格式如下表所示。

| 域的名称           | 字节数  | 说明                                                                                                                                                       |
| ------------------ | ------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Width              | 4 bytes | 图像宽度，以像素为单位                                                                                                                                     |
| Height             | 4 bytes | 图像高度，以像素为单位                                                                                                                                     |
| Bit depth          | 1 byte  | 图像深度：索引彩色图像：1，2，4或8 ；灰度图像：1，2，4，8或16 ；真彩色图像：8或16                                                                          |
| ColorType          | 1 byte  | 颜色类型：0：灰度图像, 1，2，4，8或16；2：真彩色图像，8或16 3：索引彩色图像，1，2，4或8;4：带α通道数据的灰度图像，8或16; 6：带α通道数据的真彩色图像，8或16 |
| Compression method | 1 byte  | 压缩方法(LZ77派生算法)                                                                                                                                     |
| Filter method      | 1 byte  | 滤波器方法                                                                                                                                                 |
| Interlace method   | 1 byte  | 隔行扫描方法：0：非隔行扫描 ;1： Adam7(由Adam M. Costello开发的7遍隔行扫描方法)                                                                            |

由于本文很多设计到了PNG在手机方面的应用，因此在此提出MIDP1.0对所使用PNG图片的要求：

- 在MIDP1.0中，只可以使用1.0版本的PNG图片

- 文件大小：MIDP支持任意大小的PNG图片，然而实际上，如果一个图片过大，会由于内存耗尽而无法读取

- 颜色类型：所有颜色类型都有被支持，虽然这些颜色的显示依赖于实际设备的显示能力。同时，MIDP也能支持alpha通道，但是，所有的alpha通道信息都会被忽略并且当作不透明的颜色对待

- 色深：所有的色深都能被支持

- 压缩方法：仅支持deflate压缩方式，这和jar文件的压缩方式完全相同，所以，PNG图片数据的解压和jar文件的解压可以使用相同的代码

- 滤波器方法：在PNG中所有的5种方法都被支持

- 隔行扫描：虽然MIDP支持0、1两种方式，然而，当使用隔行扫描时，MIDP却不会真正的使用隔行扫描方式来显示

- PLTE chunk：支持

- IDAT chunk：图像信息必须使用5种过滤方式中的方式之一 (None, Sub, Up, Average, Paeth)

- IEND chunk：当IEND数据块被找到时，这个PNG图像才认为是合法的PNG图像

- 可选数据块：MIDP可以支持下列辅助数据块，然而，这却不是必须的

### 例

- 00 00 00 0d 说明IHDR头块长为13

- 49 48 44 52 IHDR标识

- 00 00 00 01 图像的宽，1像素

- 00 00 00 01 图像的高，1像素

- 04 色深，2^4=16，即这是一个16色的图像（也有可能颜色数不超过16，当然，如果颜色数不超过8，用03表示更合适）

- 03 颜色类型，索引图像

- 00 PNG Spec规定此处总为0（非0值为将来使用更好的压缩方法预留），表示使压缩方法(LZ77派生算法)
00 同上
00 非隔行扫描

- ae 5c b5 55 CRC校验

CRC代码

```java
import java.util.zip.CRC32;

public class CrcTest {

    
    public static void main(String[] args) {
            
         byte[] checkData = new byte[]{0x49,0x48,0x44,0x52,0x00,0x00,0x00, 0x08,0x00,0x00,0x00, 0x08,0x04,0x03,0x00,0x00,0x00};
         CRC32 crc32 = new CRC32();  
         crc32.update(checkData);
         long value = crc32.getValue();
         
         byte[] intToBytes = longToBytes(value);
         String bytesToHexString = bytesToHexString(intToBytes);
         System.out.println(bytesToHexString);
         
    }
    
    public static byte[] longToBytes(long value)   
    {   
        byte[] src = new byte[4];  
        src[0] = (byte) ((value>>24) & 0xFF);  
        src[1] = (byte) ((value>>16)& 0xFF);  
        src[2] = (byte) ((value>>8)&0xFF);    
        src[3] = (byte) (value & 0xFF);       
        return src;  
    } 
     //将字节数组按16进制输出
        public static String bytesToHexString(byte[] src){
            
            StringBuilder stringBuilder = new StringBuilder("");
            if (src == null || src.length <= 0) {
                return null;
            }
            for (int i = 0; i < src.length; i++)
            {
                int v = src[i] & 0xFF;
                String hv = Integer.toHexString(v);

                if (stringBuilder.length() != 0) {
                    stringBuilder.append(",");
                }
                if (hv.length() < 2) {
                    stringBuilder.append(0);
                }
                stringBuilder.append(hv);
            }
            return stringBuilder.toString();
        }

}

```
