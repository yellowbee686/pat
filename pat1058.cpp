#include <iostream>
#include <string>
#include <list>
#include <cstdlib>
using namespace std;

list<string> split(string str, string separator)
{
	list<string> result;
	int cutAt;
	while( (cutAt = str.find_first_of(separator)) != str.npos )
	{
		if(cutAt > 0)
		{
			result.push_back(str.substr(0, cutAt));
		}else{
			result.push_back("");
		}
		str = str.substr(cutAt + 1);
	}
	if(str.length() > 0)
	{
		result.push_back(str);
	}else{
		result.push_back("");
	}
	return result;
}
//这道题如果把货币都换算为最小单位会超过int限制 因此就直接按三个单位分别做加法了
class Currency
{
private:
	int galleon;
	int sickle;
	int knut;
public:
	Currency(string s)
	{
		list<string> ss=split(s,".");
		galleon=atoi(ss.front().c_str());
		ss.pop_front();
		sickle=atoi(ss.front().c_str());
		ss.pop_front();
		knut=atoi(ss.front().c_str());
	}
	int getGalleon()
	{
		return galleon;
	}
	int getSickle()
	{
		return sickle;
	}
	int getKnut()
	{
		return knut;
	}
};

int main()
{
	string a,b;
	cin>>a>>b;
	Currency ca(a);
	Currency cb(b);
	int knut=ca.getKnut()+cb.getKnut();
	int sickleadd=knut/29;
	knut%=29;
	int sickle=ca.getSickle()+cb.getSickle()+sickleadd;
	int galleonadd=sickle/17;
	sickle%=17;
	int galleon=ca.getGalleon()+cb.getGalleon()+galleonadd;
	cout<<galleon<<'.'<<sickle<<'.'<<knut<<endl;
	return 0;
}