#include <stdio.h>
#define MAX 1000

struct account
{
	char id[11];
	char pwd[11];
	int ifModified;
}accounts[MAX];

int main()
{
	int i,N;
	int counter;
	char *p;
	counter = 0;
	scanf("%d",&N);
	for(i=0;i<N;++i)
	{
		scanf("%s%s",accounts[i].id,accounts[i].pwd);
		accounts[i].ifModified = 0;
		p = accounts[i].pwd;
		while(*p != '\0')
		{
			switch(*p)
			{
			case '1':
				*p = '@';
				accounts[i].ifModified = 1;
				break;
			case '0':
				*p = '%';
				accounts[i].ifModified = 1;
				break;
			case 'l':
				*p = 'L';
				accounts[i].ifModified = 1;
				break;
			case 'O':
				*p = 'o';
				accounts[i].ifModified = 1;
				break;
			}
			p++;
		}
		if(accounts[i].ifModified == 1)
			counter++;
	}
	if(counter == 0)
	{
		if(N == 1)
			printf("There is 1 account and no account is modified\n");
		else
			printf("There are %d accounts and no account is modified\n", N);
	}
	else
	{
		printf("%d\n",counter);
		for(i=0;i<N;++i)
		{
			if(accounts[i].ifModified == 1)
				printf("%s %s\n", accounts[i].id, accounts[i].pwd);
		}
	}
	return 0;
}