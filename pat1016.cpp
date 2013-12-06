#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct num
{
	char name[22];
	int month;
	int day;
	int hour;
	int minute;
	char tag[10];
}record[1001];
int cost[25];
int cmp1(const void *a, const void *b)
{
	return strcmp((*(struct num *)a).name, (*(struct num *)b).name);	
}

int cmp2(const void *a, const void *b)
{
	if((*(struct num *)a).day < (*(struct num *)b).day) return -1;
	else if((*(struct num *)a).day > (*(struct num *)b).day) return 1;
	else
	{
		if((*(struct num *)a).hour < (*(struct num *)b).hour) return -1;
		else if((*(struct num *)a).hour > (*(struct num *)b).hour)  return 1;
		else
		{
			if((*(struct num *)a).minute < (*(struct num *)b).minute)  return -1;
			else return 1;
		}
	}	
}

int main()
{
	int n,i,count,j,start=0,total=0,k,flag,flag1;
	double money,totalmoney;
	memset(cost,0,sizeof(cost));
	for(i=0;i<24;i++)
	{
		scanf("%d",&cost[i]);
	}
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%s",&record[i].name);
		scanf("%d:%d:%d:%d",&record[i].month,&record[i].day,&record[i].hour,&record[i].minute);
		scanf("%s",&record[i].tag);
	};
	qsort(record,n,sizeof(record[0]),cmp1);
	i=0;
	while(i<n)
	{
		if(strcmp(record[i].name,record[i+1].name)!=0)
		{
			totalmoney=0;
			flag=0;
			flag1=1;
			count=i;
			qsort(record+start,count-start+1,sizeof(record[0]),cmp2);
			for(j=start;j<count;j++)
			{
				total=0;
				money=0;
				if(strcmp(record[j].tag,record[j+1].tag)>0)
				{
					flag=1;
					if(flag==1&&flag1==1)
					{
						printf("%s ",record[i].name);
						printf("%02d\n",record[i].month);
						flag1=0;
					}
					printf("%02d:%02d:%02d ",record[j].day,record[j].hour,record[j].minute);
					printf("%02d:%02d:%02d ",record[j+1].day,record[j+1].hour,record[j+1].minute);
					total=(record[j+1].day-record[j].day)*1440+(record[j+1].hour-record[j].hour)*60+(record[j+1].minute-record[j].minute);
					printf("%d ",total);
					if(record[j+1].hour-record[j].hour > 0)
					{
						money+=(record[j+1].day-record[j].day)*60*(cost[0]+cost[1]+cost[2]+cost[3]+cost[4]+cost[5]+cost[6]+cost[7]+cost[8]+cost[9]+cost[10]+cost[11]+cost[12]+cost[13]+cost[14]+cost[15]+cost[16]+cost[17]+cost[18]+cost[19]+cost[20]+cost[21]+cost[22]+cost[23]);
						money+=(60-record[j].minute)*cost[record[j].hour];
						money+=(record[j+1].minute)*cost[record[j+1].hour];
						for(k=record[j].hour+1;k<record[j+1].hour;k++)
						{
							money+=60*cost[k];
						}
					}
					else if(record[j+1].hour-record[j].hour == 0)
					{
						money+=(record[j+1].day-record[j].day)*60*(cost[0]+cost[1]+cost[2]+cost[3]+cost[4]+cost[5]+cost[6]+cost[7]+cost[8]+cost[9]+cost[10]+cost[11]+cost[12]+cost[13]+cost[14]+cost[15]+cost[16]+cost[17]+cost[18]+cost[19]+cost[20]+cost[21]+cost[22]+cost[23]);
						money+=(record[j+1].minute - record[j].minute)*cost[record[j].hour];						
					}
					else
					{
						money+=(record[j+1].day-record[j].day-1)*60*(cost[0]+cost[1]+cost[2]+cost[3]+cost[4]+cost[5]+cost[6]+cost[7]+cost[8]+cost[9]+cost[10]+cost[11]+cost[12]+cost[13]+cost[14]+cost[15]+cost[16]+cost[17]+cost[18]+cost[19]+cost[20]+cost[21]+cost[22]+cost[23]);
						for(k=record[j].hour+1;k<24;k++)
						{
							money+=60*cost[k];
						}
						for(k=0;k<record[j+1].hour;k++)
						{
							money+=60*cost[k];
						}
						money+=(60-record[j].minute)*cost[record[j].hour];
						money+=(record[j+1].minute)*cost[record[j+1].hour];
					}
					money/=100;
					printf("$%.2lf\n",money);
					totalmoney+=money;					
				}				
			}
			start=i+1;
			if(flag==1)
			{
				printf("Total amount: $%.2lf\n",totalmoney);
			}
		}
		i++;
	}	
	return 0;	
}
