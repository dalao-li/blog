/*
 * @Description:
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao@xxx.com
 * @Date: 2022-08-07 13:15:01
 * @LastEditors: DaLao
 * @LastEditTime: 2022-09-03 01:20:16
 */

package main

import (
	"log"
	"os"
)

var (
	f   *os.File
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