#include <stdio.h>
#include <stdlib.h>
#define IN 1
#define OUT 0

void construt_matrix(int ***p,int n,int m);
void put_matrix(int **p,int n,int m,int cmd);
void destroy_matrix(int ***p,int n,int m);
void revolve_matrix(int ***p,int n,int m);

int main()
{
    int **mtx;
    int n,m;
    printf("please input n&m:\n");
    scanf("%d%d",&n,&m);

    construt_matrix(&mtx,n,m);

    printf("please input the matrix:\n");
    put_matrix(mtx,n,m,IN);

    revolve_matrix(&mtx,n,m);

    printf("\n\nthe matrix after revolving:\n");
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
            cmd?scanf("%d",&p[i][j]):printf("%d ",p[i][j]);
        cmd? :putchar('\n');
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
