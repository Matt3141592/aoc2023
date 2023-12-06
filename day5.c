#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <time.h>

void part1(void)
{
    FILE *in = fopen("day5.txt", "r");

    char buffer[400];
    fgets(buffer, sizeof(buffer), in);
    long seeds[20];

    char *token = strtok(buffer, ": ");
    for (int i = 0; i < 20; i++)
    {
        token = strtok(NULL, ": ");
        seeds[i] = atol(token);
    }

    int done[20] = {0};
    while (fgets(buffer, sizeof(buffer), in) != NULL)
    {
        if (buffer[0] < '0' || buffer[0] > '9')
        {
            for (int i = 0; i < 20; i++)
                done[i] = 0;
            continue;
        }

        char *nums = strtok(buffer, " ");
        long dest = atol(nums);
        nums = strtok(NULL, " ");
        long source = atol(nums);
        nums = strtok(NULL, " ");
        long range = atol(nums);
       
        for (int i = 0; i < 20; i++)
            if ((seeds[i] - source < range) && (seeds[i] - source >= 0) && !done[i])
            {
                seeds[i] += dest - source;
                done[i] = 1;
            }
    }

    long min = 999999999999;
    for (int i = 0; i < 20; i++)
        if (seeds[i] < min)
            min = seeds[i];

    printf("%li\n", min);
    fclose(in);
}

typedef struct node
{
    long start;
    long end;
    int done;
    struct node *next;
}node;

node *append(node *head, long start, long end, int new)
{
    node *n = malloc(sizeof(node));
    n -> start = start;
    n -> end = end;
    n -> done = new;
    n -> next = head;
    return n;
}

void reset(node *head)
{
    while (head != NULL)
    {
        head -> done = 0;
        head = head -> next;
    }
}

void part2(void)
{
    FILE *in = fopen("day5.txt", "r");

    char buffer[400];
    fgets(buffer, sizeof(buffer), in);
    node *head = NULL;

    char *token = strtok(buffer, ": ");
    token = strtok(NULL, ": ");
    for (int i = 0; i < 10; i++)
    {
        long start = atol(token);
        token = strtok(NULL, ": ");
        long range = atol(token);
        token = strtok(NULL, ": ");
        head = append(head, start, start + range, 0);
    }

    while (fgets(buffer, sizeof(buffer), in) != NULL)
    {
        if (buffer[0] < '0' || buffer[0] > '9')
        {
            reset(head);
            continue;
        }

        char *nums = strtok(buffer, " ");
        long dest = atol(nums);
        nums = strtok(NULL, " ");
        long source = atol(nums);
        nums = strtok(NULL, " ");
        long range = atol(nums);

        node *temp = head;

        while (temp != NULL)
        {
            if (temp -> done)
            {
                temp = temp -> next;
                continue;
            }
            else if (temp -> end < source) // completely before
            {
                temp = temp -> next;
                continue;
            }
            else if (temp -> start >= source + range) // completely after
            {
                temp = temp -> next;
                continue;
            }
            else if (temp -> start < source && temp -> end > source + range) // overhaning both sides
            {
                head = append(head, source + range, temp -> end, 0); // part after
                temp -> end = source; // changing the bit before
                head = append(head, dest, dest + range, 1); // middle bit
            }
            else if (temp -> start >= source && temp -> end <= source + range) // inbetween
            {
                temp -> start += dest - source;
                temp -> end += dest - source;
                temp -> done = 1;
            }
            else if (temp -> start < source) // start is out but end is in
            {
                head = append(head, dest, temp -> end + dest - source, 1);
                temp -> end = source;
            }
            else if (temp -> end > source + range) // start is in but end is out
            {
                head = append(head, temp -> start + dest - source, dest + range, 1);
                temp -> start = source + range;
            }
            temp = temp -> next;
        }
    }

    long min = 999999999999;
    node *prev = head;
    while (head != NULL)
    {
        if (head -> start < min)
            min = head -> start;
        head = head -> next;
        free(prev);
        prev = head;
    }

    printf("%li\n", min);
    fclose(in);
}

int main(void)
{   
    clock_t begin = clock();
    part1();
    part2();
    printf("%f\n", (float)(clock() - begin) / CLOCKS_PER_SEC);
}
