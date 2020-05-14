#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *find_longest(char str[][50],int n,int *plen);
int main()
{
    int len=0;
    char a[8][50]={"Husters","cat","dog","balabala"};
    char *longest=find_longest(a,4,&len);
    printf("%d\n%s\n",4,longest);
    return 0;
}

char *find_longest(char str[][50],int n,int *plen)
{
    char *res;
    int max=0;
    for(int i=0;i<n;++i)
    {
        if(strlen(str[i])>max)
        {
            max=strlen(str[i]);
            res=str[i];
        }
    }
    *plen=max;
    return res;
}
