// gcc aar.c -o aar -no-pie
#include <stdio.h>
#include <stdlib.h>

int token = 0xdeadbeef;

void init(){
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);
}

int main() {
    char fmt[0x50];

    init();

    printf("fmt : ");
    scanf("%80[^\n]", fmt);
    printf(fmt);

    if (token == 1234)
        system("/bin/sh");
    else
        puts("wrong token :(");

    return 0;
}
