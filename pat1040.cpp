/*
求最长对称字符串 直接以每个点为中心 判断是否为aba和abba两种类型的对称
输入一行到字符串中可以用gets(s)
在判断abba型的时候只需要检测当前是否为第一个b中心即可 因为第二个b中心的情况在上一个点已经检测过了
*/
#include <iostream>
#include <string.h>
int main()
{
	char s[1000];
	gets(s);
	int size=strlen(s);
	int j;
	int max=1;
	int tmp;
	for(int i=0;i<size;++i)
	{
		j=1;
		while(i-j>=0&&i+j<size&&s[i-j]==s[i+j])
			++j;
		tmp=2*j-1;
		if(tmp>max)
			max=tmp;
		j=1;
		while(i-j+1>=0&&i+j<size&&s[i-j+1]==s[i+j])
			++j;
		tmp=2*j-2;
		if(tmp>max)
			max=tmp;
	}
	printf("%d\n",max);
	return 0;
}