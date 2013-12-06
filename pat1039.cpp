/*
利用map<string,vector<int>>来存储每个人的课程 最后再为每个人排序输出 但是最后一个TLE
为了节省时间用scanf先读入c字符串再构造string 但依然TLE 因为map采用红黑树实现 效率并不高
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
针对map查找字符串效率不够的问题 因为题中的名字格式十分固定 因此设定一个vector<int>st[26][26][26][10];的数组st 相当于将string做了hash
这样查找起来较快 才能符合题目中的要求 而且c++的vector用起来直接声明即可 代码也十分简练
在VS中修改堆栈提交大小依然报错 修改堆栈保留大小才可以 应该是开销太大VS给这个项目的物理内存最大值也没有那么多 需要加上虚拟内存来存储
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