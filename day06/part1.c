#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IS_DIGIT(x) (x >= '0' && x <= '9')

char *find_n(char *buff, size_t iteration)
{
    size_t i = 0;
    size_t n_count = 0;
    while (buff[i])
    {
        if ((IS_DIGIT(buff[i]) || buff[i] == '+' || buff[i] == '*') && (i == 0 || buff[i-1] == ' '))
            n_count++;
        if (n_count == iteration+1)
            return buff+i;
        i++;
    }
    return NULL;
}

long long evaluate(unsigned int index, FILE *fptr)
{
    char buff[4000];
    long long nbrs[4];
    char op;
    long start_pos = ftell(fptr);

    for (size_t i = 0; i < 4; i++)
    {
        fgets(buff, 4000, fptr);
        char *n = find_n(buff, index);
        if (n == NULL) return 0;
        nbrs[i] = strtoll(n, NULL, 10);        
    }
    fgets(buff, 4000, fptr);
    op = *find_n(buff, index);
    fseek(fptr, start_pos, SEEK_SET);

    if (op == '+') return nbrs[0] + nbrs[1] + nbrs[2] + nbrs[3];
    if (op == '*') return nbrs[0] * nbrs[1] * nbrs[2] * nbrs[3];
    return 0;
}

int main(void)
{
    FILE *fptr = fopen("input.txt", "r");
    long long result = 0;
    size_t i = 0;
    long long e;
    while (e = evaluate(i, fptr))
    {
        result += e;
        i++;
    }

    printf("result: %llu\n", result);
}