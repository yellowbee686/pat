#include <iostream>
using namespace std;

int main()
{
	int color[3];
	int a[2];
	char c;
	cin >> color[0] >> color[1] >> color[2];
	cout << '#';
	for(int i=0;i<3;++i)
	{
		a[0]=color[i]/13;
		a[1]=color[i]%13;
		for(int j=0;j<2;++j)
		{
			if(a[j]>9)
			{
				c = 'A' + a[j] - 10;
				cout << c;
			}
			else
			{
				cout << a[j];
			}
		}
	}
	cout << endl;
	return 0;
}