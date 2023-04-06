/*
 * @Description:
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao@xxx.com
 * @Date: 2022-08-07 13:15:01
 * @LastEditors: Li Yuanhao
 * @LastEditTime: 2023-04-05 02:14:58
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
	f, err = os.Create("filename")

	if err != nil {
		log.Fatal(err)
	}

	log.Println(f)

	f.Close()
}
