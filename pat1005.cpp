# include <iostream>
using namespace std;

void printDigit(int n)
{
	switch(n)
	{
		case 0:
			cout << "zero";
			break;
		case 1:
			cout << "one";
			break;
		case 2:
			cout << "two";
			break;
		case 3:
			cout << "three";
			break;
		case 4:
			cout << "four";
			break;
		case 5:
			cout << "five";
			break;
		case 6:
			cout << "six";
			break;
		case 7:
			cout << "seven";
			break;
		case 8:
			cout << "eight";
			break;
		case 9:
			cout << "nine";
			break;
	}
}

void print(int n)
{
	int i = 1;
	int tmp = n;
	while(tmp / 10 > 0)
	{
		tmp /= 10;
		i *= 10;
	}
	while(i > 0)
	{
		printDigit(n / i);
		if (i > 1)
			cout << ' ';
		n %= i;
		i /= 10;
	}
}

int main()
{
	char n[110];
	int i = 0;
	int sum = 0;
	gets(n); 
	while(n[i] != 0)
	{
		sum += n[i++] - 48;
	}
	print(sum);
	return 0;
}