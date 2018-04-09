#include<stdio.h>
#include<iostream>
#include<locale.h>
#include<time.h>
#include "Header.h"

void main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	int n;
	do
	{
		printf("Введите номер задания: ");
		scanf("%d", &n);

		switch (n)
		{
		case 1:
		{
			/*1. Дан двумерный массив целых чисел
			a.	Сформировать одномерный массив, каждый элемент которого равен
			наибольшему по модулю элементу соответствующего столбца двумерного массива

			b.	Сформировать одномерный массив, каждый элемент которого равен
			наибольшему по модулю элементу соответствующей строки двумерного массива
			*/

			int row = 0, col = 0, minElem = 11, maxElem = 50, stub = 1, stub0 = 0;
			printf("Формируем двумерный массив.\n");
			int *arr = GetMemory(&row, &col);
			fillArray(arr, &row, &col, &minElem, &maxElem);
			printArray(arr, &row, &col);

			int *vecColMax = NULL;
			vecColMax = GetMemoryVect(&col); // columns

			int *vecRowMax = NULL;
			vecRowMax = GetMemoryVect(&row); // rows

			task1(arr, &row, &col, vecColMax, vecRowMax);
			
			free(arr);
			free(vecColMax);
			free(vecRowMax);

			system("pause");
			system("cls");
		}
		break;

		case 2:
		{
			/*2. Дан двумерный массив целых чисел
			a.	Сформировать одномерный массив, каждый элемент которого равен
			первому четному элементу соответствующего столбца двумерного массива
			(если такого элемента в столбце нет, то он равен нулю).
			b.	Сформировать одномерный массив, каждый элемент которого равен
			последнему нечетному элементу соответствующей строки двумерного массива
			(если такого элемента в строке нет, то он равен нулю).
			*/

			int row = 0, col = 0, minElem = 11, maxElem = 50, stub = 1, stub0 = 0;
			printf("Формируем двумерный массив.\n");
			int *arr = GetMemory(&row, &col);
			fillArray(arr, &row, &col, &minElem, &maxElem);
			printArray(arr, &row, &col);

			int *vecColFirstEven = NULL;
			vecColFirstEven = GetMemoryVect(&col); // columns

			int *vecRowLastEven = NULL;
			vecRowLastEven = GetMemoryVect(&row); // rows

			task2(arr, &row, &col, vecColFirstEven, vecRowLastEven);
			
			free(arr);
			free(vecColFirstEven);
			free(vecRowLastEven);

			system("pause");
			system("cls");
		}
		break;

		case 3:
		{
			/*3. Дан двумерный массив.
			a.	Сформировать одномерный массив, каждый элемент которого равен
			количеству элементов соответствующего столбца двумерного массива,
			больших данного числа
			b.	Сформировать одномерный массив, каждый элемент которого равен
			сумме элементов соответствующей строки двумерного массива,
			меньших данного числа.
			*/

			int Number, row = 0, col = 0, colN, rowN, minElem = 11, maxElem = 50, stub = 1, stub0 = 0;
			printf("Введите число в интервале [0; 50]: ");
			scanf("%d", &Number);

			printf("Формируем двумерный массив.\n");
			int *arr = GetMemory(&row, &col);
			fillArray(arr, &row, &col, &minElem, &maxElem);
			printArray(arr, &row, &col);

			printf("Выбирете номер столбца: ");
			scanf("%d", &colN);

			int *vectCol = NULL;
			vectCol = GetMemoryVect(&col);

			/* формируем массив, элементы которого равены количеству элементов
			соответствующего столбца двумерного массива, больших данного числа */

			int k = 0;
			for (int i = 0; i < row; i++)
			{
				if (*(arr + colN - 1 + i * row) > Number)
				{
					*(vectCol + k) = *(arr + colN - 1 + i * row);
					k++;
				}

			}
			printf("Массив, элементы которого больше числа %d:\n", Number);
			printArray(vectCol, &stub, &k);

			/* формируем одномерный массив, каждый элемент которого равен
			сумме элементов соответствующей строки двумерного массива,
			меньших данного числа */

			int *vecRow = NULL;
			vecRow = GetMemoryVect(&row); // rows

			printf("Выбирете номер строки: ");
			scanf("%d", &rowN);

			k = 0;
			int sum = 0;
			for (int i = 0; i < col; i++)
			{
				if (*(arr + (rowN - 1)*row + i) < Number)
				{
					sum += *(arr + (rowN - 1)*row + i);
					*(vecRow + k) = sum;
					k++;
				}
			}
			printf("Массив, состоящий из суммы элементов меньших числа %d:\n", Number);
			printArray(vecRow, &stub, &k);
			
			free(arr);
			free(vectCol);
			free(vecRow);

			system("pause");
			system("cls");
		}
		break;

		case 4:
		{
			/*4. Дан двумерный массив размером N x M, заполненный целыми числами
			a.	Все его элементы, кратные трем, записать в одномерный массив.
			b.	Все его положительные элементы записать в один одномерный массив, а остальные — в другой
			*/
			int Number, row = 0, col = 0, colN, rowN, minElem = -30, maxElem = 50, stub = 1, stub0 = 0;

			printf("Формируем двумерный массив размером N x M.\n");
			int *arr = GetMemory(&row, &col);
			fillArray(arr, &row, &col, &minElem, &maxElem);
			printArray(arr, &row, &col);

			/* формируем массив, элементы которого равены кратные трем */
			int rowCol = row * col;

			int *vect = GetMemoryVect(&rowCol);

			int k = 0;

			for (int i = 0; i < row; i++)
			{
				for (int j = 0; j < col; j++)
				{
					if (*(arr + i * row + j) % 3 == 0)
					{
						*(vect + k) = *(arr + i * row + j);
						k++;
					}

				}

			}
			printf("Элементы, кратные трем:\n");
			printArray(vect, &stub, &k);

			int *vectPos = GetMemoryVect(&rowCol);
			int *vectNeg = GetMemoryVect(&rowCol);

			k = 0;
			int l = 0;

			for (int i = 0; i < row; i++)
			{
				//int k = 0, count=0;
				for (int j = 0; j < col; j++)
				{
					if (*(arr + i * row + j) >= 0)
					{
						*(vectPos + k) = *(arr + i * row + j);
						k++;
					}
					else
					{
						*(vectNeg + l) = *(arr + i * row + j);
						l++;
					}

				}

			}
			printf("Положительные элементы массива: \n");
			printArray(vectPos, &stub, &k);
			printf("Отрицательные элементы массива: \n");
			printArray(vectNeg, &stub, &l);
			
			free(arr);
			free(vectPos);
			free(vectNeg);

			system("pause");
			system("cls");
		}
		break;

		case 5:
		{
			/*5. Ввести целые числа. Создать из них массив. Вычислить сумму чётных элементов массива*/
			int stub = 1;
			int *arr = NULL;
			arr = (int*)calloc(1, sizeof(int));
			int N = 1;
			printf("Для формирования массива введите произвольное число целых чисел.\n");
			printf("Для завершения ввода наберите \'+\'\n");
			do
			{
				printf("Введите число: ");
				if (scanf("%d", (arr + N - 1)) == true)
				{
					N++;
					arr = (int*)realloc(arr, sizeof(int)*(N + 1));
				}
				else
					break;

			} while (true);

			N--;
			printf("Сформированный массив: \n");
			printArray(arr, &stub, &N);
			int sum = 0;
			for (int i = 0; i < N; i++)
			{
				if (*(arr + i) % 2 == 0)
					sum += *(arr + i);
			}
			printf("Сумма четных элементов массива: %d\n", sum);
			
			free(arr);

			system("pause");
			system("cls");
			//n = 0; //непонятная ошибка, программа зацикливается и все время входит в задание 
		}
		break;

		case 6:
		{
			/*6. Ввести целое число N и массив из N вещественных чисел.
			Определить количество отрицательных элементов массива*/

			int N, stub = 1;
			double minElem = -20, maxElem = 50;

			printf("Введите число N: ");
			scanf("%d", &N);

			printf("Формируем массив из %d вещественных чисел.\n", N);
			double *arr = GetMemoryVectD(&N); // подготавливаем одномерный массив из N элементов
			fillArray(arr, &stub, &N, &minElem, &maxElem);
			printArray(arr, &stub, &N);

			int count = 0;
			for (int i = 0; i < N; i++)
			{
				if (*(arr + i) < 0)
					count++;
			}
			printf("Количество отрицательных элементов массива: %d\n", count);
			
			free(arr);

			system("pause");
			system("cls");
		}
		break;

		case 7:
		{
			/*7. Ввести целое число N. Создать массив из N вещественных чисел.
			Вычислить произведение элементов, модуль которых меньше 7.*/

			int N, stub = 1;
			double minElem = -20, maxElem = 50;

			printf("Введите число N: ");
			scanf("%d", &N);

			printf("Формируем массив из %d вещественных чисел.\n", N);
			double *arr = GetMemoryVectD(&N); // подготавливаем одномерный массив из N элементов
			fillArray(arr, &stub, &N, &minElem, &maxElem);
			printArray(arr, &stub, &N);

			double mult = 1;
			for (int i = 0; i < N; i++)
			{
				if (abs(*(arr + i)) < 7)
					mult *= abs(*(arr + i));
			}

			printf("Произведение элементов, модуль которых меньше 7: %3.2lf\n", mult);
			
			free(arr);
			
			system("pause");
			system("cls");
		}
		break;

		case 8:
		{
			/*8. Ввести вещественные числа. Создать из них массив определить наибольший элемент массива*/
			double *arr = NULL;
			int stub = 1;

			arr = (double*)calloc(1, sizeof(double));
			int N = 1;
			printf("Для формирования массива введите произвольное число вещественных чисел.\n");
			printf("Для завершения ввода наберите \'+\'\n");
			do
			{
				printf("Введите число: ");
				if (scanf("%lf", (arr + N - 1)) == true)
				{
					N++;
					arr = (double*)realloc(arr, sizeof(double)*(N + 1));
				}
				else
					break;

			} while (true);

			N--;

			printArray(arr, &stub, &N);
			printf("Наибольший элемент массива %3.2lf\n", maxArray(arr, &N));
			
			free(arr);

			system("pause");
			system("cls");
			//n = 0; // непонятная ошибка, программа зацикливается и все время входит в задание 

		}
		break;

		case 9:
		{
			/*9. Ввести целое число N и массив из N целых чисел.
			Определить наименьший элемент массива*/
			int N, stub = 1;
			int minElem = -20, maxElem = 50;

			printf("Введите число N: ");
			scanf("%d", &N);

			printf("Формируем массив из %d целых чисел.\n", N);
			int *arr = GetMemoryVect(&N); // подготавливаем одномерный массив из N элементов
			fillArray(arr, &stub, &N, &minElem, &maxElem);
			printArray(arr, &stub, &N);

			printf("Минимальный элемент массива: %d\n", minArray(arr, &N));
			
			free(arr);

			system("pause");
			system("cls");
		}
		break;

		case 10:
		{
			/*10. Ввести вещественные числа. Создать из них массив.
			Определить среднее арифметическое элементов массива.*/
			double *arr = NULL;
			int stub = 1;

			arr = (double*)calloc(1, sizeof(double));
			int N = 1;
			printf("Для формирования массива введите произвольное число вещественных чисел.\n");
			printf("Для завершения ввода наберите \'+\'\n");
			do
			{
				printf("Введите число: ");
				if (scanf("%lf", (arr + N - 1)) == true)
				{

					N++;
					arr = (double*)realloc(arr, sizeof(double)*(N + 1));
				}
				else
					break;

			} while (true);

			N--;

			printArray(arr, &stub, &N);
			printf("Cреднее арифметическое элементов массива %3.2lf\n", averArray(arr, &N));
			
			free(arr);

			system("pause");
			system("cls");
			//n = 0; // непонятная ошибка, программа зацикливается и все время входит в задание 
		}
		break;

		case 11:
		{
			/*11. Ввести вещественные числа. Создать из них массив.
			Определить количество неотрицательных элементов массива*/
			double *arr = NULL;
			int stub = 1;
			char cc = 'q';

			arr = (double*)calloc(1, sizeof(double));
			int N = 1;
			printf("Для формирования массива введите произвольное число вещественных чисел.\n");
			printf("Для завершения ввода наберите \'+\'\n");
			do
			{
				printf("Введите число: ");
				if (scanf("%lf", (arr + N - 1)) == true)
				{

					N++;
					arr = (double*)realloc(arr, sizeof(double)*(N + 1));
				}
				else
					break;

			} while (true);

			N--;

			printArray(arr, &stub, &N);

			int count = 0;
			for (int i = 0; i < N; i++)
			{
				if (*(arr + i) >= 0)
					count++;
			}
			free(arr);

			printf("Количество неотрицательных элементов массива: %d\n", count);

			system("pause");
			system("cls");
			//n = 0; // непонятная ошибка, программа зацикливается и все время входит в задание 
		}
		break;


		case 12:
		{
			/*12. Ввести целое число N и массив из N вещественных чисел.
			Определить индекс последнего отрицательного элемента массива*/
			int N, stub = 1;
			double minElem = -20, maxElem = 50;

			printf("Введите число N: ");
			scanf("%d", &N);

			printf("Формируем массив из %d вещественных чисел.\n", N);
			double *arr = GetMemoryVectD(&N); // подготавливаем одномерный массив из N элементов
			fillArray(arr, &stub, &N, &minElem, &maxElem);
			printArray(arr, &stub, &N);

			int flag = 0;
			for (int i = N - 1; i >= 0; i--)
			{
				if (*(arr + i) < 0)
				{
					printf("Последний отрицательный элемент массива: arr[%d] = %3.2lf\n", i, *(arr + i));
					flag = 1;
					break;
				}

			}
			if (!flag)
				printf("Отрицательных элементов нет.\n");
			
			free(arr);

			system("pause");
			system("cls");
		}
		break;

		case 13:
		{
			/*13. Ввести целое число N. Создать массив из N вещественных чисел.
			Вычислить сумму минимального и максимального элементов.*/
			int N, stub = 1;
			double minElem = 0, maxElem = 55;

			printf("Введите число N: ");
			scanf("%d", &N);

			printf("Формируем массив из %d целых чисел.\n ", N);
			double *arr = GetMemoryVectD(&N); // подготавливаем одномерный массив из N элементов
			fillArray(arr, &stub, &N, &minElem, &maxElem);
			printArray(arr, &stub, &N);

			printf("Минимальный элемент массива: %3.2lf\n", minArray(arr, &N));
			printf("Максимальный элемент массива: %3.2lf\n", maxArray(arr, &N));
			printf("Cумма минимального и максимального элементов %3.2lf\n", maxArray(arr, &N) + minArray(arr, &N));
			
			free(arr);

			system("pause");
			system("cls");
		}
		break;

		case 14:
		{
			/*14. Ввести вещественные числа. Создать из них массив.
			Вычислить произведение минимального и максимального элементов.*/
			int stub = 1;
			double *arr = NULL;

			arr = (double*)calloc(1, sizeof(double));
			int N = 1;
			printf("Для формирования массива введите произвольное число вещественных чисел.\n");
			printf("Для завершения ввода наберите \'+\'\n");
			do
			{
				printf("Введите число: ");
				if (scanf("%lf", (arr + N - 1)) == true)
				{
					N++;
					arr = (double*)realloc(arr, sizeof(double)*(N + 1));
				}
				else
					break;

			} while (true);

			N--;

			printArray(arr, &stub, &N);
			printf("Минимальный элемент массива: %3.2lf\n", minArray(arr, &N));
			printf("Максимальный элемент массива: %3.2lf\n", maxArray(arr, &N));
			printf("Произведение минимального и максимального элементов %3.2lf\n", maxArray(arr, &N)*minArray(arr, &N));
			
			free(arr);

			system("pause");
			system("cls");
			//n = 0; // непонятная ошибка, программа зацикливается и все время входит в задание

		}
		break;

		case 15:
		{
			/*15. Ввести целое число N и массив из N целых чисел.
			Определить, есть ли в массиве число 20.*/
			int N, searchNum, row = 0, col = 0, minElem = 0, maxElem = 30, stub = 1;

			printf("Введите число N: ");
			scanf("%d", &N);

			printf("Формируем массив из %d целых чисел.\n ", N);
			int *arr = GetMemoryVect(&N); // подготавливаем одномерный массив из N элементов
			fillArray(arr, &stub, &N, &minElem, &maxElem);
			printArray(arr, &stub, &N);

			printf("Введите число, которое нужно найти в массиве, напроимер 20: ");
			scanf("%d", &searchNum);

			searchNumber(arr, &N, &searchNum);
			
			free(arr);

			system("pause");
			system("cls");
		}
		break;
		}

	} while (n != 0);

}
