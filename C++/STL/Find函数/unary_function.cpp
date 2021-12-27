/*
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-12-23 15:07:51
 * @LastEditors: DaLao
 * @LastEditTime: 2021-12-27 16:41:10
 */

#include <iostream>     
#include <functional>   

struct IsOdd : public std::unary_function<int,bool> {
	bool operator() (int number) {
		return number & 1;
	}

};

int main () {
	IsOdd IsOdd_object;
	IsOdd::argument_type input;
	IsOdd::result_type result;
	std::cin >> input;
	result = IsOdd_object (input);
	std::cout << "Number " << input << " is " << (result?"odd":"even") << ".\n";
	return 0;

}
