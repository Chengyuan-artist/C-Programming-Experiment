#include <stdio.h>


int main()
{
    char c;
    while((c=getchar())!=EOF)
    {
        while(c==' ')
        {
            if((c=getchar())!=' ')
                putchar(' ');
        }
        putchar(c);
    }
    return 0;
}
