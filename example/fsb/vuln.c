#include <stdio.h>

int main()
{
    char buf[100];
    scanf("%[^\n]s", buf);
    printf(buf);
}