#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <time.h>

void part1(void)
{
    int time[] = {40,81,77,72};
    int dist[] = {219,1012,1365,1089};
    int sum = 1;

    for (int i = 0; i < 4; i++)
    {
        int x = 0;
        for (int j = 0; j < time[i]; j++)
        {
            if ((j * (time[i] - j)) > dist[i])
                x++;
        }
        sum *= x;
    }

    printf("%i\n", sum);
}

void part2(void)
{
    long time = 40817772;
    long dist = 219101213651089;
    int sum = 0;
 
    for (int j = 0; j < time; j++)
    {
        if ((j * (time - j)) > dist)
            sum++;
    }
    
    printf("%i\n", sum);
}

int main(void)
{   
    clock_t begin = clock();
    part1();
    part2();
    printf("%f\n", (float)(clock() - begin) / CLOCKS_PER_SEC);
}

