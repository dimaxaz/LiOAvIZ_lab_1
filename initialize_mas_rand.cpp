#include "task.h"

int initialize_mas_rand(int*** mas, int size_r, int size_c)
{
	*mas = (int**)malloc(size_r * sizeof(int*));

	if (*mas == NULL)
	{
		perror("Ошибка выделения памяти");
		return 1;
	}

	for (int i = 0; i < size_r; i++)
	{
		(*mas)[i] = (int*)malloc(size_c * sizeof(int));

		if ((*mas)[i] == NULL)
		{
			perror("Ошибка выделения памяти");
			for (int j = 0; j < i; j++)
				free((*mas)[j]);
			free(*mas);

			return 1;
		}
	}

	srand((unsigned int)time(NULL));

	for (int i = 0; i < size_r; i++)
		for (int j = 0; j < size_c; j++)
			(*mas)[i][j] = rand() % 100;

	return 0;
}

void free_mas(int** mas, int size_r)
{
	for (int i = 0; i < size_r; i++)
		free(mas[i]);
	free(mas);
}

void print_mas_rand(int** mas, int size_r, int size_c)
{
	for (int i = 0; i < size_r; i++)
	{
		for (int j = 0; j < size_c; j++)
			printf("%d ", mas[i][j]);
		printf("\n");
	}
	printf("\n");

}
