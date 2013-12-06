#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Person
{
public:
	string name;
	char gender;
	string number;
	int grade;
	Person()
	{
	}
};

int main()
{
	int n;
	cin >> n;
	Person tmp;
	vector<Person> mvPerson;
	vector<Person> fvPerson;
	for(int i = 0; i < n; ++i)
	{
		cin >> tmp.name >> tmp.gender >> tmp.number >> tmp.grade;
		if(tmp.gender == 'M')
		{
			mvPerson.push_back(tmp);
		}
		else
		{
			fvPerson.push_back(tmp);
		}
	}
	int mn = mvPerson.size();
	int fn = fvPerson.size();
	for(int i = 0; i < mn; ++i)
		for(int j = i + 1; j < mn; ++j)
		{
			if(mvPerson.at(i).grade > mvPerson.at(j).grade)
			{
				tmp = mvPerson.at(i);
				mvPerson.at(i) = mvPerson.at(j);
				mvPerson.at(j) = tmp;
			}
		}
	for(int i = 0; i < fn; ++i)
		for(int j = i + 1; j < fn; ++j)
		{
			if(fvPerson.at(i).grade < fvPerson.at(j).grade)
			{
				tmp = fvPerson.at(i);
				fvPerson.at(i) = fvPerson.at(j);
				fvPerson.at(j) = tmp;
			}
		}
	
	if(fn > 0)
	{
		cout << fvPerson.at(0).name << " " << fvPerson.at(0).number << endl;
	}
	else
	{
		cout << "Absent" << endl;
	}
	if(mn > 0)
	{
		cout << mvPerson.at(0).name << " " << mvPerson.at(0).number << endl;
	}
	else
	{
		cout << "Absent" << endl;
	}
	int ans;
	if(mn > 0 && fn > 0)
	{
		ans = fvPerson.at(0).grade - mvPerson.at(0).grade;
		cout << ans << endl;
	}
	else
	{
		cout << "NA" << endl;
	}
	return 0;
}