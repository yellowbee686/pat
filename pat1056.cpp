/*
ģ���� ��Ŀ���ѵ��Ǻܿӵ� ����ÿ���������� ��ng���� ÿ����ߵĽ�����һ�� ʣ�µļ�ֻrank��ͬ ����ng��Ҳ��Ϊһ�ֱ���
��������rankΪÿ�ֵ�С����+1 ��Ҫע�������Ŀ�е���������и������Ǳ���˳�� ÿ�������ָ����һ�����������index
��������һ�ж�Ӧλ�õ������index
*/
#include <cstdio>
#include <cstring>

const int N=1005;
int mouse[N],order[N],rank[N];
bool used[N];

int main()
{
    int NP,NG,i,group;
	bool flag=true;
	memset(used,0,sizeof(used));
	scanf("%d %d",&NP,&NG);
	for(i=0;i<NP;++i)
		scanf("%d",mouse+i);	
	for(i=0;i<NP;++i)
		scanf("%d",order+i);	
	NP%NG==0?group=NP/NG:group=NP/NG+1;

	int last,max,countNG;
	while(flag){
		if(group==1)
			flag=false;
		countNG=0,last=-1,max=-1;
		
		for(i=0;i<NP;++i){
			if(!used[order[i]]){
				if(countNG==NG){
					last=-1;
					max=-1;
					countNG=1;
				}
				else
					++countNG;
				if(mouse[order[i]]>max){
					if(last!=-1){
						rank[last]=group+1;
						used[last]=true;
					}
					last=order[i];
					max=mouse[order[i]];
				}
				else{
					rank[order[i]]=group+1;
					used[order[i]]=true;
				}
			}
		}
		group%NG==0?group=group/NG:group=group/NG+1;
	}
	rank[last]=1;

	for(i=0;i<NP;++i)
		i==NP-1?printf("%d\n",rank[i]):printf("%d ",rank[i]);

    return 0;
}