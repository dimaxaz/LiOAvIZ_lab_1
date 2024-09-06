#include "student.h"

void add_student(Student* students, int* count)
{
    Student new_student;
    new_student.id = *count + 1;

    printf("Введите имя студента: ");
    scanf("%s", new_student.first_name);

    printf("Введите фамилию студента: ");
    scanf("%s", new_student.last_name);

    printf("Введите год рождения студента (число): ");
    while (scanf("%d", &new_student.year_of_birth) != 1) {
        printf("Неверный ввод. Пожалуйста, введите число для года рождения: ");
        while (getchar() != '\n');
    }

    students[*count] = new_student;
    (*count)++;
    printf("Студент успешно добавлен!\n");
}
void delete_student(Student* students, int* count)
{
    int id;

    printf("Введите ID студента для удаления: ");
    scanf("%d", &id);

    for (int i = 0; i < *count; i++)
        if (students[i].id == id)
            for (int j = i; j < *count - 1; j++)
                students[j] = students[j + 1];
            (*count)--; // Уменьшаем количество студентов
            printf("Студент с ID %d удален.\n", id);
            return;

    printf("Студент с ID %d не найден.\n", id);
}

void search_student(const Student* students, int count)
{
    char name[50];

    printf("Введите имя или фамилию для поиска: ");
    scanf("%s", name);

    int found = 0;
    for (int i = 0; i < count; i++)
        if (strcmp(students[i].first_name, name) == 0 || strcmp(students[i].last_name, name) == 0)
            printf("ID: %d | Имя: %s | Фамилия: %s | Год рождения: %d\n",
                students[i].id, students[i].first_name, students[i].last_name, students[i].year_of_birth);
            found = 1;

    if (!found) printf("Студенты с именем или фамилией '%s' не найдены.\n", name);
}

void display_students(const Student* const students, int count)
{
    printf("Список студентов:\n");
    printf("\n%-10s %-20s %-20s %-15s\n", "ID", "Имя", "Фамилия", "Год рождения");
    printf("----------------------------------------------------------\n");

    for (int i = 0; i < count; i++)
        printf(" % -10d % -20s % -20s % -15d\n",
            students[i].id, students[i].first_name, students[i].last_name, students[i].year_of_birth);
    printf("----------------------------------------------------------\n");
}

void sort_students(Student* students, int count, int choice)
{
    for (int i = 0; i < count - 1; i++)
        for (int j = 0; j < count - i - 1; j++)
        {
            int cmp;

            if (choice == 1) { // Сортировка по имени
                cmp = strcmp(students[j].first_name, students[j + 1].first_name);
            }
            else if (choice == 2) { // Сортировка по фамилии
                cmp = strcmp(students[j].last_name, students[j + 1].last_name);
            }
            else if (choice == 3) { // Сортировка по году рождения
                cmp = students[j].year_of_birth - students[j + 1].year_of_birth;
            }
            // Сортировка по выбранному критерию
            if ((choice == 1 || choice == 2) ? cmp > 0 : cmp < 0) 
            {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
}