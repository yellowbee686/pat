#include <stdio.h>
#include <string>
using namespace std;
#define MAX 100000

int cmp(const void * a, const void * b)
{
	double tmp;
	int ret;
	tmp = *(int *)a - *(int *)b;
	if(tmp > 0)
		ret = 1;
	else
		ret = -1;
	return ret;
}

int main()
{
	int nc, np;
	int c[MAX], p[MAX];
	long long sum = 0;
	scanf("%d", &nc);
	for(int i = 0; i < nc; ++i)
	{
		scanf("%d", &c[i]);
	}
	scanf("%d", &np);
	for(int i = 0; i < np; ++i)
	{
		scanf("%d", &p[i]);
	}
	qsort(c, nc, sizeof(int),cmp);
	qsort(p, np, sizeof(int),cmp);
	int j = 0, k = 0;
	while(c[j] < 0 && p[k] < 0 && j < nc && k < np)
	{
		sum += c[j] * p[k];
		j++;
		k++;
	}
	j = nc - 1;
	k = np - 1;
	while(c[j] > 0 && p[k] > 0 && j >= 0 && k >= 0)
	{
		sum += c[j] * p[k];
		j--;
		k--;
	}
	printf("%ld\n", sum);
	return 0;
}