#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	char a,b;
	int wina[3];
	int winb[3];
	fill(wina,wina+3,0);
	fill(winb,winb+3,0);
	scanf("%d",&n);
	getchar();
	for(int i=0;i<n;++i)
	{
		scanf("%c %c",&a,&b);
		getchar();
		if(a=='C'&&b=='J')		
			wina[1]++;
		else if(a=='C'&&b=='B')		
			winb[0]++;
		else if(a=='B'&&b=='C')		
			wina[0]++;
		else if(a=='B'&&b=='J')		
			winb[2]++;
		else if(a=='J'&&b=='B')		
			wina[2]++;
		else if(a=='J'&&b=='C')		
			winb[1]++;
	}
	int sa=wina[0]+wina[1]+wina[2];
	int sb=winb[0]+winb[1]+winb[2];
	int ca=0,cb=0,max=0;
	char cc[3]={'B','C','J'};
	for(int i=0;i<3;++i)	
		if(max<wina[i])
		{
			max=wina[i];
			ca=i;
		}
	max=0;
	for(int i=0;i<3;++i)	
		if(max<winb[i])
		{
			max=winb[i];
			cb=i;
		}
	printf("%d %d %d\n",sa,n-sa-sb,sb);
	printf("%d %d %d\n",sb,n-sa-sb,sa);
	printf("%c %c\n",cc[ca],cc[cb]);
	return 0;
}