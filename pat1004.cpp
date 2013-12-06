#include <iostream>
using namespace std;

int ans[100];
int tree[100][100];
int maxLevel;

void DFS(int node, int level)
{
	int i = 0;
	while(tree[node][i])
	{
		DFS(tree[node][i], level + 1);
		++i;
	}
	if(i == 0)
		ans[level]++;
	if(level > maxLevel)
		maxLevel = level;
}

int main()
{
	int totalNum, nonNum;
	cin >> totalNum >> nonNum;
	for(int i = 0; i < 100; ++i)
		ans[i] = 0;
	int node, num;
	for(int i = 0; i < 100; ++i)
		for(int j = 0; j < 100; ++j)
			tree[i][j] = 0;
	for(int i = 0; i < nonNum; ++i)
	{
		cin >> node >> num;
		for(int j = 0; j < num; ++j)
			cin >> tree[node][j];
	}
	maxLevel = 0;
	DFS(1, 0);
	cout << ans[0];
	for(int i = 1; i <= maxLevel; ++i)
		cout << ' ' << ans[i];
	return 0;
}