#include "task.h"

int calculate_sum_columns(int** arr, int size_r, int size_c, int* sums)
{

    for (int j = 0; j < size_c; j++)
    {
        sums[j] = 0;
        for (int i = 0; i < size_r; i++)
            sums[j] += arr[i][j];
    }

    printf("Суммы значений в каждом столбце:\n");
    for (int j = 0; j < size_c; j++)
        printf("Сумма столбца %d: %d\n", j + 1, sums[j]);

    free(sums);
    return 0;
}

int calculate_sum_rows(int** arr, int size_r, int size_c, int* sums)
{
     sums = (int*)malloc(size_r * sizeof(int));
    if (!sums)
    {
        perror("Ошибка выделения памяти для сумм строк");
        return -1;
    }

    for (int i = 0; i < size_r; i++)
    {
        sums[i] = 0;
        for (int j = 0; j < size_c; j++)
            sums[i] += arr[i][j];
    }

    printf("Суммы значений в каждой строке:\n");
    for (int i = 0; i < size_r; i++)
        printf("Сумма строки %d: %d\n", i + 1, sums[i]);

    free(sums);
    return 0;
}