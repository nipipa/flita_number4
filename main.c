#include <stdio.h>
#include <stdlib.h>
#define ARR_MAX 1001

int take_vertex();
int matrix();
int find();

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
    int a, b = 0;
    puts("Write require vertex:");
    scanf("%d", &a);
    puts("------------------------");
    puts("Required edges:");
    for (b = 0; b <= ver; b++)
    {
        if (arr[a][b] == '1')
        {
            for (int i = 0; i < line; i++)
            {
                if (arr[i][b] == '1' && i != a)
                    printf("%d --> %d \n", a, i);
            }
        }
    }
    puts("------------------------");
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
