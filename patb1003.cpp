/*
������ȷ�����Զ�����ϵͳ�����������˻�ϲ�Ļظ�����������PAT�ġ�����ȷ�������� ���� ֻҪ������ַ�����������������ϵͳ�����������ȷ��������������𰸴��󡱡�

�õ�������ȷ���������ǣ�

1. �ַ����б������P, A, T�������ַ��������԰��������ַ���
2. �������� xPATx ���ַ��������Ի�á�����ȷ�������� x �����ǿ��ַ����������ǽ�����ĸ A ��ɵ��ַ�����
3. ��� aPbTc ����ȷ�ģ���ô aPbATca Ҳ����ȷ�ģ����� a, b, c �������ǿ��ַ����������ǽ�����ĸ A ��ɵ��ַ�����

���ھ�����ΪPATдһ���Զ����г����ж���Щ�ַ����ǿ��Ի�á�����ȷ���ġ�
�����ʽ�� ÿ�������������1��������������1�и���һ����Ȼ��n (<10)������Ҫ�����ַ���������������ÿ���ַ���ռһ�У��ַ������Ȳ�����100���Ҳ������ո�

�����ʽ��ÿ���ַ����ļ����ռһ�У�������ַ������Ի�á�����ȷ���������YES���������NO��

����������
8
PAT
PAAT
AAPATAA
AAPAATAAAA
xPATx
PT
Whatever
APAAATAA
���������
YES
YES
YES
YES
NO
NO
NO
NO

������Ҫע�⣬����������ǵݹ�ģ���PT�м��ж���1��A�Ϳ��ԣ��м���A���ұߵ�A������ߵ�A�ļ������������߶��ǿ��ַ���
*/

#include <iostream>
#include <string>
using namespace std;

bool check(string str)
{
	bool ret = false;
	string::size_type pos1 = str.find("P");
	string::size_type pos2 = str.find("T");
	string s1, s2, s3;
	string middle;
	int n;
	if(pos1 != string::npos && pos2 != string::npos && pos2 > pos1+1)
	{
		middle = str.substr(pos1+1,pos2-pos1-1);
		string::size_type pos3 = middle.find_first_not_of("A");
		if(pos3 == string::npos)
		{
			n = middle.size();
			s1 = str.substr(0,pos1);
			s2 = str.substr(pos2+1);
			s3 = "";
			while(n--)
			{
				s3 += s1;
			}
			if(s3 == s2)
			{
				string::size_type pos4 = s1.find_first_not_of("A");
				if(pos4 == string::npos)
				{
					ret = true;
				}
			}
		}		
	}
	return ret;
}

int main()
{
	int n;
	cin >> n;
	string str, x, a, b, c;
	while(n--)
	{
		cin >> str;
		if( check(str))
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}
	return 0;
}