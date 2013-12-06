#include <iostream>
#include <string>
using namespace std;

int main()
{
	string a,ans;
	int b,q,tmp,r=0;
	cin>>a>>b;
	for(int i=0;i<a.size();++i)
	{
		tmp=r*10+a[i]-'0';
		q=tmp/b;
		ans+='0'+q;
		r=tmp-q*b;
	}
	string::iterator ite=ans.begin();
	while(*ite=='0')
	{
		if(ans.size()<=1)
			break;
		ans.erase(ite);
		ite=ans.begin();
	}
	cout<<ans<<" "<<r<<endl;
	return 0;
}