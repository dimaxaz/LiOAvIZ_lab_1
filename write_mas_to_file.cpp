#include "task.h"

void write_mas_to_file(int* mas, int size, const char* filename, int result)
{
    FILE* file = fopen(filename, "w");
    if (file == NULL)
    {
        perror("������ �������� �����");
        return;
    }

    fprintf(file, "������:  ");
    for (int i = 0; i < size; i++)
        fprintf(file, "%d ", mas[i]);

    fprintf(file, "\n");
    fprintf(file, "������� ����� ������������ � ����������� ���������� �������: %d ", result);

    fclose(file);
}