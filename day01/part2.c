#include <stdio.h>
#include <stdlib.h>

int mod(int a)
{
    while (a > 99)
        a-=100;
    while (a < 0)
        a+=100;
    return a;
}

int main(void)
{
    FILE *fptr = fopen("input.txt", "r");
    char cmb[10];
    int value = 50;
    int password = 0;

    while (fgets(cmb, 10, fptr)) {
        int old = value;
        value += atoi(cmb + 1) * (cmb[0] - 79) / 3;
        password += abs(value) / 100 + (value < 0 && old) + !value;
        value = mod(value);
    }
    printf("%d\n", password);
}