/*
 * @Description:
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2022-07-22 22:18:47
 * @LastEditors: DaLao
 * @LastEditTime: 2022-09-03 01:20:10
 */

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
