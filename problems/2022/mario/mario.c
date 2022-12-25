#include <cs50.h>
#include <stdio.h>

void printBricks(int n);
void printSpaces(int n);

int main(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    for (int i = 1; i < height + 1; i++)
    {
        printSpaces(height - i);
        printBricks(i);
        printSpaces(2);
        printBricks(i);
        printf("\n");
    }
}

void printBricks(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("#");
    }
}

void printSpaces(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf(" ");
    }
}
