#include <stdio.h>
int RemoveSame(int *p,int n);
int main()
{
    int a[11]={1,1,2,2,2,3,3,3,3,4};
    int n=RemoveSame(a,10);
    for(int *p=a;p<a+n;++p)printf("%d ",*p);
    return 0;
}
int RemoveSame(int *a,int n)
{
    int cnt=0;
    int *p=a+1,*s=a;
    while(p<a+n)
    {
        while(p<a+n&&*p==*(p-1))++p;
        *(s++)=*(p-1);
        cnt++;
        if(p==a+n-1&&*p!=*(p-1))
        {
            *(s++)=*p;
            cnt++;
        }
        p++;
    }
    return cnt;
}
