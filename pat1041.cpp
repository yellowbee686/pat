#include <stdio.h>
#define MAX 10000
#define MAX1 100000
    
int main()
{
    int s[MAX], t[MAX1];
    long int i;
    long int N;
          
    for (i = 0; i < MAX; i++)
    s[i] = 0;
           
    scanf("%ld", &N); 
          
    for (i = 0; i < N; i++)
    { 
        scanf("%d", &t[i]);
        s[t[i]]++;
    } 
          
    for (i = 0; i < N; i++)
    {
        if (s[t[i]] == 1)
        break;
    }
          
    if (i == N)
    printf("None");
    else 
    printf("%d", t[i]);
          
    return 0;
           
}