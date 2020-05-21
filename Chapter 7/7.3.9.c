#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    double data;
    struct stack *next;
}NODE;

NODE *stack=NULL;
void pushback(double x);
double pop();
double revPolish();

int main()
{
    double res=revPolish();
    printf("%f\n",res);
    return 0;
}
void pushback(double x)
{
    NODE *nd=(NODE*)malloc(sizeof(NODE));
    nd->data=x;
    nd->next=stack;
    stack=nd;
}
double pop()
{
    double x=stack->data;
    NODE *nd=stack->next;
    free(stack);
    stack=nd;

//    printf("%f\n",x);

    return x;
}
double revPolish()
{
    char c;
    double x;
    int isnum=0;

    while((c=getchar())!='\n')
    {
        isnum=0;
        if(c==' ')continue;
        if(c>='1'&&c<='9')
        {
            ungetc(c,stdin);
            scanf("%lf",&x);
            isnum=1;
        }
        if(isnum)
        {
            pushback(x);
        }
        else
        {
            double a,b;
            b=pop();
            a=pop();
            switch(c)
            {
            case '+':pushback(a+b);break;
            case '-':pushback(a-b);break;
            case '*':pushback(a*b);break;
            case '/':pushback(a/b);break;
            }
        }
    }

    return pop();
}
