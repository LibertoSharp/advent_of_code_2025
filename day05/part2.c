#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Lazy code, again

#define MIN(a,b) (a < b) ? a : b
#define MAX(a,b) (a > b) ? a : b
typedef struct
{
    long long min;
    long long max;
} range;

int check_intersection(range *range1, range *range2)
{
    if (range2->min <= (range1->max+1) && range2->max >= (range1->min-1))
    {
        range1->min = MIN(range2->min, range1->min);
        range1->max = MAX(range2->max, range1->max);
        return 1;
    }
    return 0;
}

int merge_intersection(range ranges[190])
{
    int merged = 0;
    for (int i = 0; i < 190; i++)
    {
        for (int j = 0; j < 190; j++)
        {
            if ((ranges[i].min == 0 && ranges[i].max == 0) || (ranges[j].min == 0 && ranges[j].max == 0) || i == j) continue;
            if (check_intersection(&ranges[i], &ranges[j]))
            {
                ranges[j].min = 0;
                ranges[j].max = 0;
                merged = 1;
            }
        }
    }
    return merged;
}

void read_ranges(range out[190], FILE *fptr)
{
    char buff[200];
    int i = 0;
    for (; i < 190; i++)
    {
        out[i].min = 0;
        out[i].max = 0;
    }
    i = 0;
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
    unsigned long long result = 0;

    read_ranges(ranges, fptr);
    while (merge_intersection(ranges))
    {
    }
    for (int i = 0; i < 190; i++)
    {
        result += ranges[i].max - ranges[i].min;
        if (ranges[i].max != 0 && ranges[i].min != 0)
            result++;
    }
    printf("result: %llu\n", result);
}