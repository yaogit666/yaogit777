#pragma once

#include<stdio.h>


void InsertSort(int* array, int size);//插入排序
void ShellSort(int* array, int size);//希尔排序
void SelectSort(int* array, int size);//选择排序
void HeapSort(int* array, int size);//堆排序
void BubbleSort(int* array, int size);//冒泡排序
void QuickSort(int* array, int left, int right);//快速排序
void MergeSort(int* array, int size);//归并排序
void change(int* a, int* b);
void CountSort(int* array, int size);//计数排序
void HeapDown(int* array, int i, int size);//向下调整