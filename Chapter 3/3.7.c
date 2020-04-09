#include <stdio.h>

int main()
{
    for(int num=32;num<=99;++num)
    {
        int x=num*num;
        if(x%10==(x/10%10)&&(x/100%10)==(x/1000))
            printf("%d\n",x);
    }
    return 0;
}
