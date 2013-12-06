#include<stdio.h>
#define MAX 0x3ffffff
int cmax,N,end,M;
int node[599];
int map[599][599];
int path[599];

int rpath[599];
int in,out,nowstep,rstep;

bool hash[599][599];
int shortlen;

int dis[505];
bool use[505];
int ok=0;


void dijk( )
{
    int n=N,m;
    int min,rj,i,j;
    for(j=0;j<=n;j++)
    {
        dis[j]=map[0][j];
        use[j]=0;
    }
    use[0]=1;
    for(i=0;i<n;i++)
    {
        min=MAX;
        for(j=0;j<=n;j++)
        {
            if(use[j]==1)continue;
            if(dis[j]<min)
            {
                min=dis[j];
                rj=j;
            }
        }
        
        use[rj]=1;
        for(j=0;j<=n;j++)
        {
            if(use[j]==1)continue;
            if(dis[j]>dis[rj]+map[rj][j])
                dis[j]=dis[rj]+map[rj][j];
        }
    }

    shortlen=dis[end];
}


void print(){
    int i;
    printf("%d",in);
    printf(" 0");
    for(i=1;i<=rstep;i++){
        printf("->%d",rpath[i]);
    }
    printf(" %d\n",out);
}

void cal(){
    int tin=99999999,tout=999999999;
    int i,add=0;
    for(i=1;i<=nowstep;i++){
        add+=node[path[i]]-cmax/2;
        if(add<tin)tin=add;
    }
    if(tin>0)tin=0;
    else tin=-tin;
    tout=add+tin;

    if((tin<in)||((tin==in)&&tout<out)){
        in=tin;
        out=tout;
        if(in==0&&tout==0)ok=1;
        rstep=nowstep;
        for(i=1;i<=nowstep;i++){
            rpath[i]=path[i];
        }
    }
}
void dfs(int step,int first,int lenth)
{
    if(ok==1||lenth>dis[first])return ; //lenth>dis[first] 是个关键的剪枝，不加的话最后一个点会超时
    if(lenth==shortlen&&first==end){
        nowstep=step;
        cal();
    }

    int j;
    for(j=1;j<=N;j++){
        if(hash[first][j]==1||map[j][first]==MAX)continue;
        hash[first][j]=hash[j][first]=1;
        path[step+1]=j;
        dfs(step+1,j,lenth+map[first][j]);
        hash[first][j]=hash[j][first]=0;
    }
}

int main()
{
    while(scanf("%d%d%d%d",&cmax,&N,&end,&M)!=EOF){
        int i,j,temp;
        ok=0;
        in=99999999;
        out=99999999;

        for(i=0;i<=N;i++){
            for(j=0;j<=N;j++){
                map[i][j]=MAX;
                hash[i][j]=0;
            }
        }

        for(i=1;i<=N;i++){
            scanf("%d",&node[i]);
        }
        

        int ll,rr,v;
        for(i=1;i<=M;i++){
            scanf("%d%d%d",&ll,&rr,&v);
            map[ll][rr]=map[rr][ll]=v;
        }
        dijk();
        dfs(0,0,0);
        print();
    }

    return 0;
}
