#include <iostream>
#include <string>
using namespace std;
int main()
{
	long long a,b,c;
	int t;
	scanf("%d",&t);
	string flag;
	for(int i=1;i<=t;++i)
	{
		scanf("%lld%lld%lld",&a,&b,&c);
		if(a+b>c)
			flag="true";
		else
			flag="false";
		cout<<"Case #"<<i<<": "<<flag<<endl;
	}
	return 0;
}