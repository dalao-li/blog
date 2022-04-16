/*
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-10-06 13:11:32
 * @LastEditors: DaLao
 * @LastEditTime: 2022-01-26 22:49:43
 */

#include<bits/stdc++.h>
#define SIZE 3

using namespace std;
struct Stu {
    char name[20];
    long num;
    int age;
} stu[SIZE];

void saveFile() {
    FILE *fp;
    if((fp=fopen("stu.txt" , "wb"))==NULL) {
        cout<<"cannot open file"<<endl;
        exit(0);
    }
    for(int i=0; i<SIZE; i++) {
        if(fwrite(&stu[i] , sizeof(struct Stu) , 1 , fp)!=1) {
            cout<<"file write error"<<endl;
        }
    }
    fclose(fp);
}
int main() {
    for(int i=0; i<SIZE; i++) {
        cin>>stu[i].name >>stu[i].num >>stu[i].age;
    }
    saveFile();
    return 0;
}
