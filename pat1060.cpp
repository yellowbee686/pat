/*
�Ƚ�����������Чλ�����Ƿ���� ��Ҫע����������0.00123�����������ָ����-2
ͬʱ0 0.0 0.00����������Чλ��Ϊ3�������Ҫд��0.000*10^0
*/
#include <iostream>
#include <cstring>
using namespace std;
#define MAX_N 110
char a[MAX_N];
char aa[MAX_N];
char b[MAX_N];
char bb[MAX_N];

int main()
{
	int n;
	int powera=0, powerb=0;
	scanf("%d%s%s",&n,&a,&b);
	int i=0;
	bool zflag=false, dflag=false;
	for(int j=0;j<strlen(a);++j)
	{
		if(!zflag&&a[j]!='0'&&a[j]!='.')
			zflag=true;
		if(i>=n&&dflag)
			break;
		if(zflag)
		{
			if(a[j]!='.')
			{
				if(i<n)
					aa[i++]=a[j];
				if(!dflag)
					powera++;
			}
			else
			{
				if(!dflag)
					dflag=true;
			}
		}
		else
		{
			if(dflag)
				powera--;
			if(a[j]=='.')
				dflag=true;			
		}
	}	
	i=0;
	zflag=dflag=false;
	for(int j=0;j<strlen(b);++j)
	{
		if(!zflag&&b[j]!='0'&&b[j]!='.')
			zflag=true;
		if(i>=n&&dflag)
			break;
		if(zflag)
		{
			if(b[j]!='.')
			{
				if(i<n)
					bb[i++]=b[j];
				if(!dflag)
					powerb++;
			}
			else
			{
				if(!dflag)
					dflag=true;
			}
		}
		else
		{
			if(dflag)
				powerb--;
			if(b[j]=='.')
				dflag=true;			
		}
	}
	if(strcmp(aa,"")==0)
	{
		powera=0;
		for(int j=0;j<n;++j)
			aa[j]='0';
	}
	if(strcmp(bb,"")==0)
	{
		powerb=0;
		for(int j=0;j<n;++j)
			bb[j]='0';
	}
	if(strcmp(aa,bb)==0&&powera==powerb)
		printf("YES 0.%s*10^%d\n",aa,powera);
	else
		printf("NO 0.%s*10^%d 0.%s*10^%d\n",aa,powera,bb,powerb);
	return 0;
}