/*
����Գ��ַ��� ֱ����ÿ����Ϊ���� �ж��Ƿ�Ϊaba��abba�������͵ĶԳ�
����һ�е��ַ����п�����gets(s)
���ж�abba�͵�ʱ��ֻ��Ҫ��⵱ǰ�Ƿ�Ϊ��һ��b���ļ��� ��Ϊ�ڶ���b���ĵ��������һ�����Ѿ�������
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