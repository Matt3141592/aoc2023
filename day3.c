#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <time.h>

int toInt(char *grid, int y)
{
    while (grid[y] >= '0' && grid[y] <= '9')
        y--;
    y++;

    int ans = 0;
    while (grid[y] >= '0' && grid[y] <= '9')
    {
        ans *= 10;
        ans += grid[y] - '0';
        grid[y++] = '.';
    }
    return ans;
}

int result(char *grid[140], int x, int y)
{
    int sum = 0;

    for (int i = -1; i <= 1; i++)
        for (int j = -1; j <= 1; j++)
            if (grid[x + i][y + j] >= '0' && grid[x + i][y + j] <= '9')
                sum += toInt(grid[x+i], y+j);
    return sum;
}

void part1(void)
{
    FILE *in = fopen("day3.txt", "r");
    char *grid[140];
    char buffer[200];
    int sum = 0;
    int count = 0;

    while (fgets(buffer, sizeof(buffer), in) != NULL)
    {   
        grid[count] = malloc(150);
        strcpy(grid[count++], buffer);
    }
    
    for (int i = 0; i < 140; i++)
        for (int j = 0; j < 140; j++)
            if ((grid[i][j] < '0' || grid[i][j] > '9') && grid[i][j] != '.')
                sum += result(grid, i, j);

    for (int i = 0; i < 140; i++)
        free(grid[i]);
    printf("%i\n", sum);
    fclose(in);
}

int ratio(char *grid[140], int x, int y)
{
    int sum = 1;
    int count = 0;

    for (int i = -1; i <= 1; i++)
        for (int j = -1; j <= 1; j++)
            if (grid[x + i][y + j] >= '0' && grid[x + i][y + j] <= '9')
            {
                sum *= toInt(grid[x+i], y+j);
                count++;
            }
    return sum * (count == 2);
}

void part2(void)
{
    FILE *in = fopen("day3.txt", "r");
    char *grid[140];
    char buffer[200];
    int sum = 0;
    int count = 0;

    while (fgets(buffer, sizeof(buffer), in) != NULL)
    {   
        grid[count] = malloc(150);
        strcpy(grid[count++], buffer);
    }
    
    for (int i = 0; i < 140; i++)
        for (int j = 0; j < 140; j++)
            if (grid[i][j] == '*')
                sum += ratio(grid, i, j);

    for (int i = 0; i < 140; i++)
        free(grid[i]);
    printf("%i\n", sum);
    fclose(in);
}

int main(void)
{   
    clock_t begin = clock();
    part1();
    part2();
    printf("%f\n", (float)(clock() - begin) / CLOCKS_PER_SEC);
}
