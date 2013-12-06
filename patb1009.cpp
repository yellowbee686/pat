#include <iostream>
using namespace std;

int main()
{
	char str[85];
	cin.getline(str,85);
	int i;
	for(i=0;i<=84;++i)
	{
		if(str[i]=='\0')
			break;
	}
	int count=0;
	while(i-->=0)
	{
		count++;
		if(str[i]==' '||i<0)
		{
			for(int j=1;j<count;++j)
				cout<<str[j+i];
			count=0;
			if(i>=0)
				cout<<" ";
		}
		
	}
	cout<<endl;
	return 0;
}