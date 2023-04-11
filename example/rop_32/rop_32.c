//gcc -o rop_32 rop_32.c -m32 -mpreferred-stack-boundary=2 -fno-pic -no-pie -fno-stack-protector
#include <stdlib.h>
#include <stdio.h>

void init(){
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);
}

int main() 
{
    char buf[100];

    init();

    read(0, buf, 256);
    write(1, buf, 5);

    return 0;
}