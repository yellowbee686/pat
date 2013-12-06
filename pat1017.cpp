#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string>
using namespace std;

double MIN = 480;
double MAX = 1020;
struct person
{
	double arrival;
	double start;
	double wait;
	double cost;
} num[10000];

double endtime[100];

int cmp(const void * a, const void * b)
{
	double tmp;
	int ret;
	tmp = ((person *)a)->arrival - ((person *)b)->arrival;
	if(tmp > 0)
		ret = 1;
	else
		ret = -1;
	return ret;
}

double timeformat(string str)
{
	double ret = 0;
	int i = 0;
	ret += (str[i++] - 48) * 60.0 * 10.0;
	ret += (str[i++] - 48) * 60.0;
	++i;
	ret += (str[i++] - 48) * 10.0;
	ret += str[i++] - 48;
	++i;
	ret += (str[i++] - 48) / 6.0;
	ret += (str[i++] - 48) / 60.0;
	return ret;
}

int main()
{
	int N, K;
	cin >> N >> K;
	string tmpstr;
	for(int i = 0; i < N; ++i)
	{
		cin >> tmpstr >> num[i].cost;
		if(num[i].cost > 60)
			num[i].cost = 60.0;
		num[i].wait = 0.0;
		num[i].arrival = timeformat(tmpstr);
		num[i].start = num[i].arrival;
	}
	for(int i = 0; i < K; ++i)
		endtime[i] = 0.0;
	qsort(num, N, sizeof(num[0]), cmp);
	int d = 0;
	double minTime;
	int minIndex;
	int numQ = 0;
	while(d < N)
	{
		if(num[d].arrival < MIN)
		{
			num[d].wait += MIN - num[d].arrival;
			num[d].start = MIN;
			num[d].arrival = MIN;
		}
		if(num[d].arrival > MAX)
		{
			break;
		}
		minTime = INT_MAX;
		minIndex = 0;
		for(int j = 0; j < numQ; ++j)
		{
			if(endtime[j] < minTime)
			{
				minIndex = j;
				minTime = endtime[j];
			}
		}
		if(minTime > num[d].arrival && numQ < K)
		{
			minIndex = numQ;
			++numQ;
		}
		else if(minTime > num[d].arrival && numQ >= K)
		{
			num[d].start = minTime;
			num[d].wait += minTime - num[d].arrival;
		}
		endtime[minIndex] = num[d].start + num[d].cost;
		++d;
	}
	double sum = 0.0;
	for(int h = 0; h < d; ++h)
	{
		sum += num[h].wait;
	}
	double avg = sum * 1.0 / d;
	printf("%.1f\n", avg);
	return 0;
}