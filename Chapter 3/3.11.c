#include <stdio.h>
#include <stdlib.h>
int num[10]={0};
int isok(int a,int b);
int main()
{

    int x;
    scanf("%d",&x);
    for(int dom=1234;dom<=98765;++dom)
    {
        int fom=dom*x;
        if(fom>98765)break;
        //if(fom<56789)continue;
        if(isok(fom,dom))
        {
            printf("%d/",fom);
            if(dom<10000)printf("0");
            printf("%d=%d\n",dom,x);
        }
    }
    return 0;
}
int isok(int a,int b)
{
    for(int i=0;i<10;++i)num[i]=0;
    while(a>0)
    {
        num[a%10]=1;
        a/=10;
    }
    while(b>0)
    {
        num[b%10]=1;
        b/=10;
    }
    if(a<10000||b<10000)num[0]=1;
    int sum=0;
    for(int i=0;i<10;++i)sum+=num[i];
    if(sum==10)return 1;
    else return 0;
}
