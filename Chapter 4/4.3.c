#include <stdio.h>
//#define MAX 1000;

int power(int x,int n);
int selfpow(int k);

int data[100];//store the found self power numbers

char str[8][30]={"水仙花数","四叶玫瑰数","五角星数","六合数","北斗七星数","八仙数"};

int main(void)
{
    int k;
    while(scanf("%d",&k)!=EOF)
    {
        if(k==0)return 0;
        if(k>=3&&k<=8)
        {
            selfpow(k);
            printf("\n");
        }
        else printf("请重新输入:\n");
    }
    return 0;
}

int selfpow(int k)
{
    //find and output all the k-length self power number
    int cnt=0;
    int inf=power(10,k);
    for(int num=power(10,k-1);num<inf;++num)
    {
        int sum=0;
        int tmp=num;
        while(tmp>0)
        {
            sum+=power(tmp%10,k);
            tmp/=10;
        }
        if(sum==num)
        {
            data[cnt]=num;
            ++cnt;
        }
    }
    if(cnt>0)
    {
        printf("%d位的%s共有%d个：",k,str[k-3],cnt);
        printf("%d",data[0]);
        for(int i=1;i<cnt;++i)printf(",%d",data[i]);
        return 1;
    }
    else return 0;
}
int power(int x,int n)
{
    //compute x^n
    int res=1;
    for(int i=0;i<n;++i)
    {
        res*=x;
    }
    return res;
}
