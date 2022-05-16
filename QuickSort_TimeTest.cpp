#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <chrono>
#include <iostream>
void swap(int* a, int* b) { //������� ������ ����������
    int t = *a; 
    *a = *b;
    *b = t;
}

int partition(int array[], int low, int high) { //�������� ������������������
    int pivot = array[high]; //����������� �������

    int i = (low - 1);

    for (int j = low; j < high; j++) {
        if (array[j] <= pivot) {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[high]);
    return (i + 1);
}

void quickSort(int array[], int low, int high) { //������� ������� ����������
    if (low < high) {
        int pi = partition(array, low, high);
        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
}

void printArray(int *m, int n) { //������� ������ �������
    for (int i = 0; i < n; i++)
        printf("%d ", m[i]);
}

void ScanArray(int* m, int n) { //������� ����� ������ �������
    for (int i = 0; i < n; i++)
        scanf_s("%d", &m[i]);
}
void RandArray(int* m, int n) { //������� ����� ��������� ����� �������
    int min, max;
    puts("Input min number");
    scanf_s("%d", &min);
    puts("Input max number");
    scanf_s("%d", &max);
        srand(time(0));
    for (int i = 0; i < n; i++)
        m[i] = rand()%(max - min + 1) + min;
}

int main() {
    int n, r;
    printf("Input the number of elements: ");
    scanf_s("%d", &n); //������ ���������� ���������
    puts("Your array - 0, rand array - other"); //�������� ���� ��� ������ ������
    scanf_s("%d", &r);
    int* m = (int*)malloc(n * sizeof(int)); //�������� ������
    if (r == 0) {
        printf("Input the elements\n"); 
        ScanArray(m, n); //������ ������
    }
    else RandArray(m, n); //�� ��� ������ ������

    puts("Unsorted array");
    printArray(m, n); //����� ������������������ �������
    printf("\n");
    auto begin = std::chrono::steady_clock::now(); //������ �������� ������� ���������� ����� (�++)
    quickSort(m, 0, n - 1); //���������
    auto end = std::chrono::steady_clock::now();
    auto elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    std::cout << "Time: " << elapsed_ms.count() << " nanoseconds\n"; //����� ��������, ����� ������� � �������.
    puts("Sorted array:");
    printArray(m, n); //����� �������������� �������
    free(m);
    //getch();
    return 0;
}