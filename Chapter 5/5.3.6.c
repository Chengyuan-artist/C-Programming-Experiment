#include <stdio.h>
#define MAX 20
int chess[MAX][MAX];
int del[MAX][MAX];

void same_delete(int n,int m);
void input(int n,int m);
void output(int n,int m);

int main()
{
    int m,n;
    printf("Please input the number of lines and columns:\n");
    scanf("%d%d",&n,&m);
    printf("Please input the chess:\n");
    input(n,m);
    printf("\n\n\nThe result is:\n");
    same_delete(n,m);
    output(n,m);
    return 0;
}

void same_delete(int n,int m)
{
    int i,j;
    //对每一行
    for(i=0;i<n;++i)
    {
        for(j=1;j<m-1;++j)
        {
            if(chess[i][j]==chess[i][j-1]&&chess[i][j]==chess[i][j+1])
            {
                del[i][j]=del[i][j-1]=del[i][j+1]=1;
            }
        }
    }
    for(j=0;j<m;++j)
    {
        for(i=1;i<n-1;++i)
        {
            if(chess[i][j]==chess[i-1][j]&&chess[i][j]==chess[i+1][j])
            {
                del[i][j]=del[i-1][j]=del[i+1][j]=1;
            }
        }
    }
}

void input(int n,int m)
{
    int i, j;
    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < m; ++j)
        {
            scanf("%d", &chess[i][j]);
        }
    }
}

void output(int n,int m)
{
    int i, j;
    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < m; ++j)
        {
            if(del[i][j])printf("0 ");
            else printf("%d ",chess[i][j]);
        }
        putchar('\n');
    }
}
