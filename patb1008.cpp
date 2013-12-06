#include <stdio.h>

int main()
{
	int a[100];
	int b[100];
	int m, n;
	scanf("%d%d",&n,&m);
	m%=n;
	for(int i=0;i<n;++i)
		scanf("%d",&a[i]);
	int j=0;
    for(int i=n-m;i<n;++i)
		b[j++]=a[i];
	for(int i=0;i<n-m;++i)
		b[j++]=a[i];
	for(int i=0;i<n;++i)
	{
		if(i==n-1)
			printf("%d\n",b[i]);
		else
			printf("%d ",b[i]);
	}
	return 0;
}