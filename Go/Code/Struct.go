/*
 * @Description:
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao@xxx.com
 * @Date: 2022-08-07 13:15:01
 * @LastEditors: dalao
 * @LastEditTime: 2023-04-13 21:35:46
 */

package main

import "fmt"

type Student struct {
    id int
    name string
    school string
}

func main() {
	stu := new(Student)

	stu.id = 1000
	stu.name = "wang"
	stu.school = "MIT"

	fmt.Println(stu)
}