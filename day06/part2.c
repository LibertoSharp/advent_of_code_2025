#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define IS_DIGIT(x) (x >= '0' && x <= '9')
#define CTOULL(x) IS_DIGIT(x) * (x - 48)

void read_file(char buff[][4000], FILE *fptr) { for (size_t i = 0; fgets(buff[i],4000,fptr); i++); }

unsigned long long read_col(char buff[][4000], size_t index) 
{
    unsigned long long col = 0;
    for (size_t i = 0; i < 4; i++)
    {
        if (buff[i][index] != ' ')
            col = col * 10 + CTOULL(buff[i][index]);
    }
    
    return col;
}

int main(void)
{
    FILE *fptr = fopen("input.txt", "r");
    char buff[5][4000];
    unsigned long long result = 0;
    unsigned long long value = 0;
    size_t i = 0;
    char op;
    read_file(buff, fptr);

    while (buff[4][i] != '\n')
    {
        unsigned long long col = read_col(buff,i);
        if (col == 0)
            result += value;
        if (buff[4][i] == '+' || buff[4][i] == '*')
        {
            op = buff[4][i];
            value = op == '*';
        }
        if (op == '+') value += col;
        if (op == '*') value *= col;
        i++;
    }
    result += value;

    printf("result: %llu\n", result);
}