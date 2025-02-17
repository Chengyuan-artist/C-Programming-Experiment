#include <stdio.h>

void strcate(char[], char[]);
void strdelc(char[], char);

int main(void)
{
    char a[] = "Language", b[] = "Programming";
    printf("%s  %s\n", b, a);
    strcate(b, a);
    printf("%s  %s\n", b, a);
    strdelc(b, 'a');
    printf("%s\n", b);
    return 0;
}

void strcate(char t[], char s[])
{
    int i = 0, j = 0;
    while (t[i++]);
    //i落在了空字符后面
    --i;
    while ((t[i++] = s[j++]) != '\0');
}

void strdelc(char s[], char c)
{
    int j, k;
    for (j = k = 0; s[j] != '\0'; j++)
    {
        if (s[j] != c)
        {
            s[k++] = s[j];
        }
    }
    //应当给结果串补充字符串结束符
    s[k] = '\0';
}
