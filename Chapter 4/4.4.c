#include <stdio.h>
#include <math.h>

#define getS(a,b,c) ((a+b+c)/2)
#define getArea(a,b,c) sqrt(getS(a,b,c)*(getS(a,b,c)-a)*(getS(a,b,c)-b)*(getS(a,b,c)-c))

int main()
{
    double x,y,z;
    while(scanf("%lf%lf%lf",&x,&y,&z)!=EOF)
        printf("%f\n",getArea(x,y,z));
    return 0;
}
