#include <stdio.h>

int stack[20];//����ջ���ڴ����ڵݹ�����д�����������������������
int cnt=0;//��ʼջΪ��
int flag;

void spilt(int n,int k);
int min(int a,int b){return a<b?a:b;}
int main()
{
    int n;
    scanf("%d",&n);
    flag=n;
    spilt(n,n);
    return 0;
}

void spilt(int n,int k)
{
   if(n==0)
   {
       for(int i=0;i<cnt-1;++i)
        printf("%d+",stack[i]);
       printf("%d",stack[cnt-1]);
       if(cnt==1+flag-stack[0])printf("\n");//���������ʽ
       else printf(", ");
       return;
   }
   for(int i=min(k,n);i>=1;--i)
   {
       stack[cnt++]=i;
       spilt(n-i,i);
       cnt--;
   }
}

