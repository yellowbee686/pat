#include <iostream>
using namespace std;

int main()
{
	int ea[12], eb[12], eans[110];
	float ca[12], cb[12], cans[110];
	int ka, kb;
	cin >> ka;
	for(int i = 0; i < ka; ++i)
		cin >> ea[i] >> ca[i];
	cin >> kb;
	for(int i = 0; i < kb; ++i)
		cin >> eb[i] >> cb[i];
	int i = 0, j = 0, counter = 0;
	int tmpe;
	float tmpc;
	bool flag;
	for(int i = 0; i < 110; ++i)
	{
		eans[i] = -1;
	}
	for(int i = 0; i < ka; ++i)
		for(int j = 0; j < kb; ++j)
		{
			flag = false;
			tmpe = ea[i] + eb[j];
			tmpc = ca[i] * cb[j];
			if(!tmpc)
				continue;
			for(int k = 0; k <= counter; ++k)
			{
				if(tmpe == eans[k])
				{
					cans[k] += tmpc;
					flag = true;
					break;
				}
				else if(tmpe > eans[k])
				{
					for(int h = counter; h >= k; h--)
					{
						eans[h+1] = eans[h];
						cans[h+1] = cans[h];
					}
					counter++;
					eans[k] = tmpe;
					cans[k] = tmpc;
					flag = true;
					break;
				}
			}
			if(!flag)
			{
				counter++;
				eans[counter] = tmpe;
				cans[counter] = tmpc;
			}
		}
	int tmpcounter = counter;
	for(int m = 0; m < counter; ++m)
	{
		if(cans[m] == 0)
			tmpcounter--;
	}
	cout << tmpcounter;
	for(int m = 0; m < counter; ++m)
		if(cans[m])
			printf(" %d %.1f", eans[m], cans[m]);
	return 0;
}