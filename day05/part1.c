#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    unsigned long long min;
    unsigned long long max;
} range;

int check(range ranges[190], unsigned long long nbr)
{
    for (int i = 0; i < 190; i++)
    {
        if (nbr >= ranges[i].min && nbr <= ranges[i].max)
            return 1;
    }
    return 0;
}

void read_ranges(range out[190], FILE *fptr)
{
    char buff[200];
    int i = 0;
    while (fgets(buff, 200, fptr) && buff[0] != '\n')
    {
        out[i].min = strtoull(buff, NULL, 10);
        out[i].max = strtoull(strchr(buff, '-') + 1, NULL, 10);
        i++;
    }
}

int main(void)
{
    FILE *fptr = fopen("input.txt", "r");
    char buff[200];
    range ranges[190];
    int result = 0;

    read_ranges(ranges, fptr);
    
    while (fgets(buff, 200, fptr))
    {
            result += check(ranges, strtoull(buff, NULL, 10));
    }
    printf("result: %d\n", result);
    fclose(fptr);
}