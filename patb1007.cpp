#include <stdio.h>
#include <vector>
using namespace std;

vector<int> primes;

bool judgePrime(int num)
{
	bool ret = true;
	if(num!=2)
	{
		for(vector<int>::iterator i=primes.begin();i<primes.end();++i)
		{
			if(num%*i==0)
			{
				ret=false;
				break;
			}
		}
	}
	return ret;
}

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=2;i<=n;++i)
	{
		if(judgePrime(i))
			primes.push_back(i);
	}
	int count=0;
	for(int i=1;i<primes.size();++i)
	{
		if(primes.at(i)-primes.at(i-1)==2)
			count++;
	}
	printf("%d\n",count);
	return 0;
}