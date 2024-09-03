#include "task.h"

int calculate_difference(int mas[], int size)
{
    if (size == 0) return -1;

    int max_element = mas[0];
    int min_element = mas[0];

    for (int i = 1; i < size; i++) 
    {
        if (mas[i] > max_element)
            max_element = mas[i];

        if (mas[i] < min_element)
            min_element = mas[i];
    }

    return max_element - min_element;
}
