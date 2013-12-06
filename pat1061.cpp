/*
�����ĸ��ַ�����ÿ�������� 60 ���ַ��������ո�Ҫ������ҵ��������¹涨�������ַ����������ǵ�λ�ã�����ת����һ��ʱ��ı�
1.���αȽ�ǰ�����ַ�����ÿ��λ�õ�Ԫ�أ��ҵ���һ����ȵ��ַ����Ҹ��ַ�����[��A��, ��G��]����ĸ��ע���Сд���С�ת����һ�����������
2.�� 1 �е��ַ�����֮�󣬼����Ƚ�ǰ���������ҵ�һ����ȵ��ַ���ʹ������[��0��, ��9��] || [��A��, ��N��]��ͬ������Сд���С�
ת����һ�� 24 Сʱ��Сʱ�������
3.�ȽϺ������ַ������ҵ���һ����ȵ���ĸ��isalpha()���������������е�λ��ֵת�������������
��Ҫע����ǣ�
1. �����޿ո�����е��ַ����У�ֱ��cin���� ��getline��Ҫ getline(cin,string);
2. �ڶ��ַ����ж�ʱstring�����˺ܶຯ�� ���� isupper isalpha isdigit��
3. ��֪����ĸ������������ļ�ö���� ����Ҫдswitch ���ǰ�����װ��һ�������У���Ӧ�������Ϊ�±���з��ʼ���
4. ����һ��string��˵ str='0'+'4';�ǰ��������ַ�ֵ������ ����һ���ַ� ���Ҫʵ��04Ӧ����str="0"+"4";
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