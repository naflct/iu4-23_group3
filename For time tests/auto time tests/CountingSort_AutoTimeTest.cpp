#include <stdio.h>
#include <stdlib.h>
#include<iostream> //С++
#include<chrono> //С++

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
        int* m = (int*)malloc(n * sizeof(int)); //выделяем память
        if (r == 0) {
            printf("Input the elements\n");
        }
        else RandArray(m, n); //ну или рандом массив

        auto begin = std::chrono::steady_clock::now(); //начало подсчета времени выполнения проги (С++)
        CountingSort(m, n); //сортируем
        auto end = std::chrono::steady_clock::now(); //С++
        auto elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin); //С++
        std::cout << elapsed_ms.count() << "\n"; //конец подсчета
        free(m);
        x += 100;
        //getch();
    }
}