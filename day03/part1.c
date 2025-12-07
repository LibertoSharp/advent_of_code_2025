#include <stdio.h>
#include <stdlib.h>

char * get_max(char *s, int n)
{
    char *max = s;
    int i = 0;
    while (s[i] && i < n)
    {
        if (s[i] > *max) max = s+i;
        i++;
    }
    return max;
}

int main(void)
{
    FILE *fptr = fopen("input.txt", "r");
    char buff[100];
    int result = 0; 
    while (fgets(buff, 102, fptr))
    {
        char *max_chr = get_max(buff, 99);
        int first_digit = *max_chr - 48;
        *max_chr = 48;
        max_chr = get_max(max_chr, 100);
        int second_digit = *max_chr - 48;
        result += first_digit * 10 + second_digit;
    }
    printf("result: %d\n", result);
    fclose(fptr);
}