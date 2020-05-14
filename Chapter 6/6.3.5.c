#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int flag=1;//ÅÅÐòÃüÁî£¬Ä¬ÈÏµÝÔö
int cmp(const void *a,const void *b)
{
    return flag?*(int *)a-*(int *)b:*(int *)b-*(int *)a;
}
int main(int arg,char *argv[])
{
    if(arg>3||arg<2){printf("command error!\n");exit(-1);}
    if(arg==3)
    {
        if(strcmp(argv[2],"-d")){printf("command error!\n");exit(-2);}
        flag=0;
    }
    int n=atoi(argv[1]);
    int *a=(int*)malloc(sizeof(int)*n);
    printf("please input %d integers:\n",n);
    for(int i=0;i<n;++i)scanf("%d",a+i);
    qsort(a,n,sizeof(a[0]),cmp);
    for(int i=0;i<n;++i)printf("%d ",*(a+i));
    return 0;
}
