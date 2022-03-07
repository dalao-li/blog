

```c
#include<iostream>
#include<fstream>

using namespace std;

int main(){
    ifstream is("a.png" , ifstream::in | ios::binary);
    is.seekg(0 , is.end);
    int length = is.tellg();
    is.seekg(0 , is.beg);
    printf("length : %d\n" , length);
    char *buffer = new char[length];
    is.read(buffer , length);
    for(int i = 0; i < length; i++){
        printf("%x" , buffer[i]);
    }
    printf("\n\n%s\n" , buffer);
    delete[] buffer;
    return 0;
}
```

https://blog.csdn.net/qq_24003917/article/details/107425216
