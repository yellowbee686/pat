#include <iostream>
using namespace std;

int main()
{
	char s1[25];
	int a1[25];
	int a2[25];
	int ans[25];
	//因为题目中输入数字不超过20位，还要乘以2，因此long long也无法表示该数，所以使用get()直接读入数组
	//cin.get(buffer, num)可以将一行插入字符数组中，再在结尾插入'\0'用于区分
	cin.get(s1, 25);
	int count = 0;
	int count2 = 0;
	while(s1[count] != 0)
	{
		count++;
	}
	for(int i = 0; i < count; ++i)
	{
		a1[i] = s1[i] - '0';
	}

	int tmp;
	int carry = 0;
	for(int i = count - 1; i >= 0; --i)
	{
		tmp = a1[i] * 2 + carry;
		a2[i] = tmp % 10;
		carry = tmp / 10;
	}
	if(carry)
	{
		count2 = count+1;
		for(int i = count; i > 0; --i)
		{
			a2[i] = a2[i-1];
		}
		a2[0] = carry;
	}
	else
	{
		count2 = count;
	}
	for(int i = 0; i < count2; ++i)
	{
		ans[i] = a2[i];
	}
	bool flag = true;
	int tmpi = 0;
	for(int i = 0; i < count; ++i)
	{
		tmp = a1[i];
		tmpi = i;
		for(int j = i; j < count; ++j)
		{
			if(a1[j] < tmp)
			{
				tmp=a1[j];
				tmpi = j;
			}
		}
		a1[tmpi]=a1[i];
		a1[i]=tmp;
	}
	for(int i = 0; i < count2; ++i)
	{
		tmp = a2[i];
		tmpi = i;
		for(int j = i; j < count2; ++j)
		{
			if(a2[j] < tmp)
			{
				tmp=a2[j];
				tmpi = j;
			}
		}
		a2[tmpi]=a2[i];
		a2[i]=tmp;
	}
	if(count == count2)
	{
		for(int i=0; i<count; ++i)
		{
			if(a1[i] != a2[i])
			{
				flag=false;
				break;
			}
		}
	}
	else
	{
		flag = false;
	}
	if(flag)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	for(int i = 0; i < count2; ++i)
	{
		cout << ans[i];
	}
	cout << endl;
}