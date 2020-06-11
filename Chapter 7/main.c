#include <stdio.h>
#include <stdlib.h>

#define LSIZE sizeof(List)

typedef struct student
{
    long long id;
    char* name;
    int english;
    int calculus;
    int physics;
    int CLanguage;
    int total;
    double average;
}Student;

typedef struct list
{
    struct student data;
    struct List *next;
}List;

List* input();
void output(const List *head);
int alter(List *head);
void workAverage(List *head);
void outputAverage(const List *head);
int menu();

int main()
{
    setbuf(stdout, NULL);
    int cmd;
    struct List *list = NULL;
    while ((cmd = menu()))
    {
        switch (cmd)
        {
            case 1:
                list = input();
                workAverage(list);
                break;

            case 2:
                output(list);
                break;

            case 3:
                while (!alter(list));
                workAverage(list);
                break;

            case 4:
                outputAverage(list);
                break;
        }
    }
    return 0;
}

List* input()
{
    system("cls");
    int n;
    puts("Please input the number of students.");
    scanf("%d", &n);
    List *head, *current;
    head = current = malloc(LSIZE);
    for (int i = 0; i < n; ++i)
    {
        printf("Please input id and name: ");
        current->data.name = malloc(20 * sizeof(char));
        scanf("%lld %s", &current->data.id, current->data.name);
        printf("Please input scores in order of English, Calculus, Physics, C Programming Language:");
        scanf("%d %d %d %d", &current->data.english, &current->data.calculus,
              &current->data.physics, &current->data.CLanguage);
        if (i != n - 1)
        {
            current->next = malloc(LSIZE);
            current = current->next;
        }
        else
        {
            current->next = NULL;
        }
    }
    return head;
}

void output(const List *head)
{
    system("cls");
    while (head != NULL)
    {
        printf("#%lld\t%s\n", head->data.id, head->data.name);
        printf("English:\t%d\nCalculus:\t%d\nPhysics:\t%d\nC Programming Language:\t%d\n", head->data.english,
               head->data.calculus, head->data.physics, head->data.CLanguage);
        putchar('\n');
        head = head->next;
    }
    system("pause");
}

int alter(List *head)
{
    system("cls");
    int success = 0;
    puts("Please input the ID");
    long long id;
    scanf("%lld", &id);
    while (head != NULL)
    {
        if (head->data.id == id)
        {
            success = 1;
            break;
        }
        head = head->next;
    }
    if (success)
    {
        puts("What do you want to alter?");
        puts("1.ID\n2.Name\n3.English\n4.Calculus\n5.Physics\n6.C Programming Language");
        int cmd;
        scanf("%d", &cmd);
        switch (cmd)
        {
        case 1:
            puts("Please enter the new ID");
            scanf("%lld", &head->data.id);
            break;
        case 2:
            puts("Please enter the new NAME");
            scanf("%s", head->data.name);
            break;

        case 3:
            puts("Please enter the new English score");
            scanf("%d", &head->data.english);
            break;
        case 4:
            puts("Please enter the new Calculus score");
            scanf("%d", &head->data.calculus);
            break;
        case 5:
            puts("Please enter the new Physics score");
            scanf("%d", &head->data.physics);
            break;
        case 6:
            puts("Please enter the new C Programming Language score");
            scanf("%d", &head->data.CLanguage);
            break;
        }
        return 1;
    }
    else
    {
        puts("ID not found!");
        system("pause");
        return 0;
    }
}

void workAverage(List *head)
{
    while (head != NULL)
    {
        head->data.total = head->data.english + head->data.calculus + head->data.physics + head->data.CLanguage;
        head->data.average = head->data.total / 4.0;
        head = head->next;
    }
}

void outputAverage(const List *head)
{
    system("cls");
    while (head != NULL)
    {
        printf("#%lld\t%s\n", head->data.id, head->data.name);
        printf("Total Score:\t%d\nAverage Score:\t%.2lf\n", head->data.total, head->data.average);
        putchar('\n');
        head = head->next;
    }
    system("pause");
}

int menu()
{
    system("cls");
    puts("MENU");
    puts("0.Quit\n1.Input\n2.List\n3.Modify\n4.Show total and average scores.\n");
    int cmd;
    do
    {
        scanf("%d", &cmd);
    } while (cmd < 0 || cmd > 4);
    return cmd;
}
