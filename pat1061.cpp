/*
给定四个字符串，每个不超过 60 个字符，不含空格。要求从中找到符合如下规定的三个字符（或者它们的位置），并转化成一个时间的表达：
1.依次比较前两个字符串中每个位置的元素，找到第一个相等的字符，且该字符属于[‘A’, ‘G’]的字母，注意大小写敏感。转换成一周七天输出。
2.在 1 中的字符出现之后，继续比较前两个串，找到一个相等的字符，使它属于[‘0’, ‘9’] || [‘A’, ‘N’]，同样，大小写敏感。
转换成一天 24 小时的小时数输出。
3.比较后两个字符串，找到第一个相等的字母（isalpha()），将它在数组中的位置值转换分钟数输出。
需要注意的是：
1. 输入无空格的整行到字符串中，直接cin即可 而getline需要 getline(cin,string);
2. 在对字符做判断时string给出了很多函数 比如 isupper isalpha isdigit等
3. 在知道字母输出星期这样的简单枚举中 不需要写switch 而是把星期装入一个数组中，对应的情况作为下标进行访问即可
4. 对于一个string来说 str='0'+'4';是把这两个字符值加起来 还是一个字符 如果要实现04应该是str="0"+"4";
*/
#include <iostream>
#include <string>
#include <strstream>
using namespace std;

string getdate(char c1)
{
	int num=c1-'A';
	string ret;
	switch (num)
	{
	case 0:
		ret="MON";
		break;
	case 1:
		ret="TUE";
		break;
	case 2:
		ret="WED";
		break;
	case 3:
		ret="THU";
		break;
	case 4:
		ret="FRI";
		break;
	case 5:
		ret="SAT";
		break;
	case 6:
		ret="SUN";
		break;
	}
	return ret;
}

string getminute(int c3)
{
	string ret;
	strstream ss;
	string tmp;
	if(c3>=10)
	{
		ss<<c3;
		ss>>ret;
	}
	else if(c3>=0)
	{
		ss<<c3;
		ss>>tmp;
		ret="0"+tmp;
	}
	else
	{
		ret="00";
	}
	return ret;
}

string gethour(char c2)
{
	string ret;
	int hour;
	strstream ss;
	if(isdigit(c2))
	{
		ret='0';
		ret+=c2;
	}
	else
	{
		hour=c2-'A'+10;
		ss<<hour;
		ss>>ret;
	}
	return ret;
}

int main()
{
	char str[4][60];
	for(int i=0;i<4;++i)
		cin>>str[i];
	int i=0;
	int flag=1;
	char c1,c2;
	int c3=-1;

	while(str[0][i]!='\0'&&str[1][i]!='\0')
	{
		if(str[0][i]==str[1][i]&&(isupper(str[0][i])&&str[0][i]<='G')&&flag==1)
		{
			c1=str[0][i];
			flag++;
		}
		else if(str[0][i]==str[1][i]&&flag==2&&(isupper(str[0][i])&&str[0][i]<='N'||isdigit(str[0][i])))
		{
			c2=str[0][i];
			break;
		}
		i++;
	}
	i=0;
	while(str[2][i]!='\0'&&str[3][i]!='\0')
	{
		if(str[2][i]==str[3][i]&&isalpha(str[2][i]))
		{
			c3=i;
			break;
		}
		i++;
	}
	cout<<getdate(c1)<<" "<<gethour(c2)<<":"<<getminute(c3)<<endl;
	return 0;
}