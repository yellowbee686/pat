#include <iostream>
#include <math.h>
using namespace std;

int num[50];
int maxindex;

void getArray(int n, int radix)
{
	int j;
	for(j = 0; pow((double)radix, j) <= n; ++j)
		;
	if(n != 0)
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

int main()
{
	int n, radix;
	cin >> n >> radix;
	getArray(n, radix);
	bool flag = true;
	for(int i = 0; i < (maxindex + 1) / 2; ++i)
	{
		if(num[i] != num[maxindex - i])
		{
			flag = false;
			break;
		}
	}
	if(flag)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	for(int j = maxindex; j >= 0; --j)
	{
		if(j)
			cout << num[j] << ' ';
		else
			cout << num[j];
	}
	return 0;
}