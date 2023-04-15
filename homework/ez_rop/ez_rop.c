//gcc -o ez_rop ez_rop.c -mpreferred-stack-boundary=4 -no-pie -fno-stack-protector
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void tool(){
    __asm__("pop %rdx;"
            "ret;");
    __asm__("pop %rcx;"
            "ret;");
    __asm__("pop %r8;"
            "ret;");
    return;
}

void init(){
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);
}

void input(unsigned int length) {
    char input[0x100];

    read(0, input, length);
}

int main()
{
    int length;

    init();
    
    printf("Input length??\n");
    scanf("%d", &length);

    input(length);
}