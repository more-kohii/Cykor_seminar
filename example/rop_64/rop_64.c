//gcc -o rop_64 rop_64.c -mpreferred-stack-boundary=4 -no-pie -fno-stack-protector
#include <stdio.h>

void init(){
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);
}

int main()
{
    char buf[100];
    
    init();

    puts("Time to do x64 ROP");
    gets(buf);

    return 0;
}
