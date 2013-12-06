#include <iostream>
#include <math.h>
using namespace std;

int num[50];
int maxindex;

bool ifPrime(int n)
{
	bool ret = true;
	double limit = sqrt((double)n);
	for(int i = 2; i <= limit; ++i)
	{
		if(n % i == 0)
		{
			ret = false;
			break;
		}
	}
	if(n == 1 || n ==0)
		ret = false;
	if(n == 2)
		ret = true;
	return ret;
}

void getArray(int n, int radix)
{
	int j;
	for(j = 0; pow((double)radix, j) <= n; ++j)
		;
	--j;
	maxindex = j;
	int temp;
	while(j >= 0)
	{
		temp = pow((double)radix, j);
		num[j] = n / temp;
		n %= temp;
		--j;
	}
}

int getreverse(int r)
{
	int ret = 0;
	for(int i = maxindex; i >= 0; --i)
	{
		ret += num[i] * pow((double)r, maxindex - i);
	}
	return ret;
}

int main()
{
	int n, radix;
	while(cin >> n && n >= 0)
	{
		cin >> radix;
		for(int i = 0; i < 50; ++i)
			num[i] = 0;
		getArray(n, radix);
		int n2;
		n2 = getreverse(radix);
		bool flag1 = ifPrime(n);
		bool flag2 = ifPrime(n2);
		if(flag1 && flag2)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}