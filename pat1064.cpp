/*
给出一堆数求其完全二叉搜索树的level traversal 因此是对整棵树从根开始BFS 不需要显式的求出树的结构 
只需要确定每一次node在原数组中的index即可 Node节点是由[a[left],a[right]]包含的一段树，num统计其个数
height给出树高，这里的高度以最长的枝长度为准，单节点树height=0
对每一颗树来说 求当前根的index 只需要知道在它左边有多少个数即可，左边的数个数为前面h-1层的个数/2
再加上min(最后一层所剩的个数,最后一层放满的个数/2) 因为放满一半以后的数都会在根的右边 所以不需考虑
这样每次求出根，再更新节点加入queue中BFS即可 当right-left+1<=0时就表示已经到叶节点了
*/
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#define MAX_N 1000
struct Node
{
	int left;
	int right;
	int num;
	int height;
}nodes[MAX_N];

int a[MAX_N];
int ex[11]={1,2,4,8,16,32,64,128,256,512,1024};
int ans[MAX_N];
int getheight(int n)
{
	int h;
	for(h=0;h<11;++h)
	{
		if(n>ex[h])
			n-=ex[h];
		else
			break;
	}
	return h;
}

void bfs(int n)
{
	queue<Node> que;
	Node nn={0,n-1,n,getheight(n)};
	que.push(nn);
	int idx,cnt;
	int j=0;//idx for ans[]
	int ll,lr,rl,rr,numl,numr;
	while(!que.empty())
	{
		Node tmp = que.front();
		que.pop();
		idx=tmp.left;
		cnt=tmp.num;
		for(int i=1;i<tmp.height;++i)
			idx+=ex[i]/2;
		for(int i=0;i<tmp.height;++i)
			cnt-=ex[i];
		if(cnt>=ex[tmp.height]/2)
			idx+=ex[tmp.height]/2;
		else
			idx+=cnt;
		ans[j++]=a[idx];
		ll=tmp.left;
		lr=idx-1;
		rl=idx+1;
		rr=tmp.right;
		numl=lr-ll+1;
		numr=rr-rl+1;
		if(numl>0)
		{
			Node nl={ll,lr,numl,getheight(numl)};
			que.push(nl);
		}
		if(numr>0)
		{
			Node nr={rl,rr,numr,getheight(numr)};
			que.push(nr);
		}
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;++i)
		scanf("%d",&a[i]);
	sort(a,a+n);
	bfs(n);
	for(int i=0;i<n;++i)
		if(i!=n-1)
			printf("%d ",ans[i]);
		else
			printf("%d\n",ans[i]);
	return 0;
}