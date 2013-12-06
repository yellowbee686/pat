#include<cstdio>
#include<cstdlib>
const int NUM=505;
const int INF=0x7fffffff;
struct station
{
    double price;
    double dist;
}s[NUM];


int cmp(const void *a,const void *b)
{
    station *x=(station *)a;
    station *y=(station *)b;
    return x->dist - y->dist;
}
int main()
{
    int i,j,n,davg;
    int flag=1,index;
    double dest,cmax;
    scanf("%lf%lf%d%d",&cmax,&dest,&davg,&n);
    for(i=0;i<n;i++){
        scanf("%lf%lf",&s[i].price,&s[i].dist);
    }
    s[n].price=0;
    s[n].dist=dest;
    double step=cmax*davg;

    double currGas=0;

    double minPrice,sum=0;
    qsort(s,n,sizeof(s[0]),cmp);

    if(s[0].dist>0){
        printf("The maximum travel distance = 0.00\n");
        return 0;
    } else {
        for(i=0;i<n;){
            if(s[i+1].dist-s[i].dist>step){
                flag=0;
                printf("The maximum travel distance = %.2lf\n",s[i].dist+step);
                break;
            } else {
                index=i;
                minPrice=s[i].price;
                //1.现在有油，
                for(j=i+1;s[j].dist-s[i].dist<=currGas*davg&&j<=n;j++){//找现有油箱能跑到的比现在最便宜的油站
                    if(s[j].price<minPrice){
                        index=j;
                        minPrice=s[j].price;
                    }

                }
                if(index!=i){//现在有油，找到了比现在油站价格最便宜的油站（不加油能到），就直接开过去，不加油，到那再加
                    currGas-=(s[index].dist-s[i].dist)/davg;//耗油
                    i=index;
                    continue;
                }
                index=i;
                //minPrice=s[i].price;
                //2.现在没油或所能到的油站价格都比现在油站贵
                for(j=i+1;s[j].dist-s[i].dist<=step&&j<=n;j++){//找最近的比现油站便宜的油站
                    if(s[j].price<minPrice){
                        index=j;
                        break;
                    }
                }
                if(index!=i){//现在没油或现油箱所能到的油站价格都比现在油站贵：要去最近的比现油站便宜的油站（不加油到不了），得在现油站加上刚好满足的油量
                    sum+=((s[index].dist-s[i].dist)/davg-currGas)*s[i].price;
                    currGas=0;
                    //printf("%.2lf\n",sum);
                    i=index;
                    continue;
                }
                //3.现在有油或没油，没找到比现在便宜的油站，当然是在现油站加满，再到下一个次便宜的油站
                index=i;
                minPrice=INF;
                for(j=i+1;s[j].dist-s[i].dist<=step&&j<=n;j++){//找接下来step范围内的最便宜油站
                    if(s[j].price<minPrice){
                        index=j;
                        minPrice=s[j].price;
                    }
                }
                sum+=(cmax-currGas)*s[i].price;//没找到比现在便宜的油站，当然是在现油站加满，再到下一个次便宜的油站
                currGas=cmax-(s[index].dist-s[i].dist)/davg;
                i=index;
            }
        }
    }
    if(flag==1)
        printf("%.2lf\n",sum);
    return 0;
}