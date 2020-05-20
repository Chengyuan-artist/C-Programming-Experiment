#include <stdio.h>
#include <stdlib.h>

typedef struct bigint
{
    int data;
    struct bigint *next;
    struct bigint *last;
}BIG_INT;

typedef struct bignum
{
    struct bigint *head;
    struct bigint *tail;
}BIG_NUM;

BIG_NUM input();
void output(BIG_NUM x);
BIG_NUM add(BIG_NUM a,BIG_NUM b);

int main()
{
    BIG_NUM a=input();
    BIG_NUM b=input();
//    output(a);
//    putchar('\n');
//    output(b);
    BIG_NUM c=add(a,b);

    output(c);

    return 0;
}
BIG_NUM input()
{
    //链表以正常的书写方式存储
    BIG_INT *loc_head=NULL,*tail,*head,*loc_tail=NULL;

    char c;
    c=getchar();
    loc_head=(BIG_INT*)malloc(sizeof(BIG_INT));
    loc_head->data=c-'0';
    loc_head->last=NULL;

    head=loc_head;

    while((c=getchar())!='\n')//以换行符结束
    {
        tail=(BIG_INT*)malloc(sizeof(BIG_INT));
        tail->data=c-'0';
        tail->last=head;
        head->next=tail;
        head=tail;
    }
    head->next=NULL;

    loc_tail=head;

    BIG_NUM x;
    x.head=loc_head;
    x.tail=loc_tail;

    return x;
}

void output(BIG_NUM x)
{
    BIG_INT *tail=x.head;
    while(tail!=NULL)
    {
        printf("%d",tail->data);
        tail=tail->next;
    }
}

BIG_NUM add(BIG_NUM a,BIG_NUM b)
{
    BIG_INT *ap=a.tail,*bp=b.tail;
    int f1=1,f2=1;

    BIG_INT *loc_tail=NULL,*loc_head=NULL,*head,*tail;

    loc_tail=(BIG_INT*)malloc(sizeof(BIG_INT));
    loc_tail->data = ap->data + bp->data;

    ap=ap->last;bp=bp->last;
    if(ap==NULL)f1=0;
    if(bp==NULL)f2=0;

    loc_tail->next=NULL;
    tail=loc_tail;

    while(f1||f2)
    {
        head=(BIG_INT*)malloc(sizeof(BIG_INT));
        head->data=0;
        if(tail->data>=10)//进位操作
        {
            head->data++;
            tail->data-=10;
        }
        if(f1)head->data+=ap->data,ap=ap->last;
        if(f2)head->data+=bp->data,bp=bp->last;

        tail->last=head;
        head->next=tail;

        tail=head;

        if(ap==NULL)f1=0;
        if(bp==NULL)f2=0;
    }
    if(tail->data>=10)//对第一位做特判
    {
        head=(BIG_INT*)malloc(sizeof(BIG_INT));
        head->data=1;
        tail->data-=10;
        tail->last=head;
        head->next=tail;
        tail=head;
    }

    tail->last=NULL;
    loc_head=tail;

    BIG_NUM res;
    res.head=loc_head;
    res.tail=loc_tail;

    return res;
}
