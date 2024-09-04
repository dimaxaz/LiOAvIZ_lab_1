#include "task.h"

int initialize_mas_rand(int*** arr, int size_r, int size_c){
    // �������� ������ ��� ������ ���������� �� ������
    *arr = (int**)malloc(size_r * sizeof(int*));
    if (*arr == NULL) {
        perror("������ ��������� ������");
        return 1;
    }

    // �������� ������ ��� ������ ������
    for (int i = 0; i < size_r; i++) {
        (*arr)[i] = (int*)malloc(size_c * sizeof(int));
        if ((*arr)[i] == NULL) {
            perror("������ ��������� ������");
            for (int j = 0; j < i; j++) {
                free((*arr)[j]);
            }
            free(*arr);
            return 1;
        }
    }

    // ������������� ���������� ��������� �����
    srand((unsigned int)time(NULL));

    // ���������� ������� ���������� �������
    for (int i = 0; i < size_r; i++) {
        for (int j = 0; j < size_c; j++) {
            (*arr)[i][j] = rand() % 100;
        }
    }

    return 0; // �������� ����������
}

void free_array(int** arr, int size_r) {
    for (int i = 0; i < size_r; i++) {
        free(arr[i]); // ����������� ������ ������
    }
    free(arr); // ����������� ������ ����������
}

void print_mas_rand(int** arr, int size_r, int size_c) {
    for (int i = 0; i < size_r; i++) {
        for (int j = 0; j < size_c; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}
