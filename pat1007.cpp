#include <iostream>
using namespace std;

int main()
{
	int num[10000];
	int i;
	int k;
	cin >> k;
	for(i = 0; i < k; ++i)
		cin >> num[i];
	int j = k-1;
	i = 0;
	int maxLeft = 0, maxRight = k - 1;
	int left = 0;
	int max = -1, thisSum = 0;
	for(int j = 0; j < k; ++j)
	{
		thisSum += num[j];
		if(thisSum > max)
		{
			max = thisSum;
			maxRight = j;
			maxLeft = left;
		}
		else if(thisSum < 0)
		{
			thisSum = 0;
			left = j + 1;
		}
	}
	if(max < 0)
		max = 0;
	cout << max << ' ' << num[maxLeft] << ' ' << num[maxRight];
	return 0;
}