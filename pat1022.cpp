/*
������ѯ ����ʹ�ñȽϸ��ӵĽṹ map<string,set<string>> ����key��ֱ����query��ӵ����� ����ÿһ��ǰ��������
���ڱ�����Щ�������ͬ��� ����ⲻ������map��key���� ֱ����һ��map����ʾ���е����Ͷ�����Ҫ��ÿ���൥�����һ��map
ͬʱ����������ʱʹ��getline(cin,str); ����֮ǰ��cin>>int;ʱ��Ҫ����getchar();�������β�Ļس�
��ʹ��C++ STLʱ����������ֱ�ӵ�������ʹ�� �����ȳ�ʼ�� �������ֱ�� lib["1: "+title].insert(id); 
������map��value ����Ӧset��insert ��set���Զ����������� ���ֱ���������
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
	//������س� ��Ȼ�ᱻ��һ��getline��׽��
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