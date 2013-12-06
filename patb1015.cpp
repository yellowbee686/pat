/*
本题为简单排序 对某一个整体结构的一部分进行排序 通常用struct即可 比class要简单 在排序时按照情况进行分级 而每一级中的排序又按照另一种标准
可以将这两种标准合二为一 比如在本题中可以通过给每一级的sum加上一个较大的固定值来实现按照总分在级别内排序而又保证了每一级间的绝对顺序
另外在具体排序时使用qsort 需要#include <algorithm> qsort(array,num,sizeof(struct name),cmp); 其中cmp需要先将两个void指针强制转化为所需类型
而如果是普通的升序 就return x-y; 降序则return y-x; 
使用c风格字符串时如果有8位 则最少要char str[9];为结束符留一位 另外strcmp等函数需要#include <string.h>而不是string
*/
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
#define MAX_N 100001
struct info
{
	char id[10];
	int v;
	int t;
	int s;
}input[MAX_N];

int cmp(const void *a,const void *b)
{
	struct info *x=(struct info *)a;
	struct info *y=(struct info *)b;
	int ret;
	if(x->s!=y->s)
		ret=y->s-x->s;
	else if(x->v!=y->v)
		ret=y->v-x->v;
	else
		ret=strcmp(x->id,y->id);
	return ret;
}

int main()
{
	int n,low,up;
	char tid[10];
	int virtue;
	int talent;
	int j=0;
	scanf("%d%d%d",&n,&low,&up);
	for(int i=0;i<n;++i)
	{
		scanf("%s%d%d",tid,&virtue,&talent);
		if(virtue>=low&&talent>=low)
		{
			strcpy(input[j].id,tid);
			input[j].v=virtue;
			input[j].t=talent;
			if(virtue>=up&&talent>=up)
				input[j].s=virtue+talent+3000;
			else if(virtue>=up&&talent<up)
				input[j].s=virtue+talent+2000;
			else if(virtue>=talent)
				input[j].s=virtue+talent+1000;
			else
				input[j].s=virtue+talent;
			++j;
		}
	}
	qsort(input,j,sizeof(struct info),cmp);
	printf("%d\n",j);
	for(int i=0;i<j;++i)
		printf("%s %d %d\n",input[i].id,input[i].v,input[i].t);
	return 0;
}