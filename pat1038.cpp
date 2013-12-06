#include <iostream>  
#include <string>  
#include <algorithm>  
#include <cstdio>  
using namespace std;  
#define MAX 0Xfffffff  
string a[10001];  
  
bool cmp(string s1, string s2){  
      
    return s1+s2<s2+s1;  
}  
int main(){  
    int n;  
    cin>>n;  
    for(int i=0;i<n;++i){  
        cin>>a[i];  
    }  
    sort(a, a+n, cmp);  
    bool first = true;  
    bool print = false;  
    for(int i=0;i<n;++i){  
        int len = a[i].length();  
        for(int j=0;j<len;++j){  
            if(first){  
                if(a[i][j]!='0'){  
                    printf("%c", a[i][j]);  
                    print = true;  
                    first = false;  
                }         
            }else{  
                printf("%c", a[i][j]);  
                print = true;  
            }  
        }  
    }  
    if(!print)  
        printf("0");  
    printf("\n");   
}