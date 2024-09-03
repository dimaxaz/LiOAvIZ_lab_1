#include "task.h"

void write_mas_to_file(int* mas, int size, const char* filename, int result)
{
    FILE* file = fopen(filename, "w");
    if (file == NULL)
    {
        perror("Ошибка открытия файла");
        return;
    }

    fprintf(file, "Массив:  ");
    for (int i = 0; i < size; i++)
        fprintf(file, "%d ", mas[i]);

    fprintf(file, "\n");
    fprintf(file, "Разница между максимальным и минимальным элементами массива: %d ", result);

    fclose(file);
}