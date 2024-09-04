#include "task.h"

int initialize_mas_size(int* size_r, int* size_c)
{
    printf("������� ���������� ����� �������: ");
    if (scanf("%d", size_r) != 1)
    {
        fprintf(stderr, "������ ����� ���������� ����� �������.\n");
        return 1;
    }

    printf("������� ���������� �������� �������: ");
    if (scanf("%d", size_c) != 1)
    {
        fprintf(stderr, "������ ����� ���������� �������� �������.\n");
        return 1;
    }

    if (*size_r <= 0 || *size_c <= 0)
    {
        printf("������� ������� ������ ���� �������������� �������.\n");
        return 1;
    }

    return 0;
}