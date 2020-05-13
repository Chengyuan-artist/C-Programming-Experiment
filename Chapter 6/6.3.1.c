#include <stdio.h>

int main()
{
    long x;
    printf("please input an integer:");
    scanf("%ld",&x);
    char *p=(char *)&x+(sizeof(long)-1);
    for(int i=0;i<4;++i)
    {
        printf("%x %x ",(*p>>4)&0xf,*p&0xf);
        p--;
    }
    return 0;
}
