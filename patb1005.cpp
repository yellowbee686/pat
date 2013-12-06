#include <stdio.h>
#include <vector>
#include <set>
#include <algorithm>
#include <functional>
using namespace std;

int main()
{
	int n, ins;
	vector<int> nums;
	set<int> checker;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&ins);
		nums.push_back(ins);
	}
	sort(nums.begin(),nums.end(),greater<int>());
	for(vector<int>::iterator ite=nums.begin();ite<nums.end();++ite)
	{
		ins=*ite;
		if(checker.find(ins)==checker.end())
		{
			while(ins>1)
			{
				if(ins%2)
				{
					ins=(ins*3+1)/2;
				}
				else
				{
					ins/=2;
				}
				checker.insert(ins);
			}
		}
	}
	bool blankflag=true;
	for(vector<int>::iterator ite=nums.begin();ite<nums.end();++ite)
	{
		ins=*ite;
		if(checker.find(ins)==checker.end())
		{
			if(blankflag)
			{
				printf("%d",ins);
				blankflag=false;
			}
			else
			{
				printf(" %d",ins);
			}
		}
	}
	printf("\n");
	return 0;
}