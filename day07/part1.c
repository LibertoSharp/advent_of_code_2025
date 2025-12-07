#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    FILE *fptr = fopen("input.txt", "r");
    char buff[144][144];
    long long result = 0;

    for (size_t i = 1; fgets(buff[i],144,fptr); i++)
    {
        for (size_t j = 0; buff[i][j] != '\n'; j++)
        {
            if ((buff[i-1][j] == 'S' || buff[i-1][j] == '|') && buff[i][j] == '.')
                buff[i][j] = '|';
            if (buff[i][j] == '^' && buff[i-1][j] == '|')
            {
                buff[i][j-1] = '|';
                buff[i][j+1] = '|';
                result++;
            }
        }
        
    }
    
    printf("result: %llu\n", result);
    fclose(fptr);
}