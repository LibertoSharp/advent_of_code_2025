#include <stdio.h>
#include <stdlib.h>

char * get_max(char *s)
{
    char *max = s;
    int i = 0;
    while (s[i])
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
    unsigned long long result = 0; 
    while (fgets(buff, 102, fptr))
    {
        unsigned long long battery = 0;
        char *max_chr = buff;
        for (int i = 0; i < 12; i++)
        {
            char saved = buff[89+i];
            buff[89+i] = 0;
            max_chr = get_max(max_chr);
            buff[89+i] = saved;
            battery = battery * 10 + (*max_chr - 48);
            *max_chr = 48;
        }
        result += battery;
    }
    printf("result: %lld\n", result);
    fclose(fptr);
}