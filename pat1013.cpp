#include <iostream>

using namespace std;

int n;
int road[1000][1000];
int cities[1000];

void mark(int x)
{
	cities[x] = 1;
	for(int i = 0; i <= n; ++i)
	{
		if(road[x][i] && !cities[i])
			mark(i);
	}
}

int main()
{
	int m, k;
	cin >> n >> m >> k;
	int j, h;
	for(int i = 0; i <= n; ++i)
		for(int j = 0; j <= n; ++j)
			road[i][j] = 0;
	for(int i = 0; i < m; ++i)
	{
		cin >> j >> h;
		road[j][h] = 1;
		road[h][j] = 1;
	}
	int lost;
	int ans;
	for(int i = 0; i < k; ++i)
	{
		cin >> lost;
		ans = 0;
		for(int j = 0; j <= n; ++j)
			cities[j] = 0;
		cities[lost] = 1;
		for(int j = 1; j <= n; ++j)
			if(!cities[j])
			{
				mark(j);
				++ans;
			}
		cout << ans-1 << endl;
	}
	return 0;
}