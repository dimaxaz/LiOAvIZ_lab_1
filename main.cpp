#include "task.h"

int main() 
{
    system("chcp 1251 > nul");

    int mas_size;

    printf("Введите размер массива: ");
    if (scanf("%d", &mas_size) != 1)
    {
        fprintf(stderr, "Ошибка ввода размера массива.\n");
        return 1;
    }

    if (mas_size <= 0)
    {
        printf("Размер массива должен быть положительным числом.\n");
        return 1;
    }

    int* mas_rand = (int*)malloc(mas_size * sizeof(int));
    if (mas_rand == NULL)
    {
        perror("Ошибка выделения памяти");
        return 1;
    }

    srand(time_t(NULL));
    initialize_mas(mas_rand, mas_size);

    printf("Массив, инициализированный случайными числами:\n");
    print_mas_rand(mas_rand, mas_size);

    int result = calculate_difference(mas_rand, mas_size);

    if (result != -1) 
        printf("Разница между максимальным и минимальным элементами массива: %d\n", result);
    else
        printf("Массив пустой.\n");

    write_mas_to_file(mas_rand, mas_size, FILE_NAME, result);
    printf("Массив успешно записан в файл %s\n", FILE_NAME);

    free(mas_rand);
    return 0;
}