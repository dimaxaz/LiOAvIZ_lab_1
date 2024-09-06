#include "student.h"

void save_to_file(const Student* students, int count, const char* filename)
{
    FILE* file = fopen(filename, "w");
    if (!file)
    {
        printf("Не удалось открыть файл для записи.\n");
        return;
    }

    for (int i = 0; i < count; i++)
        fprintf(file, "%d %s %s %d\n", students[i].id, students[i].first_name, students[i].last_name, students[i].year_of_birth);

    fclose(file);
    printf("Данные сохранены в файл '%s'.\n", filename);
}

void load_from_file(Student* students, int* count, const char* filename)
{
    FILE* file = fopen(filename, "r");

    if (!file)
    {
        printf("Не удалось открыть файл для чтения.\n");
        return;
    }

    while (fscanf(file, "%d %s %s %d", &students[*count].id, students[*count].first_name, students[*count].last_name, &students[*count].year_of_birth) != EOF)
        (*count)++;

    fclose(file);
    printf("Данные загружены из файла '%s'.\n", filename);
}