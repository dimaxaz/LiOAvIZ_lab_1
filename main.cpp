#include "task.h"

int main() 
{
    system("chcp 1251 > nul");
    int mas_test[9] = { 9, 12, 3, 14, 6, 15, 1, 20, 4 };
    //int* mas_test = NULL; // Устанавливаем указатель на массив в NULL, чтобы обозначить пустой массив

    int number_of_elements = sizeof(mas_test) / sizeof(mas_test[0]);
    //int number_of_elements = 0; // Устанавливаем количество элементов в 0

    int result = calculate_difference(mas_test, number_of_elements);

    if (result != -1) 
        printf("Разница между максимальным и минимальным элементами массива: %d\n", result);
    else
        printf("Массив пустой.\n");

    return 0;
}