#include <iostream>
using namespace std;

int main()
{
	int ea[12], eb[12], eans[24];
	float ca[12], cb[12], cans[24];
	int ka, kb;
	cin >> ka;
	for(int i = 0; i < ka; ++i)
		cin >> ea[i] >> ca[i];
	cin >> kb;
	for(int i = 0; i < kb; ++i)
		cin >> eb[i] >> cb[i];
	int i = 0, j = 0, k = 0;
	while( i < ka || j < kb)
	{
		if(i < ka && j < kb)
		{
			if(ea[i] > eb[j])
			{
				eans[k] = ea[i];
				cans[k] = ca[i];
				++i;
				++k;
			}
			else if(ea[i] < eb[j])
			{
				eans[k] = eb[j];
				cans[k] = cb[j];
				++j;
				++k;
			}
			else
			{
				if( ca[i] + cb[j] != 0)
				{
					eans[k] = ea[i];
					cans[k] = ca[i] + cb[j];
					++i;
					++j;
					++k;
				}
				else
				{
					++i;
					++j;
				}
			}
		}
		else if(i == ka)
		{
			eans[k] = eb[j];
			cans[k] = cb[j];
			++j;
			++k;
		}
		else
		{
			eans[k] = ea[i];
			cans[k] = ca[i];
			++i;
			++k;
		}
	}
	cout << k;
	for(int m = 0; m < k; ++m)
		printf(" %d %.1f", eans[m], cans[m]);
	return 0;
}