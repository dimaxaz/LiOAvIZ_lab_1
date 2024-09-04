#include "task.h"

int calculate_difference(int** arr, int size_r, int size_c) {
    int max_element = arr[0][0];
    int min_element = arr[0][0];

    for (int i = 0; i < size_r; i++) {
        for (int j = 0; j < size_c; j++) {
            if (arr[i][j] > max_element) {
                max_element = arr[i][j];
            }
            if (arr[i][j] < min_element) {
                min_element = arr[i][j];
            }
        }
    }

    return max_element - min_element;
}
