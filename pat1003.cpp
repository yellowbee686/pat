#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
      
int map[500][500];
int peo[500];
int result[500][3];
      
void init(){
    for(int i=0; i<500; ++i){
        for(int j=0; j<500; ++j){
            map[i][j]=map[j][i]=-1;
        }
        map[i][i]=0;
        result[i][0]=-1;
        result[i][1]=result[i][2]=0;
    }
}
     
bool less_entry(int i, int j){
    if(result[i][0]<result[j][0])
    return true;
    else
    return false;
}
     
void dij(int s, int n){
    vector<int> temp;
    result[s][0]=0;
    result[s][1]=1;
    temp.push_back(s);
    while(!temp.empty()){
        int cur = *temp.begin();
        temp.erase(temp.begin());
        for(int i=0; i<n; ++i){
            if(i!=cur){
                    if(map[cur][i]!=-1){
                        if(result[i][0]==-1){
                            result[i][0]=result[cur][0]+map[cur][i];
                            result[i][1]=result[cur][1];
                            result[i][2]=result[cur][2]+peo[i];
                            temp.push_back(i);
                        }
                        else if(result[i][0]>result[cur][0]+map[cur][i]){
                            result[i][0]=result[cur][0]+map[cur][i];
                            result[i][1]=result[cur][1];
                            result[i][2]=result[cur][2]+peo[i];
                        }
                        else if(result[i][0]==result[cur][0]+map[cur][i]){
                            result[i][1]+=result[cur][1];
                            if(result[i][2]<result[cur][2]+peo[i])
                            result[i][2]=result[cur][2]+peo[i];
                        }
                    }
            }
        }
        sort(temp.begin(), temp.end(), less_entry);
    }
}
     
int main(){
    int n,m,c1,c2;
    cin >>n>>m>>c1>>c2;
    init();
    int ad,ac;
    for(int i=0; i<n; ++i){
        cin >>ad;
        peo[i]=result[i][2]=ad;
    }
    for(int i=0; i<m; ++i){
        cin >>ad>>ac;
        cin >>map[ad][ac];
        map[ac][ad]=map[ad][ac];
    }
    dij(c1, n);
    cout<<result[c2][1]<<" "<<result[c2][2];
}