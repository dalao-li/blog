/*
已知一个已经从小到大排序的数组，这个数组的一个平台(Plateau)就是连续的
一串值相同的元素，并且这一串元素不能再延伸.例如，在 1，2，2，3，3，3，
4，5，5，6中1，2-2，3-3-3，4，5-5，6都是平台.试编写一个程序，接收一个
数组，把这个数组最长的平台找出 来.在上面的例子中3-3-3就是最长的平台.
输出最长平台的长度.
*/

/*
#include<iostream>
using namespace std;
int main()
{
	int a[1000]，length=1，n，i;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	for(i=1;i<n;i++){
		//利用lenth来记录当前长度，并用lenth来测量后面的plate，如果遇上更大的plate则lenth++，最后返回最大lenth.
		if(a[i]==a[i-length]){
			length++;
		}
	}
	cout<<length<<endl;
	return 0;
}*/
#include <iostream>
using namespace std;
int main()
{
	int n， x， i， maxs = 1， cur， length = 0; //cur用来保存当前元素值
	cin >> n >> x;
	cur = x;
	for (i = 1; i < n; i++)
	{
		cin >> x;
		//如果cur=x，则说明是一个平台
		if (cur == x)
		{
			length++;
		}
		//若不相等则平台长度重置为1，且将新元素值保存到cur中
		else
		{
			length = 1;
			cur = x;
		}
		maxs = max(maxs， length);
	}
	cout << max << endl;
	return 0;
}
