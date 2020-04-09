#include <stdio.h>

int isprime(int n);
void guess(int n);

int main(void)
{
    int n;
    printf("Please input even number no less than four(you can input repeatly):");
    while(scanf("%d",&n)!=EOF)
    {
        if(n%2==0&&n>=4)guess(n);
        else printf("Please reinput even number no less than four:");
    }
    return 0;
}
void guess(int n)
{
    for(int num=2;num<=n/2;++num)
    {
        if(isprime(num))
        {
            if(isprime(n-num))
            {
                printf("%d=%d+%d\n",n,num,n-num);
            }
        }
    }
    return;
}
int isprime(int n)
{
    int flag=1;
    for(int i=2;i*i<=n;++i)
    {
        if(n%i==0)
        {
            flag=0;
            break;
        }
    }
    return flag;
}
