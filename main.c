#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ARR_MAX 1001

int take_vertex();
int matrix();
int find();

void time_start() { 
    mingw_gettimeofday(&tv1, &tz); 
    }

long time_stop()
{
    mingw_gettimeofday(&tv2, &tz);
    dtv.tv_sec = tv2.tv_sec - tv1.tv_sec;
    dtv.tv_usec = tv2.tv_usec - tv1.tv_usec;
    if (dtv.tv_usec < 0)
    {
        dtv.tv_sec--;
        dtv.tv_usec += 1000000;
    }
    return dtv.tv_sec * 1000 + dtv.tv_usec / 1000;
}

int main()
{
    FILE *file = fopen("matrix.txt", "r");
    char arr[ARR_MAX][ARR_MAX], s;
    int line = 1, ver = 0, reb = 0, max_len = 0;
    while (!feof(file))
    {
        fscanf(file, "%c", &s);
        if (s != ' ' && s != '\n' && s != '\0')
        {
            arr[line][ver] = s;
            ver++;
        }
        else if (s == '\n')
        {
            line++;
            max_len = ver;
            ver = 0;
        }
    }
    arr[line][max_len] = '\0';
    fclose(file);
    take_vertex(arr, line, ver);
}

int find(char arr[ARR_MAX][ARR_MAX], int line, int ver)
{
    int v, a = 0, b = 0, num = 0, kol = 0;
    int vertex[ARR_MAX];
    puts("Write require grade of vertex:");
    scanf("%d", &v);    
    time_start();
    puts("------------------------");
    puts("Required edges:");
    puts("***************");
    for (a = 0; a <= line; a++)
    {
        for (b = 0; b <= ver; b++)
        {
            if (arr[a][b] == '1' )
            {
                for (int i = 0; i <= line; i++)
                {
                    if (arr[i][b] == '1' && i != a)
                        num++;
                }
            }
        }
        vertex[a] = num;
        num = 0;
    }
    for (int i = 0; i <= line; i++)
    {
        if (vertex[i] == v)
        {
            printf("Vertex %d || grade %d \n", i, vertex[i]);
            puts("***************");
            for (b = 0; b <= ver; b++)
            {
                if (arr[i][b] == '1')
                {
                    for (int k = 0; k <= line; k++)
                    {
                        if (arr[k][b] == '1' && k != i)
                            printf("%d --> %d \n", i, k);
                    }
                }
            }
            puts("***************");
        }
    }
    puts("------------------------");
    printf("Time of finding: %ld mc\n", time_stop());
    take_vertex(arr, line, ver);
    return 0;
}

int take_vertex(char arr[ARR_MAX][ARR_MAX], int line, int ver)
{
    int vertex = 0, j = 0;
    printf("Select motion:\n");
    printf("0 - exit\n");
    printf("1 - enter the required vertex and find edges\n");
    scanf("%d", &j);
    switch (j)
    {
    case 1:
        find(arr, line, ver);
        break;
    case 0:
        exit(0);
        break;
    }
    return 0;
}
