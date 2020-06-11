//
// Created by 张承元 on 2020/6/7.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main(int argc,char* argv[])
{
    FILE *fp;
    if(argc!=4)
    {
        printf("Arguments error!\n");
        exit(-1);
    }
    if((fp=fopen(argv[1],"r"))==NULL)
    {
        printf("Can't open %s file!\n",argv[1]);
        exit(-2);
    }
    char word[20];
    int cnt=0;
    char txt[1000][20];
    int len=0;
    while((fscanf(fp,"%s",word))!=EOF)
    {
        if(strcmp(word,argv[2])==0)
        {
            sprintf(txt[len++],"%s ",argv[3]);
            cnt++;
        } else
        {
            sprintf(txt[len++],"%s ",word);
        }
    }
    fclose(fp);

    fp=fopen(argv[1],"w");
    for(int i=0;i<len;++i)
    {
        fprintf(fp,"%s",txt[i]);
    }
    printf("%d",cnt);
    return 0;
}

