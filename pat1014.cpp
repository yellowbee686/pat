#include <iostream>
#include <string>
using namespace std;

int DL = 540;
int times[1001];
int ques[1001];
int start[1001];
int q[20][11];
int N, M, K, Q;

string formatTime(int time)
{
	string ret;
	int hours = time/60 + 8;
	int minutes = time%60;
	ret.push_back(hours/10+48);
	ret.push_back(hours%10+48);
	ret.push_back(':');
	ret.push_back(minutes/10+48);
	ret.push_back(minutes%10+48);
	return ret;
}

void popQ(int qid)
{
	int num = q[qid][0];
	start[num] = q[qid][M];
	for(int i=1; i<M; ++i)
		q[qid][i-1] = q[qid][i];
	q[qid][M] += times[num];
}

int main()
{
	cin>>N>>M>>K>>Q;
	for(int i=1; i<=K; ++i)
		cin>>times[i];
	for(int i=0; i<Q; ++i)
		cin>>ques[i];
	int k = 1;
	for(int j=0; j<M && k<=K; ++j)
	{
		for(int i=0; i<N && k<=K;++i)
		{
			q[i][j] = k++;
			//now time
			q[i][M] = 0;
		}
	}
	int least;
	int leastQ;
	while(1)
	{
		int i = 0;
		while(!q[i][0])
			i++;
		if(i>=N)
			break;
		least = q[i][M] + times[q[0][0]];
		leastQ = i;
		
		for( i=i+1; i<N; ++i)
		{
			if(q[i][0]!=0 && q[i][M] + times[q[i][0]]< least)
			{
				least = q[i][M] + times[q[i][0]];
				leastQ=i;
			}
		}
		popQ(leastQ);
		if(k<=K)
			q[leastQ][M-1] = k++;
		else
			q[leastQ][M-1] = 0;
	}
	int anstime;
	for(int i=0; i<Q; ++i)
	{
		anstime = start[ques[i]];
		if(anstime < DL)
		{
			anstime += times[ques[i]];
			cout << formatTime(anstime) << endl;
		}
		else
		{
			cout << "Sorry" << endl;
		}
	}
	return 0;
}