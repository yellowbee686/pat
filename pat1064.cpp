/*
����һ����������ȫ������������level traversal ����Ƕ��������Ӹ���ʼBFS ����Ҫ��ʽ��������Ľṹ 
ֻ��Ҫȷ��ÿһ��node��ԭ�����е�index���� Node�ڵ�����[a[left],a[right]]������һ������numͳ�������
height�������ߣ�����ĸ߶������֦����Ϊ׼�����ڵ���height=0
��ÿһ������˵ ��ǰ����index ֻ��Ҫ֪����������ж��ٸ������ɣ���ߵ�������Ϊǰ��h-1��ĸ���/2
�ټ���min(���һ����ʣ�ĸ���,���һ������ĸ���/2) ��Ϊ����һ���Ժ���������ڸ����ұ� ���Բ��迼��
����ÿ����������ٸ��½ڵ����queue��BFS���� ��right-left+1<=0ʱ�ͱ�ʾ�Ѿ���Ҷ�ڵ���
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