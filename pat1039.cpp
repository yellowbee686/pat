/*
����map<string,vector<int>>���洢ÿ���˵Ŀγ� �����Ϊÿ����������� �������һ��TLE
Ϊ�˽�ʡʱ����scanf�ȶ���c�ַ����ٹ���string ����ȻTLE ��Ϊmap���ú����ʵ�� Ч�ʲ�����
*/

/*
int main()
{
	int n,k;
	int id,num;
	char ss[5];
	scanf("%d%d",&n,&k);
	map<string,vector<int>> stu;
	map<string,vector<int>>::iterator it;
	while(k--)
	{
		scanf("%d%d",&id,&num);
		while(num--)
		{
			scanf("%s",ss);
			string name(ss);
			//cin>>name;
			it=stu.find(name);
			if(it==stu.end())
			{
				vector<int> tmpv;
				tmpv.push_back(id);
				stu.insert(pair<string,vector<int>>(name,tmpv));
			}
			else
			{
				it->second.push_back(id);
			}
		}
	}
	int vsize;
	while(n--)
	{
		scanf("%s",ss);
		string name(ss);
		//cin>>name;
		it=stu.find(name);
		if(it==stu.end())
		{
			printf("%s 0\n",ss);
			//cout<<name<<" 0"<<endl;
		}
		else
		{
			vector<int> tv=it->second;
			vsize=tv.size();
			printf("%s %d",ss,vsize);
			//cout<<name<<" "<<vsize;
			sort(tv.begin(),tv.end());
			for(vector<int>::iterator vit=tv.begin();vit!=tv.end();++vit)
				printf(" %d",*vit);
			printf("\n");

		}
	}
	return 0;
}
*/

/*
���map�����ַ���Ч�ʲ��������� ��Ϊ���е����ָ�ʽʮ�̶ֹ� ����趨һ��vector<int>st[26][26][26][10];������st �൱�ڽ�string����hash
�������������Ͽ� ���ܷ�����Ŀ�е�Ҫ�� ����c++��vector������ֱ���������� ����Ҳʮ�ּ���
��VS���޸Ķ�ջ�ύ��С��Ȼ���� �޸Ķ�ջ������С�ſ��� Ӧ���ǿ���̫��VS�������Ŀ�������ڴ����ֵҲû����ô�� ��Ҫ���������ڴ����洢
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int main()
{
	int n,k;
	int id,num;
	char s[5];
	vector<int> st[26][26][26][10];
	scanf("%d%d",&n,&k);
	while(k--)
	{
		scanf("%d%d",&id,&num);
		while(num--)
		{
			scanf("%s",s);
			st[s[0]-'A'][s[1]-'A'][s[2]-'A'][s[3]-'0'].push_back(id);
		}
	}
	int vsize;
	while(n--)
	{
		scanf("%s",s);
		vector<int>tmpv=st[s[0]-'A'][s[1]-'A'][s[2]-'A'][s[3]-'0'];
		vsize=tmpv.size();
		if(vsize==0)
		{
			printf("%s 0\n",s);
		}
		else
		{
			printf("%s %d",s,vsize);
			sort(tmpv.begin(),tmpv.end());
			for(vector<int>::iterator vit=tmpv.begin();vit!=tmpv.end();++vit)
				printf(" %d",*vit);
			printf("\n");

		}
	}
	return 0;
}