#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <time.h>

void part1(void)
{
    FILE *in = fopen("day2.txt", "r");
    char buffer[500];
    int sum = 0;

    while (fgets(buffer, sizeof(buffer), in) != NULL)
    {
        char *token = strtok(buffer, ";:, ");
        token = strtok(NULL, ":;, ");
        int id = atoi(token);
        int last = 0;
        token = strtok(NULL, ":;, ");

        while (token != NULL)
        {   
            int i = atoi(token);
            if (i)
            {   
                last = i;
            }
            else
            {
                if (token[0] == 'r')
                {
                    if (last > 12)
                    {
                        id = 0;
                        break;
                    }
                }
                else if (token[0] == 'g')
                {
                    if (last > 13)
                    {
                        id = 0;
                        break;
                    }
                }
                else if (token[0] == 'b')
                {
                    if (last > 14)
                    {
                        id = 0;
                        break;
                    }
                }
            }
            token = strtok(NULL, ":;, ");
        }
        sum += id;
    }

    printf("%i\n" , sum);
    fclose(in);
}

void part2(void)
{
    FILE *in = fopen("day2.txt", "r");
    char buffer[500];
    int sum = 0;

    while (fgets(buffer, sizeof(buffer), in) != NULL)
    {
        char *token = strtok(buffer, ";:, ");
        token = strtok(NULL, ":;, ");
        int last = 0;
        token = strtok(NULL, ":;, ");

        int red = 0, green = 0, blue = 0;

        while (token != NULL)
        {   
            int i = atoi(token);
            if (i)
                last = i;
            else
            {
                if (token[0] == 'r')
                {
                    if (last > red)
                        red = last;
                }
                else if (token[0] == 'g')
                {
                    if (last > green)
                        green = last;
                }
                else if (token[0] == 'b')
                {
                    if (last > blue)
                        blue = last;
                }
            }
            token = strtok(NULL, ":;, ");
        }
        sum += red * green * blue;
    }

    printf("%i\n" , sum);
    fclose(in);
}

int main(void)
{   
    clock_t begin = clock();
    part1();
    part2();
    printf("%f\n", (float)(clock() - begin) / CLOCKS_PER_SEC);
}

