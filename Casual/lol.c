#include<stdio.h>
#include<stdlib.h>

void _start()
{
    int ret = Main();
    exit(ret);
}

int Main()
{
    puts("This is a program without main!\n");
    return 0;
}

