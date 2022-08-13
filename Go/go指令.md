<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2022-08-04 23:46:59
 * @LastEditors: DaLao
 * @LastEditTime: 2022-08-07 13:16:08
-->

## go指令


main.go

```go
package main

import (
	"fmt"
)

func main() {
	fmt.Println("Hello World!")
}
```


### 运行


```go
go run main.go
```

### 编译

```go
go build main.go
```


### 命令行参数

```go
package main

import (
	"fmt"
	"os"
)

func main() {
	for i := 1; i < len(os.Args); i++ {
		fmt.Println(os.Args[i])
	}
}
```

