//gcc -o note note.c -mpreferred-stack-boundary=4 -no-pie -fno-stack-protector
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <termios.h>

void init(){
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);
}

void input_note(char **note)
{
    int idx;

    printf("idx : ");
    scanf("%d", &idx);
    while(getchar() != '\n');

    printf("input : ");
    read(0, (char *)(note + idx), 8);

    while(getchar() != '\n');
}

void print_note(char **note)
{
    int idx;

    printf("idx : ");
    scanf("%d", &idx);

    printf("data : ");
    printf("%s\n", (char *)(note + idx));
}
    

void print_menu()
{
    printf("==================\n");
    printf("= [1] write note =\n");
    printf("= [2] print note =\n");
    printf("= [3] exit       =\n");
    printf("==================\n> ");
}

int main()
{
    char note[100][8] = {0, };
    char name[20];
    long long menu;

    init();

    printf("Welcome to my note program!!\n");
    printf("What is your name??\n> ");
    scanf("%20s",name);

    while(1)
    {
        print_menu();
        scanf("%lld", &menu);
        switch(menu)
        {
            case 1:
                input_note(note);
                continue;
            case 2:
                print_note(note);
                continue;
            case 3:
                printf("bye ~~~~\n");
                return 0;
            default:
                printf("Invalid input\n");
                continue;
        }
    }
}