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

void printArray(int* m, int n) { //������� ������ �������
    for (int i = 0; i < n; i++)
        printf("%d ", m[i]);
}

void RandArray(int* m, int n) { //������� ����� ��������� ����� �������
    int min, max, fl1 = 0, fl2 = 0, ch = 0;
    min = 1;
    max = 10000000;
    srand(time(0));
    m[0] = rand() % (max - min + 1) + min;
    for (int i = 1; i < n; i++)
    {
        fl2 = 0;
        while (fl2 == 0)
        {
            ch = rand() % (max - min + 1) + min;
            for (int j = 0; j < i; j++)
                if (m[j] == ch)
                    fl1++;
            if (fl1 == 0)
            {
                m[i] = ch;
                fl2 = 1;
            }
            fl1 = 0;
        };
    };
}

int main() {
    int n, r, x = 100;
    while (x <= 100000)
    {
        n = x;
        std::cout << x << " ";
        r = 1;
        int* m = (int*)malloc(n * sizeof(int)); //�������� ������
        if (r == 0) {
            printf("Input the elements\n");
        }
        else RandArray(m, n); //�� ��� ������ ������

        auto begin = std::chrono::steady_clock::now(); //������ �������� ������� ���������� ����� (�++)
        quickSort(m, 0, n - 1); //���������
        auto end = std::chrono::steady_clock::now();
        auto elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
        std::cout << elapsed_ms.count() << "\n"; //����� ��������, ����� ������� � �������.
        free(m);
        x += 100;
        //getch();
    };
    return 0;
}