/*
搜索查询 可以使用比较复杂的结构 map<string,set<string>> 其中key就直接用query添加的条件 即在每一项前面加上序号
由于本题这些项分属不同类别 因此这不会增加map的key项数 直接用一个map来表示所有的类型而不需要给每个类单独添加一个map
同时在输入整行时使用getline(cin,str); 在这之前有cin>>int;时需要加上getchar();输入掉行尾的回车
在使用C++ STL时基本都可以直接当做数组使用 不用先初始化 比如可以直接 lib["1: "+title].insert(id); 
这是在map的value 即对应set中insert 而set会自动按升序排序 因此直接输出即可
*/
#include <iostream>
#include <set>
#include <map>
#include <string>
using namespace std;

int main()
{
	map<string,set<string>> lib;
	int n,m;
	int index;
	cin>>n;
	//输入掉回车 不然会被第一个getline捕捉到
	getchar();
	string id,title,author,keywords,publisher,year;
	while(n--)
	{
		getline(cin,id);
		getline(cin,title);
		getline(cin,author);
		getline(cin,keywords);
		getline(cin,publisher);
		getline(cin,year);
		lib["1: "+title].insert(id);
		lib["2: "+author].insert(id);
		lib["4: "+publisher].insert(id);
		lib["5: "+year].insert(id);
		index=1;  
        while(index!=string::npos)  
        {  
            index = keywords.find(" ");  
            lib["3: "+keywords.substr(0,index)].insert(id);  
            keywords = keywords.substr(index+1);  
        }
	}
	cin>>m;
	getchar();
	string query;
	while(m--)
	{
		getline(cin,query);
		cout<<query<<endl;
		map<string,set<string>>::iterator ite=lib.find(query);
		if(ite!=lib.end())
		{
			set<string> ss=ite->second;
			for(set<string>::iterator ii=ss.begin();ii!=ss.end();++ii)
			{
				cout<<*ii<<endl;
			}
		}
		else
		{
			cout<<"Not Found"<<endl;
		}
	}
	return 0;
}