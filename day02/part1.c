#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int is_valid(const char *s)
{
    size_t len = strlen(s);
    if (len % 2 != 0) return 1;
    size_t n = len / 2;
    size_t i = 0;
    while (i < n && s[i] == s[n+i])
        i++;
    
    if (i >= n)
        return 0;
    return 1;
}

unsigned long long get_invalid(const char *s)
{
    char buff[100];
    unsigned long long min = strtoull(s, NULL, 10);
    unsigned long long max = strtoull(strchr(s, '-') + 1, NULL, 10);
    unsigned long long actual = min;
    unsigned long long sum = 0;

    while(actual <= max)
    {
        sprintf(buff, "%llu", actual);
        if (!is_valid(buff))
            sum += actual;
        actual++;
    }
    return sum;
}

int pull_id(char *str, FILE *fptr)
{
    int i = 0;
    int c;

    while ((c = getc(fptr)) != ',' && c != EOF)
    {
        str[i++] = (char)c;
    }
    str[i] = '\0';

    if (c == EOF && i == 0) return 0;
    return 1;
}

int main(void)
{
    FILE *fptr = fopen("input.txt", "r");
    if (!fptr) return 1;
    
    char str[100];
    unsigned long long sum = 0;

    while (pull_id(str, fptr))
    {
        if (strlen(str) > 0)
            sum += get_invalid(str);
    }

    printf("result:%llu\n", sum);
    fclose(fptr);
}