#include <stdio.h>

void init(){
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);
}

int main()
{
    char buf[100];
    
    init();

    gets(buf);
    puts(buf);

    return 0;   
}