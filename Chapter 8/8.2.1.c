//
// Created by 张承元 on 2020/6/7.
//
#include <stdlib.h>
#include <stdio.h>
int main(int argc,char* argv[])
{
    char ch;
    FILE *fp;
    if(argc!=2)
    {
        printf("Arguments error!\n");
        exit(-1);
    }
    if((fp=fopen(argv[1],"r"))==NULL)
    {
        printf("Can't open %s file!\n",argv[1]);
        exit(-1);
    }
    while((ch=fgetc(fp))!=EOF)
        putchar(ch);
    fclose(fp);
    return 0;
}
