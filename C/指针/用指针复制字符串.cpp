#include<stdio.h>
int main(){
	char a[]="Ich liebe dich!"，b[20];
	char *p1，*p2;
	for(p1=a，p2=b;*p1!='\0';p1++，p2++){
		*p2=*p1;
	}
	*p2='\0';
	printf("a is:%s\nb is:%s\n"，a，b);
	
	for(p1=a;*p1!='\0';p1++){
		printf("%c"，*p1);
	}
	return 0;
} 
