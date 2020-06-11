//
// Created by 张承元 on 2020/6/7.
//
#include <stdio.h>
int main()
{
    printf("input 10 float:\n");
    float a;
    FILE *fp;
    fp=fopen("float,dat","w");
    for(int i=0;i<10;++i)
    {
        scanf("%f",&a);
        fwrite(&a,sizeof(float),1,fp);
    }
    fclose(fp);

    fp=fopen("float,dat","r");
    for(int i=0;i<10;++i)
    {
        fread(&a,sizeof(float),1,fp);
        printf("%f ",a);
    }
}
