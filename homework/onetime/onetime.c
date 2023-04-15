// gcc onetime.c -o onetime -no-pie -fno-stack-protector
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void init(){
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);
}

int check = 0;

int main()
{
    char buf[0x100];
    
    init();

    if (check == 1)
        exit(0);

    printf("I'll give you one FSB & one BOF ^-^\n");
    read(0, buf, 0x100);
    printf(buf);

    read(0, buf, 0x128);
    
    check = 1;

    return 0;
}