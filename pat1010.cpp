#include <iostream>
#include <string>
#include <limits.h>
#include <math.h>
using namespace std;

int getNum(char c)
{
	int ret = -1;
	if(c >= 48 && c <= 57)
		ret = c - 48;
	else if(c >= 97 && c <= 122)
		ret = c - 87;
	return ret;
}

int main()
{
	int tag, radix;
	double n1, n2;
	string s1, s2;
	cin >> s1 >> s2 >> tag >> radix;
	string tmpStr;
	if(tag == 2)
	{
		tmpStr = s1;
		s1 = s2;
		s2 = tmpStr;
	}
	n1 = 0;
	
	int i;
	int length = s1.size();
	int e;
	for(i = length-1; i >=0; --i)
	{
		e = getNum(s1.at(i));
		n1 += e * pow((double)radix, length-1-i);
	}
	long long j;
	bool flag = false;
	int ans;
	int max = 0;
	int minRadix;
	length = s2.size();
	for(i = 0; i < length; ++i)
		if(max < s2.at(i))
			max = s2.at(i);
	minRadix = getNum(max) + 1;
	long long left = minRadix;
	long long right = INT_MAX;
	ans = 0;
	while(left <= right)
	{
		j = (left+right)/2;
		
		n2 = 0;
		for(i = length-1; i >=0; --i)
		{
			e = getNum(s2.at(i));
			n2 += e * pow((double)j, length-1-i);
		}
		if(n2 == n1)
		{
			flag = true;
			ans = j;
			break;
		}
		else if(n2 > n1)
		{
			right = j-1;
		}
		else
		{
			left = j+1;
		}
	}
	if(flag)
	{
		for(int j = minRadix; j < 1000; ++j)
		{
			n2 = 0;
			for(i = length-1; i >=0; --i)
			{
				e = getNum(s2.at(i));
				n2 += e * pow((double)j, length-1-i);
			}
			if(n2 == n1)
			{
				flag = true;
				ans = j;
				break;
			}
			else if(n2 > n1)
			{
				break;
			}
		}
	}
	if(flag)
		cout << ans << endl;
	else
		cout << "Impossible" << endl;
	return 0;
}