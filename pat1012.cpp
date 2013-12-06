#include <iostream>
#include <string>
using namespace std;

int main()
{
	int m, n;
	cin >> n >> m;
	int score[2000][7];
	for(int i = 0; i < n; ++i)
	{
		cin >> score[i][0] >> score[i][2] >> score[i][3] >> score[i][4];
		score[i][1] = (int)((score[i][2] + score[i][3] + score[i][4]) / 3.0 + 0.5);
		//使用每一行代表一个人的所有成绩 0为学号 1为A 2为C 3为M 4为E 5为他最好的rank 6为此rank的种类 在1～4中选择
		score[i][5] = 2008;
		score[i][6] = 10;
	}
	int rank;
	int tmpscore;
	for(int i = 0; i < n; ++i)
		for(int j = 1; j < 5; ++j)
		{
			//遍历每个人的所有成绩 得出最好的rank和种类存在数组中
			rank = 1;
			tmpscore = score[i][j];
			for(int k = 0; k < n; ++k)
			{
				if(score[k][j] > tmpscore)
					rank++;
			}
			//因为rank种类的优先级是从高到低，因此必须要rank小于当前rank才考虑
			if(rank < score[i][5])
			{
				score[i][5] = rank;
				score[i][6] = j;
			}
			//当rank为1时，因为后面所有优先级都低，因此不再计算
			if(rank == 1)
				break;
		}
	int id;
	bool flag;
	for(int i = 0; i < m; ++i)
	{
		cin >> id;
		flag = false;
		for(int j = 0; j < n; ++j)
		{
			if(id == score[j][0])
			{
				cout << score[j][5] << ' ';
				switch(score[j][6])
				{
				case 1: 
					cout << 'A';
					break;
				case 2: 
					cout << 'C';
					break;
				case 3: 
					cout << 'M';
					break;
				case 4: 
					cout << 'E';
					break;
				}
				cout << endl;
				flag = true;
				break;
			}
		}
		if(!flag)
			cout << "N/A" << endl;
	}
	return 0;
}