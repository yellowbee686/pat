/*
模拟题 题目不难但是很坑爹 给出每个老鼠体重 按ng分组 每组最高的进入下一轮 剩下的几只rank相同 不足ng的也作为一轮比赛
因此这里的rank为每轮的小组数+1 需要注意的是题目中的输入第三行给出的是比赛顺序 每个序号是指的上一行体重数组的index
而不是上一行对应位置的老鼠的index
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