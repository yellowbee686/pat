/*
“答案正确”是自动判题系统给出的最令人欢喜的回复。本题属于PAT的“答案正确”大派送 —— 只要读入的字符串满足下列条件，系统就输出“答案正确”，否则输出“答案错误”。

得到“答案正确”的条件是：

1. 字符串中必须仅有P, A, T这三种字符，不可以包含其它字符；
2. 任意形如 xPATx 的字符串都可以获得“答案正确”，其中 x 或者是空字符串，或者是仅由字母 A 组成的字符串；
3. 如果 aPbTc 是正确的，那么 aPbATca 也是正确的，其中 a, b, c 均或者是空字符串，或者是仅由字母 A 组成的字符串。

现在就请你为PAT写一个自动裁判程序，判定哪些字符串是可以获得“答案正确”的。
输入格式： 每个测试输入包含1个测试用例。第1行给出一个自然数n (<10)，是需要检测的字符串个数。接下来每个字符串占一行，字符串长度不超过100，且不包含空格。

输出格式：每个字符串的检测结果占一行，如果该字符串可以获得“答案正确”，则输出YES，否则输出NO。

输入样例：
8
PAT
PAAT
AAPATAA
AAPAATAAAA
xPATx
PT
Whatever
APAAATAA
输出样例：
YES
YES
YES
YES
NO
NO
NO
NO

本题需要注意，第三种情况是递归的，即PT中间有多于1个A就可以，有几个A，右边的A就是左边的A的几倍，或者两边都是空字符串
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