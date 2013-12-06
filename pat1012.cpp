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
		//ʹ��ÿһ�д���һ���˵����гɼ� 0Ϊѧ�� 1ΪA 2ΪC 3ΪM 4ΪE 5Ϊ����õ�rank 6Ϊ��rank������ ��1��4��ѡ��
		score[i][5] = 2008;
		score[i][6] = 10;
	}
	int rank;
	int tmpscore;
	for(int i = 0; i < n; ++i)
		for(int j = 1; j < 5; ++j)
		{
			//����ÿ���˵����гɼ� �ó���õ�rank���������������
			rank = 1;
			tmpscore = score[i][j];
			for(int k = 0; k < n; ++k)
			{
				if(score[k][j] > tmpscore)
					rank++;
			}
			//��Ϊrank��������ȼ��ǴӸߵ��ͣ���˱���ҪrankС�ڵ�ǰrank�ſ���
			if(rank < score[i][5])
			{
				score[i][5] = rank;
				score[i][6] = j;
			}
			//��rankΪ1ʱ����Ϊ�����������ȼ����ͣ���˲��ټ���
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