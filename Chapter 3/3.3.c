#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    scanf("%d",&n);
    int x,former,max=0;
    scanf("%d",&x);
    int val;
    for(int i=1;i<n;++i)
    {
        former=x;
        scanf("%d",&x);
        val=abs(x-former);
        if(val>max)max=val;
    }
    printf("最大波动值为%d\n",max);
    return 0;
}
