#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <time.h>

void part1(void)
{
    FILE * in = fopen("day1.txt", "r");
    char buffer[100];
    int sum = 0;

    while (fscanf(in, "%s", buffer) != EOF)
    {
        int x  = 0;
        char *tmp = buffer;

        while (*tmp < 48 || *tmp > 57)
            tmp++;
        x = *tmp++ - 48;
        int last = x;
        while (*tmp)
        {
            if (*tmp > 47 && *tmp < 58)
                last = *tmp - 48;
            tmp++;
        }
        x *= 10;
        x += last;
        sum += x;
    }

    printf("%i\n", sum);
    fclose(in);
} 

int num(char *in)
{   
    char *nums[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    char str[8] = {0};
    for (int j = 0; j < 6; j++)
    {
        str[j] = in[j];
        for (int i = 0; i < 9; i++)
            if (!strcmp(str, nums[i]))
                return i + 1;
    }
    return 0;
}

void part2(void)
{
    FILE * in = fopen("day1.txt", "r");
    char buffer[100];
    int sum = 0;

    while (fscanf(in, "%s", buffer) != EOF)
    {
        int x  = 0;
        char *tmp = buffer;

        while (*tmp)
        {
            if (*tmp > 47 && *tmp < 58)
            {
                x = *tmp++ - 48;
                break;
            }
            int a = num(tmp++);
            if (a)
            {
                x = a;
                break;
            }
        }

        int last = x;
        while (*tmp)
        {
            if (*tmp > 47 && *tmp < 58)
            {
                last = *tmp++ - 48;
                continue;
            }
            int a = num(tmp++);
            if (a)
                last = a;
        }
        x *= 10;
        x += last;
        sum += x;
    }

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