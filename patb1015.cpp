/*
����Ϊ������ ��ĳһ������ṹ��һ���ֽ������� ͨ����struct���� ��classҪ�� ������ʱ����������зּ� ��ÿһ���е������ְ�����һ�ֱ�׼
���Խ������ֱ�׼�϶�Ϊһ �����ڱ����п���ͨ����ÿһ����sum����һ���ϴ�Ĺ̶�ֵ��ʵ�ְ����ܷ��ڼ�����������ֱ�֤��ÿһ����ľ���˳��
�����ھ�������ʱʹ��qsort ��Ҫ#include <algorithm> qsort(array,num,sizeof(struct name),cmp); ����cmp��Ҫ�Ƚ�����voidָ��ǿ��ת��Ϊ��������
���������ͨ������ ��return x-y; ������return y-x; 
ʹ��c����ַ���ʱ�����8λ ������Ҫchar str[9];Ϊ��������һλ ����strcmp�Ⱥ�����Ҫ#include <string.h>������string
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