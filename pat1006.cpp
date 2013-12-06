#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Person
{
private:
	string mid;
	int inTime;
	int outTime;
public:
	int getTime(string timeStr)
	{
		int ret = 0;
		ret += atoi(timeStr.substr(0, 2).c_str()) * 3600;
		ret += atoi(timeStr.substr(3, 2).c_str()) * 60;
		ret += atoi(timeStr.substr(6, 2).c_str());
		return ret;
	}

	Person(string id, string in, string out)
	{
		mid = id;
		inTime = getTime(in);
		outTime = getTime(out);
	}
	string getId(){ return mid; }
	int getIn(){ return inTime; }
	int getOut(){ return outTime; }
};

int main()
{
	int m;
	cin >> m;
	string id, in, out;
	vector<Person> vPerson;
	for( int i = 0; i < m; ++i )
	{
		cin >> id >> in >> out;
		Person tmp(id, in, out);
		vPerson.push_back(tmp);
	}
	int firstIn, lastOut;
	int idIn = 0, idOut = 0;
	firstIn = vPerson.at(0).getIn();
	lastOut = vPerson.at(0).getOut();
	for(int i = 1; i < m; ++i)
	{
		Person p = vPerson.at(i);
		if(firstIn > p.getIn())
		{
			idIn = i;
			firstIn = p.getIn();
		}
		if(lastOut < p.getOut())
		{
			idOut = i;
			lastOut = p.getOut();
		}
	}
	cout << vPerson.at(idIn).getId() << ' ' << vPerson.at(idOut).getId();
	return 0;
}