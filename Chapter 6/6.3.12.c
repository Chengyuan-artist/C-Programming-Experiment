#include <stdio.h>
#include <string.h>
#define N 8

void task0();
void task1();
void task2();
void task3();
void task4();
void task5();
void task6();
void task7();
void scheduler();
void execute(void (**p)(), int n);

int main()
{
    scheduler();
    return 0;
}

void task0()
{
    puts("task0 is called!");
}

void task1()
{
    puts("task1 is called!");
}

void task2()
{
    puts("task2 is called!");
}

void task3()
{
    puts("task3 is called!");
}

void task4()
{
    puts("task4 is called!");
}

void task5()
{
    puts("task5 is called!");
}

void task6()
{
    puts("task6 is called!");
}

void task7()
{
    puts("task7 is called!");
}

void scheduler()
{
    void (*a[N])();
    a[0] = task0;
    a[1] = task1;
    a[2] = task2;
    a[3] = task3;
    a[4] = task4;
    a[5] = task5;
    a[6] = task6;
    a[7] = task7;

    char cmd[100];
    scanf("%s",cmd);
    int len=strlen(cmd);

    void (*call[100])();

    for(int i=0;i<len;++i)
        call[i]=a[cmd[i]-'0'];
    execute(call, len);
}

void execute(void (**p)(), int n)
{
    for (int i = 0; i < n; ++i)
    {
        p[i]();
    }
}
