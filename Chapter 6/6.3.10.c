#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)

void reve(char *a);
void swp(char *a,char *b){char c=*a;*a=*b;*b=c;}

void bigadd(char *a,char *b);
void bigmtp(char *a,char *b);

int main()
{
    char *x=(char *)malloc(sizeof(char)*(500));
    char *y=(char *)malloc(sizeof(char)*(202));

    printf("请输入两个200位以内的非负整数：");
    scanf("%s%s",x,y);
    bigmtp(x,y);

    printf("乘积为：");
    printf("%s\n",x);
    free(x);
    free(y);
    return 0;
}

void reve(char *a)
{
    int beg=0,end=strlen(a)-1;
    while(beg<end)
    {
        swp(a+beg,a+end);
        beg++;
        end--;
    }
}

void bigadd(char *a,char *b)
{
    //a+=b 结果保存在a中
    /*
    reve(a);
    reve(b);
    */

    int alen=strlen(a);
    int blen=strlen(b);

    char *oa,*ob;
    if(alen>blen)oa=a,ob=b;
    else oa=b,ob=a;

    int len=max(alen,blen);
    int cnt=min(alen,blen);

    char *res=(char *)malloc(sizeof(char)*(len+2));
    memset(res,'0',sizeof(char)*(len+2));

    for(int i=0;i<len;++i)
    {
        res[i]+=oa[i]-'0';
        if(i<cnt)res[i]+=ob[i]-'0';
        if(res[i]>'9')
        {
            res[i+1]++;
            res[i]-=10;
        }
    }
    if(res[len]!='0')res[++len]='\0';
    else res[len]='\0';

    strcpy(a,res);

    /*
    reve(a);
    reve(b);
    */
}

void bigmtp(char *a,char *b)
{
    reve(a);
    reve(b);

    int alen=strlen(a);
    int blen=strlen(b);

    /*
            b
        X   a
        ________

        =
    */
    char *sum=(char *)malloc(sizeof(char)*(alen+blen+1));
    char *tmp=(char *)malloc(sizeof(char)*(alen+blen+1));
    memset(sum,'0',sizeof(char)*(alen+blen+1));
    memset(tmp,0,sizeof(char)*(alen+blen+1));

    sum[1]='\0';

    for(int i=0;i<alen;++i)
    {
        if(a[i]=='0')continue;
        //初始化
        memset(tmp,'0',sizeof(char)*(alen+blen+1));

        for(int j=0;j<blen;++j)
        {
            tmp[j+i]-='0';
            tmp[j+i]+=(a[i]-'0')*(b[j]-'0');

            //进位
            tmp[j+i+1]+=(tmp[j+i])/10;
            tmp[j+i]=(tmp[j+i])%10+'0';

        }
        int len=blen+i;
        while(tmp[len]=='0')--len;
        tmp[len+1]='\0';

        //printf("%s\n",tmp);

        bigadd(sum,tmp);

    }

    strcpy(a,sum);
    free(sum);
    free(tmp);

    reve(a);
    reve(b);
}
