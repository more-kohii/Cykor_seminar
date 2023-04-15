//gcc -o helpme helpme.c -mpreferred-stack-boundary=4 -no-pie -fno-stack-protector
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int check = 0;
int check2 = 0;

void init(){
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);
}

void vuln()
{
    char buf[0x50];

    if (check == 1 && check2 == 1)
        exit(0);

    init();

    printf("Please Enter the input\n");
    read(0, buf, 0x60);
    printf("your input is %s\n", buf);

    if (check == 0)
        check = 1;
    else if (check == 1 && check2 == 0)
        check2 = 1;
}

int main()
{
    init();

    char name[20];
    printf("My teacher said to me that it's ez to solve.\n");
    printf("But i can't solve,,,, Can you help me????\n");
    printf("And there is some memo for this challenge!\n");
    printf("Memo: What is stack frame???? Is that connected???\n\n");
    printf("However what's your name?\n");
    scanf("%10s", name);
    printf("Thx for helping me %s\n\n", name);
    vuln();
    printf("Ooops, i called vuln() twice. It's my mistake.. XD\n");
    vuln();
}