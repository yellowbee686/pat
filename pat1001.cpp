#include <iostream>
#include <string>
using namespace std;

int main()
{
	int a, b, c;
	cin >> a >> b;
	c = a + b;
	char ans[40];
	int i = 0;
	int j = 0;
	bool flag = true;
	if( c < 0 )
	{
		flag = false;
		c = -c;
	}
	if( c == 0 )
	{
		ans[i] = 48;
		++i;
	}
	while( c > 0 )
	{
		ans[i] = c % 10 + 48;
		c = c / 10;
		++i;
		++j;
		if( j == 3 && c > 0 )
		{
			ans[i] = ',';
			++i;
			j = 0;
		}
	}
	if(!flag)
		ans[i] = '-';
	else
		--i;
	while( i >= 0 )
		cout << ans[i--];
	cout << endl;
}