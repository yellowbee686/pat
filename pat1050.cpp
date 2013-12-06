#include <iostream>
#include <string>
using namespace std;

int main() 
{
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	int asc2[128] = {0};
	int size1 = s1.size();
	int size2 = s2.size();
	for(int i = 0; i < size2; ++i)
	{
		asc2[s2[i]] = 1;
	}
	for(int i = 0; i < size1; ++i)
	{
		if(!asc2[s1[i]])
		{
			cout << s1[i];
		}
	}
	cout << endl;
	return 0;
}
