#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void swap(int* a, int* b) { //функция обмена указателей
    int t = *a; 
    *a = *b;
    *b = t;
}

int partition(int array[], int low, int high) { //алгоритм переупорядочивания
    int pivot = array[high]; //разрешающий элемент

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

void quickSort(int array[], int low, int high) { //функция быстрой сортировки
    if (low < high) {
        int pi = partition(array, low, high);
        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
}

void printArray(int *m, int n) { //функция вывода массива
    for (int i = 0; i < n; i++)
        printf("%d ", m[i]);
}

void ScanArray(int* m, int n) { //функция ввода своего массива
    for (int i = 0; i < n; i++)
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
        m[i] = rand()%(max - min + 1) + min;
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

    puts("Unsorted array");
    printArray(m, n); //вывод неотсортированного массива
    printf("\n");
    quickSort(m, 0, n - 1); //сортируем

    puts("Sorted array:");
    printArray(m, n); //вывод сортированного массива
    free(m);
    getch();
    return 0;
}
