#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 30

/*
* ��������postorder��inorder����Ҫ���levelorder�����������ɵ�ÿ��postorder�е����һ��Ϊ�������ĸ��ڵ㣬
* �����������inorder����Ϊ�ָ���Է�Ϊ������������˿��Բ��õݹ飬����Ϊ�ݹ�����Ľ��������levelorder��
* ����preorder������Ҳ��ü�¼ÿ�������������еĲ���������������
*/

void parse(int n, int *po, int *in, int ans[], int anslevel[], int level)
{
	int num;
	int ansIndex;
	int n1, n2;
	//���nΪ0�����κβ������൱�ڵݹ����
	//���nΪ1��ֻ���������ӵ��������ans�У�Ҳ�ǵݹ����
	if(n > 0)
	{
		ansIndex = ans[0];
		num = *(po+n-1);
		ans[ansIndex] = num;
		if(anslevel[0]<level)
			anslevel[0] = level;
		anslevel[ansIndex] = level++;
		ans[0]++;
		if(n > 1)
		{
			n1=0;
			while(in[n1] != num)
				n1++;
			n2 = n-n1-1;
			parse(n1,po,in,ans,anslevel,level);
			//po�и��ڵ�����ĩ�����ֱ��po+n1����in�и��ڵ���ҪҲ������������in+n1+1
			parse(n2,po+n1,in+n1+1,ans,anslevel,level);
		}
	}
}

int main()
{
	int post[MAX];
	int in[MAX];
	int ans[MAX];
	int anslevel[MAX];
	int ret[MAX];
	int n, i, j, maxLv, retIdx;

	memset(post,0,MAX*sizeof(int));
	memset(in,0,MAX*sizeof(int));
	memset(ans,0,MAX*sizeof(int));
	memset(anslevel,0,MAX*sizeof(int));
	scanf("%d",&n);
	for(i=0;i<n;++i)
	{
		scanf("%d",&post[i]);
	}
	for(i=0;i<n;++i)
	{
		scanf("%d",&in[i]);
	}
	ans[0] = 1;
	parse(n,post,in,ans,anslevel,0);
	maxLv=0;
	for(i=1;i<=n;++i)
		if(anslevel[i]>maxLv)
			maxLv = anslevel[i];
	retIdx = 0;
	for(j=0;j<=maxLv;++j)
	{
		for(i=1;i<=n;++i)
		{
			if(anslevel[i] == j)
			{
				ret[retIdx++] = ans[i];
			}
		}
	}
	for(i=0;i<n;++i)
	{
		if(i!=n-1)
			printf("%d ", ret[i]);
		else
			printf("%d\n", ret[i]);
	}
	return 0;
}