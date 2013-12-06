#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	cin >> str;
	int n, n1, n2;
	n = str.size()+2;
	n1 = n / 3;
	n2 = n1 + n % 3;
	string *whitestr = new string(n2-2, ' ');
	for(int i = 0; i < n1-1; ++i)
	{
		cout << str[i] << *whitestr << str[n-3-i] << endl;
	}
	for(int i = n1-1; i < n1 + n2-1; ++i)
	{
		cout << str[i];
	}
	cout << endl;
	return 0;
}