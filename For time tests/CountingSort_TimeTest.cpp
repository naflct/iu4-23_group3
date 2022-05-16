#include <stdio.h>
#include <stdlib.h>
#include<iostream> //С++
#include<chrono> //С++
/*void CountingSort(int array[], int size) { //собсна сам вызов функции сортировки подсчетом
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
} */

//m — указатель на начало массива
 //n — размер массива
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

/*void RandArray(int* m, int n) { //функция ввода случайных неповторяющихся чисел массива
    int min, max, fl1 = 0, fl2 = 0, ch = 0;
    puts("Input min number");
    scanf_s("%d", &min);
    puts("Input max number");
    scanf_s("%d", &max);
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
} */

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
    auto begin = std::chrono::steady_clock::now(); //начало подсчета времени выполнения проги (С++)
    CountingSort(m, n); //сортируем
    auto end = std::chrono::steady_clock::now(); //С++
    auto elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin); //С++
    std::cout << "Time: " << elapsed_ms.count() << " nanoseconds\n"; //конец подсчета
    printf("Sorted array\n");
    printArray(m, n); //вывод сортированного массива
    free(m);
    //getch();
   }
