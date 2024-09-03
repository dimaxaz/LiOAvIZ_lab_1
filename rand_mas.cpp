#include "task.h"

void initialize_mas(int* mas, int size)
{
    for (int i = 0; i < size; i++)
        mas[i] = rand() % 100;
}

void print_mas_rand(int* mas, int size)
{
    for (int i = 0; i < size; i++)
        printf("%d,  ", mas[i]);
    printf("\n");
}
