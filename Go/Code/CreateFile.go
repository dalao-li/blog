/*
 * @Description:
 * @Version: 1.0
 * @Author: DaLao
 * @Email:  
 * @Date: 2022-08-07 13:15:01
 * @LastEditors: dalao
 * @LastEditTime: 2023-04-13 21:35:46
 */

package main

import (
    "log"
    "os"
)

func main() {
    f, err := os.Create("test.txt")

    defer f.Close()

    if err != nil {
        log.Fatal(err)
    }

    log.Println(f)
}
