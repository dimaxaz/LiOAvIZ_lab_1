#include "task.h"

int initialize_mas_size(int* size_r, int* size_c)
{
    printf("Введите количество строк массива: ");
    if (scanf("%d", size_r) != 1)
    {
        fprintf(stderr, "Ошибка ввода количества строк массива.\n");
        return 1;
    }

    printf("Введите количество столбцов массива: ");
    if (scanf("%d", size_c) != 1)
    {
        fprintf(stderr, "Ошибка ввода количества столбцов массива.\n");
        return 1;
    }

    if (*size_r <= 0 || *size_c <= 0)
    {
        printf("Размеры массива должны быть положительными числами.\n");
        return 1;
    }

    return 0;
}