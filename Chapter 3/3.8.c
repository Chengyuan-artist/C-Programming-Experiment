#include <stdio.h>
#include <stdlib.h>

int main()
{
    double cnt=0;
    for(int i=0;i<16;++i)
    {
        double x=1000,y=2000;
        int m=i;
        for(int k=0;k<4;++k)
        {
            //0´ú±íÒÒÊ¤
            if(m&1)
            {
                x+=y*0.25;
                y*=0.75;
            }
            else
            {
                y+=x*0.25;
                x*=0.75;
            }
            m=m>>1;
        }
        if(abs(y-x)<1000)cnt++;
    }
    double pro=cnt/16;
    printf("%f\n",pro);
    return 0;
}
