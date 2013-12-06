#include <iostream>
#include <string>
#include <map>
#include <cctype>
using namespace std;

int main()
{
	string tmp,whole,maxstr;
	char tmpc;
	map<string,int> dic;
	map<string,int>::iterator ite;
	int maxnum=0;
	getline(cin,whole);
	//如果最后以数字或字母结尾 不加一个特殊字符会导致最后一个词不进入统计
	whole+=" ";
	for(int i=0;i<whole.size();++i)
	{
		tmpc=whole[i];
		if(isalpha(tmpc)||isdigit(tmpc))
		{
			if(isupper(tmpc))
				tmpc=tolower(tmpc);
			tmp.append(1,tmpc);
		}
		else
		{
			if(tmp!="")
			{
				ite=dic.find(tmp);
				if(ite!=dic.end())
					ite->second++;
				else
					dic.insert(pair<string,int>(tmp,1));
				tmp.clear();
			}
		}
	}
	for(ite=dic.begin();ite!=dic.end();++ite)
		if(maxnum<ite->second)
		{
			maxnum=ite->second;
			maxstr=ite->first;
		}
	cout<<maxstr<<" "<<maxnum<<endl;
	return 0;
}