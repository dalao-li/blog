/*
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-12-23 15:07:51
 * @LastEditors: DaLao
 * @LastEditTime: 2021-12-27 16:40:49
 */
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<string>
using namespace std;

class Stu {
	public:
		Stu(string name,float score):name(name),score(score) {}
		string name;
		float score;
};

class StuAdapter:public unary_function<Stu , bool> {
	private:
		string name;
	public:
		explicit StuAdapter(string name):name(name) {}
		// 重载()运算符
		bool operator()(const Stu &Stu) {
			return Stu.name == name;
		}
};

int main() {
	vector<Stu> v;
	v.push_back(Stu("lanzhihui",89.1));
	v.push_back(Stu("wangdan",89.2));
	v.push_back(Stu("wangqian",89.3));

	// 按名字查找
    string str;
    cin >> str;
	vector<Stu>::iterator it = find_if(v.begin() , v.end() , StuAdapter(str));
	// 查找到
	if(it != v.end()) {
		
	}
	return 0;
}

