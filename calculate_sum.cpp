#include "task.h"

int calculate_sum_columns(int** mas, int size_r, int size_c, int* sums)
{
    for (int j = 0; j < size_c; j++)
    {
        sums[j] = 0;
        for (int i = 0; i < size_r; i++)
            sums[j] += mas[i][j];
    }

    printf("����� �������� � ������ �������:\n");
    for (int j = 0; j < size_c; j++)
        printf("����� ������� %d: %d\n", j + 1, sums[j]);
    printf("\n");

    free(sums);
    return 0;
}

int calculate_sum_rows(int** mas, int size_r, int size_c, int* sums)
{
     sums = (int*)malloc(size_r * sizeof(int));

    if (!sums)
    {
        perror("������ ��������� ������ ��� ���� �����");
        return -1;
    }

    for (int i = 0; i < size_r; i++)
    {
        sums[i] = 0;
        for (int j = 0; j < size_c; j++)
            sums[i] += mas[i][j];
    }

    printf("����� �������� � ������ ������:\n");
    for (int i = 0; i < size_r; i++)
        printf("����� ������ %d: %d\n", i + 1, sums[i]);
    printf("\n");

    free(sums);
    return 0;
}