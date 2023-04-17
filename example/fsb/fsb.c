#include <stdio.h>

int main()
{
    long long int a, b, c;
    a = 1, b = 2, c = 3;

    printf("%p %p %p\n", a, b, c);
    printf("%p %p %p\n", a, b);
    printf("\n\n");
    //64bit 인자 전달 순서에 맞게 전달됨. rdi -> rsi -> rdx -> rcx -> r8 -> r9 -> stack
    printf("%p %p %p %p %p %p %p %p %p %p\n");
    printf("%x %x %x %x %x %x %x %x %x %x\n");
    printf("\n\n");
    printf("%2$lld %1$lld\n", a, b);
    printf("%6$p\n");
    printf("\n\n");
    printf("hello~~~%lln\n",&c);
    printf("c : %lld\n", c);
}   