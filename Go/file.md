<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-11-18 23:57:41
 * @LastEditors: DaLao
 * @LastEditTime: 2022-03-27 22:50:20
-->

## 文件操作

```go
package main
import (
    "log"
    "os"
)

var (
    f *os.File
    err error
)

func main() {
    f, err = os.Create("文件名")
    if err != nil {
        log.Fatal(err)
    }
    log.Println(f)
    f.Close()
}
```