#pragma once

void fillArray(int *arr, int *row, int *col, int *min, int *max);
void fillArray(double *arr, int *row, int *col, double *min, double *max);
void fillArray(float *arr, int *row, int *col, float *min, float *max);
void printArray(int *arr, int *row, int *col);
void printArray(float *arr, int *row, int *col);
void printArray(double *arr, int *row, int *col);
int *GetMemoryVect(int *len);
float *GetMemoryVectF(int *len);
double *GetMemoryVectD(int *len);
int *GetMemory(int *row, int *col);
float *GetMemoryFloat(int *row, int *col);
double *GetMemoryDouble(int *row, int *col);
void extremunArray(int *arr, int *len, int *min, int *minIndex, int *max, int *maxIndex);
void extremunArray(float *arr, int *len, float *min, int *minIndex, float *max, int *maxIndex);
void extremunArray(double *arr, int *len, double *min, int *minIndex, double *max, int *maxIndex);
//void orderingColArray(int *arr, int *row, int *col, int *vecColMax, int *vecRowMax, int *vecColFirstEven, int *vecRowLastEven);
int minArray(int *arr, int *len);
float minArray(float *arr, int *len);
double minArray(double *arr, int *len);
int maxArray(int *arr, int *len);
float maxArray(float *arr, int *len);
double maxArray(double *arr, int *len);
void searchNumber(int *arr, int *len, int *srcNum);
void bubbleSort(int *arr, int *len);
//double arrayInt(double N);
double averArray(int *arr, int *len);
double averArray(float *arr, int *len);
double averArray(double *arr, int *len);

void task1(int *arr, int *row, int *col, int *vecColMax, int *vecRowMax);
void task2(int *arr, int *row, int *col, int *vecColFirstEven, int *vecRowLastEven);
