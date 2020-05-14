#include <stdio.h>
#include <stdlib.h>

char *strcopy(char *, const char *);

int main()
{
    char *s1, *s2, *s3;
    //指针没有指向有效的内存
    s1 = malloc(100 * sizeof(char));
    s2 = malloc(100 * sizeof(char));

    printf("Input a string:\n");
     //参数s2是多余的
    scanf("%s", s2);
    strcopy(s1, s2);
    printf("%s\n", s1);
    printf("Input a string again:\n");
    //参数s2 是多余的
    scanf("%s", s2);
    s3 = strcopy(s1, s2);
    printf("%s\n", s3);
    return 0;
}

char *strcopy(char *t, const char *s)
{
    char *res = t;
    while (*t++ = *s++);
    // 应当返回串t的首地址，但此时t已指向了结尾
    return res;
}
