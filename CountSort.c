#include <stdio.h>
#include <stdlib.h>

void CountingSort(int* m, int n) { //функция сортировки (попытка 2)
    int max = m[0];
    for (int i = 1; i < n; i++)
        if (m[i] > max)
            max = m[i];
    int* c = (int*)malloc((max + 1) * sizeof(*m));
    memset(c, 0, sizeof(*m) * (max + 1));

    for (int i = 0; i < n; ++i) {
        ++c[m[i]];
    }

    int b = 0;
    for (int i = 0; i < max + 1; ++i) {
        for (int j = 0; j < c[i]; ++j) {
            m[b++] = i;
        }
    }

    free(c);
}

void printArray(int* m, int size) { //функция распечатки массива
    for (int i = 0; i < size; ++i)
        printf("%d ", m[i]);
}

void ScanArray(int* m, int n) { //фукнция ввода массива
    for (int i = 0; i < n; ++i)
        scanf_s("%d", &m[i]);
}

void RandArray(int* m, int n) { //функция ввода случайных чисел массива
    int min, max;
    puts("Input min number");
    scanf_s("%d", &min);
    puts("Input max number");
    scanf_s("%d", &max);
    srand(time(0));
    for (int i = 0; i < n; i++)
        m[i] = rand() % (max - min + 1) + min;
}

int main() {
    int n, r;
    printf("Input the number of elements: ");
    scanf_s("%d", &n); //вводим количество элементов
    puts("Your array - 0, rand array - other"); //выбираем свой или рандом массив
    scanf_s("%d", &r);
    int* m = (int*)malloc(n * sizeof(int)); //выделяем память
    if (r == 0) {
        printf("Input the elements\n");
        ScanArray(m, n); //вводим массив
    }
    else RandArray(m, n); //ну или рандом массив

    puts("Unsorted Array");
    printArray(m, n); //вывод неотсортированного массива
    printf("\n");
    CountingSort(m, n); //сортируем
    printf("Sorted array\n");
    printArray(m, n); //вывод сортированного массива
    free(m);
    //getch();
}