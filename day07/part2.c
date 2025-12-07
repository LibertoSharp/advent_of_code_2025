#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void read_file(unsigned char buff[144][144], FILE *fptr) { for (size_t i = 0; fgets(buff[i],144,fptr); i++); }

unsigned long long backtrack(unsigned char buff[144][144], unsigned long long mem[144][144], size_t y, size_t x)
{
    while (buff[y][x] == '.')
        y++;
    if (buff[y][x] == '^')
    {
        if (!mem[y][x])
        mem[y][x] = backtrack(buff, mem, y + 1, x + 1) + backtrack(buff, mem, y + 1, x - 1);
        return mem[y][x];
    }
    
    return 1;
}

int main(void)
{
    FILE *fptr = fopen("input.txt", "r");
    unsigned char buff[144][144] = {0};
    unsigned long long mem[144][144] = {0};
    long long result = 0;

    read_file(buff,fptr);
    
    result += backtrack(buff, mem, 1, (unsigned char *)strchr(buff[0], 'S') - buff[0]);

    printf("result: %llu\n", result);
    fclose(fptr);
}