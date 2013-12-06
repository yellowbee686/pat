#include <stdio.h>
#include <map>
using namespace std;

int main()
{
	map<int,int> pixels;
	map<int,int>::iterator ite;
	int m, n, tmp;
	scanf("%d%d",&m,&n);
	int limit = m * n;
	int rtn = -1;
	int cnt = -1;
	for(int i = 0; i < limit; ++i)
	{
		scanf("%d",&tmp);
		ite = pixels.find(tmp);
		if(ite == pixels.end())
		{
			pixels.insert(pair<int,int>(tmp,1));
		}
		else
		{
			ite->second++;
			if(ite->second>limit/2)
			{
				rtn = ite->first;
				break;
			}
		}		
	}
	if(rtn == -1)
	{
		for(ite = pixels.begin(); ite != pixels.end(); ite++)
		{
			if(ite->second>cnt)
			{
				cnt = ite->second;
				rtn = ite->first;
			}
		}
	}
	printf("%d\n",rtn);	
	return 0;
}