#include <stdio.h>
int F[10000];
int main()
{
    F[0]=F[1]=1;
    int i,k;
    unsigned long long sum=0,fabonacci(int n);
    printf("Input n:");
    scanf("%d",&k);
    for(i=1;i<=k;++i)
    {
        sum+=fabonacci(i);
        printf("i=%d\tthe sum is %llu\n",i,sum);
    }
    return 0;
}
unsigned long long fabonacci(int n)
{
    if(F[n])//�����λ쳲��������������
        return F[n];
    else
    {
        F[n]=fabonacci(n-1)+fabonacci(n-2);//���¸�λ쳲�������
        return F[n];
    }
}
