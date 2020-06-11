//
// Created by 张承元 on 2020/6/7.
//
#include <stdio.h>
#include <stdlib.h>
#define IN 1
#define OUT 0

void construt_matrix(int ***p,int n,int m);
void put_matrix(int **p,int n,int m,int cmd);
void destroy_matrix(int ***p,int n,int m);
void revolve_matrix(int ***p,int n,int m);

FILE *fin;
FILE *fout;
int main()
{
    fin=fopen("matrix.in","r");
    fout=fopen("matrix.out","w");
    int **mtx;
    int n,m;
    fscanf(fin,"%d%d",&n,&m);

    construt_matrix(&mtx,n,m);

    put_matrix(mtx,n,m,IN);

    revolve_matrix(&mtx,n,m);

    put_matrix(mtx,m,n,OUT);

    destroy_matrix(&mtx,n,m);
    return 0;
}
void construt_matrix(int ***p,int n,int m)
{
    (*p) =(int **)malloc(sizeof(int *)*n);
    for(int i=0;i<n;++i)
    {
        (*p)[i]=(int *)malloc(sizeof(int)*m);
    }
}
void put_matrix(int **p,int n,int m,int cmd)
{
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
            cmd?fscanf(fin,"%d",&p[i][j]):fprintf(fout,"%d ",p[i][j]);
        cmd? :fprintf(fout,"\n");
    }
}
void destroy_matrix(int ***p,int n,int m)
{
    for(int i=0;i<n;++i)
    {
        free((*p)[i]);
    }
    free(*p);
}
void revolve_matrix(int ***p,int n,int m)
{
    int **np;
    construt_matrix(&np,m,n);
    for(int j=0;j<m;++j)
    {
        for(int i=n-1;i>=0;--i)
        {
            np[j][i]=(*p)[i][j];
        }
    }
    destroy_matrix(p,n,m);
    (*p)=np;
}

