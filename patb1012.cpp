#include <iostream>

int main()
{
	int n;
	scanf("%d",&n);
	int a,b,c,d,e,num1,num2,num3,num4,num5;
	int tmp;
	a=b=c=d=e=num1=num2=num3=num4=num5=0;
	bool flag=true;
	while(n--)
	{
		scanf("%d",&tmp);
		switch(tmp%5)
		{
		case 0:
			if(tmp%2==0)
			{
				num1++;
				a+=tmp;
			}
			break;
		case 1:
			if(flag)
			{
				b+=tmp;
				flag=false;
			}
			else
			{
				b-=tmp;
				flag=true;
			}
			num2++;
			break;
		case 2:
			c++;
			num3++;
			break;
		case 3:
			d+=tmp;
			num4++;
			break;
		case 4:
			if(tmp>e)
				e=tmp;
			num5++;
			break;
		}
	}
	if(num1)
		printf("%d ",a);
	else
		printf("N ");
	if(num2)
		printf("%d ",b);
	else
		printf("N ");
	if(num3)
		printf("%d ",c);
	else
		printf("N ");
	if(num4)
		printf("%.1f ",d*1.0/num4);
	else
		printf("N ");
	if(num5)
		printf("%d",e);
	else
		printf("N");
	return 0;
}