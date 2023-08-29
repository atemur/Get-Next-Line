#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *str = malloc(10);
    str[0] = 'a';
    system("leaks a.out");
}