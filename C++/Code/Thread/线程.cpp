/*
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-01-16 17:59:38
 * @LastEditors: DaLao
 * @LastEditTime: 2021-02-20 20:48:40
 */
 
#include<iostream>
#include<thread>
#include<stdlib.h>
#include<time.h>
using namespace std;

void playThread01()
{
	for(int i=0;i<100;i++){
		cout<<i<<" "<<endl;
	}
}
void playThread02()
{
	//设置时间变量 
    int hour;  
    int mintue;  
    int second; 
    
	//输入时间 
    cout<<"请输入倒计时的时间(小时:分钟:秒):"; 
    cin>>hour>>mintue>>second;  
    
    //只要时间未结束就一直执行循环
    while(hour!=0||mintue!=0||second!=0){ 
	    //取得当前时间    
        time_t t=time(NULL);   
        while(time(NULL)==t);  
        if(--second<0){  
            second=59;  
            if(--mintue<0){  
                mintue=59;  
                --hour<0;  
            }  
        } 
		//输出时间  
        cout<<'\r';  
        if(hour<10){
            cout<<0;	
	    }  
        cout<<hour<<':';  
        if(mintue<10){
    	    cout<<0;
	    }  
        cout<<mintue<<':';  
        if(second<10){
    	    cout<<0; 
	    } 
        cout<<second<<flush;	  
    }  
    cout<<endl<<"--------------Time out!-------------"<<endl;
	cout<<endl<<"--------------Game over!------------"<<endl;  
    cout<<'\a';  
	
} 
 

int main()
{
	thread task01(playThread01());
	thread task02(playThread02());
	task01.detach();
	task02.detach();
	return 0;
}
