#include "student.h"

void add_student(Student* students, int* count)
{
    Student new_student;
    new_student.id = *count + 1;

    printf("������� ��� ��������: ");
    scanf("%s", new_student.first_name);

    printf("������� ������� ��������: ");
    scanf("%s", new_student.last_name);

    printf("������� ��� �������� �������� (�����): ");
    while (scanf("%d", &new_student.year_of_birth) != 1) {
        printf("�������� ����. ����������, ������� ����� ��� ���� ��������: ");
        while (getchar() != '\n');
    }

    students[*count] = new_student;
    (*count)++;
    printf("������� ������� ��������!\n");
}
void delete_student(Student* students, int* count)
{
    int id;

    printf("������� ID �������� ��� ��������: ");
    scanf("%d", &id);

    for (int i = 0; i < *count; i++)
        if (students[i].id == id)
            for (int j = i; j < *count - 1; j++)
                students[j] = students[j + 1];
            (*count)--; // ��������� ���������� ���������
            printf("������� � ID %d ������.\n", id);
            return;

    printf("������� � ID %d �� ������.\n", id);
}

void search_student(const Student* students, int count)
{
    char name[50];

    printf("������� ��� ��� ������� ��� ������: ");
    scanf("%s", name);

    int found = 0;
    for (int i = 0; i < count; i++)
        if (strcmp(students[i].first_name, name) == 0 || strcmp(students[i].last_name, name) == 0)
            printf("ID: %d | ���: %s | �������: %s | ��� ��������: %d\n",
                students[i].id, students[i].first_name, students[i].last_name, students[i].year_of_birth);
            found = 1;

    if (!found) printf("�������� � ������ ��� �������� '%s' �� �������.\n", name);
}

void display_students(const Student* const students, int count)
{
    printf("������ ���������:\n");
    printf("\n%-10s %-20s %-20s %-15s\n", "ID", "���", "�������", "��� ��������");
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

            if (choice == 1) { // ���������� �� �����
                cmp = strcmp(students[j].first_name, students[j + 1].first_name);
            }
            else if (choice == 2) { // ���������� �� �������
                cmp = strcmp(students[j].last_name, students[j + 1].last_name);
            }
            else if (choice == 3) { // ���������� �� ���� ��������
                cmp = students[j].year_of_birth - students[j + 1].year_of_birth;
            }
            // ���������� �� ���������� ��������
            if ((choice == 1 || choice == 2) ? cmp > 0 : cmp < 0) 
            {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
}