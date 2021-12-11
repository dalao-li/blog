#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<string>
using namespace std;

class Student {
	public:
		Student() {}
		Student(string iname，float iscore):name(iname)，score(iscore) {}
		~Student() {}

		string name;
		float score;
};

class StudentAdapter:public unary_function<Student，bool> {
	private:
		string name;
	public:
		explicit StudentAdapter(string iname):name(iname) {}
		//重载()运算符
		bool operator()(const Student& student) {
			return (student.name==name);
		}
};

int main() {
	vector<Student> v;
	vector<Student>::iterator it;
	Student stu1("lanzhihui"，89.1);
	Student stu2("wangdan"，89.2);
	Student stu3("wangqian"，89.3);
	v.push_back(stu1);
	v.push_back(stu2);
	v.push_back(stu3);

	for(it=v.begin(); it!=v.end(); ++it) {
		cout<<it->name<<" "<<it->score<<endl;
	}
	cout<<endl;
    cout<<"输入名字"<<endl;
    string str;
    cin>>str;
	//实验find_if
	it=find_if(v.begin()，v.end()，StudentAdapter(str));

	if(it!=v.end()) {
		cout<<"找到了"<<endl;
		cout<<it->name<<" "<<it->score<<endl;
	}

	system("pause");
	return 0;
}

