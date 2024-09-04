#include "task.h"

int initialize_mas_rand(int*** arr, int size_r, int size_c){
    // Выделяем память под массив указателей на строки
    *arr = (int**)malloc(size_r * sizeof(int*));
    if (*arr == NULL) {
        perror("Ошибка выделения памяти");
        return 1;
    }

    // Выделяем память под каждую строку
    for (int i = 0; i < size_r; i++) {
        (*arr)[i] = (int*)malloc(size_c * sizeof(int));
        if ((*arr)[i] == NULL) {
            perror("Ошибка выделения памяти");
            for (int j = 0; j < i; j++) {
                free((*arr)[j]);
            }
            free(*arr);
            return 1;
        }
    }

    // Инициализация генератора случайных чисел
    srand((unsigned int)time(NULL));

    // Заполнение массива случайными числами
    for (int i = 0; i < size_r; i++) {
        for (int j = 0; j < size_c; j++) {
            (*arr)[i][j] = rand() % 100;
        }
    }

    return 0; // Успешное завершение
}

void free_array(int** arr, int size_r) {
    for (int i = 0; i < size_r; i++) {
        free(arr[i]); // Освобождаем каждую строку
    }
    free(arr); // Освобождаем массив указателей
}

void print_mas_rand(int** arr, int size_r, int size_c) {
    for (int i = 0; i < size_r; i++) {
        for (int j = 0; j < size_c; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}
