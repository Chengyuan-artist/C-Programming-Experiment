#include<stdio.h>

int isCom(int x)
{
    int flag=0;
    int i,k;
    for(i=2,k=x>>1;i<=k;i++)
    {
        if(!(x%i))
        {
            flag=1;
            break;
        }
    }
    if(flag==1)return 1;
    else return 0;
}
int main()
{
    int cnt=0;
    for(int num=100;num<=999;++num)
    {
        if(isCom(num)&&isCom(num/10)&&isCom(num/100))
        {
            cnt++;
            printf("%d ",num);
            if(cnt%10==0)printf("\n");
        }

    }
    return 0;
}
