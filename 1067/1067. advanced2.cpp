//https://blog.csdn.net/tiantangrenjian/article/details/13749067

#include <stdio.h>
 
int findNotOK(int* arr,int begin,int end)	//从begin开始往后寻找未到位的数
{
	for(int i=begin;i<end;i++)
	{
		if(arr[i]!=i)return i;
	}
	return 0;
}
 
int main()
{
    int n;
	scanf("%d",&n);
	int* arr = new int[n];
	int i,t;
	
	for(i=0;i<n;i++)
	{
		scanf("%d",&t);
		arr[t]=i;
	}
	int tmp = 0;
	int count=0;
	int firstPos = 1;
	firstPos = findNotOK(arr,firstPos,n);
 
	while(firstPos)		//还有未到位的数字
	{
		if(arr[0]==0)		//如果0到位了，则与未到位的firstPos交换
		{
			arr[0] = arr[firstPos];
			arr[firstPos] = 0;
			count++;
		}
 
		while(arr[0]!=0)	//如果0不到位，则循环与自己所指向的值交换
		{
			tmp = arr[0];
			arr[0] = arr[tmp];
			arr[tmp] = tmp;
			count++;
		}
		firstPos = findNotOK(arr,firstPos,n);		//此时0归位了，找到下一个未到位的数字
	}
	printf("%d\n",count);
 
    return 0;
}