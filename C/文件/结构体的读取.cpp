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
    for(int i=0; i<SIZE; i++) {
        fread(&stu[i] , sizeof(struct Stu) , 1 , fp);
        cout<<stu[i].name <<" "<<stu[i].num <<" "<<stu[i].age<<endl;
    }
    fclose(fp);
    return 0;
}
