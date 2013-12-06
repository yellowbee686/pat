#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int a[100];
	int now = 0;
	int ret = 0;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	for(int i = 0; i < n; ++i)
	{
		if(a[i] > now)
		{
			ret += (a[i] - now) * 6;
			now = a[i];
		}
		else if(a[i] < now)
		{
			ret += (now - a[i]) * 4;
			now = a[i];
		}
	}
	ret += 5 * n;
	cout << ret << endl;
	return 0;
}