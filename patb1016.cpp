#include <iostream>
#include <string>
using namespace std;

int main()
{
	string a,b;
	char ca,cb;
	cin>>a>>ca>>b>>cb;
	int ex=1,suma=0,sumb=0;
	for(int i=0;i<a.size();++i)
	{
		if(a[i]==ca)
		{
			suma+=(ca-'0')*ex;
			ex*=10;
		}
	}
	ex=1;
	for(int i=0;i<b.size();++i)
	{
		if(b[i]==cb)
		{
			sumb+=(cb-'0')*ex;
			ex*=10;
		}
	}
	cout<<suma+sumb<<endl;
	return 0;
}