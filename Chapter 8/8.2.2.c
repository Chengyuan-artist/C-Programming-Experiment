//
// Created by 张承元 on 2020/6/7.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main(int argc,char* argv[])
{
    char str[1024];
    FILE *fp;
    if(argc<2||argc>4)
    {
        printf("Arguments error!\n");
        exit(-1);
    }
    if((fp=fopen(argv[1],"r"))==NULL)
    {
        printf("Can't open %s file!\n",argv[1]);
        exit(-2);
    }
    int cmd=0;
    if(argc==3)
    {
        if(strcmp(argv[2],"/p")==0)cmd=1;
        else {printf("Arguments error!\n");exit(-1);}
    }
    int cnt=0;
    while((fgets(str,1024,fp))!=NULL)
    {
        cnt++;
        printf("%d ",cnt);
        printf("%s",str);
        if(cmd&&cnt==25)
        {
            system("pause");
            cnt=0;
        }
    }
    fclose(fp);
    return 0;
}
