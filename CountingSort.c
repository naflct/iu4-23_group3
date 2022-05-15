#include <stdio.h>
#include <stdlib.h>

void CountingSort(int array[], int size) { //собсна сам вызов функции сортировки подсчетом
    int max = array[0];
    for (int i = 1; i < size; i++)
        if (array[i] > max)
            max = array[i];
    int* count = (int*)malloc(max + 1 * sizeof(int)); 

    for (int i = 0; i <= max; i++)
        count[i] = 0;

    for (int i = 0; i < size; i++)
        count[array[i]]++;

    for (int i = 1; i <= max; i++)
        count[i] += count[i - 1];

    int* out = (int*)malloc(size * sizeof(int));
    for (int i = size - 1; i >= 0; i--) {
        out[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }

    for (int i = 0; i < size; i++)
        array[i] = out[i];
    free(out);
    //free(count); //а почему оно так работает, мы не знаем и никогда не узнаем...
}

void printArray(int *m, int size) { //функция распечатки массива
    for (int i = 0; i < size; ++i)
        printf("%d ", m[i]);
}

void ScanArray(int *m, int n) { //фукнция ввода массива
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
    getch();
   }