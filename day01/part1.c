#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *fptr = fopen("input.txt", "r");
    char cmb[10];
    int value = 50;
    int password = 0;

    while (fgets(cmb,10,fptr))
    {
        value += atoi(cmb + 1) * (cmb[0]-79)/3;
        if (!(value%=100)) password++;
    }
    printf("%d\n", password);
}