#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <time.h>

void part1(void)
{
    FILE *in = fopen("day4.txt", "r");
    int points[] = {0,1,2,4,8,16,32,64,128,256,512};
    int sum = 0;

    char buffer[200];

    while (fgets(buffer, sizeof(buffer), in) != NULL)
    {
        char *token = strtok(buffer, "Card | ");
        token = strtok(NULL, "Card | ");

        int winners[100] = {0};
        for (int i = 0; i < 10; i++)
        {
            winners[atoi(token)] = 1;
            token = strtok(NULL, "Card | ");
        }

        int count = 0;
        for (int i = 0; i < 25; i++)
        {
            count += winners[atoi(token)];
            token = strtok(NULL, "Card | ");
        }
        sum += points[count];
    }
    printf("%i\n", sum);
    fclose(in);
}

void part2(void)
{
    FILE *in = fopen("day4.txt", "r");
    int sum = 0;
    int instances[204] = {0};
    char buffer[200];

    for (int j = 0; j < 204; j++)
    {
        instances[j] += 1;
        fgets(buffer, sizeof(buffer), in);
        char *token = strtok(buffer, "Card | ");
        token = strtok(NULL, "Card | ");

        int winners[100] = {0};
        for (int i = 0; i < 10; i++)
        {
            winners[atoi(token)] = 1;
            token = strtok(NULL, "Card | ");
        }

        int count = 0;
        for (int i = 0; i < 25; i++)
        {
            count += winners[atoi(token)];
            token = strtok(NULL, "Card | ");
        }

        for (int i = 1; i <= count; i++)
            instances[i + j] += instances[j];

    }

    for (int i = 0; i < 204; i++)
        sum += instances[i];

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
