#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 30

/*
* 这道题给了postorder和inorder，需要输出levelorder，经过分析可得每段postorder中的最后一个为该子树的根节点，
* 而以这个数在inorder中作为分割可以分为左右子树，因此可以采用递归，但因为递归出来的结果不符合levelorder，
* 而是preorder，因此我采用记录每个数在整个树中的层数来解决这个问题
*/

void parse(int n, int *po, int *in, int ans[], int anslevel[], int level)
{
	int num;
	int ansIndex;
	int n1, n2;
	//如果n为0则不做任何操作，相当于递归出口
	//如果n为1则只把这个数添加到结果数组ans中，也是递归出口
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
			//po中根节点在最末，因此直接po+n1，而in中根节点需要也跳过，所以是in+n1+1
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