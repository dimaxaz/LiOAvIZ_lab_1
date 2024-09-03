#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FILE_NAME "output.txt"

int calculate_difference(int mas[], int size);

void initialize_mas(int* mas, int size);
void print_mas_rand(int* mas, int size);

void write_mas_to_file(int* mas, int size, const char* filename, int result);
