#include <iostream>
#include <string>
#include <strstream>
using namespace std;

int main()
{
	string str;
	cin >> str;
	int n = 0;
	string::iterator ite = str.begin();
	while(ite != str.end())
	{
		n += *ite -'0';
		ite++;
	}
	if(!n)
	{
		cout << "ling" << endl;
	}
	strstream ss;
	ss << n;
	string ans;
	ss >> ans;
	int i = 0;
	while(i < ans.length())
	{
		switch(ans.at(i))
		{
		case '0':
			cout << "ling";
			break;
		case '1':
			cout << "yi";
			break;
		case '2':
			cout << "er";
			break;
		case '3':
			cout << "san";
			break;
		case '4':
			cout << "si";
			break;
		case '5':
			cout << "wu";
			break;
		case '6':
			cout << "liu";
			break;
		case '7':
			cout << "qi";
			break;
		case '8':
			cout << "ba";
			break;
		case '9':
			cout << "jiu";
			break;
		}
		if(i < ans.length() - 1)
		{
			cout << " ";
		}
		else
		{
			cout << endl;
		}
		++i;
	}
	return 0;
}