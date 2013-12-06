#include<iostream>
#include<stack>
using namespace std;

int main()
{
	int M; //maximum capacity of the stack
	int N; //the length of push sequence
	int K; //the number of pop sequence to be checked
	cin>>M>>N>>K;
	int i,j;
	int input,temp;
	bool flag = true;
	stack<int> sta;
    
	for(i=0; i<K; i++)
	{
		temp = 1;
		flag = true;
		for(j=0; j<N; j++)
		{
			cin>>input;
			while( sta.size() <= M && flag )
			{
				if(sta.empty() || sta.top() != input)
				{
					sta.push(temp ++);
				}
				else if(sta.top() == input)
				{
					sta.pop();
					break;
				}			
			}
			if(sta.size() > M)
			{flag = false;}
		}

		if(flag)
			cout<<"YES"<<endl;
		else 
			cout<<"NO"<<endl;
		while(!sta.empty())
			sta.pop();
	}
	return 0;
}