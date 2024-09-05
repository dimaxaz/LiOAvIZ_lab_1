#include "task.h"

void write_mas_to_file(int** arr, int size_r, int size_c, const char* filename, int result)
{
    FILE* file = fopen(filename, "w");
    if (!file)
    {
        perror("������ �������� �����");
        return;
    }

    fprintf(file, "������:\n");
    for (int i = 0; i < size_r; i++)
    {
        for (int j = 0; j < size_c; j++)
            fprintf(file, "%d ", arr[i][j]);
        fprintf(file, "\n");
    }
    fprintf(file, "������� ����� ������������ � ����������� ����������: %d\n", result);
    fclose(file);

    printf("���������� �������� � ���� '%s'.\n", filename);
    printf("\n");

}