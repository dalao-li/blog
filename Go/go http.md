<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-01-16 17:59:34
 * @LastEditors: DaLao
 * @LastEditTime: 2022-01-13 14:40:49
-->

## Web Hello World

```go
package main

import (
    "fmt"
    "net/http"
)

func main() {
    http.HandleFunc("/" , func(w http.ResponseWriter, r *http.Request) {
        fmt.Fprint(w , "Hello, World!")
    })
    fmt.Println("Please Visit -  http://localhost:8888/")
    http.ListenAndServe(":8888" , nil)
}
```

![](https://cdn.hurra.ltd/img/20210110181933.png)

## 并发 Hello World

```go
package main

import (
	"fmt"
	"time"
)

func main() {
	for i := 0; i < 5; i++ {
		go printHello(i)
	}
	time.Sleep(time.Millisecond)
}

func printHello(i int) {
	fmt.Printf("Hello World from goroutine %d!\n",i)
}
```

![](https://cdn.hurra.ltd/img/20210110194117.png)
