#include<stdio.h>
#include<stdlib.h>
#define LEN sizeof(struct Student)
struct Student {
	long num;
	int score;
	Student*next;
};
int n;
struct Student *creat(void) {
	struct Student*head，*p1，*p2;
	n=0;
	p1=p2=(struct Student*)malloc (LEN);  //p1=p2= new Student stu;
	scanf("%ld，%f，&p1->num，&p1->score");
	head=NULL;
	while(p1->num!=0) {
		n+=1;
		if(n==1) {
			head=p1;
		}
		p1=(struct Student*)malloc(LEN);
		scanf("%ld，%f，&p1->num，&p1->score");
	}
	p2->next=NULL;
}

int main() {
	struct Student*pt;
	pt=creat();
	printf("\nnum:%ld\nscore:%5.1f\n"，pt->num，pt->score);
	return 0;

}



