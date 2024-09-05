#include "task.h"

int calculate_difference(int** mas, int size_r, int size_c)
{
    int max_element = mas[0][0];
    int min_element = mas[0][0];

    for (int i = 0; i < size_r; i++)
        for (int j = 0; j < size_c; j++)
        {
            if (mas[i][j] > max_element)
                max_element = mas[i][j];
            if (mas[i][j] < min_element)
                min_element = mas[i][j];
        }

    return max_element - min_element;
}
