#include <stdio.h>

int main()
{
	int n,i;
	scanf("%d",&n);
	i = 0;
	while(n!=1)
	{
		if(n%2)
		{
			n = 3 * n + 1;		
		}		
		n /= 2;		
		++i;
	}
	printf("%d\n",i);
	return 0;
}