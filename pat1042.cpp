#include <stdio.h>
#define PKOERNUM 55
#define SINGLENUM 13
int main()
{
	int i, n, tmp, cof, re;
	int shuffle[PKOERNUM];
	int poker[PKOERNUM];
	int result[PKOERNUM];

	scanf("%d", &n);
	for(i = 1; i < PKOERNUM; ++i)
	{
		scanf("%d", &shuffle[i]);
	}

	for(i = 1; i < PKOERNUM; ++i)
	{
		poker[i] = i;
	}
	while(n--)
	{
		for(i = 1; i < PKOERNUM; ++i)
		{
			tmp = shuffle[i];
			result[tmp] = poker[i];
		}
		for(i = 1; i < PKOERNUM; ++i)
		{
			poker[i] = result[i];
		}
	}
	for(i = 1; i < PKOERNUM; ++i)
	{
		cof = poker[i] / SINGLENUM;
		re = poker[i] % SINGLENUM;
		if(re == 0)
		{
			cof--;
			re = 13;
		}
		switch(cof) 
		{
		case 0:
			printf("S");
			break;
		case 1:
			printf("H");
			break;
		case 2:
			printf("C");
			break;
		case 3:
			printf("D");
			break;
		case 4:
			printf("J");
			break;
		}
		
		printf("%d", re);
		if(i < PKOERNUM - 1)
		{
			printf(" ");
		}
		else
		{
			printf("\n");
		}
	}
	return 0;
}