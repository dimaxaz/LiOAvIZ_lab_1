#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>

#define FILE_NAME "data.txt"

int initialize_mas_size(int* size_r, int* size_c);

int initialize_mas_rand(int*** arr, int size_r, int size_c);
void print_mas_rand(int** arr, int size_r, int size_c);

int calculate_difference(int** arr, int size_r, int size_c);

int calculate_sum_columns(int** arr, int size_r, int size_c, int* sums);
int calculate_sum_rows(int** arr, int size_r, int size_c, int* sums);

void write_mas_to_file(int** arr, int size_r, int size_c, const char* filename, int result);
