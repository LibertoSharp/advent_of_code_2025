#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char get(char buff[3][200], int y, int x)
{
    if (y < 0 || y > 2) return '.';
    if (x < 0 || x > 199) return '.';
    return buff[y][x];
}

int count(char buff[3][200], int pos)
{
    int count = 0;
    for (int x = -1; x <= 1; x++)
    {
        for (int y = -1; y <= 1; y++)
        {
            if (y == 0 && x == 0) continue;
            if (get(buff, 1 + y, pos + x) == '@')
                count++;
        }
    }
    return count < 4;
}

int main(void)
{
    FILE *fptr = fopen("input.txt", "r");
    char buff[3][200];
    int result = 0;

    fgets(buff[1], 200, fptr);
    fgets(buff[2], 200, fptr);
    do
    {
        int i = 0;
        while(buff[1][i] != '\n')
        {
            if (buff[1][i] != '@')
            {
                i++;
                continue;
            }
            result += count(buff, i);
            i++;
        }
        memcpy(buff[0], buff[1], 200);
        memcpy(buff[1], buff[2], 200);
        if (!fgets(buff[2], 200, fptr)) memset(buff[2], '\n', 200);
    } while (buff[0][0] != '\n');
    printf("result: %d\n", result);
    fclose(fptr);
}