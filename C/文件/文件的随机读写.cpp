/*
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2022-02-13 19:00:24
 * @LastEditors: DaLao
 * @LastEditTime: 2022-03-15 22:04:43
 */
#include<bits/stdc++.h>
#define SIZE 3
using namespace std;

struct Stu {
    char name[20];
    long num;
    int age;
} stu[SIZE];

int main() {
    FILE *fp;
    if((fp=fopen("stu.txt" , "rb"))==NULL) {
        cout<<"cannot open file"<<endl;
        exit(0);
    }
    for(int i=0; i<SIZE; i+=2) {
        fseek(fp , i * sizeof(struct Stu) , 0);
        fread(&stu[i] , sizeof(struct Stu) , 1 , fp);
        cout<<stu[i].name <<" "<<stu[i].num <<" "<<stu[i].age<<endl;
    }
    fclose(fp);
    return 0;
}
