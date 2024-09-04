#include "task.h"

int main()
{
    system("chcp 1251 > nul");

    int size_r = NULL;
    int size_c = NULL;
    int choice, choice_plus;
    int result;

    if (initialize_mas_size(&size_r,&size_c) != 0) return 1;

    int** mas_rand = (int**)malloc(size_r * sizeof(int*));
    for (int i = 0; i < size_r; i++)
        mas_rand[i] = (int*)malloc(size_c * sizeof(int));

    initialize_mas_rand(&mas_rand, size_r, size_c);
    printf("Массив, инициализированный случайными числами:\n");
    print_mas_rand(mas_rand, size_r, size_c);

    do 
    {
        printf("Выберите задание для проверки:\n \
            1) Вычисляющую разницу между максимальным и минимальным элементами массива\n \
            2) Вычисляющую сумму значений в каждом столбце(строке)\n \
            3) Заново сгенерировать числа\n \
            4) Записать результаты в файл\n \
            5) Выйти из программы\n \
            Введите ваш выбор: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("Неверный ввод. Попробуйте снова.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice)
        {
        case 1:
        {
            result = calculate_difference(mas_rand, size_r, size_c);
            printf("Разница между максимальным и минимальным элементами массива: %d\n", result);
        } break;

        case 2:
        {
            printf("1) Сумму значений в каждом столбце\n \
                    2) Сумму значений в каждой строке\n \
                    Введите ваш выбор: ");

            if (scanf("%d", &choice_plus) != 1 )
            {
                printf("Неверный ввод. Попробуйте снова.\n");
                while (getchar() != '\n');
                continue;
            }

            switch (choice_plus)
            {
            case 1:
            {
                int* sum_column = (int*)malloc(size_c * sizeof(int));
                if (!sum_column)
                {
                    perror("Ошибка выделения памяти для суммы столбцов");
                    break;
                }

                calculate_sum_columns(mas_rand, size_r, size_c, sum_column);

                printf("Суммы значений в каждом столбце:\n");
                for (int i = 0; i < size_c; i++)
                    printf("Столбец %d: %d\n", i + 1, sum_column[i]);

                free(sum_column);
            } break;

            case 2:
            {
                int* sum_row = (int*)malloc(size_r * sizeof(int));

                if (!sum_row)
                {
                    perror("Ошибка выделения памяти для суммы строк");
                    break;
                }

                calculate_sum_rows(mas_rand, size_r, size_c, sum_row);

                printf("Суммы значений в каждой строке:\n");
                for (int i = 0; i < size_r; i++)
                    printf("Строка %d: %d\n", i + 1, sum_row[i]);

                free(sum_row);
            } break;

            default:
                printf("Неверный выбор. Пожалуйста, попробуйте снова.\n");
            }
        } break;

        case 3:
        {
            initialize_mas_rand(&mas_rand, size_r, size_c);
            printf("Массив заново инициализирован.\n");
            print_mas_rand(mas_rand, size_r, size_c);
        } break;

        case 4:
        {
            write_mas_to_file(mas_rand, size_r, size_c, FILE_NAME, result);
            printf("Результаты записаны в файл '%s'.\n", FILE_NAME, result);
        } break;

        case 5:
            printf("Выход из программы...\n");
            break;

        default:
            printf("Неверный выбор. Пожалуйста, попробуйте снова.\n");
        }

    } while (choice != 5);


    for (int i = 0; i < size_r; i++)
        free(mas_rand[i]);

    free(mas_rand);

    return 0;
}