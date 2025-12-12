#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DST_SQRD(a, b) ((long long)(a.x-b.x)*(a.x-b.x) + \
                        (long long)(a.y-b.y)*(a.y-b.y) + \
                        (long long)(a.z-b.z)*(a.z-b.z))


typedef struct s_point {
    int x;
    int y;
    int z;
} point;

point points[1000] = {0};
unsigned int roots[1000];
unsigned int size[1000];
unsigned char adjacenct_matrix[1000][1000] = {0};

void read_points()
{
    FILE *fptr = fopen("input.txt", "r");
    char buff[100];
    for (size_t i = 0; fgets(buff,100,fptr); i++)
    {
        points[i].x = atoi(buff);
        points[i].y = atoi(strchr(buff, ',')+1);
        points[i].z = atoi(strrchr(buff, ',')+1);
    }
    fclose(fptr);
}

void initialize_roots(size_t count)
{
    for (size_t i = 0; i < count; i++)
    {
        roots[i] = i;
        size[i] = 1;
    }
}

unsigned int find(unsigned int a)
{
    if (roots[a] != a)
        roots[a] = find(roots[a]);
    return roots[a];
}

unsigned long long max3(unsigned a[1000]){
    unsigned m1=0,m2=0,m3=0;
    for(int i=0;i<1000;i++){
        if(a[i]>m1){ m3=m2; m2=m1; m1=a[i]; }
        else if(a[i]>m2){ m3=m2; m2=a[i]; }
        else if(a[i]>m3) m3=a[i];
    }
    return (unsigned long long)m1*m2*m3;
}

int one_circuit(){
    int count = 0;
    for (size_t i = 0; i < 1000; i++)
    {
        if (size[i] != 0)
            count++;
        if (count > 1)
            return 0;
    }
    return 1;
}

unsigned long long connect_nearest(size_t count)
{
    unsigned long long min_dst = ULLONG_MAX; 
    size_t a_index, b_index;
    for (size_t from = 0; from < count; from++)
    {
        for (size_t to = 0; to < count; to++)
        {
            unsigned long long dst = DST_SQRD(points[from],points[to]); 
            if (dst < min_dst && from != to && !(adjacenct_matrix[from][to] || adjacenct_matrix[to][from]))
            {
                min_dst = dst;
                a_index = from;
                b_index = to;
            }
        }
    }

    unsigned int root_a = find(a_index);
    unsigned int root_b = find(b_index);
    adjacenct_matrix[a_index][b_index] = 1;
    adjacenct_matrix[b_index][a_index] = 1;
    if (root_a == root_b) return points[a_index].x * points[b_index].x;
    roots[root_b] = root_a;
    size[root_a] += size[root_b];
    size[root_b] = 0;
    return points[a_index].x * points[b_index].x;
}

int main(void)
{
    read_points();
    initialize_roots(1000);

    unsigned long long result;
    while(!one_circuit())
        result = connect_nearest(1000);
        
    printf("size: %u\n", max3(size));
    printf("result: %u\n", result);
}