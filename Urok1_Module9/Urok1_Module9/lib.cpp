#include<stdio.h>
#include<iostream>
#include<locale.h>
#include<time.h>
#include "Header.h"

void fillArray(int *arr, int *row, int *col, int *min, int *max)
{
	for (int i = 0; i < *row; i++)
	{
		for (int j = 0; j < *col; j++)
		{
			*(arr + i * *row + j) = (*max - *min)*rand() / RAND_MAX + *min;
		}
	}
}

void fillArray(float *arr, int *row, int *col, float *min, float *max)
{
	for (int i = 0; i < *row; i++)
	{
		for (int j = 0; j < *col; j++)
		{
			*(arr + i * *row + j) = (float)((*max - *min)*rand() / RAND_MAX + *min);
		}
	}
}

void fillArray(double *arr, int *row, int *col, double *min, double *max)
{
	for (int i = 0; i < *row; i++)
	{
		for (int j = 0; j < *col; j++)
		{
			*(arr + i * *row + j) = (double)((*max - *min)*rand() / RAND_MAX + *min);
		}
	}
}

void printArray(int *arr, int *row, int *col)
{
	for (int i = 0; i < *row; i++)
	{
		for (int j = 0; j < *col; j++)
		{
			printf("%3d; ", *(arr + i * *row + j));
		}
		printf("\n");
	}
	printf("\n");
}

void printArray(float *arr, int *row, int *col)
{
	for (int i = 0; i < *row; i++)
	{
		for (int j = 0; j < *col; j++)
		{
			printf("%3.2lf; ", *(arr + i * *row + j));
		}
		printf("\n");
	}
	printf("\n");
}

void printArray(double *arr, int *row, int *col)
{
	for (int i = 0; i < *row; i++)
	{
		for (int j = 0; j < *col; j++)
		{
			printf("%3.2lf; ", *(arr + i * *row + j));
		}
		printf("\n");
	}
	printf("\n");
}

/* Проверка одномерного целочисленного массива */
int *GetMemoryVect(int *len)
{
	int *arr = NULL;
	/*printf("Введите длину вектора: ");
	scanf("%d", len);*/
	arr = (int*)calloc(*len, sizeof(int));

	if (arr == NULL)
	{
		printf("Not enough memory.\n");
		exit(0);
	}
	else
		return arr;
}

/* Проверка одномерного массива типа float */
float *GetMemoryVectF(int *len)
{
	float *arr = NULL;
	/*printf("Введите длину вектора: ");
	scanf("%d", len);*/
	arr = (float*)calloc(*len, sizeof(float));

	if (arr == NULL)
	{
		printf("Not enough memory.\n");
		exit(0);
	}
	else
		return arr;
}

/* Проверка одномерного массива типа double */
double *GetMemoryVectD(int *len)
{
	double *arr = NULL;
	/*printf("Введите длину вектора: ");
	scanf("%d", len);*/
	arr = (double*)calloc(*len, sizeof(double));

	if (arr == NULL)
	{
		printf("Not enough memory.\n");
		exit(0);
	}
	else
		return arr;
}

/* Проверка двумерного целочисленного массива */
int *GetMemory(int *row, int *col)
{
	int *arr = NULL;
	printf("Введите количество строк массива: ");
	scanf("%d", row);
	printf("Введите количество столбцов массива: ");
	scanf("%d", col);
	arr = (int*)calloc(*row**col, sizeof(int));

	if (arr == NULL)
	{
		printf("Not enough memory.\n");
		exit(0);
	}
	else
		return arr;
}

/* Проверка двумерного массива типа float */
float *GetMemoryFloat(int *row, int *col)
{
	float *arr = NULL;
	printf("Введите количество строк массива: ");
	scanf("%d", row);
	printf("Введите количество столбцов массива: ");
	scanf("%d", col);
	arr = (float*)calloc(*row**col, sizeof(float));

	if (arr == NULL)
	{
		printf("Not enough memory.\n");
		exit(0);
	}
	else
		return arr;
}

/* Проверка двумерного массива типа double */
double *GetMemoryDouble(int *row, int *col)
{
	double *arr = NULL;
	printf("Введите количество строк массива: ");
	scanf("%d", row);
	printf("Введите количество столбцов массива: ");
	scanf("%d", col);
	arr = (double*)calloc(*row**col, sizeof(double));

	if (arr == NULL)
	{
		printf("Not enough memory.\n");
		exit(0);
	}
	else
		return arr;
}

/* Экстремумы одномерного массива типа int: минимальный, махсимальный элементы и их индексы */
void extremunArray(int *arr, int *len, int *min, int *minIndex, int *max, int *maxIndex)
{
	*min = *max = *arr;
	for (int i = 0; i < *len; i++)
	{
		if (*(arr + i) < *min)
		{
			*min = *(arr + i);
			*minIndex = i;
		}
		if (*(arr + i) > *max)
		{
			*max = *(arr + i);
			*maxIndex = i;
		}
	}
}

