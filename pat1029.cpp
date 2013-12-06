#include <iostream>
#define MAX 1000000
long long a[MAX],b[MAX],c[2*MAX];
int main()
{
	int n1,n2;
	scanf("%d",&n1);
	for(int i=0;i<n1;++i)
		scanf("%lld",&a[i]);
	scanf("%d",&n2);
	for(int i=0;i<n2;++i)
		scanf("%lld",&b[i]);
	int m=0;
	int j=0;
	int k=0;
	while(m<n1&&j<n2)
	{
		if(a[m]<=b[j])
			c[k++]=a[m++];
		else
			c[k++]=b[j++];
	}
	while(m<n1)
		c[k++]=a[m++];
	while(j<n2)
		c[k++]=b[j++];
	printf("%d\n",c[(k-1)/2]);
	return 0;
}