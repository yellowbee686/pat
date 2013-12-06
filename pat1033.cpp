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
                //1.�������ͣ�
                for(j=i+1;s[j].dist-s[i].dist<=currGas*davg&&j<=n;j++){//�������������ܵ��ı���������˵���վ
                    if(s[j].price<minPrice){
                        index=j;
                        minPrice=s[j].price;
                    }

                }
                if(index!=i){//�������ͣ��ҵ��˱�������վ�۸�����˵���վ���������ܵ�������ֱ�ӿ���ȥ�������ͣ������ټ�
                    currGas-=(s[index].dist-s[i].dist)/davg;//����
                    i=index;
                    continue;
                }
                index=i;
                //minPrice=s[i].price;
                //2.����û�ͻ����ܵ�����վ�۸񶼱�������վ��
                for(j=i+1;s[j].dist-s[i].dist<=step&&j<=n;j++){//������ı�����վ���˵���վ
                    if(s[j].price<minPrice){
                        index=j;
                        break;
                    }
                }
                if(index!=i){//����û�ͻ����������ܵ�����վ�۸񶼱�������վ��Ҫȥ����ı�����վ���˵���վ�������͵����ˣ�����������վ���ϸպ����������
                    sum+=((s[index].dist-s[i].dist)/davg-currGas)*s[i].price;
                    currGas=0;
                    //printf("%.2lf\n",sum);
                    i=index;
                    continue;
                }
                //3.�������ͻ�û�ͣ�û�ҵ������ڱ��˵���վ����Ȼ��������վ�������ٵ���һ���α��˵���վ
                index=i;
                minPrice=INF;
                for(j=i+1;s[j].dist-s[i].dist<=step&&j<=n;j++){//�ҽ�����step��Χ�ڵ��������վ
                    if(s[j].price<minPrice){
                        index=j;
                        minPrice=s[j].price;
                    }
                }
                sum+=(cmax-currGas)*s[i].price;//û�ҵ������ڱ��˵���վ����Ȼ��������վ�������ٵ���һ���α��˵���վ
                currGas=cmax-(s[index].dist-s[i].dist)/davg;
                i=index;
            }
        }
    }
    if(flag==1)
        printf("%.2lf\n",sum);
    return 0;
}