/* Экстремумы одномерного массива типа float: минимальный, махсимальный элементы и их индексы */
void extremunArray(float *arr, int *len, float *min, int *minIndex, float *max, int *maxIndex)
{
	*min = *max = *arr;
	for (int i = 0; i < *len; i++)
	{
		if (*(arr + i) < *min)
		{
			*min = *(arr + i);
			*minIndex = i;
		}
		if (*(arr + i) > *max)
		{
			*max = *(arr + i);
			*maxIndex = i;
		}
	}
}

/* Экстремумы одномерного массива типа double: минимальный, махсимальный элементы и их индексы */
void extremunArray(double *arr, int *len, double *min, int *minIndex, double *max, int *maxIndex)
{
	*min = *max = *arr;
	for (int i = 0; i < *len; i++)
	{
		if (*(arr + i) < *min)
		{
			*min = *(arr + i);
			*minIndex = i;
		}
		if (*(arr + i) > *max)
		{
			*max = *(arr + i);
			*maxIndex = i;
		}
	}
}

/* Минимальный элемент int array */
int minArray(int *arr, int *len)
{
	int min = *arr;
	for (int i = 0; i < *len; i++)
	{
		if (*(arr + i) < min)
			min = *(arr + i);
	}
	return min;
}

/* Минимальный элемент float array */
float minArray(float *arr, int *len)
{
	float min = *arr;
	for (int i = 0; i < *len; i++)
	{
		if (*(arr + i) < min)
			min = *(arr + i);
	}
	return min;
}

/* Минимальный элемент double array */
double minArray(double *arr, int *len)
{
	double min = *arr;
	for (int i = 0; i < *len; i++)
	{
		if (*(arr + i) < min)
			min = *(arr + i);
	}
	return min;
}

/* Максимальный элемент int array */
int maxArray(int *arr, int *len)
{
	int max = *arr;
	for (int i = 0; i < *len; i++)
	{
		if (*(arr + i) > max)
			max = *(arr + i);
	}
	return max;
}

/* Максимальный элемент float array */
float maxArray(float *arr, int *len)
{
	float max = *arr;
	for (int i = 0; i < *len; i++)
	{
		if (*(arr + i) > max)
			max = *(arr + i);
	}
	return max;
}

/* Максимальный элемент double array */
double maxArray(double *arr, int *len)
{
	double max = *arr;
	for (int i = 0; i < *len; i++)
	{
		if (*(arr + i) > max)
			max = *(arr + i);
	}
	return max;
}

/*Среднее арифметическое массива*/
double averArray(int *arr, int *len)
{
	int sum = 0, count = 0;
	for (int i = 0; i < *len; i++)
	{
		sum += *(arr + i);
		count++;
	}
	return sum / count;
}

/*Среднее арифметическое массива*/
double averArray(float *arr, int *len)
{
	float sum = 0;
	int count = 0;
	for (int i = 0; i < *len; i++)
	{
		sum += *(arr + i);
		count++;
	}
	return sum / count;
}

/*Среднее арифметическое массива*/
double averArray(double *arr, int *len)
{
	double sum = 0;
	int count = 0;
	for (int i = 0; i < *len; i++)
	{
		sum += *(arr + i);
		count++;
	}
	return (sum / count);
}

/* Сортировка одномерного массива целых чисел методом пузырька.*/
void bubbleSort(int *arr, int *len)
{
	for (int i = 0; i < (*len - 1); i++)
	{
		for (int j = (*len - 1); j > i; j--)
		{
			if (*(arr + j - 1) > *(arr + j))
			{
				int temp = *(arr + j - 1);
				*(arr + j - 1) = *(arr + j);
				*(arr + j) = temp;
			}
		}
	}
}

/* Поиск числа в массиве */
void searchNumber(int *arr, int *len, int *srcNum)
{
	int count = 0, stub = 1;

	bubbleSort(arr, len);

	printf("Массив после сортировки.\n");
	printArray(arr, &stub, len);

	int left = 0;
	int right = *len - 1;
	int search = -1;

	while (left <= right)
	{
		count++;
		int mid = (left + right) / 2;

		//printf("индекс середины: %d, элемент массива: %d\n", mid, *(arr + mid));

		if (*srcNum == *(arr + mid))
		{
			search = mid;
			break;
		}

		if (*srcNum < *(arr + mid))
			right = mid - 1;
		else
			left = mid + 1;
	}

	if (search == -1)
		printf("Элемент не найден!\n");
	else
		printf("arr[%d] = %d (за %d проходов).\n", search, *(arr + search), count);
}