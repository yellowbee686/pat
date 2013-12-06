#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	char n[4];
	float w, t, l;
	int i = 0;
	float ans = 1.0;
	while(i < 3)
	{
		cin >> w >> t >> l;
		if(w > t && w > l)
		{
			n[i] = 'W';
			ans *= w;
		}
		else if(t > w && t > l)
		{
			n[i] = 'T';
			ans *= t;
		}
		else
		{
			n[i] = 'L';
			ans *= l;
		}
		++i;
	}
	ans = (ans * 0.65 - 1.0) * 2;
	for(int j = 0; j < 3; ++j)
		cout << n[j] << ' ';
	ans *= 100;
	ans = (int)ans;
	ans = ans / 100;
	printf("%.2f\n", ans);
	return 0;
}