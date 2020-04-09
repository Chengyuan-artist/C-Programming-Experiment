#include <stdio.h>

int solfac(int i,int j);

int main()
{
    int n;//杨辉三角行数 从0开始
    scanf("%d",&n);
    for(int i=0;i<n+1;++i)
    {
        //打印空格
        for(int k=0;k<2*(n-i);++k)printf(" ");
        int x=1;
        int fomer=x;
        printf("%-4d",x);
        for(int j=1;j<i+1;++j)
        {
            x=fomer*(i-j+1)/j;
            fomer=x;
            printf("%-4d",x);
        }
        printf("\n");
    }
    return 0;
}
