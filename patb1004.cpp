#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
	map<int,string> marks;
	int n;
	cin >> n;
	string name, id;
	int mark;
	while(n--)
	{
		cin>>name>>id>>mark;
		name.push_back(' ');
		name.append(id);
		marks.insert(pair<int,string>(mark,name));
	}
	map<int,string>::iterator ite;
	for(int i=100;i>=0;i--)
	{
		ite = marks.find(i);
		if(ite!=marks.end())
		{
			cout << ite->second << endl;
			break;
		}
	}
	for(int i=0;i<=100;++i)
	{
		ite = marks.find(i);
		if(ite!=marks.end())
		{
			cout << ite->second << endl;
			break;
		}
	}

	return 0;
}