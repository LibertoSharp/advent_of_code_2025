#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This is lazy. I'm writing this at 2 AM and I'm very tired, so I'll just leave it as is.

char get(char buff[137][137], int y, int x)
{
    if (y < 0 || y > 136) return '.';
    if (x < 0 || x > 136) return '.';
    return buff[y][x];
}

int count(char buff[137][137], int line, int pos)
{
    int count = 0;
    for (int x = -1; x <= 1; x++)
    {
        for (int y = -1; y <= 1; y++)
        {
            if (y == 0 && x == 0) continue;
            if (get(buff, line + y, pos + x) == '@')
                count++;
        }
    }
    return count < 4;
}

void read_file(char buff[137][137], FILE *fptr)
{
    int i = 0;
    while(fgets(buff[i],139,fptr))
        i++;
}

int part1(char buff[137][137])
{
    int result = 0;
    int line = 0;
    do
    {
        int i = 0;
        while (i < 137)
        {
            if (buff[line][i] == '@' && count(buff, line, i))
            {
                result++;
                buff[line][i] = '.';
            }
            i++;
        }
        line++;
    } while (line < 137);
    return result;
}

int main()
{
    FILE *fptr = fopen("input.txt", "r");
    char buff[137][137];
    int result = 0;
    int old_result = 0;

    read_file(buff, fptr);
    do
    {
        old_result = result;
        result += part1(buff);
    } while (old_result != result);
    printf("result: %d\n", result);
    fclose(fptr);
}