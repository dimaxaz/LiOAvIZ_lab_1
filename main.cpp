#include "student.h"

void hide_cursor()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(hConsole, &cursorInfo);
}

void loading_animation()
{
    const char* loading_chars = "|/-\\";

    for (int i = 0; i < 25; i++)
    {
        system("cls");
        printf("Загрузка");

        for (int j = 0; j < 3; j++)
        {
            printf(".");
            fflush(stdout);
            Sleep(30);
        }
        printf(" %c\n", loading_chars[i % 4]);
    }

    system("cls");
    printf("Загрузка завершена!\n");
}

int main()
{
    system("chcp 1251 > nul");

    Student students[100];

    int count = 0;
    int choice;
    int sort_choice;

    hide_cursor();
    loading_animation();
    Sleep(1000);

    do
    {
        system("cls");

        printf("\n=======================\n");
        printf("   Студенты Меню\n");
        printf("=======================\n");
        printf("1. Добавить студента\n");
        printf("2. Удалить студента\n");
        printf("3. Искать студента\n");
        printf("4. Показать всех студентов\n");
        printf("5. Сортировать студентов\n");
        printf("6. Сохранить в файл\n");
        printf("7. Загрузить из файла\n");
        printf("0. Выход\n");
        printf("=======================\n");
        printf("Выберите действие: ");

        while (scanf("%d", &choice) != 1 || choice < 0 || choice > 7)
        {
            printf("Ошибка: Пожалуйста, введите число от 0 до 7.\n");
            while (getchar() != '\n');
            printf("Выберите опцию: ");
        }
        switch (choice)
        {
        case 1:
            add_student(students, &count);
            break;

        case 2:
            delete_student(students, &count);
            break;

        case 3:
            search_student(students, count);
            break;

        case 4:
            if (count == 0)
                printf("Список студентов пуст.\n");
            else
                display_students(students, count);
            break;

        case 5:
            printf("Выберите параметр сортировки:\n");
            printf("1. Имя\n");
            printf("2. Фамилия\n");
            printf("3. Год рождения\n");

            scanf("%d", &sort_choice);
            if (sort_choice < 1 || sort_choice > 3)
                printf("Ошибка: Неверный выбор сортировки.\n");
            else
            {
                sort_students(students, count, sort_choice);
                printf("Студенты успешно отсортированы!\n");
            }
            break;

        case 6:
            save_to_file(students, count, "students.txt");
            printf("Данные успешно сохранены в файл 'students.txt'.\n");
            break;

        case 7:
            load_from_file(students, &count, "students.txt");
            printf("Данные успешно загружены из файла 'students.txt'.\n");
            break;

        case 0:
            printf("Выход...\n");
            break;

        default:
            printf("Неверный выбор. Попробуйте еще раз.\n");
        }

        printf("\nНажмите Enter, чтобы продолжить...");
        while (getchar() != '\n');
        getchar();

    } while (choice != 0);

    return 0;
}