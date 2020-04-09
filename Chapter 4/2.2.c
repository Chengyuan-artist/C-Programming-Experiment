#include <stdio.h>

long long fac(int n);
double sum(double x,int n);

/*eliminient the mulx() fuction*/
int main(void)
{
    double x;
    int n;
    printf("Input x and n: ");
    scanf("%lf%d",&x,&n);
    printf("The result is %f",sum(x,n));
    return 0;
}
double sum(double x,int n)
{
    int i;
    double z=1.0;
    double mulx=x;
    for(i=1;i<=n;i++)
    {
        z=z+mulx/fac(i);
        mulx*=x;
    }
    return z;
}
long long fac(int n)
{
    //Use static variable to cut down repeting computation
    static long long fact=1;
    fact=n*fact;
    return fact;
}
